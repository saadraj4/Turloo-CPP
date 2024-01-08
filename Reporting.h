#ifndef REPORTING_H
#define REPORTING_H

#include <vector>
#include <iostream>

struct Medication;
struct Prescription;

void generateInventoryReport(const std::vector<Medication>& medications) {
    // Implementation for generateInventoryReport
    std::cout << "Generating Inventory Report...\n";
    // Output the inventory details, for example:
    for (const Medication& medication : medications) {
        std::cout << "Medication ID: " << medication.medicationID << ", Name: " << medication.medicationName << ", Quantity: " << medication.quantity << "\n";
    }
}

void generatePatientReport(const std::vector<Prescription>& prescriptions) {
    // Implementation for generatePatientReport
    std::cout << "Generating Patient Report...\n";
    // Output patient interaction details, for example:
    for (const Prescription& prescription : prescriptions) {
        std::cout << "Prescription ID: " << prescription.prescriptionID << ", Patient ID: " << prescription.patientID << ", Date Issued: " << prescription.dateIssued << "\n";
    }
}

#endif // REPORTING_H
