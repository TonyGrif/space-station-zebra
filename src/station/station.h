#ifndef STATION_H 
#define STATION_H

#include "repairBay.h"
#include "ships.h"

#include <iostream>
#include <array>
#include <queue>

const int NUM_OF_REPAIR_BAYS = 3;

/**
 *   
 */
class Station 
{
    public:
        // Easier to change this way if needed
        using bayCollection = std::array<RepairBay, NUM_OF_REPAIR_BAYS>;
        using lineCollection = std::queue<Ship*>;

        /**
         * Default constructor for Station.
         */
        Station();

        /**
         * Non-Default constructor for Station.
         * 
         * @param string = sets the identification of this Station.
         */
        Station(std::string);

        /** 
         * Set the repair bays.
         * 
         * @param RepairBays are the bays to be added to a Station's collection.
         */
        void Bays(RepairBay a, RepairBay b, RepairBay c) {
            this->bays[0] = a;
            this->bays[1] = b; 
            this->bays[2] = c;
        }

        /**
         * Get the repair bays.
         */
        bayCollection Bays() const {
            return this->bays;
        }

        /**
         * Return one of the bays
         * 
         * @param loc determines which of the bays to return
         * @return RepairBay 
         */
        RepairBay Bay(int loc) const {
            return this->bays.at(loc);
        }

        /**
         * Runs through all the bays and handles one time cycle worth of repairs if needed.
         */
        void RepairTimeStep();

        /**
         * Add ship to the appropriate state (bay or queue).
         */
        void AddShip(Ship*);

        /**
         * Set the waitline based on parameters.
         * 
         * @param qs a queue of ship pointers. 
         */
        void WaitLine(lineCollection qs) {
            this->waitLine = qs;
        }

        /**
         * Return the queue of ships to the user.
         * 
         * @return queue of ship pointers.  
         */
        lineCollection WaitLine() const {
            return this->waitLine;
        }

        /**
         * Sets the station id.
         * 
         * Sets the station id based on the string input supplied.
         * 
         * @param string = string representation of identification.
         */
        void StationID(std::string sid) {
            this->stationID = sid;
        }

        /**
         * Returns station id.
         * 
         * @return string representation of identification. 
         */
        std::string StationID() const {
            return this->stationID;
        }

        /**
         * Create a string report of the Station's status.
         */
        std::string toString() const;

    private: 
        /**
         * Collection of repair bays.
         * Number is determined by the constant supplied.
         */
        bayCollection bays;

        /**
         * Queue of ship pointers.
         * Occupants are added whenever a bay is unavailable.
         * Occupant is freed when a bay is made available.
         */
        lineCollection waitLine;

        /**
         * String representation of a Station object's identification. 
         */
        std::string stationID;

        /**
         * Attempt to add the ship to the bay.
         * 
         * @return true if ship was added.
         * @return false if the ship was not added.
         */
        bool AddShipToBay(Ship*);

        /**
         * Add a ship to this wait line.
         * 
         * @param sp a ship pointer to be added. 
         */
        void AddShipToQueue(Ship* sp) {
            this->waitLine.push(sp);
        }

        /**
         * Remove the ship from the top of the queue.
         */
        void RemoveShipFromQueue() {
            this->waitLine.pop();
        }
};

#endif 