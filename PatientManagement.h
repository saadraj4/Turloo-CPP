#ifndef PATIENT_MANAGEMENT_H
#define PATIENT_MANAGEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

struct Patient {
    int patientID;
    std::string Fname;
    std::string Lname;
    std::string contactDetails;
    std::string medicalHistory;
};

void addPatient(std::vector<Patient>& patients, const std::string& Fname, const std::string& Lname, const std::string& contactDetails, const std::string& medicalHistory) {
    // Implementation for addPatient
    Patient newPatient;
    newPatient.patientID = patients.size() + 1;
    newPatient.Fname = Fname;
    newPatient.Lname = Lname;
    newPatient.contactDetails = contactDetails;
    newPatient.medicalHistory = medicalHistory;

    patients.push_back(newPatient);
    std::cout << "Patient added successfully!\n";
}

void updatePatient(std::vector<Patient>& patients, int patientID, const std::string& updatedDetails) {
    // Implementation for updatePatient
    for (Patient& patient : patients) {
        if (patient.patientID == patientID) {
            // Parse and update patient details
            // For simplicity, assuming updatedDetails contains all details to be updated
            // In a real-world scenario, you may want to parse and handle this string more robustly
            patient.contactDetails = updatedDetails;  // Update contactDetails, replace with actual fields to be updated
            std::cout << "Patient details updated successfully!\n";
            return;
        }
    }
    std::cout << "Patient not found.\n";
}

void removePatient(std::vector<Patient>& patients, int patientID) {
    // Implementation for removePatient
    auto it = std::remove_if(patients.begin(), patients.end(), [patientID](const Patient& patient) {
        return patient.patientID == patientID;
    });

    if (it != patients.end()) {
        patients.erase(it, patients.end());
        std::cout << "Patient removed successfully!\n";
    } else {
        std::cout << "Patient not found.\n";
    }
}

#endif // PATIENT_MANAGEMENT_H
