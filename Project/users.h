#ifndef USERS_H
#define USERS_H

#include <stack>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

struct Users
{
    int userID;
    string username;
    string password;
    string role;
};

class users
{

public:
    stack<User> userStack;
    stack<string> roleStack;
    queue<User> signUpQueue;
    void userSignUp(const string &username, const string &password, const string &role)
    {
        // Implementation for userSignUp
        // Ensure username uniqueness
        while (!userStack.empty())
        {
            User existingUser = userStack.top();
            if (existingUser.username == username)
            {
                cout << "Username already exists. Choose a different username.\n";
                return;
            }
            userStack.pop();
        }

        // Add a new user to the stack
        User newUser;
        newUser.userID = userStack.size() + 1;
        newUser.username = username;
        newUser.password = password;
        newUser.role = role;

        userStack.push(newUser);
        roleStack.push(role);
        cout << "User registration successful!\n";
    }

    bool userLogin(const string &username, const string &password)
    {
        // Implementation for userLogin
        stack<User> tempStack = userStack;

        while (!tempStack.empty())
        {
            User user = tempStack.top();
            tempStack.pop();
            if (user.username == username && user.password == password)
            {
                return true; // Login successful
            }
        }
        return false; // Login failed
    }
    const stack<User>& getUsers() const
    {
        return userStack;
    }

    void enqueueSignUpRequest(const string &username, const string &password, const string &role)
    {
        // Enqueue sign-up request
        User newUser;
        newUser.username = username;
        newUser.password = password;
        newUser.role = role;

        signUpQueue.push(newUser);
        cout << "Sign-up request enqueued.\n";
    }

    void processSignUpRequests()
    {
        // Process sign-up requests from the queue
        while (!signUpQueue.empty())
        {
            User newUser = signUpQueue.front();
            signUpQueue.pop();
            userSignUp(newUser.username, newUser.password, newUser.role);
        }
    }
};

#endif // USERS_H
