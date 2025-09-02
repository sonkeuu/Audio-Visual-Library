#pragma once

#include "c_media.h"
#include <string>

/// @brief Class representing a book, which is a type of media.
class Book : public Media {
private:
	MediaType type = BOOK;
	uint32_t pages;
	string author;

public:

	/// @brief Constructor for Book class.
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param author 
	/// @param pages 
	/// @param availibility 
	Book(string title, uint32_t year, string genre, string author, uint32_t pages, bool availibility/*, LocationInLibrary location*/);

	/// @brief Destructor for Book class.
	~Book() override;

	/// @brief Gets the author of the book.
	/// @return author
	string getAuthor();

	/// @brief Gets the number of pages in the book.
	/// @return pages
	uint32_t getPages();

	/// @brief Gets the media type of the book.
	/// @return media type
	MediaType getMediaType() override;

	void mediaSerializing() override;

	/// @brief Displays the book information.
	/// @param out
	void display(ostream& out) override;

};