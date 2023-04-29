#include "Restaurant.h"
#include <cstring>
#pragma warning(disable:4996)
void Restaurant::copyFrom(const Restaurant& other)
{
	strcpy(_name, other._name);
	_size = other._size;
	_capacity = other._capacity;
	_list = new Product[_capacity];
	for (int i = 0; i < _size; i++)
		_list[i] = other._list[i];
}
void Restaurant::moveFrom(Restaurant&& other)
{
	strcpy(_name, other._name);
	_size = other._size;
	_capacity = other._capacity;
	_list = other._list;
	other._list = nullptr;
}
void Restaurant::free()
{
	delete[] _list;
	_list = nullptr;
	_size = _capacity = 0;
}
void Restaurant::resize(size_t newCap)
{
	_capacity = newCap;
	Product* newList = new Product[newCap];
	for (int i = 0; i < _size; i++)
		newList[i] = _list[i];
	delete[] _list;
	_list = newList;
}
bool Restaurant::hasProduct(const Product& pr) const
{
	for (int i = 0; i < _size; i++)
	{
		if (pr == _list[i])
			return true;
	}
	return false;
}
Restaurant::Restaurant(const char* name, size_t capacity)
{
	strcpy(_name, name);
	_capacity = capacity;
	_size = 0;
	_list = new Product[capacity];
}
Restaurant::Restaurant(const Restaurant& other)
{
	copyFrom(other);
}
Restaurant::Restaurant(Restaurant&& other)
{
	moveFrom(std::move(other));
}
Restaurant& Restaurant::operator=(const Restaurant& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Restaurant& Restaurant::operator=(Restaurant&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
size_t Restaurant::recieveOrder(const Order& order) const
{
	// each product takes approximately 10 mins to prepare
	size_t count = order.getCount();
	for (int i = 0; i < count; i++)
	{
		if (!hasProduct(order.getList()[i]))
			throw std::invalid_argument("No such product exists");
	}
	return 10 * count;
}
void Restaurant::addProduct(Product&& newPr)
{
	if (_size == _capacity)
		resize(2 * _capacity);
	_list[_size++] = std::move(newPr);
}
const char* Restaurant::getName() const
{
	return _name;
}
Restaurant::~Restaurant()
{
	free();
}