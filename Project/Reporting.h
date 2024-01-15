#ifndef REPORTING_H
#define REPORTING_H

#include <vector>
#include <iostream>
#include <fstream>

struct Medication;
struct Patient;

// Function to generate an inventory report
void generateInventoryReport(const vector<Medication> &medications)
{
    // Open a file for writing the inventory report
    ofstream inventoryReport("InventoryReport.txt");
    cout << "Generating Inventory Report...\n";

    // Check if the file is open
    if (inventoryReport.is_open())
    {
        // Write header to the file
        inventoryReport << "----- Inventory Report -----\n";

        // Iterate through each Medication in the vector
        for (const Medication &medication : medications)
        {
            // Write medication details to the file
            inventoryReport << "Medication ID: " << medication.medicationID << "\n";
            inventoryReport << "Name: " << medication.medicationName << "\n";
            inventoryReport << "Quantity: " << medication.quantity << "\n";
            inventoryReport << "Issue Date: " << medication.issueDate << "\n";
            inventoryReport << "Expiry Date: " << medication.expiryDate << "\n";
            inventoryReport << "--------------------------------------------\n";

            // Print medication details to the console
            cout << "Medication ID: " << medication.medicationID << "\n";
            cout << "Name: " << medication.medicationName << "\n";
            cout << "Quantity: " << medication.quantity << "\n";
            cout << "Issue Date: " << medication.issueDate << "\n";
            cout << "Expiry Date: " << medication.expiryDate << "\n";
            cout << "--------------------------------------------\n";
        }

        // Close the file
        inventoryReport.close();
        cout << "Inventory report generated successfully!\n";
    }
    else
    {
        cout << "Unable to open the file for writing.\n";
    }
}

// Function to generate a patient report
void generatePatientReport(const vector<Patient> patients)
{
    // Open a file for writing the patient report
    ofstream patientReport("PatientReport.txt");
    cout << "Generating Patient Report...\n";

    // Check if the file is open
    if (patientReport.is_open())
    {
        // Write header to the file
        patientReport << "----- Patient Report -----\n";

        // Iterate through each Patient in the vector
        for (const Patient &patient : patients)
        {
            // Write patient details to the file
            patientReport << "Patient ID: " << patient.patientID << "\n";
            patientReport << "First Name: " << patient.Fname << "\n";
            patientReport << "Last Name: " << patient.Lname << "\n";
            patientReport << "Contact Details: " << patient.contactDetails << "\n";
            patientReport << "Medical History: " << patient.medicalHistory << "\n";
            patientReport << "--------------------------------------------\n";

            // Print patient details to the console
            cout << "Patient ID: " << patient.patientID << "\n";
            cout << "First Name: " << patient.Fname << "\n";
            cout << "Last Name: " << patient.Lname << "\n";
            cout << "Contact Details: " << patient.contactDetails << "\n";
            cout << "Medical History: " << patient.medicalHistory << "\n";
            cout << "--------------------------------------------\n";
        }

        // Close the file
        patientReport.close();
        cout << "Patient report generated successfully!\n";
    }
    else
    {
        cout << "Unable to open the file for writing.\n";
    }
}

#endif // REPORTING_H
