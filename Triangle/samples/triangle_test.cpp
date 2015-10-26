#include "triangle.h"
#include "gtest/gtest.h"

class TriangleTest : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
};

TEST_F(TriangleTest, BoundaryValueTesting)
{
	EXPECT_EQ(IsTriangle(1,1,1),"Scalene");
}
