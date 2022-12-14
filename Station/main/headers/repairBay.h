#ifndef REPAIR_H 
#define REPAIR_H

#include "ships.h"

/**
 * Repair Bay class.
 * 
 * This class is responsible for conducting ship repairs.
 */
class RepairBay
{
    public:
        /**
         * Default constructor for a repair bay.
         * 
         * @param id character representation of this Bay.
         * @param sPtr ship pointer to be added to this Bay.
         */
        RepairBay(char id = 'A', Ship* sPtr = NULL);

        /**
         * Return the character designation of this Bay object. 
         * 
         * @return Character. 
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
         * 
         * @param cs ship pointer to the Ship to be docked at this Bay.
         */
        void CurrentShip(Ship* cs) {
            this->currentShip = cs;
            this->CalculateRepairTime();
        }

        /**
         * Return the current ship pointer.
         * 
         * @return Ship*.
         */
        Ship* CurrentShip() const {
            return this->currentShip;
        }

        /**
         * Remove the current ship pointer and set to NULL.
         * Reset the repair time counter. 
         */
        void RemoveShip() {
            delete this->currentShip;
            this->currentShip = NULL;
            this->repairTime = 0;
        }

        /**
         * Return the time to repair the current ship.
         * 
         * @return Integer.
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
         * Return boolean status of this Bay.
         * 
         * @return false if current ship pointer is NULL.
         * @return true if current ship pointer is not NULL.
         */
        bool IsFull() const {
            return (this->CurrentShip() == NULL ? false : true);
        }

        /**
         * Return a string representation of this object.
         * 
         * @return std::string.
         */
        std::string toString() const;

    private:
        /**
         * Stores the char representation of this Bay.
         */
        char designation;

        /**
         * Pointer to the ship currently docked.
         */
        Ship *currentShip;

        /**
         * Counter for how long the current ship will take to repair.
         */
        int repairTime;
                
        /**
         * Calculate the total time it will take to repair the current ship.
         * 
         * TODO: Beyond this project, move to ship class and have each part carry a repair number.
         *       Update the parts as repairs are conducted.
         */
        void CalculateRepairTime();

        /**
         * Set the designation of this Bay.
         * 
         * @param char representation of this Bay.
         */
        void Designation(char d) {
            this->designation = d;
        }
};

#endif 