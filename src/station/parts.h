#ifndef PARTS_H 
#define PARTS_H

#include <string>

class Parts
{
    public:
        /**
         * Default constructor
         */
        Parts();

        /**
         * Non default constructor.
         */
        Parts(int);

        /**
         * Return the part id.
         */
        int PartId() const {
            return this->partId;
        }

        /**
         * Set the status of this parts health.
         * Note: Leaving public due to potential future use to change over repair time.
         */
        void IsBroken(bool ib) {
            this->isBroken = ib;
        }

        /**
         * Return the status of this parts health.
         */
        bool IsBroken() const {
            return this->isBroken;
        }

        /**
         * Return a string representation of this object.
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
         * Set the part id.
         */
        void PartId(int id) {
            this->partId = id;
        }

};

#endif 