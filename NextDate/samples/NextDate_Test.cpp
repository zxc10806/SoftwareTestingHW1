#include "NextDate.h"
#include "gtest/gtest.h"

class NextDateTest : public testing::Test{
	protected:
//virtual void Setup();
//virtual void TearDown();
};

TEST_F(NextDateTest, BoundaryValueTesting)
{
	EXPECT_EQ(TellNextDate(1812,1,1),"1812/1/2");
	EXPECT_EQ(TellNextDate(1812,1,15),"1812/1/16");
	EXPECT_EQ(TellNextDate(2012,1,30),"2012/1/31");
	EXPECT_EQ(TellNextDate(1813,1,31),"1813/2/1");
}

TEST_F(NextDateTest, EquivalenceClassTesting)
{
	//month =>30,31,February
	//day -> 1~28,29,30,31
	//year = 2000, common year, non-century leap year
	
	EXPECT_EQ(TellNextDate(2000,6,14),"2000/6/15");
	EXPECT_EQ(TellNextDate(1996,7,29),"1996/7/30");
	EXPECT_EQ(TellNextDate(2002,2,30),"Invalid Input");
	EXPECT_EQ(TellNextDate(2000,6,31),"Invalid Input");
}

TEST_F(NextDateTest, EdgeTesting)
{

	
	EXPECT_EQ(TellNextDate(1813,1,1),"1813/1/2");
	EXPECT_EQ(TellNextDate(1813,1,31),"1813/2/1");
	EXPECT_EQ(TellNextDate(2000,2,29),"2000/3/1");
	EXPECT_EQ(TellNextDate(1813,1,25),"1813/1/26");
	EXPECT_EQ(TellNextDate(1991,9,31),"Invalid Input");


}

TEST_F(NextDateTest, DecisionTableTest)
{
	
	EXPECT_EQ(TellNextDate(2001,4,15),"2001/4/16");
	EXPECT_EQ(TellNextDate(2001,4,30),"2001/5/1");
	EXPECT_EQ(TellNextDate(2001,4,31),"Invalid Input");
	EXPECT_EQ(TellNextDate(2001,2,29),"Invalid Input");
	EXPECT_EQ(TellNextDate(2001,2,30),"Invalid Input");
	EXPECT_EQ(TellNextDate(2004,2,29),"2004/3/1");
}
