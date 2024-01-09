#ifndef PRESCRIPTION_MANAGEMENT_H
#define PRESCRIPTION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Prescription
{
    int prescriptionID;
    int patientID;
    string dateIssued;
    string medicationDetails;
};

void createPrescription(vector<Prescription> &prescriptions, int patientID, const string &dateIssued, const string &medicationDetails)
{
    // Implementation for createPrescription
    Prescription newPrescription;
    newPrescription.prescriptionID = patientID;
    newPrescription.patientID = patientID;
    newPrescription.dateIssued = dateIssued;
    newPrescription.medicationDetails = medicationDetails;

    prescriptions.push_back(newPrescription);
    cout << "Prescription created successfully!\n";
}

// Function to update prescription details
void updatePrescription(vector<Prescription> &prescriptions, int prescriptionID, const string &updatedDetails)
{
    for (Prescription &prescription : prescriptions)
    {
        if (prescription.prescriptionID == prescriptionID)
        {
            // Parse and update prescription details
            // For simplicity, assuming updatedDetails contains all details to be updated
            // In a real-world scenario, you may want to parse and handle this string more robustly

            // Update prescription details based on the provided information
            prescription.medicationDetails = updatedDetails; // Replace with actual fields to be updated

            cout << "Prescription details updated successfully!\n";
            return;
        }
    }
    cout << "Prescription not found.\n";
}

void searchPrescription(vector<Prescription> &prescriptions, int patientID)
{
    for (Prescription &prescription : prescriptions)
    {
        if (prescription.patientID == patientID)
        {
            cout << "Prescription ID: " << prescription.prescriptionID << endl;
            cout << "Patient ID: " << prescription.patientID << endl;
            cout << "Date Issued: " << prescription.dateIssued << endl;
            cout << "Medication Details: " << prescription.medicationDetails << endl;
        }
    }
}

// Function to check if a prescription with a given ID exists
bool prescriptionExists(const vector<Prescription> &prescriptions, int prescriptionID)
{
    for (const Prescription &prescription : prescriptions)
    {
        if (prescription.prescriptionID == prescriptionID)
        {
            return true;
        }
    }
    return false;
}

#endif // PRESCRIPTION_MANAGEMENT_H
