#pragma once

#include "c_media.h"
#include <string>

/// @brief Class representing a pendrive, which is a type of media.
class Pendrive : public Media {
private:
	MediaType type = PENDRIVE;
	uint32_t capicity;
	string content;

public:

	/// @brief Constructor for Pendrive class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param content 
	/// @param capicity 
	/// @param availibility 
	Pendrive(string title, uint32_t year, string genre, string content, uint32_t capicity, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Pendrive class.
	~Pendrive() override;

	/// @brief Gets the content of the pendrive.
	/// @return content
	string getContent();

	/// @brief Gets the capacity of the pendrive.
	/// @return capacity
	uint32_t getCapacity();

	/// @brief Gets the media type of the pendrive.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the pendrive information.
	/// @param out 
	void display(ostream& out) override;
};