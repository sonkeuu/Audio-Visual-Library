#include <iostream>
#include <string>
#include "c_media.h"
#include "storage.h"
#include "file_storage.h"
#include "serializer.h"
#include "c_book.h"
#include "c_dvd.h"
#include "c_audiobook.h"
#include "c_pendrive.h"
#include "c_mp3.h"
#include "c_cd.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <limits>

using namespace std;

MediaSerializer::MediaSerializer() {
}

MediaSerializer::~MediaSerializer() {
}

void MediaSerializer::Serialize(Media* item, ofstream* stream){
	item->mediaSerializing();
	for (const string& word : item->words) {
		*stream << word << ";";
	}
}

/*void MediaSerializer::Serialize(Media* item, ofstream* stream) {

	vector<string> words;

	int media_type_as_int = static_cast<int>(item->getMediaType());

	words.push_back(to_string(media_type_as_int));
	words.push_back(to_string(item->getId()));
	words.push_back(item->getTitle());
	words.push_back(to_string(item->getYear()));
	words.push_back(item->getGenre());
	words.push_back(to_string(item->getAvailability()));

	switch (item->getMediaType()) {
		case BOOK: {
			Book* book = (Book*)item;
			if (book) {
				words.push_back(book->getAuthor());
				words.push_back(to_string(book->getPages()));
			}
			break;
		}
		case AUDIOBOOK: {
			Audiobook* audiobook = (Audiobook*)item;
			if (audiobook) {
				words.push_back(audiobook->getAuthor());
				words.push_back(to_string(audiobook->getChapters()));
			}
			break;
		}
		case CD: {
			Cd* cd = (Cd*)item;
			if (cd) {
				words.push_back(cd->getAuthor());
				words.push_back(to_string(cd->getTracks()));
			}
			break;
		}
		case DVD: {
			Dvd* dvd = (Dvd*)item;
			if (dvd) {
				words.push_back(dvd->getDirector());
				words.push_back(to_string(dvd->getLength()));
			}
			break;
		}
		case PENDRIVE: {
			Pendrive* pendrive = (Pendrive*)item;
			if (pendrive) {
				words.push_back(to_string(pendrive->getCapacity()));
				words.push_back(pendrive->getContent());
			}
			break;
		}
		case MP3: {
			Mp3* mp3 = (Mp3*)item;
			if (mp3) {
				words.push_back(to_string(mp3->getLength()));
				words.push_back(to_string(mp3->getTracks()));
			}
			break;
		}
		default:
			break;
	}

	words.push_back(to_string(item->getLocation().shelf));
	words.push_back(to_string(item->getLocation().cabinet));

	for (const string& word : words) {
		*stream << word << ";";
	}
}*/

bool isNumber(const string& s) {
	return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

vector<Media*> MediaSerializer::Deserialize(ifstream* stream) {

	vector<Media*> items;
	string line;
	int lineNumber = 0;

	while (getline(*stream, line)) {
		lineNumber++;
		stringstream ss(line);
		string mediaTypeStr, title, genre, yearStr, idStr, availabilityStr, shelf_str, cabinet_str;

		getline(ss, mediaTypeStr, ';');
		getline(ss, idStr, ';');
		getline(ss, title, ';');
		getline(ss, yearStr, ';');
		getline(ss, genre, ';');
		getline(ss, availabilityStr, ';');

		if (mediaTypeStr.empty() || idStr.empty() || title.empty() || yearStr.empty() || genre.empty() || availabilityStr.empty() ||
			!isNumber(mediaTypeStr) || !isNumber(yearStr) || !isNumber(idStr)) {
			cout << "Metadata error: Skipping line: " << lineNumber << endl;
			break;
		}

		int mediaTypeInt = stoi(mediaTypeStr);
		uint32_t year = stoul(yearStr);
		bool availability = (availabilityStr == "1" || availabilityStr == "true" || availabilityStr == "True");
		uint32_t id = stoul(idStr);

		Media* item = nullptr;

		switch (static_cast<MediaType>(mediaTypeInt)) {
			case BOOK: {
				string author, pagesStr;
				getline(ss, author, ';');
				getline(ss, pagesStr, ';');
				if (author.empty() || pagesStr.empty() || !isNumber(pagesStr)) break;
				uint32_t pages = stoul(pagesStr);
				item = new Book(title, year, genre, author, pages, availability);
				break;
			}
			case AUDIOBOOK: {
				string author, chaptersStr;
				getline(ss, author, ';');
				getline(ss, chaptersStr, ';');
				if (author.empty() || chaptersStr.empty() || !isNumber(chaptersStr)) break;
				uint32_t chapters = stoul(chaptersStr);
				item = new Audiobook(title, year, genre, author, chapters, availability);
				break;
			}
			case CD: {
				string author, tracksStr;
				getline(ss, author, ';');
				getline(ss, tracksStr, ';');
				if (author.empty() || tracksStr.empty() || !isNumber(tracksStr)) break;
				uint32_t tracks = stoul(tracksStr);
				item = new Cd(title, year, genre, author, tracks, availability);
				break;
			}
			case DVD: {
				string director, lengthStr;
				getline(ss, director, ';');
				getline(ss, lengthStr, ';');
				if (director.empty() || lengthStr.empty() || !isNumber(lengthStr)) break;
				uint32_t length = stoul(lengthStr);
				item = new Dvd(title, year, genre, director, length, availability);
				break;
			}
			case PENDRIVE: {
				string capacityStr, content;
				getline(ss, capacityStr, ';');
				getline(ss, content, ';');
				if (capacityStr.empty() || !isNumber(capacityStr) || content.empty()) break;
				uint32_t capacity = stoul(capacityStr);
				item = new Pendrive(title, year, genre, content, capacity, availability);
				break;
			}
			case MP3: {
				string lengthStr, tracksStr;
				getline(ss, lengthStr, ';');
				getline(ss, tracksStr, ';');
				if (lengthStr.empty() || tracksStr.empty() || !isNumber(lengthStr) || !isNumber(tracksStr)) break;
				uint32_t length = stoul(lengthStr);
				uint32_t tracks = stoul(tracksStr);
				item = new Mp3(title, year, genre, length, tracks, availability);
				break;
			}
		default:
			cout << "Error: Unknown media type: " << mediaTypeStr << ", skipping line: " << line << endl;
			break;
		}

		if (item) {
			item->setId(id);

			MediaLocation _loc;
			if (getline(ss, shelf_str, ';') 
				&& getline(ss, cabinet_str, ';')
				&& isNumber(shelf_str)
				&& isNumber(cabinet_str)) {
				int32_t _shelf = stoi(shelf_str);
				int32_t _cabinet = stoi(cabinet_str);
				if (_shelf > 0 && _shelf <= Storage::MAX_SHELF && _cabinet > 0 && _cabinet <= Storage::MAX_CABINET) {
					_loc.shelf = stoi(shelf_str);
					_loc.cabinet = stoi(cabinet_str);
				}
			}
			item->setLocation(_loc);

			items.push_back(item);
		}
		else {
			cout << "Error: Skipping line: " << lineNumber << endl;
		}

	}
	ArrangeLocation(items);
	
	return items;
}

MediaLocation MediaSerializer::FindFreeLocation(vector<Media*> items) {
	for (int shelfNum = 1; shelfNum <= Storage::MAX_SHELF; shelfNum++) {
		for (int cabNum = 1; cabNum <= Storage::MAX_CABINET; cabNum++) {
			Media* FreeMediaLoc = GetMediaByLocation(MediaLocation(shelfNum, cabNum), items);

			if (FreeMediaLoc == NULL) {
				return MediaLocation(shelfNum, cabNum);
			}
		}
	}

	return MediaLocation(-1, -1);
}

Media* MediaSerializer::GetMediaByLocation(MediaLocation location, vector<Media*> items) {
	for (Media* item : items) {
		if (item->getLocation().shelf == location.shelf && item->getLocation().cabinet == location.cabinet) {
			return item;
		}
	}
	return NULL;
}

void MediaSerializer::ArrangeLocation(vector<Media*> items) {
	//int32_t shelf = 1;
	//int32_t cabinet = 1;
	for (Media* item : items) {
		if (!item->getAvailability()) {
			continue;
		}

		if (item->getLocation().shelf == -1 || item->getLocation().cabinet == -1) {
			MediaLocation newMediaLoc = FindFreeLocation(items);
			if (newMediaLoc.shelf == -1 && newMediaLoc.cabinet == -1) {
				cout << "Error: No free location found." << endl;
				return;
			}

			item->setLocation(newMediaLoc);
		}
	}
}