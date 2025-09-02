#include "c_media.h"
#include "c_book.h"
#include "c_mp3.h"

using namespace std;

Mp3::Mp3(string title, uint32_t year, string genre, uint32_t length, uint32_t tracks, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->length = length;
	this->tracks = tracks;
};

Mp3::~Mp3() {}

uint32_t Mp3::getLength() {
	return length;
}

uint32_t Mp3::getTracks() {
	return tracks;
}

MediaType Mp3::getMediaType() {
	return MP3;
}

void Mp3::display(ostream& out) {
	displayBase(out);
	out << "Length: " << getLength() << " minutes" << endl;
	out << "Tracks: " << getTracks() << endl;
	out << "--------------------------" << endl;
}

void Mp3::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(to_string(getLength()));
	words.push_back(to_string(getTracks()));
}

