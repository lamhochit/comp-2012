#ifndef __PASTA_H
#define __PASTA_H

#include "spaghetti.h"
#include "herb.h"
#include "chicken.h"
#include "cheese.h"
class Pasta {
public:
    Pasta();
    ~Pasta();
private:
    Spaghetti* s;
    Herb* h;
    Chicken* c;
    Cheese* cheese;
};

#endif