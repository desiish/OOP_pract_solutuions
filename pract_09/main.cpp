#include <iostream>
#include "FoodPanda.h"
int main()
{
    FoodPanda fp(3);
    Restaurant r1("Happy", 3);
    r1.addProduct(Product("Sushi"));
    r1.addProduct(Product("Pumpkin Soup"));
    r1.addProduct(Product("Pizza"));
    Restaurant r2("Burrata", 2);
    r2.addProduct(Product("Sushi"));
    r2.addProduct(Product("Chicken Soup"));
    Restaurant r3("Sante", 3);
    r3.addProduct(Product("Wine"));
    r3.addProduct(Product("Pizza"));
    r3.addProduct(Product("Soup"));
    fp.addRestaurant(r1);
    fp.addRestaurant(r2);
    fp.addRestaurant(r3);
    fp.run();
    return 0;
}