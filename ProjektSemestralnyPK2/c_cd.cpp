#include "c_media.h"
#include "c_book.h"
#include "c_cd.h"


using namespace std;

Cd::Cd(string title, uint32_t year, string genre, string author, uint32_t tracks, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->author = author;
	this->tracks = tracks;
};

Cd::~Cd() {}

string Cd::getAuthor() {
	return author;
}

uint32_t Cd::getTracks() {
	return tracks;
}

MediaType Cd::getMediaType() {
	return CD;
}

void Cd::display(ostream& out) {
	displayBase(out);
	out << "Author: " << getAuthor() << endl;
	out << "Tracks: " << getTracks() << endl;
	out << "--------------------------" << endl;
}

void Cd::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(getAuthor());
	words.push_back(to_string(getTracks()));
}

