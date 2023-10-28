/**
 * \file    test_runner.cpp
 * \author  Alexander Zoellner
 * \date    20 May 2020
 * \brief   Runs all unit test functions which use the 'TEST' macro.
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
