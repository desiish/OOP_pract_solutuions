#pragma once
#include "MyString.h"
#include "Product.h"
class Order
{
	MyString _restName;
	size_t _productsCount = 0;
	Product* _list = nullptr;

	void copyFrom(const Order& other);
	void moveFrom(Order&& other);
	void free();

public:
	Order(const MyString& name, size_t count);
	Order(const Order& other);
	Order(Order&& other);
	Order& operator=(const Order& other);
	Order& operator=(Order&& other);
	~Order();
	const Product* getList() const;
	size_t getCount() const;
	friend std::istream& operator>>(std::istream& is, Order& order);
};

