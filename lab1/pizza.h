#ifndef __PIZZA_H
#define __PIZZA_H

#include "dough.h"
#include "chicken.h"
#include "cheese.h"
class Pizza {
public:
    Pizza();
    ~Pizza();
private:
    Dough* d;
    Chicken* c; 
    Cheese* cheese; 
};

#endif