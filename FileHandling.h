#ifndef FILE_HANDLING_H
#define FILE_HANDLING_H

#include <fstream>
#include <vector>
#include "UserManagement.h"
#include "PatientManagement.h"
#include "PrescriptionManagement.h"
#include "MedicationManagement.h"

using namespace std;

// File paths
const string USERS_FILE = "users.txt";
const string PATIENTS_FILE = "patients.txt";
const string PRESCRIPTIONS_FILE = "prescriptions.txt";
const string MEDICATIONS_FILE = "medications.txt";

// Load data from files
void loadDataFromFile(std::vector<User>& users, std::vector<Patient>& patients, std::vector<Prescription>& prescriptions, std::vector<Medication>& medications) {
    // Load users
    ifstream usersFile(USERS_FILE);
    if (usersFile.is_open()) {
        User user;
        while (usersFile >> user.userID >> user.username >> user.password >> user.role) {
            users.push_back(user);
        }
        usersFile.close();
    }

    // Load patients
    ifstream patientsFile(PATIENTS_FILE);
    if (patientsFile.is_open()) {
        Patient patient;
        while (patientsFile >> patient.patientID >> patient.Fname >> patient.Lname >> patient.contactDetails >> patient.medicalHistory) {
            patients.push_back(patient);
        }
        patientsFile.close();
    }

    // Load prescriptions
    ifstream prescriptionsFile(PRESCRIPTIONS_FILE);
    if (prescriptionsFile.is_open()) {
        Prescription prescription;
        while (prescriptionsFile >> prescription.prescriptionID >> prescription.patientID >> prescription.dateIssued >> std::ws) {
            std::getline(prescriptionsFile, prescription.medicationDetails);
            prescriptions.push_back(prescription);
        }
        prescriptionsFile.close();
    }

    // Load medications
    ifstream medicationsFile(MEDICATIONS_FILE);
    if (medicationsFile.is_open()) {
        Medication medication;
        while (medicationsFile >> medication.medicationID >> medication.medicationName >> medication.quantity >> medication.issueDate >> medication.expiryDate) {
            medications.push_back(medication);
        }
        medicationsFile.close();
    }
}

// Save data to files
void saveDataToFile(const std::vector<User>& users, const std::vector<Patient>& patients, const std::vector<Prescription>& prescriptions, const std::vector<Medication>& medications) {
    // Save users
    ofstream usersFile(USERS_FILE);
    if (usersFile.is_open()) {
        for (const User& user : users) {
            usersFile << user.userID << ' ' << user.username << ' ' << user.password << ' ' << user.role << '\n';
        }
        usersFile.close();
    }

    // Save patients
    ofstream patientsFile(PATIENTS_FILE);
    if (patientsFile.is_open()) {
        for (const Patient& patient : patients) {
            patientsFile << patient.patientID << ' ' << patient.Fname << ' ' << patient.Lname << ' ' << patient.contactDetails << ' ' << patient.medicalHistory << '\n';
        }
        patientsFile.close();
    }

    // Save prescriptions
    ofstream prescriptionsFile(PRESCRIPTIONS_FILE);
    if (prescriptionsFile.is_open()) {
        for (const Prescription& prescription : prescriptions) {
            prescriptionsFile << prescription.prescriptionID << ' ' << prescription.patientID << ' ' << prescription.dateIssued << ' ' << prescription.medicationDetails << '\n';
        }
        prescriptionsFile.close();
    }

    // Save medications
    ofstream medicationsFile(MEDICATIONS_FILE);
    if (medicationsFile.is_open()) {
        for (const Medication& medication : medications) {
            medicationsFile << medication.medicationID << ' ' << medication.medicationName << ' ' << medication.quantity << ' ' << medication.issueDate << ' ' << medication.expiryDate << '\n';
        }
        medicationsFile.close();
    }
}

#endif // FILE_HANDLING_H
