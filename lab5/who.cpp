//
// Created by lamhochit on 15/4/2020.
//

#include <iostream>
#include <cstring>

#include "who.h"

using namespace std;

WHO::WHO(const char *name) : Organization(name) {
}

WHO::~WHO() {
    for (int i = 0; i < num_watchlist; i++)
        delete watchlist[i];
    cout << "WHO Dtor" << endl;
}

void WHO::print_description() const {
    cout << "Organization: " << this->name << " Type: WHO" << endl;
}

void WHO::watch(Organization *new_organization) {
    if (this->num_watchlist == MAX_NUM_WATCHLIST) {
        return;
    }
    else {
        this->watchlist[this->num_watchlist] = new_organization;
        num_watchlist += 1;
    }
}

bool WHO::report() const {
    int num_severe = 0;
    for(int i = 0; i < num_watchlist; i++){
        watchlist[i]->print_description();
        if(watchlist[i]->report())
            num_severe++;
    }
    this->print_description();
    if(num_severe > num_watchlist/2){
        cout << "Severe regions: " << num_severe << "/" << num_watchlist << ", severe!" << endl;
        return true;
    }
    else{
        cout << "Severe regions: " << num_severe << "/" << num_watchlist << ", not severe!" << endl;
        return false;
    }
}

