#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <vector>
#include <string>
#include "User.h" 

class FitnessTracker {
private:
    std::vector<User> users;
    User* currentLoggedInUser; // A pointer to the user who is logged in

    void showMainMenu();
    void showUserMenu();
    void registerUser();
    void login();
    void logout();

public:
    FitnessTracker(); // Constructor
    
    // function that starts the program
    void run();
};

#endif // FITNESSTRACKER_H