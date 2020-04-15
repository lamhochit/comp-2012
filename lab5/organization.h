#ifndef ORGANIZATION_H
#define ORGANIZATION_H

class Organization {
public:
	// Modify the function declarations below

	explicit Organization(const char* name);

	virtual ~Organization();

	virtual void print_description() const;

	virtual bool report() const;

protected:
    char* name;
};

#endif
