#include "FoodPanda.h"
#include <iostream>
void FoodPanda::copyFrom(const FoodPanda& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_restaurants = new Restaurant * [_capacity] {nullptr};
	for (int i = 0; i < _size; i++)
		_restaurants[i] = new Restaurant(*other._restaurants[i]);

}
void FoodPanda::moveFrom(FoodPanda&& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_restaurants = other._restaurants;
	other._restaurants = nullptr;
	other._capacity = other._size = 0;
}
void FoodPanda::free()
{
	for (int i = 0; i < _size; i++)
		delete _restaurants[i];
	delete[] _restaurants;
	_restaurants = nullptr;
	_size = _capacity = 0;
}
void FoodPanda::resize(size_t newCap)
{
	_capacity = newCap;
	Restaurant** newRes = new Restaurant * [_capacity] {nullptr};
	for (int i = 0; i < _size; i++)
		newRes[i] = _restaurants[i];
	delete[] _restaurants;
	_restaurants = newRes;
}
int FoodPanda::getRestaurantIdx(const char* name) const
{
	for (int i = 0; i < _size; i++)
	{
		if (strcmp(name, _restaurants[i]->getName()) == 0)
			return i;
	}
	return -1;
}
FoodPanda::FoodPanda(size_t capacity)
{
	_capacity = capacity;
	_restaurants = new Restaurant * [_capacity] {nullptr};
}
FoodPanda::FoodPanda(const FoodPanda& other)
{
	copyFrom(other);
}
FoodPanda::FoodPanda(FoodPanda&& other) noexcept
{
	moveFrom(std::move(other));
}
FoodPanda& FoodPanda::operator=(const FoodPanda& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}
FoodPanda& FoodPanda::operator=(FoodPanda&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}
FoodPanda::~FoodPanda()
{
	free();
}
void FoodPanda::addRestaurant(Restaurant& newR)
{
	if (_size == _capacity)
		resize(_capacity * 2);
	_restaurants[_size++] = &newR;
}
void FoodPanda::run() const
{
	int count;
	char buff[1024];
	while (true)
	{
		std::cin >> buff;
		if (strcmp(buff, "0") == 0)
			break;
		std::cin >> count;
		Order newOrder(buff, count);
		std::cin >> newOrder;
		int idx = getRestaurantIdx(buff);
		size_t time = 0;
		if (idx == -1)
		{
			std::cout << "Invalid order, no such restaurant exists!" << std::endl;
			continue;
		}
		try
		{
			time = _restaurants[idx]->recieveOrder(newOrder);
		}
		catch (const std::exception& exc)
		{
			std::cout << "The restaurant does not have all of the products in stock" << std::endl;
			throw;
		}
		std::cout << "The order from "<< _restaurants[idx]->getName() << " will take " << time << " minutes to get ready!" << std::endl;
	}
}