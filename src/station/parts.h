#ifndef PARTS_H 
#define PARTS_H

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
        Parts(int, bool);

        /**
         * Set the part id.
         */
        void PartId(int id) {
            this->partId = id;
        }

        /**
         * Return the part id.
         */
        int PartId() const {
            return this->partId;
        }

        /**
         * Set the status of this parts health.
         */
        void IsBroken(bool ib) {
            this->isBroken = ib;
        }

        /**
         * Return the status of this parts health
         */
        bool IsBroken() const {
            return this->isBroken;
        }

    private:
        /**
         * Integer representation of this part object.
         */
        int partId;

        /**
         * Boolean status of this part's health.
         */
        bool isBroken;
};

#endif 