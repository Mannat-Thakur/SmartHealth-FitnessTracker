#ifndef WORKOUT_H
#define WORKOUT_H

#include "Activity.h" //include the base class
#include <string>

// Workout "Derived Class" that inherits from Activity
class Workout : public Activity
{
private:
    std::string workoutType;
    int sets;
    int reps;

public:
    // Constructor
    Workout(const std::string &date, int duration, const std::string &type, int sets, int reps);

    // Override the pure virtual functions
    virtual double calculateCaloriesBurned() const override;
    virtual std::string getSummary() const override;
};

#endif // WORKOUT_H