#ifndef REPAIR_H 
#define REPAIR_H

#include "ships.h"

/**
 * @brief Repair Bay class.
 * 
 * This class is responsible for conducting ship repairs.
 */
class RepairBay
{
    public:
        /**
         * @brief Default constructor for a repair bay.
         * 
         * @param id character representation of this Bay.
         * @param sPtr ship pointer to be added to this Bay.
         */
        RepairBay(char id = 'A', Ship* sPtr = NULL);

        /**
         * @brief Return the character designation of this Bay object. 
         * 
         * @return Character. 
         */
        char Designation() const {
            return this->designation;
        }

        /**
         * @brief Set the current ship pointer and calculate the necessary repair time.
         * 
         * Does not check to ensure a Ship is not already docked at this bay, must do so before calling this function.
         * 
         * @param cs ship pointer to be docked at this Bay.
         */
        void AddShip(Ship* cs) {
            this->CurrentShip(cs);
            this->CalculateRepairTime();
        }

        /**
         * @brief Return the current ship pointer.
         * 
         * @return Ship*.
         */
        Ship* CurrentShip() const {
            return this->currentShip;
        }

        /**
         * @brief Remove the current ship pointer and set to NULL; then, reset the time counter to zero.
         * 
         * Does not check to ensure the current ship has been fully repaired; check must happen before calling this function. 
         */
        void RemoveShip() {
            delete this->currentShip;
            this->currentShip = NULL;
            this->repairTime = 0;
        }

        /**
         * @brief Return the time to repair the current ship.
         * 
         * @return Integer.
         */
        int TimeToRepair() const {
            return this->repairTime;
        }

        /**
         * @brief Decrements the repair counter by one.
         * 
         * Will continue whether or not zero has been reached; check before or after this function for appropriate response.
         */
        void DecrementRepairCounter() {
            this->repairTime--;
        }

        /** 
         * @brief Return boolean status of this Bay.
         * 
         * @return false if current ship pointer is NULL.
         * @return true if current ship pointer is not NULL.
         */
        bool IsFull() const {
            return (this->CurrentShip() == NULL ? false : true);
        }

        /**
         * @brief Return a string representation of this object.
         * 
         * @return std::string.
         */
        std::string toString() const;

    private:
        /**
         * @brief Stores the character representation of this Bay.
         */
        char designation;

        /**
         * @brief Pointer to the ship currently docked.
         */
        Ship *currentShip;

        /**
         * @brief Counter for how long the current ship will take to repair.
         */
        int repairTime;

        /**
         * @brief Set the current ship pointer. 
         * 
         * @param cs ship pointer to the Ship to be docked at this Bay.
         */
        void CurrentShip(Ship* cs) {
            this->currentShip = cs;
        }

        /**
         * @brief Calculate the total time it will take to repair the current ship.
         */
        void CalculateRepairTime();

        /**
         * @brief Set the designation of this Bay.
         * 
         * @param char representation of this Bay.
         */
        void Designation(char d) {
            this->designation = d;
        }
};

#endif 