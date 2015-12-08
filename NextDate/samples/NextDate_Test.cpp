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

TEST_F(NextDateTest, C0Test)
{
	
	EXPECT_EQ("Invalid Input",TellNextDate(1996,1,0));
	EXPECT_EQ("1996/2/1",TellNextDate(1996,1,31));
	EXPECT_EQ("1996/1/2",TellNextDate(1996,1,1));
	EXPECT_EQ("Invalid Input",TellNextDate(1996,4,0));
	EXPECT_EQ("1996/5/1",TellNextDate(1996,4,30));
	EXPECT_EQ("1996/4/6",TellNextDate(1996,4,5));
	EXPECT_EQ("1996/12/2",TellNextDate(1996,12,1));
	EXPECT_EQ("1997/1/1",TellNextDate(1996,12,31));
	EXPECT_EQ("Invalid Input",TellNextDate(1996,12,32));
	EXPECT_EQ("1996/2/28",TellNextDate(1996,2,27));
	EXPECT_EQ("Invalid Input",TellNextDate(1996,2,0));
	EXPECT_EQ("1996/2/29",TellNextDate(1996,2,28));
	EXPECT_EQ("1997/3/1",TellNextDate(1997,2,28));
	EXPECT_EQ("1996/3/1",TellNextDate(1996,2,29));
	EXPECT_EQ("Invalid Input",TellNextDate(1997,2,29));
}

TEST_F(NextDateTest, C1Test)
{
	//1,2,3	
	EXPECT_EQ("1996/2/1",TellNextDate(1996,1,31));
	//1,4,5
	EXPECT_EQ("Invalid Input",TellNextDate(1996,4,31));
	//1,6
	EXPECT_EQ("1996/12/31",TellNextDate(1996,12,30));
	//1,6,7
	EXPECT_EQ("1997/1/1",TellNextDate(1996,12,31));
	//1,8
	EXPECT_EQ("1996/2/28",TellNextDate(1996,2,27));
	//1,8,9,10,12
	EXPECT_EQ("1996/3/1",TellNextDate(1996,2,29));
	//1,8,9,11
	EXPECT_EQ("1996/2/29",TellNextDate(1996,2,28));
}
