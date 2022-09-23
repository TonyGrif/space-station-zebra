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
         * Non-Default constructor for Station.
         * 
         * @param RepairBays = set default repair bays for Station.
         */
        Station(RepairBay, RepairBay, RepairBay);

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
        std::array<RepairBay, 3> Bays() const {
            return this->bays;
        }

        /**
         * Add the ship to the bay.
         */
        void AddShipToBay(Ship*);

        /**
         * Set the waitline based on parameters.
         * 
         * @param qs a queue of ship pointers. 
         */
        void WaitLine(std::queue<Ship*> qs) {
            this->waitLine = qs;
        }

        /**
         * Return the queue of ships to the user.
         * 
         * @return queue of ship pointers.  
         */
        std::queue<Ship*> WaitLine() const {
            return this->waitLine;
        }

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
        std::array<RepairBay, 3> bays;

        /**
         * Queue of ship pointers.
         * Occupants are added whenever a bay is unavailable.
         * Occupant is freed when a bay is made available.
         */
        std::queue<Ship*> waitLine;

        /**
         * String representation of a Station object's identification. 
         */
        std::string stationID;
};

#endif 