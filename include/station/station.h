#ifndef STATION_H
#define STATION_H

#include "repairBay.h"
#include "ships.h"

#include <array>
#include <memory>
#include <queue>

const int NUM_OF_REPAIR_BAYS = 3;

/**
 * @brief Station class.
 *
 * Responsible for managing a collection of repair bays and a wait line to the bays.
 */
class Station
{
public:
    /**
     * @brief Data structure to be used to create a colleciton of Bays.
     *
     * Number is determined by a constant supplied.
     */
    using bayCollection = std::array<RepairBay, NUM_OF_REPAIR_BAYS>;

    /**
     * @brief Data structure to be used to create a line of Ships.
     */
    using lineCollection = std::queue<std::unique_ptr<Ship>>;

    /**
     * @brief Default constructor for Station.
     *
     * @param id sets the identification of this Station.
     */
    Station(std::string id = "Zebra");

    /**
     * @brief Returns this Station's ID.
     *
     * @return std::string.
     */
    std::string StationID() const { return this->stationID; }

    /**
     * @brief Return the Repair Bay collection.
     *
     * @return bayCollection.
     */
    const bayCollection& Bays() const { return this->bays; }

    /**
     * @brief Runs through all the bays and handles one time cycle worth of repairs if needed.
     */
    void RepairTimeStep();

    /**
     * @brief Add ship to the appropriate state (bay or queue).
     *
     * @param sPtr Ship pointer; ownership is transferred to the Station.
     */
    void AddShip(std::unique_ptr<Ship> sPtr);

    /**
     * @brief Return the collection of ships located in the wait line.
     *
     * @return lineCollection.
     */
    const lineCollection& WaitLine() const { return this->waitLine; }

    /**
     * @brief Return a string representation of this Station.
     *
     * @return std::string.
     */
    std::string toString() const;

private:
    /**
     * @brief String representation of this Station's identification.
     */
    std::string stationID;

    /**
     * @brief Collection of repair bays.
     */
    bayCollection bays;

    /**
     * @brief Queue of ship pointers.
     *
     * Occupants are added whenever a bay is unavailable.
     * Occupant is freed when a bay is made available.
     */
    lineCollection waitLine;

    /**
     * @brief Set this Station's ID.
     *
     * @param string sets the ID.
     */
    void StationID(std::string sid) { this->stationID = sid; }

    /**
     * @brief Attempt to add the ship to the bay.
     *
     * @param sPtr Ship pointer to be added; moved into a Bay on success, left untouched on failure.
     * @return true if ship was added.
     * @return false if the ship was not added.
     */
    bool AddShipToBay(std::unique_ptr<Ship>& sPtr);

    /**
     * @brief Add a ship to this wait line.
     *
     * @param sPtr ship pointer to be added; ownership is transferred to the wait line.
     */
    void AddShipToQueue(std::unique_ptr<Ship> sPtr) { this->waitLine.push(std::move(sPtr)); }

    /**
     * @brief Remove a ship from the top of the queue.
     */
    void RemoveShipFromQueue() { this->waitLine.pop(); }
};

#endif