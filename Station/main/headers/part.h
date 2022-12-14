#ifndef PARTS_H 
#define PARTS_H

#include <string>

/**
 * Part class.
 * 
 * This class is responsible for creating a part with an id and health status.
 */
class Part
{
    public:
        /**
         * Default constructor.
         * 
         * @param id sets the ID of this Part.
         * @param b sets the health status of this Part.
         */
        Part(int id = 1, bool b = false);

        /**
         * @brief Return the ID of this Part.
         * 
         * @return Integer. 
         */
        int PartId() const {
            return this->partId;
        }

        /**
         * Set the health status of this Part.
         * 
         * @param ib sets the health status of this Part.
         */
        void IsBroken(bool ib) {
            this->isBroken = ib;
        }

        /**
         * Return the health status of this Part.
         * 
         * @return Boolean.
         */
        bool IsBroken() const {
            return this->isBroken;
        }

        /**
         * Equivalence operator. 
         * 
         * @return True if both the part id and the heath status are the same.
         */
        bool operator==(const Part&) const;

        /**
         * Less than operator.
         * 
         * @return True if LHS part ID comes after RHS part ID.
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
         * Set the ID for this Part.
         * 
         * @param int sets the ID of this Part.
         */
        void PartId(int id) {
            this->partId = id;
        }
};

#endif 