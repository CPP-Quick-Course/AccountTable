#include "Person.h"

int Person::s_IDGenerator = 1;

Person::Person(std::string type)
	: m_ID(s_IDGenerator++), m_type(type)
{
}

Person::Person(std::string type, std::string name, std::string phone, std::string mail)
	: m_ID(s_IDGenerator++), m_type(type), m_name(name), m_phone(phone), m_mail(mail)
{
}

int Person::getID()
{
	return m_ID;
}

std::string Person::getType() const {
	return m_type;
}

void Person::setName(std::string name) {
	this->m_name = name;
}

std::string Person::getName() const {
	return m_name;
}

void Person::setPhone(std::string phone) {
	this->m_phone = phone;
}

std::string Person::getPhone() const {
	return m_phone;
}

void Person::setMail(std::string mail) {
	this->m_mail = mail;
}

std::string Person::getMail() const {
	return m_mail;
}