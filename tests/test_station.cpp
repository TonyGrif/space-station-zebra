#include <gtest/gtest.h>

#include <memory>

#include "station/station.h"

using ::testing::Ne;

TEST(StationTest, TestStationConstructor)
{
    Station defaultStation, idStation("Otter");

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
    ASSERT_EQ(idStation.StationID(), "Otter");
    ASSERT_NE(defaultStation.StationID(), idStation.StationID());

    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(idStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(idStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(idStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(defaultStation.WaitLine().empty());
    ASSERT_TRUE(idStation.WaitLine().empty());
}

TEST(StationTest, TestStationDesignation)
{
    Station defaultStation, nonDefaultStation("Otter");

    ASSERT_EQ(defaultStation.StationID(), "Zebra");

    ASSERT_NE(nonDefaultStation.StationID(), "Zebra");
    ASSERT_EQ(nonDefaultStation.StationID(), "Otter");

    ASSERT_EQ(nonDefaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(nonDefaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(nonDefaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(nonDefaultStation.WaitLine().empty());
}

TEST(StationTest, TestStationBays)
{
    Station defaultStation;

    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
    ASSERT_TRUE(defaultStation.WaitLine().empty());
}

TEST(StationTest, TestRepairTimeCycle)
{
    Station defaultStation;

    // Add a new ship to each bay
    // Add three extra to the queue
    for (auto& i : defaultStation.Bays())
    {
        defaultStation.AddShip(std::make_unique<Ship>());
        defaultStation.AddShip(std::make_unique<Ship>());
    }

    int smallestBay = 0;
    for (int x = 1; x < NUM_OF_REPAIR_BAYS; x++)
    {
        if (defaultStation.Bays()[smallestBay].TimeToRepair() >
            defaultStation.Bays()[x].TimeToRepair())
        {
            smallestBay = x;
        }
    }

    // Grab the first repair time number
    int repairNumber = defaultStation.Bays()[smallestBay].TimeToRepair();

    // Ensure changes to the repair time counter
    defaultStation.RepairTimeStep();
    ASSERT_NE(repairNumber, defaultStation.Bays()[smallestBay].TimeToRepair());

    while (defaultStation.Bays()[smallestBay].TimeToRepair() != 0)
    {
        defaultStation.RepairTimeStep();
    }
    Ship* storePtr = defaultStation.WaitLine().front().get();
    defaultStation.RepairTimeStep();

    ASSERT_EQ(storePtr, defaultStation.Bays()[smallestBay].CurrentShip());

    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');
}

TEST(StationTest, TestAddShip)
{
    Station defaultStation;

    for (int x = 0; x < NUM_OF_REPAIR_BAYS; x++)
    {
        defaultStation.AddShip(std::make_unique<Ship>());
    }

    // Ensure each bay is full
    for (auto& i : defaultStation.Bays())
    {
        ASSERT_TRUE(i.CurrentShip() != nullptr);
    }
    // Ensure queue remains empty
    ASSERT_TRUE(defaultStation.WaitLine().empty());

    defaultStation.AddShip(std::make_unique<Ship>());

    auto lastShip = std::make_unique<Ship>();
    Ship* lastShipRaw = lastShip.get();
    defaultStation.AddShip(std::move(lastShip));

    for (auto& i : defaultStation.Bays())
    {
        ASSERT_TRUE(i.CurrentShip() != nullptr);
        ASSERT_FALSE(i.CurrentShip() == lastShipRaw);
    }
    ASSERT_EQ(defaultStation.WaitLine().size(), 2);
}

TEST(StationTest, TestToString)
{
    Station defaultStation;

    std::string value = defaultStation.toString();

    ASSERT_TRUE(value.find(defaultStation.StationID()) != std::string::npos);

    // Testing that important data is included in our report
    for (int x = 0; x < NUM_OF_REPAIR_BAYS; x++)
    {
        ASSERT_TRUE(value.find(defaultStation.Bays()[x].toString()) != std::string::npos);
    }

    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(defaultStation.WaitLine().empty());

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
}
