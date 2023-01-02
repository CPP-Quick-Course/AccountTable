#pragma once
#include "person.h"

class Employee : public Person{
public:
    Employee(int id, std::string type, std::string name, std::string phone, std::string mail, std::string department)
    : Person(id,type,name,phone,mail), department(department){}
    std::string getDepartment() const override;
    void setDepartment(const std::string& dep);
    std::ofstream& getAllData(std::ofstream& stream, const std::map<std::string,size_t>& container) const override{
        stream << std::left << "| " << std::setw(container.at("id")) << std::setfill(' ') << id << " | " << std::setw(container.at("type")) << std::setfill(' ') << type
            << " | " << std::setw(container.at("name")) << std::setfill(' ') << name << " | " << std::setw(container.at("phone")) << std::setfill(' ') << phone
            << " | " << std::setw(container.at("mail")) << std::setfill(' ') << mail << " | " << std::setw(container.at("department")) << std::setfill(' ') << department << " |"
            << std::endl;
        return stream;
    }
private:
    std::string department;
};