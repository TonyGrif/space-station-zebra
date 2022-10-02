#include <gtest/gtest.h>

#include "../../src/station/repairBay.h"

TEST(RepairBayTest, TestBayConstructor)
{
    // Ensure all variables are set correctly
    RepairBay bay;

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_EQ(NULL, bay.CurrentShip());
}

TEST(RepairBayTest, TestNonDefaultBayConstructor)
{
    RepairBay defaultBay;
    RepairBay nonDefaultBay('Z');

    // Testing set value
    ASSERT_NE(defaultBay.Designation(), nonDefaultBay.Designation());
    ASSERT_EQ(nonDefaultBay.Designation(), 'Z');

    // Testing remaining variables
    ASSERT_EQ(defaultBay.CurrentShip(), nonDefaultBay.CurrentShip());
    ASSERT_EQ(NULL, nonDefaultBay.CurrentShip());
}

TEST(RepairBayTest, TestBayDesignation)
{
    // Testing default designation
    RepairBay bay, bay2('Z');
    ASSERT_EQ(bay.Designation(), 'A');

    // Testing designation accessor and mutator
    ASSERT_NE(bay2.Designation(), 'A');
    ASSERT_EQ(bay2.Designation(), 'Z');

    // Testing all other variables to ensure no changes
    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(NULL, bay2.CurrentShip());
}

TEST(RepairBayTest, TestCurrentShip)
{
    // Testing default current ship (null)
    RepairBay bay;
    ASSERT_EQ(NULL, bay.CurrentShip());

    // Testing result when adding ship pointer
    Ship battleship;
    Ship* testingPtr = &battleship;
    bay.CurrentShip(testingPtr);

    ASSERT_EQ(bay.CurrentShip(), &battleship);

    // Testing all other variables
    ASSERT_EQ(bay.Designation(), 'A');
}

TEST(RepairBayTest, TestIsFull)
{
    Ship battleship;
    Ship* testingPtr = &battleship;
    RepairBay nullBay, nonNullBay;
    nonNullBay.CurrentShip(testingPtr);

    // Testing return
    ASSERT_FALSE(nullBay.IsFull());
    ASSERT_TRUE(nonNullBay.IsFull());
}

TEST(RepairBayTest, TestToString)
{
    RepairBay defaultBay;
    Ship battleship;
    Ship* testingPtr = &battleship;
    defaultBay.CurrentShip(testingPtr);

    std::string value = defaultBay.toString();

    // Assert that it contains the designation and the current ship id
    ASSERT_TRUE(value.find(defaultBay.Designation()) != std::string::npos);
    // Contains string empty because the current ship pointer is null
    ASSERT_TRUE(value.find("Empty"));

    defaultBay.CurrentShip(testingPtr);

    // Contains the current ship information
    ASSERT_TRUE(value.find(std::to_string(defaultBay.CurrentShip()->ShipID())));
    ASSERT_TRUE(value.find(defaultBay.CurrentShip()->Type()) != std::string::npos);

    // Ensure no values were changed
    ASSERT_EQ(defaultBay.Designation(), 'A');
}