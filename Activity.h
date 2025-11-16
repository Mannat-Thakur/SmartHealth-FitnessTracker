#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>

//  Abstract Base Class.
class Activity
{
protected:
    std::string date;
    int durationInMinutes;

public:
    // Constructor
    Activity(const std::string &date, int duration)
    {
        this->date = date;
        this->durationInMinutes = duration;
    }

    // Virtual destructor
    virtual ~Activity()
    {
    }

    // Pure Virtual Functions
    virtual double calculateCaloriesBurned() const = 0;
    virtual std::string getSummary() const = 0;
};

#endif // ACTIVITY_H