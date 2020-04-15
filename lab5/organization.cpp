#include <iostream>
#include <cstring>

#include "organization.h"

using namespace std;

Organization::Organization(const char* name)
{
	// 1. Allocate dynamic memory for private member "name"
	// Hint: strlen() function is useful here
	// 2. Copy the name using strcpy
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Organization::~Organization()
{
	cout << "Organization Dtor: "<< name << endl;
	delete [] this->name;
	this->name = nullptr;
	// Free dynamically allocated memory
}

void Organization::print_description() const
{
	cout << "Organization: " << name;
}

bool Organization::report() const {
    return false;
}
