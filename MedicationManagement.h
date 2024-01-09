#ifndef MEDICATION_MANAGEMENT_H
#define MEDICATION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Medication
{
    int medicationID;
    string medicationName;
    int quantity;
    string issueDate;
    string expiryDate;
};

void addMedication(vector<Medication> &medications, int id, const string &medicationName, int quantity, const string &issueDate, const string &expiryDate)
{
    // Implementation for addMedication
    Medication newMedication;
    newMedication.medicationID = id;
    newMedication.medicationName = medicationName;
    newMedication.quantity = quantity;
    newMedication.issueDate = issueDate;
    newMedication.expiryDate = expiryDate;

    medications.push_back(newMedication);
    cout << "Medication added successfully!\n";
}

void updateMedicationStock(vector<Medication> &medications, int medicationID, int newQuantity, const string &newName, const string &newIssueDate, const string &newExpiryDate)
{
    // Implementation for updateMedicationStock
    for (Medication &medication : medications)
    {
        if (medication.medicationID == medicationID)
        {
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

void removeMedication(vector<Medication> &medications, int medicationID)
{
    // Implementation for removeMedication
    auto it = remove_if(medications.begin(), medications.end(), [medicationID](const Medication &medication)
                             { return medication.medicationID == medicationID; });

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
// function to search for medication   
void searchMedication(vector<Medication> &medications, int medicationID){
    // Implementation for searchMedication
    for (Medication &medication : medications)
    {
        if (medication.medicationID == medicationID)
        {
            cout << "Medication ID: " << medication.medicationID << endl;
            cout << "Name: " << medication.medicationName << endl;
            cout << "Quantity: " << medication.quantity << endl;
            cout << "issue Date: " << medication.issueDate << endl;
            cout << "Expiry Date: " << medication.expiryDate << endl;
        }
        
    }
}
// Function to check if a medication with a given ID exists
bool medicationExists(const vector<Medication> &medications, int medicationID)
{
    auto it = find_if(medications.begin(), medications.end(),
                           [medicationID](const Medication &medication)
                           {
                               return medication.medicationID == medicationID;
                           });

    return it != medications.end();
}

#endif // MEDICATION_MANAGEMENT_H
