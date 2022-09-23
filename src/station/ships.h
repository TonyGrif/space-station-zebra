#ifndef SHIP_H 
#define SHIP_H

#include "parts.h"

#include <string>
#include <vector>

class Ship 
{
    public:
        /**
         * Default Ship constructor.
         */
        Ship();

        /**
         * Non-default Ship constructor.
         */
        Ship(int);

        /**
         * Non-default Ship constructor.
         */
        Ship(char);

        /**
         * Construct a full ship object
         */
        Ship(int, char);

        /**
         * Function to generate parts for this ship.
         */
        void GenerateParts();

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
         * Set the ship's type.
         * 
         * @param t char identification letter.
         */
        void Type(char t) {
            this->type = t;
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
        using partsCollection = std::vector<Parts>;

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
};

#endif 