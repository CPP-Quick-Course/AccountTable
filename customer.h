#pragma once
#include "person.h"

class Customer : public Person{
public:
    Customer(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
};