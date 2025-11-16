#ifndef GOAL_H
#define GOAL_H

#include <iostream>
#include <string>

// template declaration
template <typename T>
class Goal
{
private:
    std::string name;
    T targetValue;
    T currentValue;

public:
    // Constructor
    Goal(const std::string &name, T target)
    {
        this->name = name;
        this->targetValue = target;
        this->currentValue = 0; // Initialize to 0
    }

    // Method to add progress
    void addProgress(T amount)
    {
        currentValue = currentValue + amount;
    }

    // Method to get a summary
    void displaySummary() const
    {
        std::cout << "Goal: " << name << "\n"
                  << "  Progress: " << currentValue << " / " << targetValue << "\n";
    }

    // Method to check if the goal is met
    bool isMet() const
    {
        return (currentValue >= targetValue);
    }
};

#endif // GOAL_H