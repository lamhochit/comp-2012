//
// Created by lamhochit on 15/4/2020.
//

#ifndef LAB5_WHO_H
#define LAB5_WHO_H

#include "organization.h"

const int MAX_NUM_WATCHLIST = 5;

class WHO: public Organization{
public:
    // Modify the function declarations below

    WHO(const char* name);

    virtual ~WHO();

    void print_description() const override;

    void watch(Organization *new_organization);

    virtual bool report() const;

private:
    Organization* watchlist[MAX_NUM_WATCHLIST];
    int num_watchlist = 0;

};
#endif //LAB5_WHO_H
