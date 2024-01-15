#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct User {
    int userID;
    string username;
    string password;
    string role;
};

// Function to sign up a new user
void userSignUp(vector<User>& users, const string& username, const string& password, const string& role) {
    // Ensure username uniqueness
    for (const User& user : users) {
        if (user.username == username) {
            cout << "Username already exists. Choose a different username.\n";
            return;
        }
    }

    // Add a new user
    User newUser;
    newUser.userID = users.size() + 1;
    newUser.username = username;
    newUser.password = password;
    newUser.role = role;

    users.push_back(newUser);
    cout << "User registration successful!\n";
}

// Function to check user login credentials
bool userLogin(const vector<User>& users, const string& username, const string& password) {
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}

#endif // USER_MANAGEMENT_H
