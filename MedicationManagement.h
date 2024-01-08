#ifndef MEDICATION_MANAGEMENT_H
#define MEDICATION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>

struct Medication {
    int medicationID;
    std::string medicationName;
    int quantity;
    std::string issueDate;
    std::string expiryDate;
};

void addMedication(std::vector<Medication>& medications, const std::string& medicationName, int quantity, const std::string& issueDate, const std::string& expiryDate) {
    // Implementation for addMedication
    Medication newMedication;
    newMedication.medicationID = medications.size() + 1;
    newMedication.medicationName = medicationName;
    newMedication.quantity = quantity;
    newMedication.issueDate = issueDate;
    newMedication.expiryDate = expiryDate;

    medications.push_back(newMedication);
    std::cout << "Medication added successfully!\n";
}

void updateMedicationStock(std::vector<Medication>& medications, int medicationID, int newQuantity) {
    // Implementation for updateMedicationStock
    for (Medication& medication : medications) {
        if (medication.medicationID == medicationID) {
            medication.quantity = newQuantity;
            std::cout << "Medication stock updated successfully!\n";
            return;
        }
    }
    std::cout << "Medication not found.\n";
}

void removeMedication(std::vector<Medication>& medications, int medicationID) {
    // Implementation for removeMedication
    auto it = std::remove_if(medications.begin(), medications.end(), [medicationID](const Medication& medication) {
        return medication.medicationID == medicationID;
    });

    if (it != medications.end()) {
        medications.erase(it, medications.end());
        std::cout << "Medication removed successfully!\n";
    } else {
        std::cout << "Medication not found.\n";
    }
}

#endif // MEDICATION_MANAGEMENT_H
