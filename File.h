#pragma once
#include <fstream>
#include "Table.h"

class File
{
private:
	std::ofstream m_file;

public:
	File() = delete;
	File(std::string filename);
	~File();
	void writeTable(Table* table);
};

