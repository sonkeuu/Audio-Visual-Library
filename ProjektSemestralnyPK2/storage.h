#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "c_media.h"

using namespace std;

/// @brief Class representing a storage system for media items.
class Storage {
private:

	/// @brief Checks if the given location is already occupied by another media item.
	/// @param location 
	/// @return true or false 
	bool CheckIfLocationExists(MediaLocation location);

	/// @brief Finds a free location in the storage.
	/// @return media location 
	MediaLocation FindFreeLocation();

	/// @brief Gets the media item by its location.
	/// @param location 
	/// @return media item
	Media* GetMediaByLocation(MediaLocation location);

	/// @brief Arranges all media items in the storage to ensure they have valid locations.
	void ArrangeAllLocations();

	/// @brief Arranges the location of a specific media item by its ID.
	/// @param id 
	void ArrangeLocationById(uint32_t id);

protected:

	vector<Media*> items;
	uint32_t last_id = 0;

	/// @brief Sets the next ID number. 
	/// @param id 
	void setLastId(int id) {
		last_id = id;
	}

public:

	static const int MAX_SHELF = 10;
	static const int MAX_CABINET = 10;

	Storage();

	~Storage();

	/// @brief Adds new media item to the storage.
	/// @param instance 
	void AddMedia(Media* instance);

	/// @brief Removes media item from the storage. 
	/// @param id 
	void RemoveMedia(uint32_t id);

	/// @brief Toggles media item availability in the storage. 
	/// @param id 
	void ToggleMediaAvailability(uint32_t id);

	/// @brief Displays all media items.
	/// @param out 
	void DisplayAllItems(ostream& out);

	/// @brief Displays media item by its ID. 
	/// @param id 
	/// @param out 
	void DisplayMediaById(uint32_t id, ostream& out);

	/// @brief Commits full storage to the file. 
	virtual void Commit() = 0;

	/// @brief Gets media item location by its ID. 
	/// @param media_id 
	/// @return media location
	MediaLocation GetMediaLocation(uint32_t media_id);

	/// @brief Sets media item new location by its ID. 
	/// @param media_id 
	/// @param location 
	/// @return true or false
	bool SetMediaLocation(uint32_t media_id, MediaLocation location);
};