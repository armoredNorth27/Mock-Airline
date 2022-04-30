#include <iomanip>
#include "Part.h"

//============================================//
//                Constructors                //
//============================================//

// **********Base Class********** //
Part::Part(const string& name): name(name), installationDate(Date()), flighthours(0){}

Part::~Part(){}



// **********Children Classes********** //
FH_Part::FH_Part(const string& name, int time): Part(name), fh_inspect(time){}

FH_Part::~FH_Part(){}

IT_Part::IT_Part(const string& name, int time): Part(name), it_inspect(time){}

IT_Part::~IT_Part(){}

FHIT_Part::FHIT_Part(const string& name, int fh_inspect_hours, int it_inspect_hours): FH_Part(name, fh_inspect_hours), IT_Part(name, it_inspect_hours), Part(name){}

FHIT_Part::~FHIT_Part(){}

//============================================//
//               Member Functions             //
//============================================//

// **********Base Class********** //
// Return the name of the part
string Part::getName() const{ return name; }

// Add the number of hours to the flighthours attribute
void Part::addFlightHours(int hours){ flighthours += hours; }

// Set the installationDate to the input parameter
void Part::install(Date& date){ installationDate = date; }

// Format the output stream for the part object
ostream& operator<<(ostream& ost, const Part& part){
    part.print(ost);
    return ost;
}

// Print part if it's a Part
void Part::print(ostream& ost) const{
    ost << "Part:" << setfill(' ') << setw(16) << " " << this->getName() << endl;
    ost << "Flight Hours:" << setfill(' ') << setw(8) << " " << this->flighthours << endl;
    ost << "Installation Date: " << setfill(' ') << setw(2) << " " << this->installationDate;
}



// **********Children Classes********** //
// Return true if flighthours >= fh_inspect
// Return false otherwise
bool FH_Part::inspection(Date& date) const{
    return flighthours >= fh_inspect;
}

// Return true if the number of days in installation date
//        minus the number of days input param is greater
//        than or equal to it_inspect
// Return false otherwise
bool IT_Part::inspection(Date& date) const{
    return ((date.toDays() - installationDate.toDays()) >= it_inspect);
}

// Return true if either the inspection functions of the parent
//        classes return true
// Return false otherwise
bool FHIT_Part::inspection(Date& date) const{
    if(FH_Part::inspection(date) || IT_Part::inspection(date)){
        return true;
    }
    
    return false;
}

// Print part if it's an FH_Part
void FH_Part::print(ostream& ost) const{
    Part::print(ost);
    ost << "Inspect every: " << setfill(' ') << setw(6) << " " << fh_inspect << " flight hours" << endl;
}

// Print part if it's an IT_Part
void IT_Part::print(ostream& ost) const{
    Part::print(ost);
    ost << "Inspect every: " << setfill(' ') << setw(6) << " " << it_inspect << " days installed" << endl;
}

// Print part if it's an FHIT_Part
void FHIT_Part::print(ostream& ost) const{
    Part::print(ost);
    ost << "Inspect every: " << setfill(' ') << setw(6) << " " << fh_inspect << " flight hours" << endl;
    ost << "Inspect every: " << setfill(' ') << setw(6) << " " << it_inspect << " days installed" << endl;
}