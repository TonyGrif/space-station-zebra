#include <gtest/gtest.h>

#include <memory>

#include "station/repairBay.h"

TEST(RepairBayTest, TestBayConstructor)
{
    RepairBay bay;
    RepairBay idBay('Z');
    RepairBay fullBay('C', std::make_unique<Ship>(123));

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_EQ(nullptr, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);

    ASSERT_EQ(idBay.Designation(), 'Z');
    ASSERT_EQ(nullptr, idBay.CurrentShip());
    ASSERT_EQ(idBay.TimeToRepair(), 0);

    ASSERT_EQ(fullBay.Designation(), 'C');
    ASSERT_FALSE(fullBay.CurrentShip() == nullptr);
    ASSERT_NE(fullBay.TimeToRepair(), 0);
    ASSERT_EQ(fullBay.CurrentShip()->ShipID(), 123);
}

TEST(RepairBayTest, TestBayDesignation)
{
    RepairBay bay, bay2('Z');
    ASSERT_EQ(bay.Designation(), 'A');

    ASSERT_NE(bay2.Designation(), 'A');
    ASSERT_EQ(bay2.Designation(), 'Z');

    ASSERT_EQ(nullptr, bay.CurrentShip());
    ASSERT_EQ(nullptr, bay2.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay2.TimeToRepair(), 0);
}

TEST(RepairBayTest, TestAddShip)
{
    RepairBay bay;
    ASSERT_EQ(nullptr, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay.Designation(), 'A');

    bay.AddShip(std::make_unique<Ship>());

    ASSERT_FALSE(bay.CurrentShip() == nullptr);
    ASSERT_NE(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay.Designation(), 'A');
}

TEST(RepairBayTest, TestCurrentShip)
{
    RepairBay bay;
    ASSERT_EQ(nullptr, bay.CurrentShip());
    ASSERT_EQ(bay.TimeToRepair(), 0);
    ASSERT_EQ(bay.Designation(), 'A');

    bay.AddShip(std::make_unique<Ship>());

    ASSERT_FALSE(bay.CurrentShip() == nullptr);
    ASSERT_EQ(bay.Designation(), 'A');
}

TEST(RepairBayTest, TestCalcRepairTime)
{
    RepairBay bay;
    ASSERT_EQ(bay.TimeToRepair(), 0);

    bay.AddShip(std::make_unique<Ship>());
    ASSERT_NE(bay.TimeToRepair(), 0);

    ASSERT_EQ(bay.Designation(), 'A');
    ASSERT_TRUE(bay.CurrentShip() != nullptr);
}

TEST(RepairBayTest, TestRemoveShip)
{
    RepairBay defaultBay('A', std::make_unique<Ship>());

    ASSERT_EQ(defaultBay.Designation(), 'A');
    ASSERT_TRUE(defaultBay.CurrentShip() != nullptr);
    ASSERT_NE(defaultBay.TimeToRepair(), 0);

    defaultBay.RemoveShip();
    ASSERT_TRUE(defaultBay.CurrentShip() == nullptr);
    ASSERT_EQ(defaultBay.TimeToRepair(), 0);

    ASSERT_EQ(defaultBay.Designation(), 'A');
}

TEST(RepairBayTest, TestDecrementCounter)
{
    RepairBay defaultBay;

    defaultBay.AddShip(std::make_unique<Ship>());

    int defaultCounter = defaultBay.TimeToRepair();
    ASSERT_EQ(defaultBay.Designation(), 'A');
    ASSERT_TRUE(defaultBay.CurrentShip() != nullptr);

    defaultBay.DecrementRepairCounter();
    ASSERT_NE(defaultCounter, defaultBay.TimeToRepair());
    ASSERT_EQ(defaultCounter - 1, defaultBay.TimeToRepair());

    ASSERT_EQ(defaultBay.Designation(), 'A');
    ASSERT_TRUE(defaultBay.CurrentShip() != nullptr);
}

TEST(RepairBayTest, TestIsFull)
{
    RepairBay nullBay, nonNullBay;
    nonNullBay.AddShip(std::make_unique<Ship>());

    ASSERT_FALSE(nullBay.IsFull());
    ASSERT_TRUE(nonNullBay.IsFull());
}

TEST(RepairBayTest, TestToString)
{
    RepairBay defaultBay;

    std::string value = defaultBay.toString();

    // Assert that it contains the designation and the current ship id
    ASSERT_TRUE(value.find(defaultBay.Designation()) != std::string::npos);
    // Contains string empty because the current ship pointer is null
    ASSERT_TRUE(value.find("Empty"));

    defaultBay.AddShip(std::make_unique<Ship>());
    value = defaultBay.toString();
    ASSERT_TRUE(value.find(defaultBay.CurrentShip()->toString()) != std::string::npos);

    ASSERT_EQ(defaultBay.Designation(), 'A');
}
