#include "c_media.h"
#include "c_book.h"
#include "c_audiobook.h"

using namespace std;

Audiobook::Audiobook(string title, uint32_t year, string genre, string author, uint32_t chapters, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->author = author;
	this->chapters = chapters;
};

Audiobook::~Audiobook() {}

string Audiobook::getAuthor() {
	return author;
}

uint32_t Audiobook::getChapters() {
	return chapters;
}

MediaType Audiobook::getMediaType() {
	return AUDIOBOOK;
}

void Audiobook::display(ostream& out) {
	displayBase(out);
	out << "Author: " << getAuthor() << endl;
	out << "Chapters: " << getChapters() << endl;
	out << "--------------------------" << endl;
}

void Audiobook::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(getAuthor());
	words.push_back(to_string(getChapters()));
}
