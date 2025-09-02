#pragma once

#include "c_media.h"
#include <string>

/// @brief Class representing a CD, which is a type of media.
class Cd : public Media {
private:
	MediaType type = CD;
	uint32_t tracks;
	string author;

public:

	/// @brief Constructor for Cd class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param author 
	/// @param tracks 
	/// @param availibility 
	Cd(string title, uint32_t year, string genre, string author, uint32_t tracks, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Cd class.
	~Cd() override;

	/// @brief Gets the author of the CD.
	/// @return author
	string getAuthor();

	/// @brief Gets the number of tracks on the CD.
	/// @return tracks
	uint32_t getTracks();

	/// @brief Gets the media type of the CD.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the CD information.
	/// @param out 
	void display(ostream& out) override;
};