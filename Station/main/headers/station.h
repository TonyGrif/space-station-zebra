#ifndef STATION_H 
#define STATION_H

#include "repairBay.h"
#include "ships.h"

#include <array>
#include <queue>

const int NUM_OF_REPAIR_BAYS = 3;

/**
 * Station class.
 * 
 * Responsible for managing a collection of repair bays and wait line to the bays.
 */
class Station 
{
    public:
        using bayCollection = std::array<RepairBay, NUM_OF_REPAIR_BAYS>;
        using lineCollection = std::queue<Ship*>;

        /**
         * Default constructor for Station.
         */
        Station();

        /**
         * Non-Default constructor for Station.
         * 
         * @param string sets the identification of this Station.
         */
        Station(std::string);

        /**
         * Returns this Station's ID.
         * 
         * @return std::string. 
         */
        std::string StationID() const {
            return this->stationID;
        }

        /**
         * Return the Repair Bay collection.
         * 
         * @return bayCollection.
         */
        bayCollection Bays() const {
            return this->bays;
        }

        /**
         * Runs through all the bays and handles one time cycle worth of repairs if needed.
         */
        void RepairTimeStep();

        /**
         * Add ship to the appropriate state (bay or queue).
         * 
         * @param sPtr Ship pointer.
         */
        void AddShip(Ship* sPtr);

        /**
         * Return the collection of ships located in the wait line.
         * 
         * @return lineCollection. 
         */
        lineCollection WaitLine() const {
            return this->waitLine;
        }

        /**
         * Return a string representation of this Station.
         * 
         * @return std::string.
         */
        std::string toString() const;

    private: 
        /**
         * String representation of a Station object's identification. 
         */
        std::string stationID;
        
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
         * Set this Station's ID.
         * 
         * @param string sets the ID.
         */
        void StationID(std::string sid) {
            this->stationID = sid;
        }

        /** 
         * Set the repair bays.
         * 
         * @param RepairBays RepairBays to be added to this Station.
         */
        void Bays(RepairBay a, RepairBay b, RepairBay c) {
            this->bays[0] = a;
            this->bays[1] = b; 
            this->bays[2] = c;
        }

        /**
         * Attempt to add the ship to the bay.
         * 
         * @param sPtr Ship pointer to be added.
         * @return true if ship was added.
         * @return false if the ship was not added.
         */
        bool AddShipToBay(Ship* sPtr);

        /**
         * Add a ship to this wait line.
         * 
         * @param sPtr ship pointer to be added. 
         */
        void AddShipToQueue(Ship* sPtr) {
            this->waitLine.push(sPtr);
        }

        /**
         * Remove a ship from the top of the queue.
         */
        void RemoveShipFromQueue() {
            this->waitLine.pop();
        }
};

#endif 