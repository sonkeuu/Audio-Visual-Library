#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "c_media.h"
#include "storage.h"

using namespace std;

bool Storage::CheckIfLocationExists(MediaLocation location) {
	for (Media* item : items) {
		if (item->getLocation().shelf == location.shelf && item->getLocation().cabinet == location.cabinet) {
			return true;
		}
	}
	return false;
}

MediaLocation Storage::FindFreeLocation() {
	for (int shelfNum = 1; shelfNum <= MAX_SHELF; shelfNum++) {
		for (int cabNum = 1; cabNum <= MAX_CABINET; cabNum++) {
			Media* FreeMediaLoc = GetMediaByLocation(MediaLocation(shelfNum, cabNum));
			if (FreeMediaLoc == NULL) {
				return MediaLocation(shelfNum, cabNum);
			}
		}
	}

	return MediaLocation(-1, -1);
}

Media* Storage::GetMediaByLocation(MediaLocation location) {
	for (Media* item : items) {
		if (item->getLocation().shelf == location.shelf && item->getLocation().cabinet == location.cabinet) {
			return item;
		}
	}	
	return NULL;
}

Storage::Storage() {
}

Storage::~Storage() {
}

void Storage::AddMedia(Media* instance) {
	instance->setId(++last_id);

	if (instance->getAvailability()) {
		MediaLocation freeLoc = FindFreeLocation();
		instance->setLocation(freeLoc);
	}
	else {
		instance->setLocation(MediaLocation(-1, -1));
	}

	items.push_back(instance);
}

void Storage::RemoveMedia(uint32_t id) {
	for (int i = 0; i < items.size(); i++) {
		Media* item = items[i];
		if (item->getId() == id) {
			cout << "Media with ID: " << id << " has been removed." << endl;
			delete item;
			items.erase(items.begin() + i);
			return;
		}
	}
	cout << "Error: No media with ID: " << id << " found." << endl;
}

void Storage::ToggleMediaAvailability(uint32_t id) {
	for (int i = 0; i < items.size(); i++) {
		Media* item = items[i];

		if (item->getId() == id) {
			item->toggleAvailability();

			if (!item->getAvailability()) {
				item->setLocation(MediaLocation(-1, -1));
			}
			else {
				ArrangeLocationById(id);
			}

			cout << "Media availability with ID: " << id << " changed to " << item->getAvailability() << endl;
			return;
		}
	}
	cout << "Error: No media with ID: " << id << " found." << endl;
}

void Storage::DisplayAllItems(ostream& out) {
	for (Media* item : items) {
		if (item) {
			item->display(out);
		}
		else { cout << "Error: No media items found." << endl; }
	}
}

void Storage::DisplayMediaById(uint32_t id, ostream& out) {
	for (Media* item : items) {
		if (item->getId() == id) {
			item->display(out);
		}
	}
}

MediaLocation Storage::GetMediaLocation(uint32_t media_id) {
	for (Media* item : items) {
		if (item->getId() == media_id) {
			return item->getLocation();
		}
	}
}

bool Storage::SetMediaLocation(uint32_t media_id, MediaLocation location) {
	
	if (location.shelf < 1 || location.shelf > MAX_SHELF) {
		cout << "Error: Location is not available or out of range.";
		return false;
	}

	if (location.cabinet < 1 || location.cabinet > MAX_CABINET) {
		cout << "Error: Location is not available or out of range.";
		return false;
	}
	
	for (Media* item : items) {
		if (item->getId() == media_id) {

			if (!item->getAvailability()) {
				cout << "Error: Cannot change location of an unavailable item." << endl;
				return false;
			}

			if (!CheckIfLocationExists(location)) {
				item->setLocation(location);
				return true;
			}
		}
	}
	cout << "Error: Location is not available or out of range.";
	return false;
}

void Storage::ArrangeAllLocations() {
	//int32_t shelf = 1;
	//int32_t cabinet = 1;
	for (Media* item : items) {
		if (item->getLocation().shelf == -1 || item->getLocation().cabinet == -1) {
			MediaLocation newMediaLoc = FindFreeLocation();
			if (newMediaLoc.shelf == -1 && newMediaLoc.cabinet == -1) {
				cout << "Error: No free location found." << endl;
				return;
			}
			item->setLocation(newMediaLoc);
		}
	}
}

void Storage::ArrangeLocationById(uint32_t id) {
	for (Media* item : items) {

		if (item->getId() == id) {

			if (item->getLocation().shelf == -1 || item->getLocation().cabinet == -1) {
				MediaLocation newMediaLoc = FindFreeLocation();

				if (newMediaLoc.shelf == -1 && newMediaLoc.cabinet == -1) {
					cout << "Error: No free location found." << endl;
					return;
				}
				item->setLocation(newMediaLoc);
			}
		}
	}
}