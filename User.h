#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <memory>
#include "Activity.h"
#include "FoodItem.h"
#include "Goal.h"

class User
{
private:
    std::string username;

    // vector for activities (Workout/Cardio)
    std::vector<std::unique_ptr<Activity>> activityLog;

    // Vector for food items
    std::vector<FoodItem> foodLog;

    Goal<double> dailyCalorieGoal;
    Goal<int> weeklyWorkoutGoal;

    void logNewWorkout(std::vector<std::unique_ptr<Activity>> &log);
    void logNewCardio(std::vector<std::unique_ptr<Activity>> &log);

public:
    // Constructor
    User(const std::string &username);

    // methods
    void logActivity();
    void logFood();
    void viewDailySummary() const;

    std::string getUsername() const;
};

#endif // USER_H