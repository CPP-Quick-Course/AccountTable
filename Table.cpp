#include "Table.h"
#include "Director.h"
#include <string>

Table* Table::m_instance = nullptr;

Table::Table()
{
}

Table* Table::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Table();
	}

	return m_instance;
}

void Table::addRow(Person* person)
{
	Row row;
	row.m_ID = std::to_string(person->getID());
	row.m_ID.resize(3, ' ');

	row.m_type = person->getType();
	row.m_type.resize(8, ' ');

	row.m_name = person->getName();
	row.m_name.resize(19, ' ');

	row.m_phone = person->getPhone();
	row.m_phone.resize(13, ' ');

	row.m_mail = person->getMail();
	row.m_mail.resize(17, ' ');

	Director* director = dynamic_cast<Director*>(person);
	if (director != NULL)
	{
		row.m_department = director->getDepartment();
	}
	row.m_department.resize(23, ' ');

	rows.push_back(row);
}

void Table::deleteRow(int accountID)
{
	int ID;
	for (int i = 0; i < rows.size(); ++i)
	{
		ID = std::stoi(rows.at(i).m_ID);
		if (ID == accountID)
		{
			rows.erase(rows.begin() + i);
		}
	}
}

void Table::clearTable()
{
	rows.clear();
}

int Table::getRowsCount()
{
	return rows.size();
}

std::string Table::getRow(int index)
{
	Row row = rows.at(index);
	return "| " + row.m_ID + " | " + row.m_type + " | " + row.m_name + " | "
		+ row.m_phone + " | " + row.m_mail + " | " + row.m_department + " |";
}

std::string Table::getHeader()
{
	std::string header;
	header.append("+----------------------------------------------------------------------------------------------------+\n")
		.append("| ACCOUNTS                                                                                           |\n")
		.append("+====================================================================================================+\n")
		.append("| ID  | type     | name                | phone         | mail              | department              |\n")
		.append("+====================================================================================================+\n");

	return header;
}

std::string Table::getFooter()
{
	return "+----------------------------------------------------------------------------------------------------+";
}