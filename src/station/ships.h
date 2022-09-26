#ifndef SHIP_H 
#define SHIP_H

#include "parts.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>

class Ship 
{    
    public:
        using partsCollection = std::vector<Parts>;

        /**
         * Default Ship constructor.
         */
        Ship();

        /**
         * Non-default Ship constructor.
         */
        Ship(int);

        /**
         * Calls the set type and generate parts functions 
         */
        void Build() {
            this->SetType();
            this->GenerateParts();
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
         * Set the ship identification number.
         * 
         * @param si integer identification number.
         */
        void ShipID(int si) {
            this->shipID = si;
        }

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
         * @return ship type char.
         */
        char Type() const {
            return this->type;
        }

        /**
         * Generate a string representation of this object.
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        /**
         * Collection of parts that make up the ship.
         */
        partsCollection parts;

        /**
         * Ship identification number.
         */
        int shipID;

        /**
         * Ship type.
         */
        char type;

        /**
         * Generate the ship's type.
         * 
         * Set the value based on the percentage chance of any of them.
         * H(50%), F(15%), K(10%), R(5%), O(20%)
         */
        void SetType();

        /**
         * Function to generate parts for this ship based on the type.
         * 
         * H = id (1 - 100)
         * F = id (75 - 150)
         * K = id (2 - 200, only even)
         * R = id (1 - 199, only odd)
         * O = id (200 - 999)
         */
        void GenerateParts();
};

#endif 