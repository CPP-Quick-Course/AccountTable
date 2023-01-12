#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

class Table
{
	static Table* m_instance;

	std::vector<Person*> rows;

	Table();

public:
	Table(Table& table) = delete;
	void operator=(const Table&) = delete;
	
	static Table* getInstance();
	void addRow(Person* person);
	void deleteRow(int accountID);
	void clearTable();
	int getRowsCount();
	std::string getStrRow(int index);
	std::string getHeader();
	std::string getFooter();
};

