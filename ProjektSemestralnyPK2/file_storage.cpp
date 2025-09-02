#include <filesystem>
#include "file_storage.h"
#include <iostream>
#include "storage.h"
#include <fstream>
#include "file_storage.h"
#include "serializer.h"


bool static fileExists(const std::string& filename) {
	std::ifstream file(filename);
	return file.good();
}

FileStorage::FileStorage(const string FileName) {
	if (fileExists(FileName)) {
		MediaSerializer serializer;
		ifstream inputFile(FileName);
		items = serializer.Deserialize(&inputFile);
		for (Media* item : items) {
			if (item->getId() > last_id) {
				last_id = item->getId();
			}
		}
	}

	this->FileName = FileName;
}

FileStorage::~FileStorage() {
	for (Media* item : items) {
		delete item;
	}
	items.clear();
}

void FileStorage::Commit() {

	ofstream file(this->FileName);

	if (file.is_open()) {

		MediaSerializer* serializer = new MediaSerializer();
		for (Media* item : items) {
			serializer->Serialize(item, &file);
			file << std::endl;
		}

		file.close();
	}
	else {
		cout << "Could not open the file to append." << std::endl;
	}

	cout << "The storage contains " << this->items.size() << " elements.\n";
}


