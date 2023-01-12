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
	rows.push_back(person);
}

void Table::deleteRow(int accountID)
{
	for (int i = 0; i < rows.size(); ++i)
	{
		if (rows[i]->getID() == accountID)
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

std::string Table::getStrRow(int index)
{
	std::string id(std::to_string(rows[index]->getID()));
	id.resize(3, ' ');

	std::string type(rows[index]->getType());
	type.resize(8, ' ');

	std::string name(rows[index]->getName());
	name.resize(19, ' ');

	std::string phone(rows[index]->getPhone());
	phone.resize(13, ' ');

	std::string mail(rows[index]->getMail());
	mail.resize(17, ' ');

	std::string department;
	Director* director = dynamic_cast<Director*>(rows[index]);
	if (director != NULL)
	{
		department = director->getDepartment();
	}
	department.resize(23, ' ');

	return "| " + id + " | " + type + " | " + name + " | "
		+ phone + " | " + mail + " | " + department + " |";
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