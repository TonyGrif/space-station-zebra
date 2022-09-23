#ifndef REPAIR_H 
#define REPAIR_H

#include <cstddef>

#include "ships.h"

/**
 * 
 */
class RepairBay
{
    public:
        /**
         * Default constructor for a repair bay.
         */
        RepairBay();

        /**
         * Non-default constructor for a repair bay.
         * 
         * @param char = character representation of a bay.
         */
        RepairBay(char);

        /**
         * Non-default constructor for a repair bay.
         * 
         * @param ship* = ship pointer to be "docked" at the bay/
         */
        RepairBay(Ship*);

        /**
         * Set the designation of a bay object.
         * 
         * @param char = character representation of a bay.
         */
        void Designation(char d) {
            this->designation = d;
        }

        /**
         * Return the char designation of a bay object. 
         * 
         * @return char representation. 
         */
        char Designation() const {
            return this->designation;
        }

        /**
         * Set the current ship pointer. 
         */
        void CurrentShip(Ship* cs) {
            this->currentShip = cs;
        }

        /**
         * Return the current ship pointer.
         * @return Ship*.
         */
        Ship* CurrentShip() const {
            return this->currentShip;
        }

        /** 
         * Return boolean status of this bay.
         * 
         * @return false if current ship pointer is NULL
         * @return true if current ship pointer is not NULL
         */
        bool IsFull() const {
            return (this->CurrentShip() == NULL ? false : true);
        }

        /**
         * Return a string representation of this object.
         * 
         * @return std::string 
         */
        std::string toString() const;

    private:
        /**
         * Stores the char representation of a bay.
         */
        char designation;

        /**
         * Pointer to the ship currently docked
         */
        Ship *currentShip;
};

#endif 