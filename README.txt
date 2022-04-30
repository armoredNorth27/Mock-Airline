Contents:

    class.py
        A python file that can be used to make template c++ files

    README.txt
        Contains info on the classes and compilation
        instructions

    Makefile
        Compiles and links all .cc files into an executable
    
    Part.h
        Single header file that contains the following
        4 different classes

        1) Part: Virtual base class of all other Parts. Contains
        general data and functions for things like
        printing objects and names

        2) FH_Part: A derived part class that needs to be 
        inspected after a certain number of flight hours

        3) IT_Part: A derived part class that needs to be
        inspected after a certain number of days of being
        installed on an aircraft

        4) FHIT_Part: A derived part class of FH_Part and
        IT_Part that must be inspected after a certain
        number of days of being installed on an aircraft
        and after a certain number of flight hours
    
    Part.cc
        Define all functions in Part.h

    Array.h
        A simple templated data structure that represents
        a list. It's like a makeshift vector or arraylist
        class.
    
    Aircraft.h
        Contains aircraft data along with an array of
        installed parts. Allows for functionality such
        as flying and providing an inspection report

    Aircraft.cc
        Implements all functions contained in Aircraft.h
    
    Airline.h
        Tracks parts, aircraft, installation dates, flights,
        etc. It's like a master control class that keeps
        track of all aircraft and parts and is capable of
        things like making aircraft fly and providing
        inspection reports for every part

    Airline.cc
        Implements all functions contained in Airline.h
