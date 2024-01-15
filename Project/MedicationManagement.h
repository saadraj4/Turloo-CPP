#ifndef MEDICATION_MANAGEMENT_H
#define MEDICATION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
using namespace std;

// Structure to represent Medication information
struct Medication
{
    int medicationID;
    string medicationName;
    int quantity;
    string issueDate;
    string expiryDate;
};

// Function to add a new medication to the vector
void addMedication(vector<Medication> &medications, int id, const string &medicationName, int quantity, const string &issueDate, const string &expiryDate)
{
    // Create a new Medication instance
    Medication newMedication;
    newMedication.medicationID = id;
    newMedication.medicationName = medicationName;
    newMedication.quantity = quantity;
    newMedication.issueDate = issueDate;
    newMedication.expiryDate = expiryDate;

    // Add the new Medication to the vector
    medications.push_back(newMedication);
    cout << "Medication added successfully!\n";
}

// Function to update medication stock information
void updateMedicationStock(vector<Medication> &medications, int medicationID, int newQuantity, const string &newName, const string &newIssueDate, const string &newExpiryDate)
{
    // Iterate through the medications vector
    for (Medication &medication : medications)
    {
        // Check if the medication with the specified ID is found
        if (medication.medicationID == medicationID)
        {
            // Update medication details
            medication.quantity = newQuantity;
            medication.medicationName = newName;
            medication.issueDate = newIssueDate;
            medication.expiryDate = newExpiryDate;
            cout << "Medication stock updated successfully!\n";
            return;
        }
    }
    cout << "Medication not found.\n";
}

// Function to remove a medication from the vector
void removeMedication(vector<Medication> &medications, int medicationID)
{
    // Use remove_if and erase to remove the medication with the specified ID
    auto it = remove_if(medications.begin(), medications.end(), [medicationID](const Medication &medication)
                             { return medication.medicationID == medicationID; });

    // Check if the medication was found and removed
    if (it != medications.end())
    {
        medications.erase(it, medications.end());
        cout << "Medication removed successfully!\n";
    }
    else
    {
        cout << "Medication not found.\n";
    }
}

// Function to search for a medication by ID
void searchMedication(vector<Medication> &medications, int medicationID)
{
    // Iterate through the medications vector
    for (Medication &medication : medications)
    {
        // Check if the medication with the specified ID is found
        if (medication.medicationID == medicationID)
        {
            // Print medication details
            cout << "Medication ID: " << medication.medicationID << endl;
            cout << "Name: " << medication.medicationName << endl;
            cout << "Quantity: " << medication.quantity << endl;
            cout << "Issue Date: " << medication.issueDate << endl;
            cout << "Expiry Date: " << medication.expiryDate << endl;
            return;
        }
    }

    // If the loop completes without returning, the medication was not found
    cout << "Medication not found.\n";
}

// Function to check if a medication with a given ID exists
bool medicationExists(const vector<Medication> &medications, int medicationID)
{
    // Use find_if to check if a medication with the specified ID exists
    auto it = find_if(medications.begin(), medications.end(),
                      [medicationID](const Medication &medication)
                      {
                          return medication.medicationID == medicationID;
                      });

    // Return true if the medication was found, false otherwise
    return it != medications.end();
}

#endif // MEDICATION_MANAGEMENT_H
