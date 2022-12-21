#include <string>
#include <map>
#include <memory>

class Person{
public:
    Person(int id, std::string type, std::string name, std::string phone, std::string mail)
    : id(id), type(type), name(name), phone(phone), mail(mail){}
    int getId() const;
    std::string getType() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getMail() const;
    void setId(int id);
    void setType(std::string type);
    void setName(std::string name);
    void setPhone(std::string phone);
    void setMail(std::string mail);
    virtual void getAllData() const{
        printf("Id - %i, type - %s, name - %s, phone - %s, mail - %s\n",id,type.c_str(),name.c_str(),phone.c_str(),mail.c_str());
    }
protected:
    int id;
    std::string type;
    std::string name;
    std::string phone;
    std::string mail;
};

class Employee : public Person{
public:
    Employee(int id, std::string type, std::string name, std::string phone, std::string mail, std::string department)
    : Person(id,type,name,phone,mail), department(department){}
    std::string getDepartment() const;
    void setDepartment(std::string dep);
    void getAllData() const override{
        printf("Id - %i, type - %s, name - %s, phone - %s, mail - %s, department - %s\n",id,type.c_str(),name.c_str(),phone.c_str(),mail.c_str(),department.c_str());
    }
private:
    std::string department;
};

class Director : public Person{
public:
    Director(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
private:
};

class Customer : public Person{
public:
    Customer(int id, std::string type, std::string name, std::string phone, std::string mail)
    : Person(id,type,name,phone,mail){}
private:
};

//Singleton
class Table{
public:
    Table(){}
    template <typename T>
    void addRecord(T s_ptr){
        table[s_ptr->getId()] = s_ptr;
    }
    ~Table();
    void clearAll();
    bool deleteRecord(int id);
private:
    std::map<int,std::shared_ptr<Person>> table;
};