#pragma once
#include "Person.h"

class Customer: public Person
{
public:
	Customer();
	Customer(std::string name, std::string phone, std::string mail);
};

