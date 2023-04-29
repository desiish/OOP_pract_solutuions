#include "Order.h"
void Order::copyFrom(const Order& other)
{
	_restName = other._restName;
	_productsCount = other._productsCount;
	_list = new Product[_productsCount];
	for (int i = 0; i < _productsCount; i++)
		_list[i] = other._list[i];
}
void Order::moveFrom(Order&& other)
{
	_restName = other._restName;
	_productsCount = other._productsCount;
	_list = other._list;
	other._list = nullptr;
	other._productsCount = 0;
}
void Order::free()
{
	delete[] _list;
	_list = nullptr;
	_productsCount = 0;
}
Order::Order(const MyString& name, size_t count)
{
	_restName = name;
	_productsCount = count;
	_list = new Product[count];
}
Order::Order(const Order& other)
{
	copyFrom(other);
}
Order::Order(Order&& other)
{
	moveFrom(std::move(other));
}
Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
Order& Order::operator=(Order&& other)
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
Order::~Order()
{
	free();
}
const Product* Order::getList() const
{
	return _list;
}
size_t Order::getCount() const
{
	return _productsCount;
}
std::istream& operator>>(std::istream& is, Order& order)
{
	for (int i = 0; i < order._productsCount; i++)
		is >> order._list[i];
	return is;
}
