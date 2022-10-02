#include <gtest/gtest.h>

#include "../../src/station/ships.h"

Ship *testingPtr, *secondPtr;

// Utility function for pointer deletion
void cleanUpShips() {
    delete testingPtr;
    delete secondPtr;
}

TEST(ShipTest, TestDefaultConstructor)
{
    testingPtr = new Ship();

    ASSERT_EQ(testingPtr->ShipID(), 1);
    ASSERT_TRUE(testingPtr->Type() == 'H'
        || testingPtr->Type() == 'F'
        || testingPtr->Type() == 'K'
        || testingPtr->Type() == 'R'
        || testingPtr->Type() == 'O');


    ASSERT_FALSE(testingPtr->GetParts().empty());

    // Note: Does not test for the odd/even mix
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

    cleanUpShips();
}

TEST(ShipTest, TestNonDefaultConstructor)
{
    testingPtr = new Ship();
    secondPtr = new Ship(7);

    // Compare the two ships
    ASSERT_NE(testingPtr->ShipID(), secondPtr->ShipID());
    ASSERT_EQ(secondPtr->ShipID(), 7);

    ASSERT_TRUE(secondPtr->Type() == 'H'
        || secondPtr->Type() == 'F'
        || secondPtr->Type() == 'K'
        || secondPtr->Type() == 'R'
        || secondPtr->Type() == 'O');

    ASSERT_FALSE(secondPtr->GetParts().empty());
    int minVal, maxVal;
    if(secondPtr->Type() == 'H') {
        minVal = 1;
        maxVal= 100;
    }
    else if(secondPtr->Type() == 'F') {
        minVal = 75;
        maxVal= 150;
    }
    else if(secondPtr->Type() == 'K') {
        minVal = 2;
        maxVal= 200;
    }
    else if(secondPtr->Type() == 'R') {
        minVal = 1;
        maxVal= 199;
    }
    else {
        minVal = 200;
        maxVal = 999;
    }

    for(auto& i : secondPtr->GetParts())
    {
        ASSERT_TRUE(i.PartId() >= minVal && i.PartId() <= maxVal);
    }

    cleanUpShips();
}

TEST(ShipTest, TestSetType)
{
    testingPtr = new Ship();

    ASSERT_FALSE(testingPtr->GetParts().empty());

    // TODO: Write a test case that will ensure all of these are valid within one test run
    ASSERT_TRUE(testingPtr->Type() == 'H'
        || testingPtr->Type() == 'F'
        || testingPtr->Type() == 'K'
        || testingPtr->Type() == 'R'
        || testingPtr->Type() == 'O');

    cleanUpShips();
}

TEST(ShipTest, TestGenerateParts)
{
    testingPtr = new Ship();

    ASSERT_FALSE(testingPtr->GetParts().empty());
    ASSERT_TRUE(testingPtr->GetParts().size() >= 1);

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

    cleanUpShips();
}

TEST(ShipTest, TestShipID)
{
    testingPtr = new Ship();
    secondPtr = new Ship(24);

    // Test default set
    ASSERT_EQ(testingPtr->ShipID(), 1);

    // Testing non default set
    ASSERT_NE(secondPtr->ShipID(), 1);
    ASSERT_EQ(secondPtr->ShipID(), 24);

    // Ensure no other variables were changed
    ASSERT_TRUE(testingPtr->Type() == 'H'
        || testingPtr->Type() == 'F'
        || testingPtr->Type() == 'K'
        || testingPtr->Type() == 'R'
        || testingPtr->Type() == 'O');

    cleanUpShips();
}

TEST(ShipTest, TestToString)
{
    testingPtr = new Ship();

    std::string value = testingPtr->toString();

    ASSERT_TRUE(value.find(std::to_string(testingPtr->ShipID())) != std::string::npos);
    ASSERT_TRUE(value.find(testingPtr->Type()) != std::string::npos);
}