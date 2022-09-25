#include <gtest/gtest.h>

#include "../../src/station/ships.h"

TEST(ShipTest, TestDefaultConstructor)
{
    Ship defaultShip;

    ASSERT_EQ(defaultShip.ShipID(), 1);
    ASSERT_TRUE(defaultShip.Type() == 'H'
        || defaultShip.Type() == 'F'
        || defaultShip.Type() == 'K'
        || defaultShip.Type() == 'R'
        || defaultShip.Type() == 'O');


    ASSERT_FALSE(defaultShip.GetParts().empty());
    // Note: Does not test for the odd/even mix
    int minVal, maxVal;
    if(defaultShip.Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(defaultShip.Type() == 'F') {
        minVal = 75;
        maxVal= 125;
    }
    else if(defaultShip.Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(defaultShip.Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    for(auto& i : defaultShip.GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
    }
}

TEST(ShipTest, TestNonDefaultConstructor)
{
    Ship defaultShip, nonDefaultShip(7);

    // Compare the two ships
    ASSERT_NE(defaultShip.ShipID(), nonDefaultShip.ShipID());
    ASSERT_EQ(nonDefaultShip.ShipID(), 7);

    ASSERT_TRUE(nonDefaultShip.Type() == 'H'
        || nonDefaultShip.Type() == 'F'
        || nonDefaultShip.Type() == 'K'
        || nonDefaultShip.Type() == 'R'
        || nonDefaultShip.Type() == 'O');

    ASSERT_FALSE(defaultShip.GetParts().empty());
    int minVal, maxVal;
    if(nonDefaultShip.Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(nonDefaultShip.Type() == 'F') {
        minVal = 75;
        maxVal= 125;
    }
    else if(nonDefaultShip.Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(nonDefaultShip.Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    for(auto& i : nonDefaultShip.GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
    }
}

TEST(ShipTest, TestGenerateParts)
{
    Ship defaultShip;

    ASSERT_FALSE(defaultShip.GetParts().empty());
    ASSERT_TRUE(defaultShip.GetParts().size() >= 1);
    int minVal, maxVal;
    if(defaultShip.Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(defaultShip.Type() == 'F') {
        minVal = 75;
        maxVal= 125;
    }
    else if(defaultShip.Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(defaultShip.Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    for(auto& i : defaultShip.GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
    }
}

TEST(ShipTest, TestShipID)
{
    Ship defaultShip;

    // Test default set
    ASSERT_EQ(defaultShip.ShipID(), 1);

    // Testing post set
    defaultShip.ShipID(24);
    ASSERT_NE(defaultShip.ShipID(), 1);
    ASSERT_EQ(defaultShip.ShipID(), 24);

    // Ensure no other variables were changed
    ASSERT_TRUE(defaultShip.Type() == 'H'
        || defaultShip.Type() == 'F'
        || defaultShip.Type() == 'K'
        || defaultShip.Type() == 'R'
        || defaultShip.Type() == 'O');
}

TEST(ShipTest, TestShipType)
{
    Ship defaultShip;

    ASSERT_TRUE(defaultShip.Type() == 'H'
        || defaultShip.Type() == 'F'
        || defaultShip.Type() == 'K'
        || defaultShip.Type() == 'R'
        || defaultShip.Type() == 'O');

    ASSERT_EQ(defaultShip.ShipID(), 1);
}

TEST(ShipTest, TestToString)
{
    Ship defaultShip;

    std::string value = defaultShip.toString();

    ASSERT_TRUE(value.find(std::to_string(defaultShip.ShipID())) != std::string::npos);
    ASSERT_TRUE(value.find(defaultShip.Type()) != std::string::npos);
}