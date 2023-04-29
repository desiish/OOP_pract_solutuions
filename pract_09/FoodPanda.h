#pragma once
#include "Restaurant.h"
#include "Order.h"
class FoodPanda
{
	Restaurant** _restaurants = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;

	void copyFrom(const FoodPanda& other);
	void moveFrom(FoodPanda&& other);
	void free();
	void resize(size_t newCap);
	int getRestaurantIdx(const char* name) const;

public:
	FoodPanda(size_t capacity);
	FoodPanda(const FoodPanda& other);
	FoodPanda(FoodPanda&& other) noexcept;
	FoodPanda& operator=(const FoodPanda& other);
	FoodPanda& operator=(FoodPanda&& other) noexcept; 
	~FoodPanda();
	void addRestaurant(Restaurant& newR);
	void run() const;
};

