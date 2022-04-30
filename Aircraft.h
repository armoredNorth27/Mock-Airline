#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include "Part.h"
#include "Array.h"

class Aircraft{

    friend ostream& operator<<(ostream&, Aircraft&);

    public:
        //* Constructors
        Aircraft(const string& type, const string& regNum);
        ~Aircraft();

        //* Member Functions
        string getRegistration() const;
        void install(Part*, Date&);
        void takeFlight(int);
        void inspectionReport(Date&, Array<Part*>&) const;

    private:
        //* Member Variables
        string type;
        string registration;
        int flighthours;
        Array<Part*> pArr;

};

#endif