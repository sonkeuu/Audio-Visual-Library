#pragma once

#include <iostream>
#include "storage.h"

/// @brief Class representing a file-based storage system for media items.
class FileStorage : public Storage {

private:

	string FileName;

public:

	/// @brief Constructor for FileStorage class.
	/// @param FileName 
	FileStorage(const string FileName);

	/// @brief Destructor for FileStorage class.
	~FileStorage();

	/// @brief Commit media to a file.
	virtual void Commit() override;
};
