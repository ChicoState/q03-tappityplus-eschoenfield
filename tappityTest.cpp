/**
 * Unit Test suite
**/

#include <gtest/gtest.h>
#include "tappity.h"
using namespace std;

class tappityTest : public ::testing::Test
{
	protected:
		tappityTest(){} 
		virtual ~tappityTest(){} 
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(tappityTest, smoke_test)
{
    ASSERT_TRUE(true);
}
TEST(tappityTest, empty_strings) //happy
{
    tappity test("");
	test.entry("");
	int expected = 0;
	int actual = test.length_difference();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, equal_len_strings)
{
    tappity test("hello");
	test.entry("hello");
	int expected = 0;
	int actual = test.length_difference();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, diff_len_strings)
{
    tappity test("hello5");
	test.entry("hello");
	int expected = 1;
	int actual = test.length_difference();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, acc_100_strings)
{
    tappity test("Applejacks");
	test.entry("Applejacks");
	double expected = 100.0;
	double actual = test.accuracy();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, acc_50_strings)
{
    tappity test("Applejacks");
	test.entry("Apple");
	double expected = 50.0;
	double actual = test.accuracy();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, acc_00_strings)
{
    tappity test("Applejacks");
	test.entry("zeroPercasdasd");
	double expected = 0.0;
	double actual = test.accuracy();
	ASSERT_EQ(actual, expected);
}
TEST(tappityTest, acc_empty_strings)
{
    tappity test("");
	test.entry("");
	double expected = 0.0;
	double actual = test.accuracy();
	ASSERT_EQ(actual, expected);
}