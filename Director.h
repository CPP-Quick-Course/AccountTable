#pragma once
#include "Person.h"

class Director: public Person
{
	std::string m_department;

public:
	Director();
	Director(std::string name, std::string phone, std::string mail, std::string department);
	void setDepartment(std::string department);
	std::string getDepartment() const;
};

