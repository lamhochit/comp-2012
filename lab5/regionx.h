//
// Created by lamhochit on 15/4/2020.
//

#ifndef LAB5_REGIONX_H
#define LAB5_REGIONX_H

#include "organization.h"

class RegionX: public Organization{
public:
    // Modify the function declarations below

    RegionX(const char* name, int num_patient, int num_death);

    virtual ~RegionX();

    void print_description() const override;

    virtual bool report() const;

private:
    int num_patient;
    int num_death;

};

#endif //LAB5_REGIONX_H
