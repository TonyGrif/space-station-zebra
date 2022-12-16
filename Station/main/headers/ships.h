#ifndef SHIP_H 
#define SHIP_H

#include "part.h"

#include <list>

#include <ctime>
#include <random>

/**
 * @brief Ship class.
 * 
 * This class is responsible for generating a type, list of parts (broken or not), and its own ID number.
 */
class Ship 
{    
    public:
        /**
         * @brief Data structure to be used in part collection.
         */
        using partsCollection = std::list<Part>;

        /**
         * @brief Default Ship constructor.
         * 
         * @param id sets the ID for this Ship.
         */
        Ship(int id = 1);

        /**
         * @brief Return this Ship's identification number.
         * 
         * @return Integer.
         */
        int ShipID() const {
            return this->shipID;
        }

        /**
         * @brief Return this Ship's type.
         * 
         * @return Character.
         */
        char Type() const {
            return this->type;
        }

        /**
         * @brief Return this Ship's part collection. 
         * 
         * @return partsCollection.
         */
        partsCollection GetParts() const {
            return this->parts;
        }

        /**
         * @brief Return a string representation of this object.
         * 
         * @return std::string.
         */
        std::string toString() const;

    private:
        /**
         * @brief Ship identification number.
         */
        int shipID;

        /**
         * @brief Ship type.
         */
        char type;

        /**
         * @brief Collection of parts that make up the ship.
         */
        partsCollection parts;

        /**
         * @brief Set the ship identification number.
         * 
         * @param si sets the ID for this Ship.
         */
        void ShipID(int si) {
            this->shipID = si;
        }

        /**
         * @brief Generate this Ship's type.
         * 
         * Set the value based on the percentage chance of any of them.
         * H(50%), F(15%), K(10%), R(5%), O(20%).
         */
        void SetType();

        /**
         * @brief Function to generate parts for this Ship based on the type.
         * 
         * H = id (1 - 100), 5% chance of broken part.
         * F = id (75 - 150), 8% chance of broken part.
         * K = id (2 - 200, only even), 6% chance of broken part.
         * R = id (1 - 199, only odd), 6% chance of broken part.
         * O = id (200 - 999), 7% chance of broken part.
         */
        void GenerateParts();

        /**
         * @brief Random engine to be shared amongst all Ships.
         */
        static std::default_random_engine gen;
};

#endif 