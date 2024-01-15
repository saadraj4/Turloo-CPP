#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include "UserManagement.h"
#include "PatientManagement.h"
#include "PrescriptionManagement.h"
#include "MedicationManagement.h"
#include "Reporting.h"
#include "users.h"
#include "FileHandling.h"

using namespace std;

// Function declarations
void displayMainMenu(bool isLoggedIn);
void displayUserManagementMenu();
void displayPatientManagementMenu();
void displayPrescriptionManagementMenu();
void displayMedicationManagementMenu();
void displayReportingMenu();
void clearScreen()
{
    // ANSI escape code to clear screen
    cout << "\033[2J\033[H";
}

int main()
{
    vector<User> user;
    vector<Patient> patients;
    vector<Prescription> prescriptions;
    vector<Medication> medications;
    users userManager;
    list<Patient> patient;
    stack<Prescription> prescription;
    list<Medication> medication;

    bool isLoggedIn = false; // Flag to track user login status
    int mainMenuChoice;
    loadDataFromFile(user, patients, prescriptions, medications);

    do
    {
        if (!isLoggedIn)
        {
            // Display login menu
            displayUserManagementMenu();
            cin >> mainMenuChoice;

            string username, password, role;
            clearScreen();
            switch (mainMenuChoice)
            {
            case 1: // Signup
                // Take user input for signup
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter Role: ";
                cin >> role;
                clearScreen();
                userSignUp(user, username, password, role);
                saveDataToFile(user, patients, prescriptions, medications);

                break;
            case 2: // Log In
                // Take user input for login
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                clearScreen();
                if (userLogin(user, username, password))
                {
                    cout << "Login successful!\n";
                    isLoggedIn = true; // Set login status to true
                }
                else
                {
                    cout << "Login failed.\n";
                }
                break;
            case 0:
                cout << "Exiting the Pharmacy Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                clearScreen();
            }
        }
        else
        {
            // Display main menu after successful login
            displayMainMenu(isLoggedIn);
            
            cin >> mainMenuChoice;
            clearScreen();

            switch (mainMenuChoice)
            {
            case 1: // Patient Management
                int patientSubMenuChoice;
                do
                {
                    displayPatientManagementMenu();
                    cin >> patientSubMenuChoice;
                    clearScreen();

                    switch (patientSubMenuChoice)
                    {
                    case 1:
                        // Add Patient
                        {
                            string firstName, lastName, phoneNumber, notes;
                            int id;
                            cout << "Enter patient ID: ";
                            cin >> id;
                            cout << "Enter patient's first name: ";
                            cin >> firstName;
                            cout << "Enter patient's last name: ";
                            cin >> lastName;
                            cout << "Enter patient's phone number: ";
                            cin >> phoneNumber;
                            cout << "Enter additional notes: ";
                            cin >> notes;
                            clearScreen();

                            addPatient(patients, id, firstName, lastName, phoneNumber, notes);
                            saveDataToFile(user, patients, prescriptions, medications);
                        }
                        break;

                    case 2:
                        // Update Patient
                        {
                            int patientId;
                            cout << "Enter patient ID to update: ";
                            cin >> patientId;

                            // Check if patient exists
                            if (patientExists(patients, patientId))
                            {
                                // Get updated information
                                string updatedFirstName, updatedLastName, updatedContact, updatedDetails;

                                cout << "Enter updated first name: ";
                                cin >> updatedFirstName;
                                cout << "Enter updated last name: ";
                                cin >> updatedLastName;
                                cout << "Enter updated contact: ";
                                cin >> updatedContact;
                                cout << "Enter updated details: ";
                                cin >> updatedDetails;
                                clearScreen();

                                // Update patient information
                                updatePatient(patients, patientId, updatedFirstName, updatedLastName, updatedContact, updatedDetails);
                                saveDataToFile(user, patients, prescriptions, medications);
                            }
                        }

                        break;

                    case 3:
                        // Remove Patient
                        {
                            int patientId;
                            cout << "Enter patient ID to remove: ";
                            cin >> patientId;
                            clearScreen();

                            // Check if patient exists
                            if (patientExists(patients, patientId))
                            {
                                removePatient(patients, patientId);
                                saveDataToFile(user, patients, prescriptions, medications);
                            }
                            else
                            {
                                cout << "Patient not found.\n";
                            }
                        }
                        break;

                    case 4:
                    {
                        int patientId;
                        cout << "Enter patient ID to search: ";
                        cin >> patientId;
                        clearScreen();

                        // Check if patient exists
                        if (patientExists(patients, patientId))
                        {
                            searchPatient(patients, patientId);
                        }
                        else
                        {
                            cout << "Patient not found.\n";
                        }
                    }

                    case 0:
                        break;

                    default:
                        cout << "Invalid choice. Please try again.\n";
                        
                    }
                } while (patientSubMenuChoice != 0);
                break;

            case 2: // Prescription Management
            {
                int patientID;
                cout << "Enter patient ID: ";
                cin >> patientID;
                clearScreen();

                // Check if the patient exists
                if (patientExists(patients, patientID))
                {
                    int prescriptionChoice;
                    displayPrescriptionManagementMenu();
                    cin >> prescriptionChoice;

                    switch (prescriptionChoice)
                    {
                    case 1: // Create Prescription
                    {
                        string date, details;
                        cout << "Enter prescription date (YYYY-MM-DD): ";
                        cin >> date;
                        cout << "Enter prescription details: ";
                        cin.ignore(); // Clear buffer
                        getline(cin, details);
                        clearScreen();

                        createPrescription(prescriptions, patientID, date, details);
                        saveDataToFile(user, patients, prescriptions, medications);
                        break;
                    }
                    case 2: // Update Prescription
                    {
                        int prescriptionID;
                        cout << "Enter prescription ID to update: ";
                        cin >> prescriptionID;
                        clearScreen();

                        // Check if the prescription exists
                        if (prescriptionExists(prescriptions, prescriptionID))
                        {
                            string updatedDetails;
                            cout << "Enter updated prescription details: ";
                            cin.ignore(); // Clear buffer
                            getline(cin, updatedDetails);
                            clearScreen();

                            updatePrescription(prescriptions, prescriptionID, updatedDetails);
                            saveDataToFile(user, patients, prescriptions, medications);
                        }

                        break;
                    }
                    case 3:
                    {
                        int prescriptionID;
                        cout << "Enter prescription ID to search: ";
                        cin >> prescriptionID;
                        clearScreen();

                        // Check if the prescription exists
                        if (prescriptionExists(prescriptions, prescriptionID))
                        {
                            searchPrescription(prescriptions, prescriptionID);
                        }
                        else
                        {
                            cout << "Prescription not found.\n";
                        }
                    }
                    case 0: // Back to Patient Management Menu
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }
                }
                else
                {
                    cout << "Patient not found.\n";
                }
                break;
            }

            case 3: // Medication Management

                int medicationMenuChoice;
                do
                {
                    displayMedicationManagementMenu();
                    cin >> medicationMenuChoice;
                    clearScreen();

                    switch (medicationMenuChoice)
                    {
                    case 1: // Add Medication
                    {
                        int medicationID;
                        string medicationName;
                        int quantity;
                        string isuueDate;
                        string expiryDate;
                        cout << "Enter medication ID: ";
                        cin >> medicationID;
                        cout << "Enter medication name: ";
                        cin >> medicationName;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        cout << "Enter issue date (YYYY-MM-DD): ";
                        cin >> isuueDate;
                        cout << "Enter expiry date (YYYY-MM-DD): ";
                        cin >> expiryDate;
                        clearScreen();

                        addMedication(medications, medicationID, medicationName, quantity, isuueDate, expiryDate);
                        saveDataToFile(user, patients, prescriptions, medications);
                        break;
                    }
                    case 2: // Update Medication Stock
                    {
                        int medicationID, newQuantity;
                        string newName, newIssueDate, newExpiryDate;
                        cout << "Enter medication ID to update stock: ";
                        cin >> medicationID;

                        // Check if medication exists
                        if (medicationExists(medications, medicationID))
                        {
                            cout << "Enter medication name: ";
                            cin >> newName;
                            cout << "Enter quantity: ";
                            cin >> newQuantity;
                            cout << "Enter issue date (YYYY-MM-DD): ";
                            cin >> newIssueDate;
                            cout << "Enter expiry date (YYYY-MM-DD): ";
                            cin >> newExpiryDate;
                            clearScreen();

                            updateMedicationStock(medications, medicationID, newQuantity, newName, newIssueDate, newExpiryDate);
                            saveDataToFile(user, patients, prescriptions, medications);
                        }
                        else
                        {
                            cout << "Medication not found.\n";
                        }
                        break;
                    }
                    case 3: // Remove Medication
                    {
                        int medicationID;
                        cout << "Enter medication ID to remove: ";
                        cin >> medicationID;
                        clearScreen();

                        // Check if medication exists
                        if (medicationExists(medications, medicationID))
                        {
                            removeMedication(medications, medicationID);
                            saveDataToFile(user, patients, prescriptions, medications);
                        }
                        else
                        {
                            cout << "Medication not found.\n";
                        }
                        break;
                    }
                    case 4:
                    {
                        int medicationID;
                        cout << "Enter medication ID to search: ";
                        cin >> medicationID;
                        clearScreen();

                        // Check if medication exists
                        if (medicationExists(medications, medicationID))
                        {
                            searchMedication(medications, medicationID);
                            cout<<"press 1 to go back to main menu: ";
                            int choice;
                            cin>>choice;
                            if (choice==1)
                            {
                                clearScreen();
                            }
                            
                        }
                        else
                        {
                            cout << "Medication not found.\n";
                        }
                    }
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }
                } while (medicationMenuChoice != 0);

                break;

            case 4: // Reporting
                int reportingMenuChoice;
                do
                {
                    displayReportingMenu();
                    cin >> reportingMenuChoice;
                    clearScreen();

                    switch (reportingMenuChoice)
                    {
                    case 1:
                        generateInventoryReport(medications);
                        cout<<"press 1 to go back to main menu: ";
                            int choice;
                            cin>>choice;
                            if (choice==1)
                            {
                                clearScreen();
                            }
                        break;
                    case 2:
                        generatePatientReport(patients);
                        cout<<"press 1 to go back to main menu: ";
                            cin>>choice;
                            if (choice==1)
                            {
                                clearScreen();
                            }
                        break;
                    case 0:
                        break;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                    }
                } while (reportingMenuChoice != 0);
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
    cout << "4. Search Patient\n";
    cout << "0. Back to Main Menu\n";
    cout << "----------------------------------\n";
    cout << "Enter your choice: ";
}

void displayPrescriptionManagementMenu()
{
    cout << "\n----- Prescription Management Menu -----\n";
    cout << "1. Create Prescription\n";
    cout << "2. Update Prescription\n";
    cout << "3. Search Prescription\n";
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
    cout << "4. Search Medication\n";
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