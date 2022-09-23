#include <gtest/gtest.h>

#include "../../src/station/ships.h"

TEST(ShipTest, TestDefaultConstructor)
{
    Ship defaultShip;

    ASSERT_EQ(defaultShip.ShipID(), 1);
    ASSERT_EQ(defaultShip.Type(), 'A');
}

TEST(ShipTest, TestNonDefaultConstructor)
{
    Ship defaultShip, nonDefaultShip(7);

    // Compare the two ships
    ASSERT_NE(defaultShip.ShipID(), nonDefaultShip.ShipID());
    ASSERT_EQ(nonDefaultShip.ShipID(), 7);

    ASSERT_EQ(defaultShip.Type(), nonDefaultShip.Type());
}

TEST(ShipTest, TestNonDefaultCharConstructor)
{
    Ship defaultShip, nonDefaultShip('E');

    // Compare two ships
    ASSERT_NE(defaultShip.Type(), nonDefaultShip.Type());
    ASSERT_EQ(nonDefaultShip.Type(), 'E');

    ASSERT_EQ(defaultShip.ShipID(), nonDefaultShip.ShipID());
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
    ASSERT_EQ(defaultShip.Type(), 'A');
}

TEST(ShipTest, TestShipType)
{
    Ship defaultShip;

    // Test default set
    ASSERT_EQ(defaultShip.Type(), 'A');

    // Testing post set
    defaultShip.Type('Z');
    ASSERT_NE(defaultShip.Type(), 'A');
    ASSERT_EQ(defaultShip.Type(), 'Z');

    // Ensure no other variables were changed
    ASSERT_EQ(defaultShip.ShipID(), 1);
}

TEST(ShipTest, TestFullConstructor)
{
    Ship defaultShip, nonDefaultShip(7, 'E');

    ASSERT_NE(defaultShip.ShipID(), nonDefaultShip.ShipID());
    ASSERT_NE(defaultShip.Type(), nonDefaultShip.Type());

    ASSERT_EQ(nonDefaultShip.ShipID(), 7);
    ASSERT_EQ(nonDefaultShip.Type(), 'E');
}

TEST(ShipTest, TestToString)
{
    Ship defaultShip;

    std::string value = defaultShip.toString();

    ASSERT_TRUE(value.find(std::to_string(defaultShip.ShipID())) != std::string::npos);
    ASSERT_TRUE(value.find(defaultShip.Type()) != std::string::npos);
}