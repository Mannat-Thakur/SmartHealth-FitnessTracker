#include "User.h"
#include "Workout.h"
#include "Cardio.h"
#include <iostream>
#include <memory>
#include <limits>
#include <string>

using namespace std;

// Constructor
User::User(const string &name)
    : dailyCalorieGoal("Max Calories", 2500.0),
      weeklyWorkoutGoal("Weekly Workouts", 5)
{
    this->username = name;
}

string User::getUsername() const
{
    return this->username;
}

// --- Main Activity Menu ---
void User::logActivity()
{
    cout << "\n--- Log Activity ---\n";
    cout << "1. Log Workout (e.g., Weights)\n";
    cout << "2. Log Cardio (e.g., Running)\n";
    cout << "0. Back to User Menu\n";
    cout << "Choice: ";

    int choice;
    while (!(cin >> choice))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    switch (choice)
    {
    case 1:
        logNewWorkout(activityLog);
        break;
    case 2:
        logNewCardio(activityLog);
        break;
    case 0:
        cout << "Returning to user menu...\n";
        break;
    default:
        cout << "Invalid choice. Please try again.\n";
        break;
    }
}

// Log Workout
void User::logNewWorkout(vector<unique_ptr<Activity>> &log)
{
    string date, type;
    int duration, sets, reps;

    cout << "Enter date (YYYY-MM-DD): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, date);

    cout << "Enter duration (in minutes): ";
    while (!(cin >> duration) || duration <= 0)
    {
        cout << "Invalid. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter workout type (e.g., Weightlifting): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, type);

    cout << "Enter sets: ";
    while (!(cin >> sets) || sets < 0)
    {
        cout << "Invalid. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter reps per set: ";
    while (!(cin >> reps) || reps < 0)
    {
        cout << "Invalid. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Create object and add to log
    log.push_back(make_unique<Workout>(date, duration, type, sets, reps));

    // UPDATE GOAL
    weeklyWorkoutGoal.addProgress(1);

    cout << "\nSuccessfully logged Workout!\n";
}

// Log Cardio
void User::logNewCardio(vector<unique_ptr<Activity>> &log)
{
    string date, type;
    int duration;
    double distance;

    cout << "Enter date (YYYY-MM-DD): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, date);

    cout << "Enter duration (in minutes): ";
    while (!(cin >> duration) || duration <= 0)
    {
        cout << "Invalid. Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter cardio type (e.g., Running): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, type);

    cout << "Enter distance (in km): ";
    while (!(cin >> distance) || distance < 0)
    {
        cout << "Invalid. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Create object and add to log
    log.push_back(make_unique<Cardio>(date, duration, type, distance));

    // UPDATE GOAL
    weeklyWorkoutGoal.addProgress(1);

    cout << "\nSuccessfully logged Cardio!\n";
}

// Log Food
void User::logFood()
{
    string name;
    double calories, protein, carbs, fats;

    cout << "\n--- Log Food Item ---\n";

    cout << "Enter food name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter calories: ";
    while (!(cin >> calories) || calories < 0)
    {
        cout << "Invalid. Enter a non-negative number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter protein (g): ";
    while (!(cin >> protein) || protein < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter carbs (g): ";
    while (!(cin >> carbs) || carbs < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter fats (g): ";
    while (!(cin >> fats) || fats < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Add to vector
    foodLog.push_back(FoodItem(name, calories, protein, carbs, fats));

    // UPDATE GOAL
    dailyCalorieGoal.addProgress(calories);

    cout << "\nSuccessfully logged " << name << "!\n";
}

// View Summary
void User::viewDailySummary() const
{
    cout << "\n--- Daily Summary for " << this->username << " ---";

    // 1. Activities
    cout << "\n\n--- Logged Activities ---" << endl;
    double totalCaloriesBurned = 0;

    if (activityLog.empty())
    {
        cout << "No activities logged." << endl;
    }
    else
    {
        for (const auto &activityPtr : activityLog)
        {
            cout << activityPtr->getSummary() << endl;
            totalCaloriesBurned += activityPtr->calculateCaloriesBurned();
        }
    }

    // 2. Food
    cout << "\n\n--- Logged Food ---" << endl;
    double totalCaloriesConsumed = 0;

    if (foodLog.empty())
    {
        cout << "No food logged." << endl;
    }
    else
    {
        for (const FoodItem &item : foodLog)
        {
            cout << "- " << item.getName()
                 << " (" << item.getCalories() << " kcal)" << endl;
            totalCaloriesConsumed += item.getCalories();
        }
    }

    // 3. Totals
    cout << "\n\n--- Grand Totals ---" << endl;
    cout << "Total Calories Burned: " << totalCaloriesBurned << " kcal" << endl;
    cout << "Total Calories Consumed: " << totalCaloriesConsumed << " kcal" << endl;
    cout << "Net Calorie Balance: " << (totalCaloriesConsumed - totalCaloriesBurned) << " kcal" << endl;

    // 4. GOALS
    cout << "\n--- Goals Status ---" << endl;

    // Weekly Workouts
    weeklyWorkoutGoal.displaySummary();
    if (weeklyWorkoutGoal.isMet())
    {
        cout << "   >> CONGRATS! Workout goal met!" << endl;
    }

    // Daily Calories
    dailyCalorieGoal.displaySummary();

    cout << "\n--- End of Summary ---\n";
}