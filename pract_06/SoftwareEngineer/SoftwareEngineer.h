#pragma once
class SoftwareEngineer
{
	char* _name;
	char* _position;
	size_t _salary = 0;

	void copyFrom(const SoftwareEngineer& other);
	void free();
public:
	SoftwareEngineer();
	SoftwareEngineer(const SoftwareEngineer& other);
	SoftwareEngineer(const char* name, const char* position, size_t salary);
	SoftwareEngineer& operator=(const SoftwareEngineer& other);
	~SoftwareEngineer();
	void setName(const char* name);
	void setPosition(const char* position);
	void setSalary(size_t salary);
	const char* getName() const;
	const char* getPosition() const;
	size_t getSalary() const;
};

