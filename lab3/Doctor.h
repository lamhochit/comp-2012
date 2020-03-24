//TODO: Class declaration of Doctor

//define the const int MAX_NUM_OF_PATIENTS to be 15 here
const int MAX_NUM_OF_PATIENTS = 15;

#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include "Person.h"
#include "Patient.h"

class Doctor: public Person {
private:
    int num_of_patients;
    const Patient* patient_list;
public:
    Doctor(const std::string& pname);
    void responsible_for(Patient const* patient);
    void print_patient_name_list() const;
};

#endif