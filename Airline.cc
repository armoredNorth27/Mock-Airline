#include "Airline.h"

//==============================================//
//				   Constructors  				//
//==============================================//

Airline::Airline(const string& name): name(name), partArray(Array<Part*>()), aircraftArray(Array<Aircraft*>()){}

Airline::~Airline(){
    int partLength = partArray.getSize();
    int aircraftLength = aircraftArray.getSize();

    for(int i=0; i<partLength; i++){
        delete partArray[i];
    }

    for(int i=0; i<aircraftLength; i++){
        delete aircraftArray[i];
    }
}

//==============================================//
//				 Member Functions  				//
//==============================================//

// Format an airline object that can be output to the console
ostream& operator<<(ostream& ost, const Airline& airline){
    ost << "Airline: " << airline.name << endl << endl;
    
    ost << endl << "All aircraft contained in the airline: " << endl;
    airline.printAircraft();

    ost << endl << "All parts contained in the airline: " << endl;
    airline.printParts();

    return ost;
}

// Find a part with the matching name and store it in
// the output parameter. Store null if part isn't found
// Return true if part is found
// Return false otherwise
bool Airline::getPart(const string& name, Part** outPart) const{
    for(int i=0; i<partArray.getSize(); i++){

        if(name == partArray[i]->getName()){
            *outPart = partArray[i];
            return true;
        }
    }

    outPart = NULL;
    return false;
}

// Find the aircraft with the matching regNum and store it in
// the output parameter. Store null if aircraft isn't found
// Return true if aircraft is found
// Return false otherwise
bool Airline::getAircraft(const string& regNum, Aircraft** outAircraft) const{
    for(int i=0; i<aircraftArray.getSize(); i++){
        if(regNum == aircraftArray[i]->getRegistration()){
            *outAircraft = aircraftArray[i];
            return true;
        }
    }

    outAircraft = NULL;
    return false;
}

// Create and add a new aircraft to the aircraft array
void Airline::addAircraft(const string& type, const string& reg){
    if(!aircraftArray.isFull()){
        aircraftArray.add(new Aircraft(type, reg));
    }
}

// Create and add a new part to the part array
// If both int input parameters are > 0, make a new FHIT_Part
// If fh_inspect == 0, make an IT_Part
// If it_inspect == 0, make an FH_Part
void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
    if(partArray.isFull()){
        return;
    }

    if(fh_inspect != 0 && it_inspect != 0){
        partArray.add(new FHIT_Part(part, fh_inspect, it_inspect));
    }
    else if(fh_inspect == 0){
        partArray.add(new IT_Part(part, it_inspect));
    }
    else if(it_inspect == 0){
        partArray.add(new FH_Part(part, fh_inspect));
    }
}

// Find the aircraft with the matching registration number
// and make it take flight for the given number of hours.
// If aircraft is not found, err message is outputted
void Airline::takeFlight(const string& reg, int hours){
    Aircraft* aircraft;
    
    if(getAircraft(reg, &aircraft)){
        aircraft->takeFlight(hours);
        return;
    }

    cout << "ERROR: Could not find specified aircraft." << endl;
}

// Print out all aircraft in the aircraft array
void Airline::printAircraft() const{
    for(int i=0; i<aircraftArray.getSize(); i++){
        cout << *aircraftArray[i] << endl;
    }
}

// Print out all parts in the parts array
void Airline::printParts() const{
    for(int i=0; i<partArray.getSize(); i++){
        cout << *partArray[i] << endl;
    }
}

// Find aircraft with matching reg number and print out its
// registration and all parts on that aircraft that require inspection.
// If aircraft is not found, err message is outputted
void Airline::inspectionReport(const string& reg, Date& date){
    Aircraft* aircraft;
    Array<Part*> outputArray;

    if(getAircraft(reg, &aircraft)){
        cout << "The following parts from " << aircraft->getRegistration() << " require inspection:" << endl;
        
        // Find and print all parts that need inspection
        aircraft->inspectionReport(date, outputArray);
        for(int i=0; i<outputArray.getSize(); i++){
            cout << *outputArray[i] << endl;
        }

        cout << endl;
    }
    else{
        cout << "ERROR: Could not find specified aircraft." << endl;
    }

}

// Find the aircraft with the matching reg number and the part
// with the matching part number. If either of these aren't found,
// output an appropriate error message then exit.
// If both parts are found, add the part to the aircraft
bool Airline::install(const string& airReg, const string& partName, Date& date){
    Part* foundPart;
    Aircraft* foundAircraft;

    if(!getPart(partName, &foundPart)){
        cout << "ERROR: Could not find specified part." << endl;
        return false;
    }

    if(!getAircraft(airReg, &foundAircraft)){
        cout << "ERROR: Could not find specified aircraft." << endl;
        return false;
    }

    foundAircraft->install(foundPart, date);
    return true;
}