#include "employee.h"

std::string Employee::getDepartment() const{
    return department;
}

void Employee::setDepartment(const std::string& dep){
    this->department = dep;
}