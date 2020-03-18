#include "pasta.h"
#include <iostream>
using namespace std;
Pasta::Pasta() {
    s = new Spaghetti;
    c = new Chicken;
    h = new Herb;
    cheese = new Cheese;
    cout << "Make Pasta! " << endl << endl;
}

Pasta::~Pasta() {
    delete s;
    delete c;
    delete h;
    delete cheese;
}
