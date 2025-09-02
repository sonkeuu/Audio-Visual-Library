#include <iostream>
#include "view.h"
#include "storage.h"
#include "c_media.h"
#include "c_book.h"
#include "c_audiobook.h"
#include "c_cd.h"
#include "c_dvd.h"
#include "c_pendrive.h"
#include "c_mp3.h"


using namespace std;

void View::ShowMenu() {
    cout << endl;
	cout << "---------- MENU ----------" << endl;
	cout << "1. Show all items" << endl;
    cout << "2. Show item by ID" << endl;
	cout << "3. Add new item" << endl;
	cout << "4. Remove item" << endl;
	cout << "5. Toggle item availability" << endl;
	cout << "6. Print to file" << endl;
    cout << "7. Change media location" << endl;
	cout << "8. Exit" << endl;
	cout << "--------------------------" << endl;
    cout << "Choose an option: ";
}

void View::RunMenu(Storage& storage) {
    int choice = 0;
    do {
        ShowMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
        case 1:
            ShowAllItems(storage);
            break;
        case 2:
            ShowItemById(storage);
            break;
        case 3:
            AddMediaInMenu(storage);
            break;
        case 4:
            RemoveMediaInMenu(storage);
            break;
        case 5:
            ToggleAvailabilityInMenu(storage);
            break;
		case 6:
			PrintToFile(storage);
			break;
        case 7:
            ChangeMediaLocation(storage);
            break;
        case 8:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Error: Invalid option. Try again." << endl;
        }
    } while (choice != 8);
}

void View::ShowAllItems(Storage& storage) {
	cout << endl;
    cout << "-------- STORAGE ---------" << endl;
    storage.DisplayAllItems(cout);
}

void View::ShowItemById(Storage& storage) {
    int32_t id;
    cout << "Item ID: ";
    cin >> id;
    cout << "--------------------------" << endl;
    storage.DisplayMediaById(id, cout);
}

void View::ShowItemToAdd(Storage& storage) {
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "1. BOOK" << endl;
    cout << "2. AUDIOBOOK" << endl;
    cout << "3. CD" << endl;
    cout << "4. DVD" << endl;
	cout << "5. PENDRIVE" << endl;
    cout << "6. MP3" << endl;
	cout << "7. Exit" << endl;
    cout << "--------------------------" << endl;
    cout << "Chose new media item to add: ";
}

void View::AddMediaInMenu(Storage& storage) {
    int choice = 0;
    ShowItemToAdd(storage);
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 1:
		AddBook(storage);
        break;
    case 2:
		AddAudiobook(storage);
        break;
    case 3:
		AddCd(storage);
        break;
    case 4:
		AddDvd(storage);
        break;
    case 5:
		AddPendrive(storage);
        break;
    case 6:
		AddMp3(storage);
		break;
	case 7:
		return;
    default:
        cout << "Error: Invalid option. Try again." << endl;
    }
	storage.Commit();
}

void View::AddBook(Storage& storage) {
    string title, genre, author;
	uint32_t year, pages;
    bool availability = 1;

	cout << "Enter title: ";
	getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

	cout << "Enter genre: ";
	getline(cin, genre);
	cout << "Enter author: ";
	getline(cin, author);

    while (true) {
        cout << "Enter number of pages: ";
        if (cin >> pages) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

	storage.AddMedia(new Book(title, year, genre, author, pages, availability));
	cout << "Book added successfully!" << endl;
}

void View::AddAudiobook(Storage& storage) {
    string title, genre, author;
    uint32_t year, chapters;
    bool availability = 1;

    cout << "Enter title: ";
    getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
	cin.ignore();

    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter author: ";
    getline(cin, author);

    while (true) {
        cout << "Enter number of chapters: ";
        if (cin >> chapters) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    storage.AddMedia(new Audiobook(title, year, genre, author, chapters, availability));
    cout << "Audiobook added successfully!" << endl;
}

void View::AddCd(Storage& storage) {
    string title, genre, author;
    uint32_t year, tracks;
    bool availability = 1;

    cout << "Enter title: ";
    getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter author: ";
    getline(cin, author);

    while (true) {
        cout << "Enter number of tracks: ";
        if (cin >> tracks) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    storage.AddMedia(new Cd(title, year, genre, author, tracks, availability));
    cout << "CD added successfully!" << endl;
}

void View::AddDvd(Storage& storage) {
    string title, genre, director;
    uint32_t year, length;
    bool availability = 1;

    cout << "Enter title: ";
    getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter director: ";
    getline(cin, director);

    while (true) {
        cout << "Enter length: ";
        if (cin >> length) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    storage.AddMedia(new Dvd(title, year, genre, director, length, availability));
    cout << "DVD added successfully!" << endl;
}

void View::AddPendrive(Storage& storage) {
    string title, genre, content;
    uint32_t year, capicity;
    bool availability = 1;

    cout << "Enter title: ";
    getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter type of content: ";
    getline(cin, content);

    while (true) {
        cout << "Enter capicity: ";
        if (cin >> capicity) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    storage.AddMedia(new Pendrive(title, year, genre, content, capicity, availability));
    cout << "Pendrive added successfully!" << endl;
}

void View::AddMp3(Storage& storage) {
    string title, genre;
    uint32_t year, length, tracks;
    bool availability = 1;

    cout << "Enter title: ";
    getline(cin, title);

    while (true) {
        cout << "Enter year: ";
        if (cin >> year) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    cout << "Enter genre: ";
    getline(cin, genre);

    while (true) {
        cout << "Enter length: ";
        if (cin >> length) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    while (true) {
        cout << "Enter number of tracks: ";
        if (cin >> tracks) break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number.\n";
    }
    cin.ignore();

    storage.AddMedia(new Mp3(title, year, genre, length, tracks, availability));
    cout << "MP3 added successfully!" << endl;
}

void View::RemoveMediaInMenu(Storage& storage) {
    uint32_t id;
    cout << "Enter ID of item to remove: ";
    cin >> id;
    cin.ignore();
    storage.RemoveMedia(id);
	storage.Commit();
}

void View::ToggleAvailabilityInMenu(Storage& storage) {
    uint32_t id;
    cout << "Enter ID of item to toggle availability: ";
    cin >> id;
    cin.ignore();
    storage.ToggleMediaAvailability(id);
	storage.Commit();
}

void View::ChangeMediaLocation(Storage& storage) {
    uint32_t id, shelf, cabinet;

    cout << "Enter ID of item to change location: ";
    cin >> id;
    cin.ignore();
    cout << "Enter shelf: ";
    cin >> shelf;
    cin.ignore();
    cout << "Enter cabinet: ";
    cin >> cabinet;
    cin.ignore();

    MediaLocation mediaLoc = MediaLocation(shelf, cabinet);
    bool result = storage.SetMediaLocation(id, mediaLoc);
    if (!result) {
        //cout << "Error: Location is not available or out of range.";
    }
    else { 
        storage.Commit(); 
    }
}

void View::PrintToFile(Storage& storage) {
    string fileName;
	cout << "Enter file name to save items: ";
	getline(cin, fileName);

	ofstream outFile(fileName);
	if (!outFile) {
		cout << "Error: Could not open file " << fileName << " for writing." << endl;
		return;
	}

	outFile << "-------- STORAGE ---------" << endl;
	storage.DisplayAllItems(outFile);
	outFile.close();

	cout << "Items saved to " << fileName << " successfully!" << endl;
}
