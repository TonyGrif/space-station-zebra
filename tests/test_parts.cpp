#include <gtest/gtest.h>

#include "station/part.h"

TEST(PartsTest, TestConstructor)
{
    Part testingPart;
    Part idPart(3);
    Part fullPart(5, true);

    ASSERT_EQ(testingPart.PartId(), 1);
    ASSERT_FALSE(testingPart.IsBroken());

    ASSERT_EQ(idPart.PartId(), 3);
    ASSERT_FALSE(idPart.IsBroken());

    ASSERT_EQ(fullPart.PartId(), 5);
    ASSERT_TRUE(fullPart.IsBroken());
}

TEST(PartsTest, TestPartID)
{
    Part testingPart(123);
    Part secondTestingPart(4);

    ASSERT_EQ(testingPart.PartId(), 123);
    ASSERT_EQ(secondTestingPart.PartId(), 4);
    ASSERT_NE(testingPart.PartId(), secondTestingPart.PartId());

    ASSERT_FALSE(testingPart.IsBroken());
    ASSERT_FALSE(secondTestingPart.IsBroken());
}

TEST(PartsTest, TestIsBroken)
{
    Part testingPart;

    ASSERT_FALSE(testingPart.IsBroken());
    ASSERT_EQ(testingPart.PartId(), 1);

    testingPart.IsBroken(true);

    ASSERT_TRUE(testingPart.IsBroken());
    ASSERT_EQ(testingPart.PartId(), 1);
}

TEST(PartsTest, TestEquivalenceOp)
{
    Part testingPart, secondTestingPart;
    Part greaterPart(3);
    Part brokenPart(1, true);

    ASSERT_TRUE(testingPart == secondTestingPart);
    ASSERT_TRUE(secondTestingPart == testingPart);

    ASSERT_FALSE(testingPart == greaterPart);
    ASSERT_FALSE(testingPart == brokenPart);
}

TEST(PartsTest, TestLessThanOp)
{
    Part defPart, defPart2;

    ASSERT_FALSE(defPart < defPart2);
    defPart2.IsBroken(true);
    ASSERT_FALSE(defPart < defPart2);

    Part largeID(404);
    ASSERT_TRUE(defPart < largeID);
    ASSERT_FALSE(largeID < defPart);

    Part negID(-404);
    ASSERT_TRUE(negID < largeID);
    ASSERT_TRUE(negID < defPart);
}

TEST(PartsTest, TestToString)
{
    Part testingPart;
    std::string value = testingPart.toString();

    ASSERT_TRUE(value.find(std::to_string(testingPart.PartId())) != std::string::npos);
    ASSERT_TRUE(value.find(std::to_string(testingPart.IsBroken())) != std::string::npos);
}
