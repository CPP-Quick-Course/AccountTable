#pragma once
#include "Person.h"

class Employee: public Person
{
public:
	Employee();
	Employee(std::string name, std::string phone, std::string mail);
};

