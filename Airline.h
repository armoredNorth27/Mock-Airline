#ifndef AIRLINE_H
#define AIRLINE_H

#include "Aircraft.h"

class Airline{

    friend ostream& operator<<(ostream&, const Airline&);

    public:
        //* Constructors
        Airline(const string& name);
        ~Airline();

        //* Member functions
        void addAircraft(const string& type, const string& reg);
        void addPart(const string& part, int fh_inspect, int it_inspect);
        void takeFlight(const string& reg, int hours);
        void printAircraft() const;
        void printParts() const;
        void inspectionReport(const string& reg, Date&);
        bool install(const string& airReg, const string& partName, Date&);

    private:
        //* Member variables
        string name;
        Array<Part*> partArray;
        Array<Aircraft*> aircraftArray;

        //* Member functions
        bool getPart(const string&, Part**) const;
        bool getAircraft(const string&, Aircraft**) const;
        
};

#endif