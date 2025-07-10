#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Patient {
    static int idCounter;
    int id;
    string name;
    int age;
    string disease;

    Patient(string n, int a, string d) {
        id = ++idCounter;
        name = n;
        age = a;
        disease = d;
    }
};

int Patient::idCounter = 0;

struct Doctor {
    static int idCounter;
    int id;
    string name;
    string specialization;

    Doctor(string n, string s) {
        id = ++idCounter;
        name = n;
        specialization = s;
    }
};

int Doctor::idCounter = 0;

struct Appointment {
    static int idCounter;
    int id;
    int patientID;
    int doctorID;
    string date;

    Appointment(int pID, int dID, string dt) {
        id = ++idCounter;
        patientID = pID;
        doctorID = dID;
        date = dt;
    }
};

int Appointment::idCounter = 0;

vector<Patient> patients;
vector<Doctor> doctors;
vector<Appointment> appointments;

void addPatient() {
    string name, disease;
    int age;

    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter disease: ";
    cin.ignore();
    getline(cin, disease);

    patients.push_back(Patient(name, age, disease));
    cout << "Patient added successfully. ID: " << patients.back().id << endl;
}

void viewPatients() {
    cout << "\n--- List of Patients ---\n";
    for (auto &p : patients) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << ", Disease: " << p.disease << endl;
    }
}

void addDoctor() {
    string name, spec;

    cout << "Enter doctor name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter specialization: ";
    getline(cin, spec);

    doctors.push_back(Doctor(name, spec));
    cout << "Doctor added successfully. ID: " << doctors.back().id << endl;
}

void viewDoctors() {
    cout << "\n--- List of Doctors ---\n";
    for (auto &d : doctors) {
        cout << "ID: " << d.id << ", Name: " << d.name << ", Specialization: " << d.specialization << endl;
    }
}

void scheduleAppointment() {
    int pid, did;
    string date;

    if (patients.empty() || doctors.empty()) {
        cout << "Patients or Doctors list is empty.\n";
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> pid;
    cout << "Enter Doctor ID: ";
    cin >> did;
    cout << "Enter Date (DD/MM/YYYY): ";
    cin.ignore();
    getline(cin, date);

    appointments.push_back(Appointment(pid, did, date));
    cout << "Appointment scheduled successfully. ID: " << appointments.back().id << endl;
}

void viewAppointments() {
    cout << "\n--- List of Appointments ---\n";
    for (auto &a : appointments) {
        cout << "ID: " << a.id << ", Patient ID: " << a.patientID
             << ", Doctor ID: " << a.doctorID << ", Date: " << a.date << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Hospital Management System =====\n";
        cout << "1. Add Patient\n";
        cout << "2. View Patients\n";
        cout << "3. Add Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Schedule Appointment\n";
        cout << "6. View Appointments\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: scheduleAppointment(); break;
            case 6: viewAppointments(); break;
            case 0: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
