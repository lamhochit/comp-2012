//
// Created by lamhochit on 15/4/2020.
//

#ifndef LAB5_REGIONY_H
#define LAB5_REGIONY_H

#include "organization.h"

class RegionY: public Organization{
public:
    // Modify the function declarations below

    RegionY(const char* name, int num_patient, int num_death);

    virtual ~RegionY();

    void print_description() const override;

    virtual bool report() const;

private:
    int num_patient;
    int num_death;

};
#endif //LAB5_REGIONY_H
