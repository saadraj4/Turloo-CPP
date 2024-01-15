#ifndef PRESCRIPTION_MANAGEMENT_H
#define PRESCRIPTION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Structure to represent Prescription information
struct Prescription
{
    int prescriptionID;
    int patientID;
    string dateIssued;
    string medicationDetails;
};

// Function to create a new prescription
void createPrescription(vector<Prescription> &prescriptions, int patientID, const string &dateIssued, const string &medicationDetails)
{
    // Create a new Prescription instance
    Prescription newPrescription;
    newPrescription.prescriptionID = patientID;  // It seems like there is a typo here. It might be newPrescription.prescriptionID = some_unique_id;
    newPrescription.patientID = patientID;
    newPrescription.dateIssued = dateIssued;
    newPrescription.medicationDetails = medicationDetails;

    // Add the new Prescription to the vector
    prescriptions.push_back(newPrescription);
    cout << "Prescription created successfully!\n";
}

// Function to update prescription details
void updatePrescription(vector<Prescription> &prescriptions, int prescriptionID, const string &updatedDetails)
{
    // Iterate through the prescriptions vector
    for (Prescription &prescription : prescriptions)
    {
        // Check if the prescription with the specified ID is found
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

// Function to search for a prescription by patient ID
void searchPrescription(vector<Prescription> &prescriptions, int patientID)
{
    // Iterate through the prescriptions vector
    for (Prescription &prescription : prescriptions)
    {
        // Check if the prescription with the specified patient ID is found
        if (prescription.patientID == patientID)
        {
            // Print prescription details
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
    // Use any_of to check if a prescription with the specified ID exists
    return any_of(prescriptions.begin(), prescriptions.end(), [prescriptionID](const Prescription &prescription)
                  { return prescription.prescriptionID == prescriptionID; });
}

#endif // PRESCRIPTION_MANAGEMENT_H
