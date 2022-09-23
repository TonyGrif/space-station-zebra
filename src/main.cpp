#include <iostream>

#include "station/station.h"

int main()
{
    int timeCycles;

    /* Display Title */
    std::cout << "==================================" << std::endl;
    std::cout << "      Space Station Zebra         " << std::endl;
    std::cout << "==================================" << std::endl;

    /* Determine intial time cycles */
    std::cout << "Enter how many time cycles would you like to run: ";
    std::cin >> timeCycles;
    std::cout << std::endl;

    return 0;
}
