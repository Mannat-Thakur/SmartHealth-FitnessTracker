#ifndef FOODITEM_H
#define FOODITEM_H

#include <string>

class FoodItem
{
private:
    std::string name;
    double calories;
    double protein;
    double carbs;
    double fats;

public:
    FoodItem(const std::string &name, double cal, double pro, double carb, double fat);

    // get() functions to access the data
    std::string getName() const;
    double getCalories() const;
};

#endif // FOODITEM_H