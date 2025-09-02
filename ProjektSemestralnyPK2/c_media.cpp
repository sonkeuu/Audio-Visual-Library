#include <iostream>
#include "c_media.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Media::Media(MediaType type, string title, uint32_t year, string genre, bool availibility/*, LocationInLibrary location*/)
{
	this->title = title;
	this->year = year;
	this->type = type;
	this->genre = genre;
	this->availability = availibility;
	
	
};

Media::~Media() {}

uint32_t Media::getId() {
	return id;
}

void Media::setId(uint32_t id) {
	this->id = id;
}

string Media::getTitle() {
	return title;
}

uint32_t Media::getYear() {
	return year;
}

string Media::getGenre() {
	return genre;
}

bool Media::getAvailability() {
	return availability;
}

bool Media::toggleAvailability() {
	availability = !availability;
	if (!availability) {
		setLocation(MediaLocation(-1, -1));
	}
	return availability;
}

string Media::MediaTypeToString(MediaType type) {
	switch (type) {
	case BOOK: return "BOOK";
	case AUDIOBOOK: return "AUDIOBOOK";
	case CD: return "CD";
	case DVD: return "DVD";
	case PENDRIVE: return "PENDRIVE";
	case MP3: return "MP3";
	default: return "UNKNOWN";
	}
}

MediaLocation Media::getLocation() {
	return mediaLoc;
}

void Media::displayBase(ostream& out) {
	//cout << "--------------------------" << endl;
	out << "Media Type: " << MediaTypeToString(getMediaType()) << endl;
	out << "ID: " << getId() << endl;
	out << "Title: " << getTitle() << endl;
	out << "Year: " << getYear() << endl;
	out << "Genre: " << getGenre() << endl;
	out << "Availability: " << (getAvailability() ? "Available" : "Not Available") << endl;
	out << "Shelf: " << getLocation().shelf << endl;
	out << "Cabinet: " << getLocation().cabinet << endl;
}

void Media::setLocation(MediaLocation location) {
	this->mediaLoc = location;
}

void Media::mediaSerializing() {

	int media_type_as_int = static_cast<int>(getMediaType());

	words.push_back(to_string(media_type_as_int));
	words.push_back(to_string(getId()));
	words.push_back(getTitle());
	words.push_back(to_string(getYear()));
	words.push_back(getGenre());
	words.push_back(to_string(getAvailability()));
}

