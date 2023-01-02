#pragma once
#include "person.h"

class Director : public Person{
public:
    Director(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
};