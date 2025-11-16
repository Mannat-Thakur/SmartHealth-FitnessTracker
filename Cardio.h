#ifndef CARDIO_H
#define CARDIO_H

#include "Activity.h" // include the base class
#include <string>

class Cardio : public Activity
{
private:
    std::string cardioType;
    double distanceInKm;

public:
    // Constructor
    Cardio(const std::string &date, int duration, const std::string &type, double distance);

    // Override the pure virtual functions
    virtual double calculateCaloriesBurned() const override;
    virtual std::string getSummary() const override;
};

#endif // CARDIO_H