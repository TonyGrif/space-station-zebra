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
}

TEST(ShipTest, TestGenerateParts)
{
    Ship defaultShip;
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