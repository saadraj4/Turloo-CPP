#ifndef MEDICATION_MANAGEMENT_H
#define MEDICATION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct Medication
{
    int medicationID;
    std::string medicationName;
    int quantity;
    std::string issueDate;
    std::string expiryDate;
};

void addMedication(std::vector<Medication> &medications, int id, const std::string &medicationName, int quantity, const std::string &issueDate, const std::string &expiryDate)
{
    // Implementation for addMedication
    Medication newMedication;
    newMedication.medicationID = id;
    newMedication.medicationName = medicationName;
    newMedication.quantity = quantity;
    newMedication.issueDate = issueDate;
    newMedication.expiryDate = expiryDate;

    medications.push_back(newMedication);
    std::cout << "Medication added successfully!\n";
}

void updateMedicationStock(std::vector<Medication> &medications, int medicationID, int newQuantity, const std::string &newName, const std::string &newIssueDate, const std::string &newExpiryDate )
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
            std::cout << "Medication stock updated successfully!\n";
            return;
        }
    }
    std::cout << "Medication not found.\n";
}

void removeMedication(std::vector<Medication> &medications, int medicationID)
{
    // Implementation for removeMedication
    auto it = std::remove_if(medications.begin(), medications.end(), [medicationID](const Medication &medication)
                             { return medication.medicationID == medicationID; });

    if (it != medications.end())
    {
        medications.erase(it, medications.end());
        std::cout << "Medication removed successfully!\n";
    }
    else
    {
        std::cout << "Medication not found.\n";
    }
}

// Function to check if a medication with a given ID exists
bool medicationExists(const std::vector<Medication> &medications, int medicationID)
{
    auto it = std::find_if(medications.begin(), medications.end(),
                           [medicationID](const Medication &medication)
                           {
                               return medication.medicationID == medicationID;
                           });

    return it != medications.end();
}

#endif // MEDICATION_MANAGEMENT_H
