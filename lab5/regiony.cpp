//
// Created by lamhochit on 15/4/2020.
//

#include <iostream>
#include <cstring>

#include "regiony.h"

using namespace std;

RegionY::RegionY(const char *name, int num_patient, int num_death): Organization(name),
                                                                    num_patient(num_patient), num_death(num_death) {
}

RegionY::~RegionY() {
    cout << "RegionX Dtor" << endl;
}

void RegionY::print_description() const {
    cout << "Organization: " << this->name << " Type: RegionY" << endl;
}

bool RegionY::report() const {
    double death_rate = static_cast<double>(num_death)/static_cast<double>(num_patient) * 100;
    death_rate = static_cast<double>(roundf(death_rate*100)/100);
    if (death_rate > 4) {
        cout << "Death rate: " << death_rate << "% > 4%, severe!" << endl;
        return true;
    }
    else {
        cout << "Death rate: " << death_rate << " <= 4%, not severe!" << endl;
        return false;
    }

}

