#include "gtest/gtest.h"
#include "gmock/gmock.h"

/*

  Common Test macros

  // Boolean expressions
  EXPECT_TRUE(boolean_expr);
  EXPECT_FALSE(boolean_expr);

  // Relational expressions
  EXPECT_EQ(expr1, expr2);  // ==
  EXPECT_NE(expr1, expr2);  // !=
  EXPECT_GT(expr1, expr2);  // >
  EXPECT_GE(expr1, expr2);  // >=
  EXPECT_LT(expr1, expr2);  // <
  EXPECT_LE(expr1, expr2);  // <=

  // String comparison
  EXPECT_STREQ(string1, string2); // ==
  EXPECT_STRNE(string1, string2); // !=

   // Within 4 ULPs (unit of least precision)
  EXPECT_FLOAT_EQ(float1, float2);
  EXPECT_DOUBLE_EQ(double1, double2);

  // Choose custom precision
  EXPECT_NEAR(float1, float2, abs_error);

  // All the above macros are also available with 'ASSERT_'.
  // 'EXPECT_' macros will continue executing a test even if the evaluated item
  // fails. 'ASSERT_' on the other hand will terminate the current test
  // immediately. Useful to prevent crashes down the line, e.g. if a device is
  // not available.

  // Manually set the test to failed (although probably hardly used)
  FAIL();

  See also http://google.github.io/googletest/ for more information.

*/


/*
  Tests with the same suite name are grouped together.
  The first argument of the 'GTEST_TEST' macro is the suite and the second one
  the test name.
  Combinations of suite.test can only be used once.
  Avoid using underbars ('_') in suite and test names, as recommended by
  googletest.
*/


// Normal test
GTEST_TEST(TestSuiteName, testName) {
}


// Disabled test which will not be run on default (prefix is DISABLED_)
GTEST_TEST(SomeOtherSuite, DISABLED_testName) {
}
