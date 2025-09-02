#pragma once

#include <iostream>
#include "c_media.h"
#include "storage.h"
#include "file_storage.h"

/// @brief Class for serializing and deserializing media items.
class MediaSerializer {
public:
	
	/// @brief Constructor for MediaSerializer class.
	MediaSerializer();

	/// @brief Destructor for MediaSerializer class.
	~MediaSerializer();

	/// @brief Serializes a media item to a file stream.
	/// @param item 
	/// @param stream 
	void Serialize(Media* item, ofstream* stream);

	/// @brief Deserializes media items from a file stream.
	/// @param stream 
	/// @return vector of Media items
	vector<Media*> Deserialize(ifstream* stream);

private:

	/// @brief Finds a free location for media items in the storage.
	/// @param items 
	/// @return location
	MediaLocation FindFreeLocation(vector<Media*> items);

	/// @brief Gets a media item by its location from a vector of media items.
	/// @param location 
	/// @param items 
	/// @return Media item or NULL
	Media* GetMediaByLocation(MediaLocation location, vector<Media*> items);

	/// @brief Arranges the shelf by placing media items in their respective locations.
	/// @param items 
	void ArrangeLocation(vector<Media*> items);
};
