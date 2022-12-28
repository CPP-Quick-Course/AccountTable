#pragma once
#include <iostream>
#include <vector>
#include "Person.h"

class Table
{
	static Table* m_instance;

	struct Row
	{
		std::string m_ID;
		std::string m_type;
		std::string m_name;
		std::string m_phone;
		std::string m_mail;
		std::string m_department;
	};

	std::vector<Row> rows;

	Table();

public:
	Table(Table& table) = delete;
	void operator=(const Table&) = delete;
	
	static Table* getInstance();
	void addRow(Person* person);
	void deleteRow(int accountID);
	void clearTable();
	int getRowsCount();
	std::string getRow(int index);
	std::string getHeader();
	std::string getFooter();
};

