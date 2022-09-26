#include <iostream>

#include "station/station.h"

int main()
{
    Station station;
    int timeCycles;
    bool proceed;
    Ship* newShipPtr;

    // Generation settings for the number of ships to arrive w/ each time cycle
    std::default_random_engine generator;
    std::poisson_distribution<int> pDistribution(1.2);

    /* Display Title */
    std::cout << "==================================" << std::endl;
    std::cout << "      Space Station Zebra         " << std::endl;
    std::cout << "==================================" << std::endl;

    do
    {   
        /* Determine time cycles */
        std::cout << "Enter how many time cycles would you like to run: ";
        std::cin >> timeCycles;
        std::cout << std::endl;

        for(int x = 0; x < timeCycles; x++)
        {
            // Determine number of ships entering the station
            int shipNum = pDistribution(generator);

            // Process them into the station
            for(int x = 0; x < shipNum; x++) {
                newShipPtr = new Ship();
                station.AddShip(newShipPtr);
            }
        }

        std::cout << station.toString();
        std::cout << std::endl << std::endl;

        std::cout << "Would you like to continue? \n";
        std::cout << "    0 for no, 1 for yes: ";
        std::cin >> proceed;
        std::cout << std::endl;
    } while (proceed == true);

    return 0;
}
