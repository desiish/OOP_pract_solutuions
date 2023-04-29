#pragma once
#include "MyString.h"
class Product
{
	MyString _name;

public:
	Product();
	Product(const MyString& name);
	const MyString& getName() const;
	friend std::istream& operator>>(std::istream& is, Product& pr);
};

bool operator==(const Product& lhs, const Product& rhs);

