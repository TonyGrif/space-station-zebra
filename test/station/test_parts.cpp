#include <gtest/gtest.h>

#include "../../src/station/parts.h"

Part *testingPart, *secondTestingPart;

TEST(PartsTest, TestDefaultConstructor)
{
    testingPart = new Part();

    ASSERT_EQ(testingPart->PartId(), 1);
    ASSERT_FALSE(testingPart->IsBroken());

    delete testingPart;
    delete secondTestingPart;
}

TEST(PartsTest, TestNonDefaultIntConstructor)
{
    testingPart = new Part();
    secondTestingPart = new Part(3);

    ASSERT_NE(testingPart->PartId(), secondTestingPart->PartId());
    ASSERT_EQ(secondTestingPart->PartId(), 3);
    ASSERT_EQ(testingPart->IsBroken(), secondTestingPart->IsBroken());
    ASSERT_FALSE(testingPart->IsBroken());

    delete testingPart;
    delete secondTestingPart;
}

TEST(PartsTest, TestPartID)
{
    testingPart = new Part();
    secondTestingPart = new Part(4);

    ASSERT_EQ(testingPart->PartId(), 1);

    ASSERT_EQ(secondTestingPart->PartId(), 4);

    ASSERT_EQ(testingPart->IsBroken(), false);
    ASSERT_EQ(secondTestingPart->IsBroken(), false);

    delete testingPart;
    delete secondTestingPart;
}

TEST(PartsTest, TestIsBroken)
{
    testingPart = new Part();

    ASSERT_EQ(testingPart->IsBroken(), false);

    testingPart->IsBroken(true);
    ASSERT_EQ(testingPart->IsBroken(), true);

    ASSERT_EQ(testingPart->PartId(), 1);

    delete testingPart;
    delete secondTestingPart;
}

TEST(PartsTest, TestToString)
{
    testingPart = new Part();
    std::string value = testingPart->toString();

    ASSERT_TRUE(value.find(std::to_string(testingPart->PartId())) != std::string::npos);
    ASSERT_TRUE(value.find(std::to_string(testingPart->IsBroken())) != std::string::npos);

    ASSERT_EQ(testingPart->PartId(), 1);
    ASSERT_EQ(testingPart->IsBroken(), false);

    delete testingPart;
    delete secondTestingPart;
}