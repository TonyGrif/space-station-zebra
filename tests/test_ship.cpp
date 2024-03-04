#include <gtest/gtest.h>

#include "station/ships.h"

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

    Ship IDShip(88);

    ASSERT_EQ(IDShip.ShipID(), 88);
    ASSERT_NE(IDShip.ShipID(), testingShip.ShipID());
    ASSERT_TRUE(IDShip.Type() == 'H'
        || IDShip.Type() == 'F'
        || IDShip.Type() == 'K'
        || IDShip.Type() == 'R'
        || IDShip.Type() == 'O');

    ASSERT_FALSE(IDShip.GetParts().empty());
}

TEST(ShipTest, TestShipID)
{
    Ship testingShip;
    Ship secondShip(24);

    ASSERT_EQ(testingShip.ShipID(), 1);

    ASSERT_NE(secondShip.ShipID(), testingShip.ShipID());
    ASSERT_EQ(secondShip.ShipID(), 24);

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

    bool isEven = false;
    bool isOdd = false;
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
        isEven = true;
    }
    else if(testingPtr->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
        isOdd = true;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    int lastVal = 0;
    for(auto& i : testingPtr->GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
        ASSERT_TRUE(i.PartId() >= lastVal) << testingPtr->toString();

        if(isEven)
        {
            ASSERT_TRUE(i.PartId() % 2 == 0);
        }
        else if(isOdd)
        {
            ASSERT_TRUE(i.PartId() % 2 != 0);
        }
        lastVal = i.PartId();
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
