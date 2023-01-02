#pragma once
#include <string>
#include <iomanip>
#include <map>
#include <fstream>

class Person{
public:
    Person(int id, std::string type, std::string name, std::string phone, std::string mail)
    : id(id), type(type), name(name), phone(phone), mail(mail){}
    int getId() const;
    std::string getType() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getMail() const;
    virtual std::string getDepartment() const {
        return "";
    };
    void setId(int id);
    void setType(std::string type);
    void setName(std::string name);
    void setPhone(std::string phone);
    void setMail(std::string mail);
    virtual std::ofstream& getAllData(std::ofstream& stream, const std::map<std::string,size_t>& container) const{
        stream << std::left << "| " << std::setw(container.at("id")) << std::setfill(' ') << id << " | " << std::setw(container.at("type")) << std::setfill(' ') << type
            << " | " << std::setw(container.at("name")) << std::setfill(' ') << name << " | " << std::setw(container.at("phone")) << std::setfill(' ') << phone
            << " | " << std::setw(container.at("mail")) << std::setfill(' ') << mail << " | " << std::setw(container.at("department")) << std::setfill(' ') << getDepartment() << " |"
            << std::endl;
        return stream;
    }
protected:
    int id;
    std::string type;
    std::string name;
    std::string phone;
    std::string mail;
};