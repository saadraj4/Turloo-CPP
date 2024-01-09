#ifndef PRESCRIPTION_MANAGEMENT_H
#define PRESCRIPTION_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>

struct Prescription {
    int prescriptionID;
    int patientID;
    std::string dateIssued;
    std::string medicationDetails;
};

void createPrescription(std::vector<Prescription>& prescriptions, int patientID, const std::string& dateIssued, const std::string& medicationDetails) {
    // Implementation for createPrescription
    Prescription newPrescription;
    newPrescription.prescriptionID = patientID;
    newPrescription.patientID = patientID;
    newPrescription.dateIssued = dateIssued;
    newPrescription.medicationDetails = medicationDetails;

    prescriptions.push_back(newPrescription);
    std::cout << "Prescription created successfully!\n";
}

// Function to update prescription details
void updatePrescription(std::vector<Prescription>& prescriptions, int prescriptionID, const std::string& updatedDetails) {
    for (Prescription& prescription : prescriptions) {
        if (prescription.prescriptionID == prescriptionID) {
            // Parse and update prescription details
            // For simplicity, assuming updatedDetails contains all details to be updated
            // In a real-world scenario, you may want to parse and handle this string more robustly

            // Update prescription details based on the provided information
            prescription.medicationDetails = updatedDetails;  // Replace with actual fields to be updated

            std::cout << "Prescription details updated successfully!\n";
            return;
        }
    }
    std::cout << "Prescription not found.\n";
}


// Function to check if a prescription with a given ID exists
bool prescriptionExists(const std::vector<Prescription>& prescriptions, int prescriptionID) {
    for (const Prescription& prescription : prescriptions) {
        if (prescription.prescriptionID == prescriptionID) {
            return true;
        }
    }
    return false;
}


#endif // PRESCRIPTION_MANAGEMENT_H
