#pragma once
#include <iostream>

class Person
{
private:
	static int s_IDGenerator;

protected:
	int m_ID;
	std::string m_type;
	std::string m_name;
	std::string m_phone;
	std::string m_mail;

	Person() = delete;
	Person(std::string type);
	Person(std::string type, std::string name, std::string phone, std::string mail);

public:
	int getID();
	virtual std::string getType() const;
	virtual void setName(std::string name);
	virtual std::string getName() const;
	virtual void setPhone(std::string phone);
	virtual std::string getPhone() const;
	virtual void setMail(std::string mail);
	virtual std::string getMail() const;
};