#include "FoodItem.h"
using namespace std;

// Constructor
FoodItem::FoodItem(const string &name, double cal, double pro, double carb, double fat)
{
    this->name = name;
    this->calories = cal;
    this->protein = pro;
    this->carbs = carb;
    this->fats = fat;
}

// get() function
string FoodItem::getName() const
{
    return name;
}

double FoodItem::getCalories() const
{
    return calories;
}
