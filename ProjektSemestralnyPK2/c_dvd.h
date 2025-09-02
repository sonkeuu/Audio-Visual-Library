#pragma once

#include "c_media.h"
#include <string>

using namespace std;

/// @brief Class representing a DVD, which is a type of media.
class Dvd : public Media {
private:
	MediaType type = MediaType::DVD;
	uint32_t length;
	string director;

public:

	/// @brief Constructor for Dvd class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param director 
	/// @param length 
	/// @param availibility 
	Dvd(string title, uint32_t year, string genre, string director, uint32_t length, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Dvd class.
	~Dvd() override;

	/// @brief Gets the director of the DVD.
	/// @return director
	string getDirector();

	/// @brief Gets the length of the DVD in minutes.
	/// @return length 
	uint32_t getLength();

	/// @brief Gets the media type of the DVD.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the DVD information.
	/// @param out 
	void display(ostream& out) override;

};