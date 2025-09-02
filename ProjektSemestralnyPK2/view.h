#pragma once
#include <iostream>
#include "storage.h"


using namespace std;

/// @brief Class representing the view layer of the application.
class View {

public:

	/// @brief Shows the main menu of the application.
	void ShowMenu();

	/// @brief Runs the main menu of the application.
	/// @param storage 
	void RunMenu(Storage& storage);

	/// @brief Shows all items in the storage.
	/// @param storage 
	void ShowAllItems(Storage& storage);

	/// @brief Shows item by its ID in the storage.
	/// @param storage 
	void ShowItemById(Storage& storage);

	/// @brief Shows the item to be added in the storage.
	/// @param storage 
	void ShowItemToAdd(Storage& storage);

	/// @brief Adds media item in the menu and prompts the user for input.
	/// @param storage 
	void AddMediaInMenu(Storage& storage);

	/// @brief Adds a book to the storage.
	/// @param storage 
	void AddBook(Storage& storage);

	/// @brief Adds an audiobook to the storage.
	/// @param storage 
	void AddAudiobook(Storage& storage);

	/// @brief Adds a CD to the storage.
	/// @param storage 
	void AddCd(Storage& storage);

	/// @brief Adds a DVD to the storage.
	/// @param storage 
	void AddDvd(Storage& storage);

	/// @brief Adds a pendrive to the storage.
	/// @param storage 
	void AddPendrive(Storage& storage);

	/// @brief Adds an MP3 file to the storage.
	/// @param storage 
	void AddMp3(Storage& storage);

	/// @brief Removes media item from the menu and prompts the user for input.
	/// @param storage 
	void RemoveMediaInMenu(Storage& storage);

	/// @brief Toggles the availability of media item in the menu and prompts the user for input.
	/// @param storage 
	void ToggleAvailabilityInMenu(Storage& storage);

	/// @brief Changes the media location in the menu and prompts the user for input.
	/// @param storage 
	void ChangeMediaLocation(Storage& storage);

	/// @brief Prints the storage content to a file.
	/// @param storage 
	void PrintToFile(Storage& storage);
};