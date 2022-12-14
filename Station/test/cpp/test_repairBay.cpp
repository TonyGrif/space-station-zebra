#include <gtest/gtest.h>

#include "../../main/headers/repairBay.h"

TEST(RepairBayTest, TestBayConstructor)
{
    RepairBay bay;
    RepairBay idBay('Z');
    RepairBay fullBay('C', new Ship(123));

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);

    ASSERT_EQ(idBay.Designation(), 'Z');
    ASSERT_EQ(NULL, idBay.CurrentShip());
    ASSERT_EQ(idBay.TimeToRepair(), 0);

    ASSERT_EQ(fullBay.Designation(), 'C');
    ASSERT_FALSE(fullBay.CurrentShip() == NULL);
    ASSERT_NE(fullBay.TimeToRepair(), 0);
    ASSERT_EQ(fullBay.CurrentShip()->ShipID(), 123);
}

TEST(RepairBayTest, TestBayDesignation)
{
    RepairBay bay, bay2('Z');
    ASSERT_EQ(bay.Designation(), 'A');

    ASSERT_NE(bay2.Designation(), 'A');
    ASSERT_EQ(bay2.Designation(), 'Z');

    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(NULL, bay2.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay2.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestCurrentShip)
{
    RepairBay bay;
    ASSERT_EQ(NULL, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);

    bay.CurrentShip(new Ship);

    ASSERT_FALSE(bay.CurrentShip() == NULL);
    ASSERT_NE(bay.TimeToRepair(), 0);

    ASSERT_EQ(bay.Designation(), 'A');
}

TEST(RepairBayTest, TestRemoveShip)
{
    RepairBay defaultBay('A', new Ship);

    ASSERT_TRUE(defaultBay.CurrentShip() != NULL);
    ASSERT_NE(defaultBay.TimeToRepair(), 0);

    defaultBay.RemoveShip();
    ASSERT_TRUE(defaultBay.CurrentShip() == NULL);
    ASSERT_EQ(defaultBay.TimeToRepair(), 0);

    ASSERT_EQ(defaultBay.Designation(), 'A');
}

TEST(RepairBayTest, TestCalcRepairTime)
{
    RepairBay bay;
    ASSERT_EQ(bay.TimeToRepair(), 0);

    bay.CurrentShip(new Ship);
    ASSERT_NE(bay.TimeToRepair(), 0);

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_TRUE(bay.CurrentShip() != NULL);
}

TEST(RepairBayTest, TestDecrementCounter)
{
    RepairBay defaultBay;

    defaultBay.CurrentShip(new Ship);

    int defaultCounter = defaultBay.TimeToRepair();

    defaultBay.DecrementRepairCounter();
    ASSERT_NE(defaultCounter, defaultBay.TimeToRepair());
    ASSERT_EQ(defaultCounter-1, defaultBay.TimeToRepair());

    ASSERT_EQ(defaultBay.Designation(), 'A');
    ASSERT_TRUE(defaultBay.CurrentShip() != NULL);
}

TEST(RepairBayTest, TestIsFull)
{
    RepairBay nullBay, nonNullBay;
    nonNullBay.CurrentShip(new Ship);

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
    value = defaultBay.toString();
    ASSERT_TRUE(value.find(defaultBay.CurrentShip()->toString()) != std::string::npos);

    ASSERT_EQ(defaultBay.Designation(), 'A');
}