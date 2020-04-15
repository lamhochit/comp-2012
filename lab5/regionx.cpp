//
// Created by lamhochit on 15/4/2020.
//

#include <iostream>
#include <cstring>

#include "regionx.h"

using namespace std;

RegionX::RegionX(const char *name, int num_patient, int num_death): Organization(name),
    num_patient(num_patient), num_death(num_death) {
}

RegionX::~RegionX() {
    cout << "RegionX Dtor" << endl;
}

void RegionX::print_description() const {
    cout << "Organization: " << this->name << " Type: RegionX" << endl;
}

bool RegionX::report() const {
    double death_rate = static_cast<double>(num_death)/static_cast<double>(num_patient) * 100;
    death_rate = static_cast<double>(roundf(death_rate*100)/100);
    if (death_rate > 3) {
        cout << "Death rate: " << death_rate << "% > 3%, severe!" << endl;
        return true;
    }
    else {
        cout << "Death rate: " << death_rate << " <= 3%, not severe!" << endl;
        return false;
    }

}

