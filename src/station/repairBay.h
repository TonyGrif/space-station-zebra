#ifndef REPAIR_H 
#define REPAIR_H

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
         * @param char character representation of a bay.
         * @param Ship pointer to a ship to be docked at the bay (optional)
         */
        RepairBay(char, Ship* = NULL);

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
            this->CalculateRepairTime();
        }

        /**
         * Return the current ship pointer.
         * @return Ship*.
         */
        Ship* CurrentShip() const {
            return this->currentShip;
        }

        /**
         * Return the time to repair
         */
        int TimeToRepair() const {
            return this->repairTime;
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

        /**
         * Counter for how long the current ship will take to repair
         */
        int repairTime;
                
        /**
         * Calculate the total time it will take to repair the current ship
         */
        void CalculateRepairTime();

        /**
         * Set the designation of a bay object.
         * 
         * @param char = character representation of a bay.
         */
        void Designation(char d) {
            this->designation = d;
        }
};

#endif 