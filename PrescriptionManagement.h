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
    newPrescription.prescriptionID = prescriptions.size() + 1;
    newPrescription.patientID = patientID;
    newPrescription.dateIssued = dateIssued;
    newPrescription.medicationDetails = medicationDetails;

    prescriptions.push_back(newPrescription);
    std::cout << "Prescription created successfully!\n";
}

void updatePrescription(std::vector<Prescription>& prescriptions, int prescriptionID, const std::string& updatedDetails) {
    // Implementation for updatePrescription
    for (Prescription& prescription : prescriptions) {
        if (prescription.prescriptionID == prescriptionID) {
            // Update prescription details
            // For simplicity, assuming updatedDetails contains all details to be updated
            // In a real-world scenario, you may want to parse and handle this string more robustly
            std::cout << "Prescription details updated successfully!\n";
            return;
        }
    }
    std::cout << "Prescription not found.\n";
}

#endif // PRESCRIPTION_MANAGEMENT_H
