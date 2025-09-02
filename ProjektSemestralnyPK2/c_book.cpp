#include "c_media.h"
#include "c_book.h"

using namespace std;

Book::Book(string title, uint32_t year, string genre, string author, uint32_t pages, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->author = author;
	this->pages = pages;

};

Book::~Book() {}

string Book::getAuthor() {
	return author;
}

uint32_t Book::getPages() {
	return pages;
}

MediaType Book::getMediaType() {
	return BOOK;
}

void Book::display(ostream& out) {
	displayBase(out);
	out << "Author: " << getAuthor() << endl;
	out << "Pages: " << getPages() << endl;
	out << "--------------------------" << endl;
}

void Book::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(getAuthor());
	words.push_back(to_string(getPages()));
}
