#include "c_media.h"
#include "c_book.h"
#include <string>
#include "c_pendrive.h"

using namespace std;

Pendrive::Pendrive(string title, uint32_t year, string genre, string content, uint32_t capicity, bool availibility/*, LocationInLibrary location*/)
	: Media(type, title, year, genre, availibility/*, location*/) {
	this->capicity = capicity;
	this->content = content;
};

Pendrive::~Pendrive() {}

string Pendrive::getContent() {
	return content;
}

uint32_t Pendrive::getCapacity() {
	return capicity;
}

MediaType Pendrive::getMediaType() {
	return PENDRIVE;
}

void Pendrive::display(ostream& out) {
	displayBase(out);
	out << "Content: " << getContent() << endl;
	out << "Capicity: " << getCapacity() << " GB" << endl;
	out << "--------------------------" << endl;
}

void Pendrive::mediaSerializing() {

	Media::mediaSerializing();
	words.push_back(to_string(getCapacity()));
	words.push_back(getContent());
}

