#include "Employee.h"

Employee::Employee()
	: Person("Employee")
{
}

Employee::Employee(std::string name, std::string phone, std::string mail)
	: Person("Employee", name, phone, mail)
{
}
