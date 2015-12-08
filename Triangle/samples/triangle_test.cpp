#include "triangle.h"
#include "gtest/gtest.h"

class TriangleTest : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
};

TEST_F(TriangleTest, BoundaryValueTesting)
{
	EXPECT_EQ(IsTriangle(1,1,1),"Equilateral");
        EXPECT_EQ(IsTriangle(0,1,1),"Not a Triangle");
        EXPECT_EQ(IsTriangle(50,50,70),"Isosceles");
	EXPECT_EQ(IsTriangle(200,200,200),"Equilateral");
	EXPECT_EQ(IsTriangle(100,200,100),"Not a Triangle");
 	EXPECT_EQ(IsTriangle(1,150,1),"Not a Triangle");
	EXPECT_EQ(IsTriangle(6,7,8),"Scalene");
}

TEST_F(TriangleTest, EquivalenceClassTesting)
{
	EXPECT_EQ(IsTriangle(5,5,5),"Equilateral");
	EXPECT_EQ(IsTriangle(2,2,3),"Isosceles");
	EXPECT_EQ(IsTriangle(3,4,5),"Scalene");
	EXPECT_EQ(IsTriangle(4,1,2),"Not a Triangle");
}

TEST_F(TriangleTest, EdgeTesing)
{
	EXPECT_EQ(IsTriangle(1,1,1),"Equilateral");
	EXPECT_EQ(IsTriangle(200,200,200),"Equilateral");
	EXPECT_EQ(IsTriangle(50,50,1),"Isosceles");
	EXPECT_EQ(IsTriangle(199,200,200),"Isosceles");
	EXPECT_EQ(IsTriangle(198,199,200),"Scalene");
	EXPECT_EQ(IsTriangle(1,2,1),"Not a Triangle");
}

TEST_F(TriangleTest, DecistionTableTest)
{
	//a != b
	EXPECT_EQ(IsTriangle(1,2,3),"Not a Triangle");
	//a = b
	EXPECT_EQ(IsTriangle(2,2,3),"Isosceles");
	//b != c
	EXPECT_EQ(IsTriangle(200,150,140),"Scalene");
	//a == c
	EXPECT_EQ(IsTriangle(40,40,40),"Equilateral");


}

TEST_F(TriangleTest, C0Test)
{
	EXPECT_EQ("Not a Triangle",IsTriangle(0,0,0));
	EXPECT_EQ("Not a Triangle",IsTriangle(1,0,0));
	EXPECT_EQ("Not a Triangle",IsTriangle(1,1,0));
	EXPECT_EQ("Equilateral",IsTriangle(3,3,3));
	EXPECT_EQ("Scalene",IsTriangle(3,4,5));
	EXPECT_EQ("Not a Triangle",IsTriangle(1,2,3));
	EXPECT_EQ("Isosceles",IsTriangle(2,3,2));

}

TEST_F(TriangleTest, C1Test)
{
	//1,2
	EXPECT_EQ("Not a Triangle",IsTriangle(5,0,0));
	//2,3
	EXPECT_EQ("Not a Triangle",IsTriangle(5,3,0));
	//3,4
	EXPECT_EQ("Not a Triangle",IsTriangle(5,3,1));
	//4,5
	EXPECT_EQ("Equilateral",IsTriangle(5,5,5));
	//5,6
	EXPECT_EQ("Scalene",IsTriangle(33,43,53));
	//1,2,3
	EXPECT_EQ("Not a Triangle",IsTriangle(50,33,0));
	//2,3,4
	EXPECT_EQ("Not a Triangle",IsTriangle(50,13,13));
	//4,5,6
	EXPECT_EQ("Isosceles",IsTriangle(14,13,13));
	//1,2,3,4
	EXPECT_EQ("Not a Triangle",IsTriangle(1,3,1));
	//1,2,3,4,5,6
	EXPECT_EQ("Isosceles",IsTriangle(140,150,140));
	
}
