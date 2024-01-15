#ifndef MEDICATION_MANAGEMENT_H
#define MEDICATION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Medication
{
    string medicationID;
    string medicationName;
    int quantity;
    string issueDate;
    string expiryDate;
};

void addMedication(vector<Medication> &medications, const string id, const string &medicationName, int quantity, const string &issueDate, const string &expiryDate)
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

void updateMedicationStock(vector<Medication> &medications, const string medicationID, int newQuantity, const string &newName, const string &newIssueDate, const string &newExpiryDate)
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

void removeMedication(vector<Medication> &medications, const string medicationID)
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

void selectionSort(vector<Medication> &medications)
{
    int n = medications.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (medications[j].medicationID < medications[minIndex].medicationID)
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(medications[i], medications[minIndex]);
        }
    }
}

void searchMedication(vector<Medication> &medications, const string medicationID)
{
    // Sort the medications using selection sort
    selectionSort(medications);

    // Binary search implementation
    int low = 0;
    int high = medications.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (medications[mid].medicationID == medicationID)
        {
            cout << "Medication ID: " << medications[mid].medicationID << endl;
            cout << "Name: " << medications[mid].medicationName << endl;
            cout << "Quantity: " << medications[mid].quantity << endl;
            cout << "Issue Date: " << medications[mid].issueDate << endl;
            cout << "Expiry Date: " << medications[mid].expiryDate << endl;
            return;
        }
        else if (medications[mid].medicationID < medicationID)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "Medication not found.\n";
}
// Function to check if a medication with a given ID exists
bool medicationExists(const vector<Medication> &medications, const string medicationID)
{
    auto it = find_if(medications.begin(), medications.end(),
                      [medicationID](const Medication &medication)
                      {
                          return medication.medicationID == medicationID;
                      });

    return it != medications.end();
}

#endif // MEDICATION_MANAGEMENT_H
