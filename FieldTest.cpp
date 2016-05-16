/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}
/*TEST(FieldTest, placeMineOutBounds)
{
	Field minefield;
       bool caught=false;
	 try
	{
          minefield.placeMine(11,11);
          caught=true;
	}
	catch(int err)
       {
        err=minefield.get(11,11);
        ASSERT_EQ(err,-1);
       }
}*/
TEST(FieldTest,issafeimplementedminehidden)
{
	Field minefield;
        bool caught=false;
        try
	{
          minefield.isSafe(4,5);
          caught=true;
	}
	catch(int err)
       {
         caught=true;
       }
       ASSERT_TRUE(caught);
}
TEST(FieldTest,issafeimplementedemptyhidden)
{
	Field minefield;
        bool caught=false;
        try
	{
          minefield.isSafe(3,7);
          caught=true;
	}
	catch(int err)
       {
         caught=true;
       }
       ASSERT_TRUE(caught);
}
TEST(FieldTest,issafeimplementedemptyhidden1)
{
	Field minefield;
        bool caught=false;
        try
	{
          minefield.isSafe(11,11);
          //caught=true;
	}
	catch(int err)
       {
         caught=true;
       }
       ASSERT_TRUE(caught);
}
