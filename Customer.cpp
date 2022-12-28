#include "Customer.h"

Customer::Customer()
	: Person("Customer")
{
}

Customer::Customer(std::string name, std::string phone, std::string mail)
	: Person("Director", name, phone, mail)
{
}
