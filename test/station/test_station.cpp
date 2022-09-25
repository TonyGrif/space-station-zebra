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

TEST(StationTest, TestAddToBay)
{
    Station defaultStation;
    Ship battleship, tank(2), stealth(3), last(4);
    Ship* bPtr = &battleship;
    Ship* tPtr = &tank;
    Ship* sPtr = &stealth;
    Ship* fPtr = &last;

    for(int x = 0; x < NUM_OF_REPAIR_BAYS; x++) {
        ASSERT_FALSE(defaultStation.Bays()[x].IsFull());
    }

    // Add all the ships to the bays
    defaultStation.AddShipToBay(bPtr);
    defaultStation.AddShipToBay(tPtr);
    defaultStation.AddShipToBay(sPtr);

    ASSERT_TRUE(defaultStation.Bays()[0].IsFull());

    ASSERT_TRUE(defaultStation.WaitLine().empty());
    // Add in one more, should add to the queue
    defaultStation.AddShipToBay(fPtr);
    ASSERT_FALSE(defaultStation.WaitLine().empty());
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

    // Adding to queue to ensure difference
    testStation.AddShipToQueue(fPtr);
    ASSERT_NE(testStation.WaitLine(), testQueue);
    ASSERT_EQ(testStation.WaitLine().size(), 3);

    // Testing other variables to ensure no changes
    ASSERT_EQ(testStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(testStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(testStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(testStation.StationID(), "Zebra");
}

TEST(StationTest, TestAddToQueue)
{
    Station defaultStation;
    // Ship variables
    Ship ship1, ship2;
    Ship* sPtr1 = &ship1;
    Ship* sPtr2 = &ship2;

    // Testing default state. 
    ASSERT_TRUE(defaultStation.WaitLine().empty());

    // Adding to queue
    defaultStation.AddShipToQueue(sPtr1);
    ASSERT_EQ(defaultStation.WaitLine().size(), 1);

    // Adding another to queue
    defaultStation.AddShipToQueue(sPtr2);
    ASSERT_EQ(defaultStation.WaitLine().size(), 2);

    // Testing all other variables
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
}

TEST(StationTest, TestStationPop)
{
    Station defaultStation;
    // Ship variables
    Ship ship1, ship2;
    Ship* sPtr1 = &ship1;
    Ship* sPtr2 = &ship2;

    // Testing default state. 
    ASSERT_TRUE(defaultStation.WaitLine().empty());

    // Adding to queue
    defaultStation.AddShipToQueue(sPtr1);
    defaultStation.AddShipToQueue(sPtr2);

    // Begin pop
    defaultStation.RemoveShipFromQueue();
    ASSERT_EQ(defaultStation.WaitLine().size(), 1);

    defaultStation.RemoveShipFromQueue();
    ASSERT_TRUE(defaultStation.WaitLine().empty());

    // Testing all other variables
    ASSERT_EQ(defaultStation.Bays()[0].Designation(), 'A');
    ASSERT_EQ(defaultStation.Bays()[1].Designation(), 'B');
    ASSERT_EQ(defaultStation.Bays()[2].Designation(), 'C');

    ASSERT_EQ(defaultStation.StationID(), "Zebra");
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