#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>

struct User {
    int userID;
    std::string username;
    std::string password;
    std::string role;
};

void userSignUp(std::vector<User>& users, const std::string& username, const std::string& password, const std::string& role) {
    // Implementation for userSignUp
    // Ensure username uniqueness
    for (const User& user : users) {
        if (user.username == username) {
            std::cout << "Username already exists. Choose a different username.\n";
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
    std::cout << "User registration successful!\n";
}

bool userLogin(const std::vector<User>& users, const std::string& username, const std::string& password) {
    // Implementation for userLogin
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true; // Login successful
        }
    }
    return false; // Login failed
}

#endif // USER_MANAGEMENT_H
