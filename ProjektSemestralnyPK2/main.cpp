#include <iostream>
#include <fstream>
#include "storage.h"
#include "c_media.h"
#include "c_book.h"
#include "file_storage.h"
#include "c_dvd.h"
#include "serializer.h"
#include "c_audiobook.h"
#include "c_pendrive.h"
#include "c_mp3.h"
#include "c_cd.h"
#include "utilities.h"
#include "view.h"

using namespace std;


int main(int argc, char* argv[]) {

	if (argc != 2) {
		print_usage();
		return 1;
	}

	string fileName = argv[1];

	//ifstream inputFile(fileName);
	//if (!inputFile.is_open()) { cout << "Error: Could not open file for reading." << endl; return 1; }
	//MediaSerializer serializer;
	//vector<Media*> mediaItems = serializer.Deserialize(&inputFile);
	//inputFile.close();

	FileStorage fileStorage(fileName);


	//fileStorage.AddMedia(new Book("BB", 2020, "Fiction", "B", 320, true));
	//fileStorage.AddMedia(new Audiobook("BBB", 2024, "Drama", "BB", 10, true));
	//fileStorage.AddMedia(new Pendrive("BBBB", 2025, "Horror", "BBB", 64, true));
	//fileStorage.RemoveMedia(1);
	//fileStorage.ToggleMediaAvailability(2)

	View view;
	view.RunMenu(fileStorage);

	fileStorage.Commit();

	/*FileStorage* fileStorage = new FileStorage("c:\\temp\\books_db\\books.txt");

	fileStorage->AddMedia(new Book("Title1", 2020, "Fiction", "J.K.", 320, true));
	fileStorage->AddMedia(new Book("Title2", 2021, "Non-Fiction", "Me", 213, true));
	fileStorage->AddMedia(new Book("Title3", 2022, "Science", "Someone", 362, true));
	fileStorage->AddMedia(new Dvd("Title4", 2023, "Action", "Director", 120, true));
	fileStorage->AddMedia(new Audiobook("Title5", 2024, "Drama", "Author", 10, true));
	fileStorage->AddMedia(new Pendrive("Title6", 2025, "Horror", "Content", 64, true));
	fileStorage->AddMedia(new Book("Title7", 2026, "Fantasy", "Author", 400, true));
	fileStorage->AddMedia(new Cd("Title8", 2027, "Pop", "Artist", 12, true));
	fileStorage->AddMedia(new Mp3("Title9", 2028, "Rock", 180, 15, true));
	fileStorage->AddMedia(new Book("Title10", 2029, "Mystery", "Author", 250, true));

	fileStorage->RemoveMedia(3);
	fileStorage->RemoveMedia(15);

	fileStorage->setAvailability(2);
	fileStorage->setAvailability(3);

	fileStorage->Commit();*/
	
	return 0;
}


