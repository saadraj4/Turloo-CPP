#ifndef REPORTING_H
#define REPORTING_H

#include <vector>
#include <iostream>
#include <fstream>

struct Medication;
struct Patient;


void generateInventoryReport(const vector<Medication> &medications)
{
    // Implementation for generateInventoryReport
    ofstream inventoryReport("InventoryReport.txt");
    cout << "Generating Inventory Report...\n";
    if (inventoryReport.is_open())
    {
        inventoryReport << "----- Inventory Report -----\n";
        for (const Medication &medication : medications)
        {
            inventoryReport << "Medication ID: " << medication.medicationID << "\n";
            inventoryReport << "Name: " << medication.medicationName << "\n";
            inventoryReport << "Quantity: " << medication.quantity << "\n";
            inventoryReport << "Issue Date: " << medication.issueDate << "\n";
            inventoryReport << "Expiry Date: " << medication.expiryDate << "\n";
            inventoryReport << "--------------------------------------------\n";

            cout << "Medication ID: " << medication.medicationID << "\n";
            cout << "Name: " << medication.medicationName << "\n";
            cout << "Quantity: " << medication.quantity << "\n";
            cout << "Issue Date: " << medication.issueDate << "\n";
            cout << "Expiry Date: " << medication.expiryDate << "\n";
            cout << "--------------------------------------------\n";
        }
        inventoryReport.close();
        cout << "Inventory report generated successfully!\n";
    }
    else
    {
        cout << "Unable to open the file for writing.\n";
    }
}

void generatePatientReport(const vector<Patient> patients)
{
    // Implementation for generatePatientReport
    ofstream patientReport("PatientReport.txt");
    cout << "Generating Patient Report...\n";
    if (patientReport.is_open())
    {
        patientReport << "----- Patient Report -----\n";
        for (const Patient &patient : patients)
        {
            patientReport << "Patient ID: " << patient.patientID << "\n";
            patientReport << "First Name: " << patient.Fname << "\n";
            patientReport << "Last Name: " << patient.Lname << "\n";
            patientReport << "Contact Details: " << patient.contactDetails << "\n";
            patientReport << "Medical History: " << patient.medicalHistory << "\n";
            patientReport << "--------------------------------------------\n";

            cout << "Patient ID: " << patient.patientID << "\n";
            cout << "First Name: " << patient.Fname << "\n";
            cout << "Last Name: " << patient.Lname << "\n";
            cout << "Contact Details: " << patient.contactDetails << "\n";
            cout << "Medical History: " << patient.medicalHistory << "\n";
            cout << "--------------------------------------------\n";
        }
        patientReport.close();
        cout << "Patient report generated successfully!\n";
    }
    else
    {
        cout << "Unable to open the file for writing.\n";
    }
}

#endif // REPORTING_H
