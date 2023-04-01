#include "SoftwareEngineer.h"
#include <cstring>
#pragma warning(disable:4996)
void SoftwareEngineer::copyFrom(const SoftwareEngineer& other)
{
	_salary = other._salary;
	_name = new char[strlen(other._name) + 1];
	strcpy(_name, other._name);
	_position = new char[strlen(other._position) + 1];
	strcpy(_position, other._position);
}
void SoftwareEngineer::free()
{
	delete[] _name;
	delete[] _position;
	_name = _position = nullptr;
	_salary = 0;
}
SoftwareEngineer::SoftwareEngineer()
{
	_name = new char[8];
	_position = new char[8];
}
SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other)
{
		copyFrom(other);
}
namespace
{
	bool isValidLetter(char s)
	{
		return s >= 'a' && s <= 'z';
	}
	bool isValidName(const char* name)
	{
		if (*name < 'A' || *name > 'Z')
			return false;
		name++;
		while (*name)
		{
			if (!isValidLetter(*name))
				return false;
			name++;
		}
		return true;
	}
}
SoftwareEngineer::SoftwareEngineer(const char* name, const char* position, size_t salary)
{
	if (name == nullptr || position == nullptr)
		return;
	if (!isValidName(name))
		return;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
	_position = new char[strlen(position) + 1];
	strcpy(_position, position);
	_salary = salary;
}
SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
SoftwareEngineer::~SoftwareEngineer()
{
	free();
}
void SoftwareEngineer::setName(const char* name)
{
	if (name == nullptr || name == _name)
		return;
	delete[] _name;
	_name = new char[strlen(name) + 1];
	strcpy(_name, name);
}
void SoftwareEngineer::setPosition(const char* position)
{
	if (position == nullptr || position == _position)
		return;
	delete[] _position;
	_position = new char[strlen(position) + 1];
	strcpy(_position, position);
}
void SoftwareEngineer::setSalary(size_t salary)
{
	if (salary > 0)
		salary = 0;
	_salary = salary;
}
const char* SoftwareEngineer::getName() const
{
	return _name;
}
const char* SoftwareEngineer::getPosition() const
{
	return _position;
}
size_t SoftwareEngineer::getSalary() const
{
	return _salary;
}