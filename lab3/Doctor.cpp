#include <iostream>
#include "Doctor.h"
#include "Patient.h"
using namespace std;

//TODO: complete the constructor of Doctor
Doctor::Doctor(const string &pname): Person(pname), num_of_patients(0), patient_list(nullptr) {}

//TODO: complete Doctor::responsible_for
void Doctor::responsible_for(Patient const* patient) {
    if (num_of_patients >= MAX_NUM_OF_PATIENTS)
        cout << "Reach the maximum number of patients." << endl;
    else{
        Patient* temp = new Patient[++num_of_patients];
        Patient temp1 = *patient;
        for(int i = 0; i < num_of_patients-1;i++){
            temp[i] = patient_list[i];
        }
        temp[num_of_patients-1] = temp1;
        if (patient_list)
            delete []patient_list;
        patient_list = temp;
    }
    cout<<"Doctor "<<get_name()<<" is responsible for patient "<< (patient_list[num_of_patients -1].get_name()) <<"\n";
    //add new patient to the end of the patient list
    //increment the number of patients
    //print "Doctor {doctor's name} is responsible for patient {patient's name}."
}

//TODO:complete Doctor::print_patient_name_list
void Doctor::print_patient_name_list() const {
    //print "Doctor {doctor's name}'s patients:\n"
    //print information of each patient like: "Patient {number}: {patient's name}, age {patient's age}\n"
    cout << "Doctor " << get_name() << " 's patients:\n";
    for (int i = 0; i < num_of_patients; i++)
    {
        cout << "Patient " << i << ": " << patient_list[i].get_name() << ", " << patient_list[i].get_age() << endl;
    }
}

