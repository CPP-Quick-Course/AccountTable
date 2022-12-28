#include "Director.h"

Director::Director()
	: Person("Director")
{
}

Director::Director(std::string name, std::string phone, std::string mail, std::string department)
	: Person("Director", name, phone, mail), m_department(department)
{
}

void Director::setDepartment(std::string department)
{
	this->m_department = department;
}

std::string Director::getDepartment() const
{
	return m_department;
}