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

void addPatient(std::vector<Patient>& patients, int id,const std::string& Fname, const std::string& Lname, const std::string& contactDetails, const std::string& medicalHistory) {
    // Implementation for addPatient
    Patient newPatient;
    newPatient.patientID = id;
    newPatient.Fname = Fname;
    newPatient.Lname = Lname;
    newPatient.contactDetails = contactDetails;
    newPatient.medicalHistory = medicalHistory;

    patients.push_back(newPatient);
    std::cout << "Patient added successfully!\n";
}

void updatePatient(std::vector<Patient>& patients, int patientID, const std::string& updatedFirstName, const std::string& updatedLastName, const std::string& updatedContact, const std::string& updatedDetails) {
    // Implementation for updatePatient
    for (Patient& patient : patients) {
        if (patient.patientID == patientID) {
            // Update patient details
            patient.Fname = updatedFirstName;
            patient.Lname = updatedLastName;
            patient.contactDetails = updatedContact;
            patient.medicalHistory = updatedDetails;

            std::cout << "Patient details updated successfully!\n";
            return;
        }
    }
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
bool patientExists(const std::vector<Patient>& patients, int patientID) {
    // Check if a patient with the given ID exists in the vector
    return std::any_of(patients.begin(), patients.end(), [patientID](const Patient& patient) {
        return patient.patientID == patientID;
    });
}

#endif // PATIENT_MANAGEMENT_H
