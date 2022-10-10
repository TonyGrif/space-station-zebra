#include <gtest/gtest.h>

#include "../../src/station/ships.h"

TEST(ShipTest, TestDefaultConstructor)
{
    Ship testingShip;

    ASSERT_EQ(testingShip.ShipID(), 1);
    ASSERT_TRUE(testingShip.Type() == 'H'
        || testingShip.Type() == 'F'
        || testingShip.Type() == 'K'
        || testingShip.Type() == 'R'
        || testingShip.Type() == 'O');

    ASSERT_FALSE(testingShip.GetParts().empty());
}

TEST(ShipTest, TestNonDefaultConstructor)
{
    Ship testingShip;
    Ship secondShip(7);

    // Compare the two ships
    ASSERT_NE(testingShip.ShipID(), secondShip.ShipID());
    ASSERT_EQ(secondShip.ShipID(), 7);

    ASSERT_TRUE(secondShip.Type() == 'H'
        || secondShip.Type() == 'F'
        || secondShip.Type() == 'K'
        || secondShip.Type() == 'R'
        || secondShip.Type() == 'O');

    ASSERT_FALSE(secondShip.GetParts().empty());
}

TEST(ShipTest, TestShipID)
{
    Ship testingShip;
    Ship secondShip(24);

    // Test default set
    ASSERT_EQ(testingShip.ShipID(), 1);

    // Testing non default set
    ASSERT_NE(secondShip.ShipID(), testingShip.ShipID());
    ASSERT_EQ(secondShip.ShipID(), 24);

    // Ensure no other variables were changed
    ASSERT_TRUE(secondShip.Type() == 'H'
        || secondShip.Type() == 'F'
        || secondShip.Type() == 'K'
        || secondShip.Type() == 'R'
        || secondShip.Type() == 'O');

    ASSERT_FALSE(secondShip.GetParts().empty());
}

TEST(ShipTest, TestSetType)
{
    Ship *testingPtr;

    // Efficient? No!
    // Works? Probably!
    do { testingPtr = new Ship(); }
    while(testingPtr->Type() != 'H');
    ASSERT_EQ(testingPtr->Type(), 'H');
    delete testingPtr;

    do { testingPtr = new Ship(); }
    while(testingPtr->Type() != 'F');
    ASSERT_EQ(testingPtr->Type(), 'F');
    delete testingPtr;

    do { testingPtr = new Ship(); }
    while(testingPtr->Type() != 'K');
    ASSERT_EQ(testingPtr->Type(), 'K');
    delete testingPtr;

    do { testingPtr = new Ship(); }
    while(testingPtr->Type() != 'R');
    ASSERT_EQ(testingPtr->Type(), 'R');
    delete testingPtr;

    do { testingPtr = new Ship(); }
    while(testingPtr->Type() != 'O');
    ASSERT_EQ(testingPtr->Type(), 'O');
    delete testingPtr;
}

TEST(ShipTest, TestGenerateParts)
{
    Ship* testingPtr = new Ship();

    ASSERT_FALSE(testingPtr->GetParts().empty());
    ASSERT_TRUE(testingPtr->GetParts().size() >= 1);

    // Note: does not test for odd/even
    // Note: does not test for all values in each run
    int minVal, maxVal;
    if(testingPtr->Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(testingPtr->Type() == 'F') {
        minVal = 75;
        maxVal= 150;
    }
    else if(testingPtr->Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(testingPtr->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    for(auto& i : testingPtr->GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
    }

    if(testingPtr->Type() != 'K' && testingPtr->Type() != 'R' && testingPtr->Type() != 'O') {
        ASSERT_EQ(testingPtr->GetParts().size(), (maxVal-minVal)+1);
    }
    else {
        ASSERT_EQ(testingPtr->GetParts().size(), 100);
    }

    delete testingPtr;
}

TEST(ShipTest, TestToString)
{
    Ship testingShip;

    std::string value = testingShip.toString();

    ASSERT_TRUE(value.find(std::to_string(testingShip.ShipID())) != std::string::npos);
    ASSERT_TRUE(value.find(testingShip.Type()) != std::string::npos);

    // Contains all broken part info
    for(auto& i : testingShip.GetParts()) {
        if(i.IsBroken()) {
            ASSERT_TRUE(value.find(std::to_string(i.PartId())) != std::string::npos);
            ASSERT_TRUE(value.find(std::to_string(i.IsBroken())) != std::string::npos);
        }
    }
}