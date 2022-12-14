#include <gtest/gtest.h>

#include "../../main/headers/repairBay.h"

TEST(RepairBayTest, TestBayConstructor)
{
    // Ensure all variables are set correctly
    RepairBay bay;

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestNonDefaultBayConstructor)
{
    RepairBay defaultBay;
    RepairBay nonDefaultBay('Z');

    Ship battleship;
    Ship* bPtr = &battleship;
    RepairBay shipBay('C', bPtr);

    ASSERT_NE(defaultBay.Designation(), nonDefaultBay.Designation());
    ASSERT_EQ(nonDefaultBay.Designation(), 'Z');

    ASSERT_EQ(shipBay.Designation(), 'C');
    ASSERT_EQ(&battleship, shipBay.CurrentShip());

    ASSERT_EQ(defaultBay.CurrentShip(), nonDefaultBay.CurrentShip());
    ASSERT_EQ(NULL, nonDefaultBay.CurrentShip());
    ASSERT_EQ(nonDefaultBay.TimeToRepair(), 0);

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
    ASSERT_EQ(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay2.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestCurrentShip)
{
    // Testing default current ship (null)
    RepairBay bay;
    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);

    // Testing result when adding ship pointer
    Ship battleship;
    Ship* testingPtr = &battleship;
    bay.CurrentShip(testingPtr);

    ASSERT_EQ(bay.CurrentShip(), &battleship);
    ASSERT_NE(bay.TimeToRepair(), 0);

    // Testing all other variables
    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_NE(bay.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestRemoveShip)
{
    RepairBay defaultBay;
    Ship* testPtr;

    testPtr = new Ship();
    defaultBay.CurrentShip(testPtr);

    ASSERT_TRUE(defaultBay.CurrentShip() != NULL);
    ASSERT_NE(defaultBay.TimeToRepair(), 0);

    defaultBay.RemoveShip();
    ASSERT_EQ(NULL, defaultBay.CurrentShip());
    ASSERT_EQ(defaultBay.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestCalcRepairTime)
{
    RepairBay bay;
    ASSERT_EQ(bay.TimeToRepair(), 0);

    Ship* sPtr = new Ship();
    bay.CurrentShip(sPtr);

    ASSERT_NE(bay.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestDecrementCounter)
{
    RepairBay defaultBay;
    Ship* testPtr;

    testPtr = new Ship();
    defaultBay.CurrentShip(testPtr);

    int defaultCounter = defaultBay.TimeToRepair();

    defaultBay.DecrementRepairCounter();
    ASSERT_NE(defaultCounter, defaultBay.TimeToRepair());
    ASSERT_EQ(defaultCounter-1, defaultBay.TimeToRepair());
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

    std::string value = defaultBay.toString();

    // Assert that it contains the designation and the current ship id
    ASSERT_TRUE(value.find(defaultBay.Designation()) != std::string::npos);
    // Contains string empty because the current ship pointer is null
    ASSERT_TRUE(value.find("Empty"));

    defaultBay.CurrentShip(testingPtr);

    // Ensure no values were changed
    ASSERT_EQ(defaultBay.Designation(), 'A');
}