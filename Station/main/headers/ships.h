#ifndef SHIP_H 
#define SHIP_H

#include "part.h"

#include <list>

#include <ctime>
#include <random>

/**
 * Ship class.
 * 
 * This class is responsible for generating a type, list of parts (broken or not), and have its own id number.
 */
class Ship 
{    
    public:
        using partsCollection = std::list<Part>;

        /**
         * Default Ship constructor.
         * 
         * @param id sets the ID for this Ship.
         */
        Ship(int id = 1);

        /**
         * Return this Ship's identification number.
         * 
         * @return Integer.
         */
        int ShipID() const {
            return this->shipID;
        }

        /**
         * Return this Ship's type.
         * 
         * @return Character.
         */
        char Type() const {
            return this->type;
        }

        /**
         * Return this Ship's part collection. 
         * 
         * @return partsCollection.
         */
        partsCollection GetParts() const {
            return this->parts;
        }

        /**
         * Return a string representation of this object.
         * 
         * @return std::string.
         */
        std::string toString() const;

    private:
        /**
         * Ship identification number.
         */
        int shipID;

        /**
         * Ship type.
         */
        char type;

        /**
         * Collection of parts that make up the ship.
         */
        partsCollection parts;

        /**
         * Set the ship identification number.
         * 
         * @param si sets the ID for this Ship.
         */
        void ShipID(int si) {
            this->shipID = si;
        }

        /**
         * Generate this Ship's type.
         * 
         * Set the value based on the percentage chance of any of them.
         * H(50%), F(15%), K(10%), R(5%), O(20%).
         */
        void SetType();

        /**
         * Function to generate parts for this Ship based on the type.
         * 
         * H = id (1 - 100), 5% chance of broken part.
         * F = id (75 - 150), 8% chance of broken part.
         * K = id (2 - 200, only even), 6% chance of broken part.
         * R = id (1 - 199, only odd), 6% chance of broken part.
         * O = id (200 - 999), 7% chance of broken part.
         */
        void GenerateParts();

        // Generates a random engine that will persist through all instances of ships objects.
        static std::default_random_engine gen;
};

#endif 