#include <gtest/gtest.h>

#include "../../src/station/station.h"

using ::testing::Ne;

TEST(StationTest, TestStationConstructor)
{
    Station testDefault;

    ASSERT_EQ(testDefault.Bays()[0].Designation(), 'A');
    ASSERT_EQ(testDefault.Bays()[1].Designation(), 'B');
    ASSERT_EQ(testDefault.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(testDefault.WaitLine().empty());

    ASSERT_EQ(testDefault.StationID(), "Zebra");
}

TEST(StationTest, TestStationNonDefaultConstuctor)
{
    Station defaultStation;
    Station nonDefaultStation("Otter");

    // Testing set values
    ASSERT_EQ(nonDefaultStation.StationID(), "Otter");
    ASSERT_NE(defaultStation.StationID(), nonDefaultStation.StationID());

    // Testing other variables
    ASSERT_EQ(nonDefaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(nonDefaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(nonDefaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(nonDefaultStation.WaitLine().empty());
}

TEST(StationTest, TestRepairTimeCycle)
{
    Station defaultStation;
    Ship* testPtr;

    // Add a new ship to each bay
    // Add three extra to the queue
    for(auto& i : defaultStation.Bays()) {
        testPtr = new Ship();
        defaultStation.AddShip(testPtr);

        testPtr = new Ship();
        defaultStation.AddShip(testPtr);
    }

    // Grab the first repair time number
    int repairNumber = defaultStation.Bay(0).TimeToRepair();

    // Ensure changes to the repair time counter
    defaultStation.RepairTimeStep();
    ASSERT_NE(repairNumber, defaultStation.Bay(0).TimeToRepair());

    Ship *storePtr;

    while(defaultStation.Bay(0).TimeToRepair() != 0) {
        defaultStation.RepairTimeStep();
    }
    storePtr = defaultStation.WaitLine().front();
    defaultStation.RepairTimeStep();

    ASSERT_EQ(storePtr, defaultStation.Bay(0).CurrentShip());

    // Ensure no other changes
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    delete testPtr, storePtr;
}

TEST(StationTest, TestStationBays)
{
    Station defaultStation;

    // Testing default values
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    // Ensuring no other variables were changed
    ASSERT_EQ(defaultStation.StationID(), "Zebra");
    ASSERT_TRUE(defaultStation.WaitLine().empty());
}

TEST(StationTest, TestAddShip)
{
    Station defaultStation;
    Ship s1, s2, s3, s4, s5;
    Ship* s1p = &s1, 
        *s2p = &s2,
        *s3p = &s3,
        *s4p = &s4,
        *s5p = &s5;

    defaultStation.AddShip(s1p);
    defaultStation.AddShip(s2p);
    defaultStation.AddShip(s3p);

    // Ensure each bay is full
    for(auto& i : defaultStation.Bays()) {
        ASSERT_TRUE(i.CurrentShip() != NULL);
    }
    // Ensure queue remains empty
    ASSERT_TRUE(defaultStation.WaitLine().empty());

    defaultStation.AddShip(s4p);
    defaultStation.AddShip(s5p);

    for(auto& i : defaultStation.Bays()) {
        ASSERT_TRUE(i.CurrentShip() != NULL);
    }
    ASSERT_EQ(defaultStation.WaitLine().size(), 2);
}

TEST(StationTest, TestStationDesignation)
{
    Station defaultStation, nonDefaultStation("Otter");

    // Testing default designation
    ASSERT_EQ(defaultStation.StationID(), "Zebra");

    // Testing post change
    ASSERT_NE(nonDefaultStation.StationID(), "Zebra");
    ASSERT_EQ(nonDefaultStation.StationID(), "Otter");

    // Ensuring no other variables were changed
    ASSERT_EQ(nonDefaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(nonDefaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(nonDefaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(nonDefaultStation.WaitLine().empty());
}

TEST(StationTest, TestToString)
{
    Station defaultStation;
    std::string value;

    value = defaultStation.toString();

    // Contains Station information at the top
    ASSERT_TRUE(value.find(defaultStation.StationID()) != std::string::npos);

    // Testing that important data is included in our report
    for(int x = 0; x < NUM_OF_REPAIR_BAYS; x++)
    {
        ASSERT_TRUE(value.find(defaultStation.Bays()[x].Designation()) != std::string::npos);
    }
    //ASSERT_TRUE(value.find(std::to_string(defaultStation.Bays()[0].CurrentShip()->ShipID())));


    // Ensure no variables were changed
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(defaultStation.WaitLine().empty());

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}