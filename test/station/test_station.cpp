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

TEST(StationTest, TestStationBayBasedConstructor)
{
    Station defaultStation;
    Station nonDefaultStation(RepairBay('Z'), RepairBay('Y'), RepairBay('X'));

    // Testing set values
    ASSERT_NE(nonDefaultStation.Bays()[0].Designation(), 'A');
    ASSERT_NE(nonDefaultStation.Bays()[1].Designation(), 'B');
    ASSERT_NE(nonDefaultStation.Bays()[2].Designation(), 'C');    
    
    ASSERT_EQ(nonDefaultStation.Bays()[0].Designation(), 'Z');
    ASSERT_EQ(nonDefaultStation.Bays()[1].Designation(), 'Y');
    ASSERT_EQ(nonDefaultStation.Bays()[2].Designation(), 'X');

    // Testing other variables
    ASSERT_EQ(defaultStation.StationID(), nonDefaultStation.StationID());

    ASSERT_TRUE(nonDefaultStation.WaitLine().empty());
}

TEST(StationTest, TestStationBays)
{
    Station defaultStation;

    // Testing default values
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    // Testing values post change
    defaultStation.Bays(RepairBay('Z'), RepairBay('Y'), RepairBay('X'));

    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'Z');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'Y');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'X');

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

TEST(StationTest, TestStationWaitList) 
{
    // Default Station
    Station testStation;
    // Ship variables
    Ship ship1, ship2, finalShip;
    Ship* sPtr1 = &ship1;
    Ship* sPtr2 = &ship2;
    Ship* fPtr = &finalShip;
    // Setting up testing queue
    std::queue<Ship*> testQueue;
    testQueue.push(sPtr1);
    testQueue.push(sPtr2);

    // Testing default state
    ASSERT_TRUE(testStation.WaitLine().empty());

    // Testing post set
    testStation.WaitLine(testQueue);
    ASSERT_TRUE(testStation.WaitLine() == testQueue);
    ASSERT_EQ(testStation.WaitLine().size(), 2);

    // Testing other variables to ensure no changes
    ASSERT_EQ(testStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(testStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(testStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(testStation.StationID(), "Zebra");
}

TEST(StationTest, TestStationDesignation)
{
    Station defaultStation;

    // Testing default designation
    ASSERT_EQ(defaultStation.StationID(), "Zebra");

    // Testing post change
    defaultStation.StationID("Otter");
    ASSERT_NE(defaultStation.StationID(), "Zebra");
    ASSERT_EQ(defaultStation.StationID(), "Otter");

    // Ensuring no other variables were changed
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_TRUE(defaultStation.WaitLine().empty());
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