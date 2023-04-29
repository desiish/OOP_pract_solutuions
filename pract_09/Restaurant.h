#pragma once
#include "Product.h"
#include "Order.h"
class Restaurant
{
	char _name[25] = "";
	Product* _list = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();
	void resize(size_t newCap);
	bool hasProduct(const Product& pr) const;
public:
	Restaurant(const char* name, size_t capacity);
	Restaurant(const Restaurant& other);
	Restaurant(Restaurant&& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant& operator=(Restaurant&& other);
	size_t recieveOrder(const Order& order) const;
	void addProduct(Product&& newPr);
	const char* getName() const;
	~Restaurant();
};

