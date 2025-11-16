#include "Cardio.h"
#include <sstream> // to build a summary string
using namespace std;

// Constructor (Hybrid Style)
Cardio::Cardio(const string &date, int duration, const string &type, double distance)
    : Activity(date, duration)
{
    this->cardioType = type;
    this->distanceInKm = distance;
}

// Overridden Functions
double Cardio::calculateCaloriesBurned() const
{
    return (durationInMinutes * 8.0) + (distanceInKm * 10.0);
}

string Cardio::getSummary() const
{
    ostringstream oss;
    oss << "CARDIO (" << date << "): " << cardioType << "\n"
        << "  - Duration: " << durationInMinutes << " mins\n"
        << "  - Distance: " << distanceInKm << " km\n"
        << "  - Est. Calories: " << calculateCaloriesBurned() << " kcal";
    return oss.str();
}