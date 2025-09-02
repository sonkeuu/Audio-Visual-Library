#pragma once  

#include <iostream>  
#include <cstdint> 
#include <string>
#include <vector>

using namespace std;  

/// @brief Enum representing different types of media.
enum MediaType {
	BOOK = 1,
	AUDIOBOOK = 2,
	CD = 3,
	DVD = 4,
	PENDRIVE = 5,
	MP3 = 6,
}; 

/// @brief Struct representing the location of media in the library.
struct MediaLocation {
	int32_t shelf;
	int32_t cabinet;
	
	/// @brief Constructor for MediaLocation.
	/// @param shelf 
	/// @param cabinet 
	MediaLocation(int32_t shelf, int32_t cabinet) {
		this->shelf = shelf;
		this->cabinet = cabinet;
	}

	/// @brief Default constructor for MediaLocation.
	MediaLocation() : MediaLocation(-1, -1) {
	}
};

class Media { 

private:  
	uint32_t id = 0; 
	MediaType type;
	string title;  
  	uint32_t year;
	string genre;
	bool availability;
	MediaLocation mediaLoc = MediaLocation();

public:  

	vector<string> words;

	/// @brief Constructor for Media class.
	/// @param type 
	/// @param title 
	/// @param year 
	/// @param genre 
	/// @param availibility 
	Media(MediaType type, string title, uint32_t year, string genre, bool availibility);

	/// @brief Destructor for Media class.
	virtual ~Media();  

	/// @brief Sets the location of the media in the library.
	/// @param location 
	void setLocation(MediaLocation location);

	/// @brief Gets the ID of the media item.
	/// @return id
	virtual uint32_t getId();

	/// @brief Sets the ID of the media item.
	/// @param id 
	void setId(uint32_t id);

	/// @brief Gets the media type of the item.
	/// @return media type
	virtual MediaType getMediaType() = 0;

	/// @brief Gets the title of the media item.
	/// @return title
	virtual string getTitle();

	/// @brief Gets the author of the media item.
	/// @return year
	virtual uint32_t getYear();

	/// @brief Gets the genre of the media item.
	/// @return genre 
	virtual string getGenre();

	/// @brief Checks if the media item is available.
	/// @return true or false
	virtual bool getAvailability();

	/// @brief Sets the availability of the media item.
	/// @return true or false
	virtual bool toggleAvailability();

	/// @brief Converts the media type to a string representation.
	/// @param type 
	/// @return media type as string
	string MediaTypeToString(MediaType type);

	/// @brief Displays the media item information.
	/// @param out 
	virtual void display(ostream& out) = 0;  

	/// @brief Displays the base information of the media item.
	/// @param out 
	virtual void displayBase(ostream& out);

	/// @brief Gets the location of the media item in the library.
	/// @return location
	MediaLocation getLocation();

	virtual void mediaSerializing();
};