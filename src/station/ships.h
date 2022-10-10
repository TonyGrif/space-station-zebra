#ifndef SHIP_H 
#define SHIP_H

#include "parts.h"

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
         */
        Ship();

        /**
         * Non-default Ship constructor.
         * 
         * @param int sets the ship identification number.
         */
        Ship(int);

        /**
         * Return the ship's identification number.
         * 
         * @return ship identification number.
         */
        int ShipID() const {
            return this->shipID;
        }

        /**
         * Return the ship's type.
         * 
         * @return the ship's types.
         */
        char Type() const {
            return this->type;
        }

        /**
         * Get the parts collection. 
         * 
         * @return partsCollection 
         */
        partsCollection GetParts() const {
            return this->parts;
        }

        /**
         * Generate a string representation of this object.
         * 
         * @return std::string 
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
         * @param si integer identification number.
         */
        void ShipID(int si) {
            this->shipID = si;
        }

        /**
         * Generate the ship's type.
         * 
         * Set the value based on the percentage chance of any of them.
         * H(50%), F(15%), K(10%), R(5%), O(20%).
         */
        void SetType();

        /**
         * Function to generate parts for this ship based on the type.
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