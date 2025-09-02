#pragma once

#include "c_media.h"
#include <string>

/// @brief Class representing an audiobook, which is a type of media.
class Audiobook : public Media {
private:
	MediaType type = AUDIOBOOK;
	uint32_t chapters;
	string author;

public:

	/// @brief Constructor for Audiobook class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param author 
	/// @param chapters 
	/// @param availibility 
	Audiobook(string title, uint32_t year, string genre, string author, uint32_t chapters, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Audiobook class.
	~Audiobook() override;

	/// @brief Gets the author of the audiobook.
	/// @return author
	string getAuthor();

	/// @brief Gets the number of chapters in the audiobook.
	/// @return chapters
	uint32_t getChapters();

	/// @brief Gets the media type of the audiobook.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the audiobook information.
	/// @param out
	void display(ostream& out) override;
};
