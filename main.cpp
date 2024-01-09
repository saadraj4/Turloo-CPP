#include <iostream>
#include <vector>
#include "UserManagement.h"
#include "PatientManagement.h"
#include "PrescriptionManagement.h"
#include "MedicationManagement.h"
#include "Reporting.h"
#include "FileHandling.h"

using namespace std;

// Function declarations
void displayMainMenu(bool isLoggedIn);
void displayUserManagementMenu();
void displayPatientManagementMenu();
void displayPrescriptionManagementMenu();
void displayMedicationManagementMenu();
void displayReportingMenu();

int main()
{
    vector<User> users;
    vector<Patient> patients;
    vector<Prescription> prescriptions;
    vector<Medication> medications;

    bool isLoggedIn = false; // Flag to track user login status
    int mainMenuChoice;
    loadDataFromFile(users, patients, prescriptions, medications);

    do
    {
        if (!isLoggedIn)
        {
            // Display login menu
            displayUserManagementMenu();
            cin >> mainMenuChoice;

            string username, password, role;

            switch (mainMenuChoice)
            {
            case 2: // Log In
                // Take user input for login
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (userLogin(users, username, password))
                {
                    cout << "Login successful!\n";
                    isLoggedIn = true; // Set login status to true
                }
                else
                {
                    cout << "Login failed.\n";
                }
                break;
            case 1: // Signup
                // Take user input for signup
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter Role: ";
                cin >> role;
                userSignUp(users,username,password,role);
                saveDataToFile(users, patients, prescriptions, medications);
               
                break;
            case 0:
                cout << "Exiting the Pharmacy Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
        else
        {
            // Display main menu after successful login
            displayMainMenu(isLoggedIn);
            cin >> mainMenuChoice;

            switch (mainMenuChoice)
            {
            case 1: // User Management
                // Add the user management logic here
                break;
            case 2: // Patient Management
                // Add the patient management logic here
                break;
            case 3: // Prescription Management
                // Add the prescription management logic here
                break;
            case 4: // Medication Management
                // Add the medication management logic here
                break;
            case 5: // Reporting
                // Add the reporting logic here
                break;
            case 6: // Save Data to Files
                saveDataToFile(users, patients, prescriptions, medications);
                cout << "Data saved successfully!\n";
                break;
            case 0:
                cout << "Exiting the Pharmacy Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (mainMenuChoice != 0);

    return 0;
}

// Helper Functions Definitions

void displayMainMenu(bool isLoggedIn)
{
    cout << "\n----- Pharmacy Management System Menu -----\n";
    if (isLoggedIn)
    {
        cout << "1. Patient Management\n";
        cout << "2. Prescription Management\n";
        cout << "3. Medication Management\n";
        cout << "4. Reporting\n";
        cout << "5. Save Data to Files\n";
    }
    else
    {
        cout << "1. Log In\n";
    }
    cout << "0. Exit\n";
    cout << "-------------------------------------------\n";
    cout << "Enter your choice: ";
}

void displayUserManagementMenu()
{
    cout << "\n----- User Management Menu -----\n";
    cout << "1. Sign Up\n";
    cout << "2. Log In\n";
    cout << "0. Back to Main Menu\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
}

void displayPatientManagementMenu()
{
    cout << "\n----- Patient Management Menu -----\n";
    cout << "1. Add Patient\n";
    cout << "2. Update Patient\n";
    cout << "3. Remove Patient\n";
    cout << "0. Back to Main Menu\n";
    cout << "----------------------------------\n";
    cout << "Enter your choice: ";
}

void displayPrescriptionManagementMenu()
{
    cout << "\n----- Prescription Management Menu -----\n";
    cout << "1. Create Prescription\n";
    cout << "2. Update Prescription\n";
    cout << "0. Back to Main Menu\n";
    cout << "-----------------------------------------\n";
    cout << "Enter your choice: ";
}

void displayMedicationManagementMenu()
{
    cout << "\n----- Medication Management Menu -----\n";
    cout << "1. Add Medication\n";
    cout << "2. Update Medication Stock\n";
    cout << "3. Remove Medication\n";
    cout << "0. Back to Main Menu\n";
    cout << "--------------------------------------\n";
    cout << "Enter your choice: ";
}

void displayReportingMenu()
{
    cout << "\n----- Reporting Menu -----\n";
    cout << "1. Generate Inventory Report\n";
    cout << "2. Generate Patient Report\n";
    cout << "0. Back to Main Menu\n";
    cout << "---------------------------\n";
    cout << "Enter your choice: ";
}