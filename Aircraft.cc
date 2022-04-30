#include "Aircraft.h"

//==============================================//
//				   Constructors  				//
//==============================================//

Aircraft::Aircraft(const string& type, const string& regNum): type(type), registration(regNum), flighthours(0), pArr(Array<Part*>()){}

Aircraft::~Aircraft(){}

//==============================================//
//				 Member Functions  				//
//==============================================//

// Return registration string of aircraft
string Aircraft::getRegistration() const{ return registration; }

// Add the given part to the array of parts
void Aircraft::install(Part* part, Date& date){
    part->install(date);
    pArr.add(part);
}

// Add the supplied number of hours to the flighthours
// member variable. Also add the supplied number of hours
// to all parts in the parts array
void Aircraft::takeFlight(int hours){
    flighthours += hours;

    for(int i=0; i<pArr.getSize(); i++){
        pArr[i]->addFlightHours(hours);
    }
}

// Iterate over all parts in the parts array.
// If any of the parts require inspection,
// add them to the output array
void Aircraft::inspectionReport(Date& date, Array<Part*>& outArr) const{
    for(int i=0; i<pArr.getSize(); i++){
        if(pArr[i]->inspection(date)){
            outArr.add(pArr[i]);
        }
    }
}

ostream& operator<<(ostream& ost, Aircraft& aircraft){
    ost << "Aircraft: " << setfill(' ') << setw(5) << " " << aircraft.type << endl;
    ost << "Registration: " << setfill(' ') << setw(1) << " " << aircraft.registration << endl;

    return ost;
}