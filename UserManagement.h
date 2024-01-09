#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct User {
    int userID;
    string username;
    string password;
    string role;
};

void userSignUp(std::vector<User>& users, const string& username, const string& password, const string& role) {
    // Implementation for userSignUp
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

bool userLogin(const std::vector<User>& users, const string& username, const string& password) {
    // Implementation for userLogin
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}

#endif // USER_MANAGEMENT_H
