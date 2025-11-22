#include "FitnessTracker.h"
#include "User.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void showUserMenu();
void logout();

// Constructor
FitnessTracker::FitnessTracker()
{
    currentLoggedInUser = nullptr;
}

void FitnessTracker::run()
{
    cout << "Welcome to the SmartHealth Fitness Tracker!" << endl;

    int choice = -1;
    bool running = true;

    while (running)
    {

        if (currentLoggedInUser == nullptr)
        {
            // Logged-Out (Main) Menu
            showMainMenu();

            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (choice)
            {
            case 1:
                registerUser();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Exiting. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            }
        }
        else
        {
            // Logged-In (User) Menu
            showUserMenu();

            while (!(cin >> choice))
            {
                cout << "Invalid input. Please enter a number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (choice)
            {
            case 1:
                currentLoggedInUser->logActivity();
                break;
            case 2:
                currentLoggedInUser->logFood();
                break;
            case 3:
                currentLoggedInUser->viewDailySummary();
                break;
            case 4:
                logout();
                break;

            default:
                cout << "Invalid choice. Try again.\n";
            }
        }
    }
}

// Main menu function
void FitnessTracker::showMainMenu()
{
    cout << "\n--- Main Menu ---\n";
    cout << "1. Register New User\n";
    cout << "2. Login\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
}

// User Menu
void FitnessTracker::showUserMenu()
{
    cout << "\n--- [" << currentLoggedInUser->getUsername() << "'s Dashboard] ---\n";
    cout << "1. Log Activity (Workout/Cardio)\n";
    cout << "2. Log Food\n";
    cout << "3. View Daily Summary\n";
    cout << "4. Logout\n";
    cout << "Choice: ";
}

// Register User Function
void FitnessTracker::registerUser()
{
    cout << "--- Register New User ---\n";
    string newName;
    cout << "Enter username: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newName);

    users.push_back(User(newName));
    cout << "User '" << newName << "' registered successfully!\n";
}

// User login function
void FitnessTracker::login()
{
    cout << "--- User Login ---\n";
    string name;
    cout << "Enter username: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < users.size(); ++i)
    {
        if (users[i].getUsername() == name)
        {
            currentLoggedInUser = &users[i];
            found = true;
            cout << "Login successful. Welcome back, " << name << "!\n";
            break;
        }
    }

    if (!found)
    {
        cout << "Login failed. User '" << name << "' not found.\n";
    }
}

// Logout function
void FitnessTracker::logout()
{
    cout << "Logging out " << currentLoggedInUser->getUsername() << "...\n";
    currentLoggedInUser = nullptr;
}