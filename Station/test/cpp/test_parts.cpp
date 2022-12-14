#include <gtest/gtest.h>

#include "../../main/headers/parts.h"

TEST(PartsTest, TestDefaultConstructor)
{
    Part testingPart;

    ASSERT_EQ(testingPart.PartId(), 1);
    ASSERT_FALSE(testingPart.IsBroken());
}

TEST(PartsTest, TestNonDefaultConstructor)
{
    Part testingPart;
    Part secondTestingPart(3);
    Part thirdTestingPart(5, true);

    ASSERT_NE(testingPart.PartId(), secondTestingPart.PartId());
    ASSERT_EQ(secondTestingPart.PartId(), 3);
    ASSERT_EQ(testingPart.IsBroken(), secondTestingPart.IsBroken());
    ASSERT_FALSE(testingPart.IsBroken());

    ASSERT_EQ(thirdTestingPart.PartId(), 5);
    ASSERT_TRUE(thirdTestingPart.IsBroken());
}

TEST(PartsTest, TestPartID)
{
    Part testingPart;
    Part secondTestingPart(4);

    ASSERT_EQ(testingPart.PartId(), 1);
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
    Part testingPart;
    Part secondTestingPart;
    Part greaterPart(3);
    Part brokenPart(1, true);

    ASSERT_TRUE(testingPart == secondTestingPart);

    ASSERT_FALSE(testingPart == greaterPart);

    ASSERT_FALSE(testingPart == brokenPart);
}

TEST(PartsTest, TestLessThanOp)
{
    Part testingPart(3);
    Part secondTestingPart(4);
    Part thirdTestingPart(5);

    ASSERT_TRUE(testingPart < secondTestingPart);
    ASSERT_TRUE(testingPart < thirdTestingPart);
    ASSERT_FALSE(thirdTestingPart < secondTestingPart);
}

TEST(PartsTest, TestToString)
{
    Part testingPart;
    std::string value = testingPart.toString();

    ASSERT_TRUE(value.find(std::to_string(testingPart.PartId())) != std::string::npos);
    ASSERT_TRUE(value.find(std::to_string(testingPart.IsBroken())) != std::string::npos);

    ASSERT_EQ(testingPart.PartId(), 1);
    ASSERT_EQ(testingPart.IsBroken(), false);
}