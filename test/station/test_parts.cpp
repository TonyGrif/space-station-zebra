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
    Parts defaultPart, nonDefaultShip(3, true);

    ASSERT_NE(defaultPart.PartId(), nonDefaultShip.PartId());
    ASSERT_EQ(nonDefaultShip.PartId(), 3);
    ASSERT_NE(defaultPart.IsBroken(), nonDefaultShip.IsBroken());
    ASSERT_TRUE(nonDefaultShip.IsBroken());
}

TEST(PartsTest, TestPartID)
{
    Parts defaultPart;

    ASSERT_EQ(defaultPart.PartId(), 1);

    defaultPart.PartId(4);
    ASSERT_EQ(defaultPart.PartId(), 4);

    ASSERT_EQ(defaultPart.IsBroken(), false);
}

TEST(PartsTest, TestIsBroken)
{
    Parts defaultPart;

    ASSERT_EQ(defaultPart.IsBroken(), false);

    defaultPart.IsBroken(true);
    ASSERT_EQ(defaultPart.IsBroken(), true);

    ASSERT_EQ(defaultPart.PartId(), 1);
}