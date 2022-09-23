#include <gtest/gtest.h>

#include "../../src/station/parts.h"

TEST(PartsTest, TestDefaultConstructor)
{
    Parts defaultShip;

    ASSERT_EQ(defaultShip.PartId(), 1);
    ASSERT_FALSE(defaultShip.IsBroken());
}

TEST(PartsTest, TestNonDefaultIntConstructor)
{
    Parts defaultShip, nonDefaultShip(3, true);

    ASSERT_NE(defaultShip.PartId(), nonDefaultShip.PartId());
    ASSERT_EQ(nonDefaultShip.PartId(), 3);
    ASSERT_NE(defaultShip.IsBroken(), nonDefaultShip.IsBroken());
    ASSERT_TRUE(nonDefaultShip.IsBroken());
}