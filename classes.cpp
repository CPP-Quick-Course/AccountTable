#include "classes.h"

int Person::getId() const {
    return id;
}
std::string Person::getType() const {
    return type;
}
std::string Person::getName() const {
    return name;
}
std::string Person::getPhone() const {
    return phone;
}
std::string Person::getMail() const {
    return mail;
}
void Person::setId(int id){
    this->id = id;
}
void Person::setType(std::string type){
    this->type = type;
}
void Person::setName(std::string name){
    this->name = name;
}
void Person::setPhone(std::string phone){
    this->phone = phone;
}
void Person::setMail(std::string mail){
    this->mail = mail;
}

std::string Employee::getDepartment() const {
    return department;
}
void Employee::setDepartment(std::string dep){
    this->department = dep;
}
Table::~Table(){
    for(const auto& c : table){
        c.second-> getAllData();
    }
}
void Table::clearAll(){
    table.clear();
}
bool Table::deleteRecord(int id){
    return table.erase(id);
}