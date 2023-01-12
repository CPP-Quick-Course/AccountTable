#include <iostream>
#include <string>
#include "Person.h"
#include "Director.h"
#include "Employee.h"
#include "Customer.h"
#include "Table.h"
#include "File.h"

int beginAction(char action);
void createAccount(Table* table);
std::vector<std::string> enterData(char accountType);
void deleteAccount(Table* table);
void clearTable(Table* table);

int main() {
	char action;

	while (1)
	{
		std::cout << "Choose action (a - add, d - delete, c - clear):" << std::endl;
		std::cin >> action;
		
		if (beginAction(action) == 1)
		{
			return 0;
		}
	}
}

int beginAction(char action)
{
	Table* table = Table::getInstance();
	File file("Accounts.txt");

	switch (action)
	{
	case 'a':
		createAccount(table);
		file.writeTable(table);
		break;

	case 'd':
		deleteAccount(table);
		file.writeTable(table);
		break;

	case 'c':
		clearTable(table);
		file.writeTable(table);
		break;

	default:
		std::cout << "Closed" << std::endl;
		return 1;
	}

	return 0;
}

void createAccount(Table* table)
{
	char accountType;
	Person* person = nullptr;

	do {
		std::cout << "Choose account type (d - director, e - employee, c - customer):" << std::endl;
		std::cin >> accountType;
	} while (accountType!='d' && accountType != 'e' && accountType != 'c');
	
	std::vector<std::string> data(enterData(accountType));
	
	switch (accountType)
	{
	case 'd':
		person = new Director(data[0], data[1], data[2], data[3]);
		break;

	case 'e':
		person = new Employee(data[0], data[1], data[2]);
		break;

	case 'c':
		person = new Customer(data[0], data[1], data[2]);
		break;

	default:
		std::cout << "Canceled" << std::endl;
		break;
	}

	table->addRow(person);
	std::cout << "Account was created with ID " << person->getID() << "\n" << std::endl;
}

std::vector<std::string> enterData(char accountType)
{
	std::string name, phone, mail, department;
	std::cout << "Enter name:" << std::endl;
	std::getline(std::cin.ignore(), name);

	std::cout << "Enter phone:" << std::endl;
	std::cin >> phone;

	std::cout << "Enter mail:" << std::endl;
	std::cin >> mail;
	
	if (accountType == 'd')
	{
		std::cout << "Enter department:" << std::endl;
		std::cin >> department;
	}

	return { name, phone, mail, department };
}

void deleteAccount(Table* table)
{
	int accountID;

	std::cout << "Enter account ID to delete:" << std::endl;
	std::cin >> accountID;

	table->deleteRow(accountID);
	std::cout << "Account with ID " << accountID << " was deleted\n" << std::endl;
}

void clearTable(Table* table)
{
	table->clearTable();
	std::cout << "Table was cleared\n" << std::endl;
}