#ifndef REPAIR_H 
#define REPAIR_H

#include "ships.h"

/**
 * Repair Bay class.
 * 
 * Responsible for conducting ship repairs.
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
         * @return designation value. 
         */
        char Designation() const {
            return this->designation;
        }

        /**
         * TODO: Move to private and create add ship function?
         *       Syntax difference not really functionality difference. 
         * 
         * Set the current ship pointer. 
         * Calculate the time it will take to repair the new ship.
         */
        void CurrentShip(Ship* cs) {
            this->currentShip = cs;
            this->CalculateRepairTime();
        }

        /**
         * Return the current ship pointer.
         * 
         * @return Ship* docked.
         */
        Ship* CurrentShip() const {
            return this->currentShip;
        }

        /**
         * Removes the current ship pointer and set to NULL.
         */
        void RemoveShip() {
            delete this->currentShip;
            this->currentShip = NULL;
            this->repairTime = 0;
        }

        /**
         * Return the time to repair
         */
        int TimeToRepair() const {
            return this->repairTime;
        }

        /**
         * Decrements the repair counter by one.
         */
        void DecrementRepairCounter() {
            this->repairTime--;
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
         * 
         * TODO: Beyond this project, move to ship class and have each part carry this repair number.
         */
        void CalculateRepairTime();

        /**
         * Set the designation of a bay object.
         * 
         * @param char representation of a bay.
         */
        void Designation(char d) {
            this->designation = d;
        }
};

#endif 