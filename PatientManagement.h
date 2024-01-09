#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Patient
{
    int patientID;
    string Fname;
    string Lname;
    string contactDetails;
    string medicalHistory;
};

void addPatient(vector<Patient> &patients, int id, const string &Fname, const string &Lname, const string &contactDetails, const string &medicalHistory)
{
    // Implementation for addPatient
    Patient newPatient;
    newPatient.patientID = id;
    newPatient.Fname = Fname;
    newPatient.Lname = Lname;
    newPatient.contactDetails = contactDetails;
    newPatient.medicalHistory = medicalHistory;

    patients.push_back(newPatient);
    cout << "Patient added successfully!\n";
}

void updatePatient(vector<Patient> &patients, int patientID, const string &updatedFirstName, const string &updatedLastName, const string &updatedContact, const string &updatedDetails)
{
    // Implementation for updatePatient
    for (Patient &patient : patients)
    {
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

void removePatient(vector<Patient> &patients, int patientID)
{
    // Implementation for removePatient
    auto it = remove_if(patients.begin(), patients.end(), [patientID](const Patient &patient)
                        { return patient.patientID == patientID; });

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

void searchPatient(vector<Patient> &patients, int patientID)
{
    // Implementation for searchPatient
    for (Patient &patient : patients)
    {
        if (patient.patientID == patientID)
        {
            cout << "Patient ID: " << patient.patientID << endl;
            cout << "First Name: " << patient.Fname << endl;
            cout << "Last Name: " << patient.Lname << endl;
            cout << "Contact Details: " << patient.contactDetails << endl;
            cout << "Medical History: " << patient.medicalHistory << endl;
        }
        
    }
}

bool patientExists(const vector<Patient> &patients, int patientID)
{
    // Check if a patient with the given ID exists in the vector
    return any_of(patients.begin(), patients.end(), [patientID](const Patient &patient)
                  { return patient.patientID == patientID; });
}

#endif // PATIENT_MANAGEMENT_H
