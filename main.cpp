#include <iostream>
#include <vector>
#include "UserManagement.h"
#include "PatientManagement.h"
#include "PrescriptionManagement.h"
#include "MedicationManagement.h"
#include "Reporting.h"
#include "FileHandling.h"

using namespace std;

void displayMainMenu()
{
    cout << "\n----- Pharmacy Management System Menu -----\n";
    cout << "1. User Management\n";
    cout << "2. Patient Management\n";
    cout << "3. Prescription Management\n";
    cout << "4. Medication Management\n";
    cout << "5. Reporting\n";
    cout << "6. Save Data to Files\n";
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
    // Add options for patient management submenu
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
    // Add options for prescription management submenu
    cout << "1. Create Prescription\n";
    cout << "2. Update Prescription\n";
    cout << "0. Back to Main Menu\n";
    cout << "-----------------------------------------\n";
    cout << "Enter your choice: ";
}

void displayMedicationManagementMenu()
{
    cout << "\n----- Medication Management Menu -----\n";
    // Add options for medication management submenu
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
    // Add options for reporting submenu
    cout << "1. Generate Inventory Report\n";
    cout << "2. Generate Patient Report\n";
    cout << "0. Back to Main Menu\n";
    cout << "---------------------------\n";
    cout << "Enter your choice: ";
}

// Add similar functions for other submenus

int main()
{
    vector<User> users;
    vector<Patient> patients;
    vector<Prescription> prescriptions;
    vector<Medication> medications;

    int mainMenuChoice;

    do
    {
        displayMainMenu();
        cin >> mainMenuChoice;            
        string username, password, role;

        switch (mainMenuChoice)
        {

        case 1: // User Management
            int userMenuChoice;
            do
            {
                displayUserManagementMenu();
                cin >> userMenuChoice;

                switch (userMenuChoice)
                {
                case 1:
                    // Take user input for signup
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    cout << "Enter role: ";
                    cin >> role;
                    userSignUp(users, username, password, role);
                    break;
                case 2:
                    // Take user input for login
                    cout << "Enter username: ";
                    cin >> username;
                    cout << "Enter password: ";
                    cin >> password;
                    if (userLogin(users, username, password))
                    {
                        cout << "Login successful!\n";
                    }
                    else
                    {
                        cout << "Login failed.\n";
                    }
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (userMenuChoice != 0);
            break;
        case 2: // Patient Management
            int patientMenuChoice;
            do
            {
                displayPatientManagementMenu();
                cin >> patientMenuChoice;

                switch (patientMenuChoice)
                {
                case 1:
                    // Implement add patient logic
                    break;
                case 2:
                    // Implement update patient logic
                    break;
                case 3:
                    // Implement remove patient logic
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (patientMenuChoice != 0);
            break;
        case 3: // Prescription Management
            int prescriptionMenuChoice;
            do
            {
                displayPrescriptionManagementMenu();
                cin >> prescriptionMenuChoice;

                switch (prescriptionMenuChoice)
                {
                case 1:
                    // Implement create prescription logic
                    break;
                case 2:
                    // Implement update prescription logic
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (prescriptionMenuChoice != 0);
            break;
        case 4: // Medication Management
            int medicationMenuChoice;
            do
            {
                displayMedicationManagementMenu();
                cin >> medicationMenuChoice;

                switch (medicationMenuChoice)
                {
                case 1:
                    // Implement add medication logic
                    break;
                case 2:
                    // Implement update medication stock logic
                    break;
                case 3:
                    // Implement remove medication logic
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (medicationMenuChoice != 0);
            break;
        case 5: // Reporting
            int reportingMenuChoice;
            do
            {
                displayReportingMenu();
                cin >> reportingMenuChoice;

                switch (reportingMenuChoice)
                {
                case 1:
                    // Implement generate inventory report logic
                    break;
                case 2:
                    // Implement generate patient report logic
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
                }
            } while (reportingMenuChoice != 0);
            break;
        // Add similar cases for other main menu options
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
    } while (mainMenuChoice != 0);

    return 0;
}
