#include "Workout.h"
#include <sstream> // to build a summary string
using namespace std;

// Constructor
Workout::Workout(const string& date, int duration, const string& type, int sets, int reps)
    : Activity(date, duration)
{
    this->workoutType = type;
    this->sets = sets;
    this->reps = reps;
}

// Overridden Functions 
double Workout::calculateCaloriesBurned() const {
    return (durationInMinutes * 5.0) + (sets * reps * 0.5);
}

string Workout::getSummary() const {
    ostringstream oss;
    oss << "WORKOUT (" << date << "): " << workoutType << "\n"
        << "  - Duration: " << durationInMinutes << " mins\n"
        << "  - Stats: " << sets << " sets x " << reps << " reps\n"
        << "  - Est. Calories: " << calculateCaloriesBurned() << " kcal";
    return oss.str();
}