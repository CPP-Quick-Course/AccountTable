#pragma once
#include <string>
#include <map>
#include <memory>
#include <algorithm>
#include "person.h"
#include "employee.h"

bool compare_set_field(size_t& to_field, const size_t& from_field);

class Table{
public:
    template <typename T>
    void addRecord(T s_ptr){
        table[s_ptr->getId()] = s_ptr;
        auto current_size = std::to_string(s_ptr->getId()).size();
        compare_set_field(id_max_size,current_size);
        current_size = s_ptr->getType().size();
        compare_set_field(type_max_size,current_size);
        current_size = s_ptr->getName().size();
        compare_set_field(name_max_size,current_size);
        current_size = s_ptr->getPhone().size();
        compare_set_field(phone_max_size,current_size);
        current_size = s_ptr->getMail().size();
        compare_set_field(mail_max_size,current_size);
        std::shared_ptr<Employee> temp = std::dynamic_pointer_cast<Employee>(s_ptr);
        if(temp.get()!=nullptr){
            current_size = s_ptr->getDepartment().size();
            compare_set_field(department_max_size,current_size);
        }
    }
    static Table* GetInstance(const std::string& path);
    ~Table();
    void clearAll();
    bool deleteRecord(int id);
protected:
    Table(const std::string& path) : path(path){}
    Table() : path("Dumb") {}
private:
    Table(Table&) = delete;
    void operator=(const Table&) = delete;
    static Table table_;
    std::map<int,std::shared_ptr<Person>> table;
    std::string path;
    static size_t id_max_size;
    static size_t type_max_size;
    static size_t name_max_size;
    static size_t phone_max_size;
    static size_t mail_max_size;
    static size_t department_max_size;
};