#pragma once

#include "c_media.h"
#include <string>

/// @brief Class representing an MP3 file, which is a type of media.
class Mp3 : public Media {
private:
	MediaType type = MP3;
	uint32_t tracks;
	uint32_t length;

public:

	/// @brief Constructor for Mp3 class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param length 
	/// @param tracks 
	/// @param availibility 
	Mp3(string title, uint32_t year, string genre, uint32_t length, uint32_t tracks, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Mp3 class.
	~Mp3() override;

	/// @brief Gets the number of tracks in the MP3 file.
	/// @return tracks
	uint32_t getTracks();

	/// @brief Gets the length of the MP3 file in seconds.
	/// @return length
	uint32_t getLength();

	/// @brief Gets the media type of the MP3 file.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the MP3 file information.
	/// @param out 
	void display(ostream& out) override;
};