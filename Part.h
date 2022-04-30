#ifndef PART_H
#define PART_H

#include "Date.h"

class Part{

    friend ostream& operator<<(ostream&, const Part&);

    public:
        //* Constructors
        Part(const string&);
        virtual ~Part();

        //* Member Functions
        // Getters
        string getName() const;

        void addFlightHours(int);
        void install(Date&);
        virtual bool inspection(Date&) const = 0;
        virtual void print(ostream&) const;

    protected:
        //* Member variables
        int flighthours;
        Date installationDate;

    private:
        string name;

};

class FH_Part: virtual public Part{

    public:
        //* Constructors
        FH_Part(const string&, int);
        virtual ~FH_Part();

        //* Member Functions
        virtual bool inspection(Date&) const;
        virtual void print(ostream&) const;

    protected:
        //* Member variables
        int fh_inspect;

};

class IT_Part: virtual public Part{

    public:
        //* Constructors
        IT_Part(const string&, int);
        virtual ~IT_Part();

        //* Member Functions
        virtual bool inspection(Date&) const;
        virtual void print(ostream&) const;

    protected:
        //* Member variables
        int it_inspect;
        
};

class FHIT_Part: public FH_Part, public IT_Part{

    public:
        //* Constructors
        FHIT_Part(const string&, int fh_inspect_hours, int it_inspect_hours);
        virtual ~FHIT_Part();

        //* Member Functions
        virtual bool inspection(Date&) const;
        virtual void print(ostream&) const;

};

#endif