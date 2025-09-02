#include "c_media.h"
#include "c_dvd.h"

Dvd::Dvd(string title, uint32_t year, string genre, string director, uint32_t length, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->director = director;
	this->length = length;
};

Dvd::~Dvd() {}

string Dvd::getDirector() {
	return director;
}

uint32_t Dvd::getLength() {
	return length;
}

MediaType Dvd::getMediaType() {
	return DVD;
}

void Dvd::display(ostream& out) {
	displayBase(out);
	out << "Director: " << getDirector() << endl;
	out << "Length: " << getLength() << " minutes" << endl;
	out << "--------------------------" << endl;
}

void Dvd::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(getDirector());
	words.push_back(to_string(getLength()));
}
