#include "Product.h"

Product::Product() : Product("Unknown") {}
Product::Product(const MyString& name)
{
	_name = name;
}
const MyString& Product::getName() const
{
	return _name;
}
bool operator==(const Product& lhs, const Product& rhs)
{
	return lhs.getName() == rhs.getName();
}
std::istream& operator>>(std::istream& is, Product& pr)
{
	return (is >> pr._name);
}
