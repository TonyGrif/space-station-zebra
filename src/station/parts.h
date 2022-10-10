#ifndef PARTS_H 
#define PARTS_H

#include <string>

/**
 * Parts class.
 * 
 * Parts class to later make up a ships class.
 * This class is responsible for generating a part (its id and health status).
 */
class Part
{
    public:
        /**
         * Default constructor.
         */
        Part();

        /**
         * Non default constructor.
         * 
         * @param int sets the part id.
         * @param bool sets the broken status, optional.
         */
        Part(int, bool = false);

        /**
         * Return the part id.
         * 
         * @return the part id.
         */
        int PartId() const {
            return this->partId;
        }

        /**
         * Set the status of this parts health.
         * Note: Leaving public due to potential future use to change over repair time.
         * 
         * @param bool sets the status of health based on this parameter.
         */
        void IsBroken(bool ib) {
            this->isBroken = ib;
        }

        /**
         * Return the status of this parts health.
         * 
         * @return the boolean health status of this part.
         */
        bool IsBroken() const {
            return this->isBroken;
        }

        /**
         * Equivalence operator. 
         * 
         * @return true if both the part id and the heath status are the same.
         */
        bool operator==(const Part&) const;

        /**
         * Less than operator.
         * 
         * @return true if LHS part id comes after RHS part id.
         */
        bool operator<(const Part&) const;

        /**
         * Return a string representation of this object.
         * 
         * @return string of this object.
         */
        std::string toString() const;

    private:
        /**
         * Integer representation of this part object.
         */
        int partId;

        /**
         * Boolean status of this part's health.
         */
        bool isBroken;

        /**
         * Sets the part id.
         * 
         * @param int sets the part id.
         */
        void PartId(int id) {
            this->partId = id;
        }
};

#endif 