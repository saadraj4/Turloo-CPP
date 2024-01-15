#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Structure to represent Patient information
struct Patient
{
    int patientID;
    string Fname;
    string Lname;
    string contactDetails;
    string medicalHistory;
};

// Function to add a new patient to the vector
void addPatient(vector<Patient> &patients, int id, const string &Fname, const string &Lname, const string &contactDetails, const string &medicalHistory)
{
    // Create a new Patient instance
    Patient newPatient;
    newPatient.patientID = id;
    newPatient.Fname = Fname;
    newPatient.Lname = Lname;
    newPatient.contactDetails = contactDetails;
    newPatient.medicalHistory = medicalHistory;

    // Add the new Patient to the vector
    patients.push_back(newPatient);
    cout << "Patient added successfully!\n";
}

// Function to update patient details
void updatePatient(vector<Patient> &patients, int patientID, const string &updatedFirstName, const string &updatedLastName, const string &updatedContact, const string &updatedDetails)
{
    // Iterate through the patients vector
    for (Patient &patient : patients)
    {
        // Check if the patient with the specified ID is found
        if (patient.patientID == patientID)
        {
            // Update patient details
            patient.Fname = updatedFirstName;
            patient.Lname = updatedLastName;
            patient.contactDetails = updatedContact;
            patient.medicalHistory = updatedDetails;

            cout << "Patient details updated successfully!\n";
            return;
        }
    }
}

// Function to remove a patient from the vector
void removePatient(vector<Patient> &patients, int patientID)
{
    // Use remove_if and erase to remove the patient with the specified ID
    auto it = remove_if(patients.begin(), patients.end(), [patientID](const Patient &patient)
                        { return patient.patientID == patientID; });

    // Check if the patient was found and removed
    if (it != patients.end())
    {
        patients.erase(it, patients.end());
        cout << "Patient removed successfully!\n";
    }
    else
    {
        cout << "Patient not found.\n";
    }
}

// Function to search for a patient by ID
void searchPatient(vector<Patient> &patients, int patientID)
{
    // Iterate through the patients vector
    for (Patient &patient : patients)
    {
        // Check if the patient with the specified ID is found
        if (patient.patientID == patientID)
        {
            // Print patient details
            cout << "Patient ID: " << patient.patientID << endl;
            cout << "First Name: " << patient.Fname << endl;
            cout << "Last Name: " << patient.Lname << endl;
            cout << "Contact Details: " << patient.contactDetails << endl;
            cout << "Medical History: " << patient.medicalHistory << endl;
            return;
        }
    }

    // If the loop completes without returning, the patient was not found
    cout << "Patient not found.\n";
}

// Function to check if a patient with a given ID exists
bool patientExists(const vector<Patient> &patients, int patientID)
{
    // Use any_of to check if a patient with the specified ID exists
    return any_of(patients.begin(), patients.end(), [patientID](const Patient &patient)
                  { return patient.patientID == patientID; });
}

#endif // PATIENT_MANAGEMENT_H
