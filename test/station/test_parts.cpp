#include <gtest/gtest.h>

#include "../../src/station/parts.h"

TEST(PartsTest, TestDefaultConstructor)
{
    Parts defaultPart;

    ASSERT_EQ(defaultPart.PartId(), 1);
    ASSERT_FALSE(defaultPart.IsBroken());
}

TEST(PartsTest, TestNonDefaultIntConstructor)
{
    Parts defaultPart, nonDefaultShip(3);

    ASSERT_NE(defaultPart.PartId(), nonDefaultShip.PartId());
    ASSERT_EQ(nonDefaultShip.PartId(), 3);
    ASSERT_EQ(defaultPart.IsBroken(), nonDefaultShip.IsBroken());
    ASSERT_FALSE(nonDefaultShip.IsBroken());
}

TEST(PartsTest, TestPartID)
{
    Parts defaultPart, differentPartID(4);

    ASSERT_EQ(defaultPart.PartId(), 1);

    ASSERT_EQ(differentPartID.PartId(), 4);

    ASSERT_EQ(defaultPart.IsBroken(), false);
    ASSERT_EQ(differentPartID.IsBroken(), false);
}

TEST(PartsTest, TestIsBroken)
{
    Parts defaultPart;

    ASSERT_EQ(defaultPart.IsBroken(), false);

    defaultPart.IsBroken(true);
    ASSERT_EQ(defaultPart.IsBroken(), true);

    ASSERT_EQ(defaultPart.PartId(), 1);
}

TEST(PartsTest, TestToString)
{
    Parts defaultPart;
    std::string value = defaultPart.toString();

    ASSERT_TRUE(value.find(std::to_string(defaultPart.PartId())) != std::string::npos);
    ASSERT_TRUE(value.find(std::to_string(defaultPart.IsBroken())) != std::string::npos);
}