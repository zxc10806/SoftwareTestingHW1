#include "NextDate.h"
#include "gtest/gtest.h"

class NextDateTest : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
};

TEST_F(NextDateTest, BoundaryValueTesting)
{
	EXPECT_EQ(TellNextDate(1812,1,3),"1812/1/4");
}
