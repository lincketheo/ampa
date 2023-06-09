//
// Created by theo on 5/27/23.
//

// Project includes
#include "ampa/lex/scanner/impl/StringScanner.h"

// External includes
#include <gtest/gtest.h>

TEST(Scanner, DoesNothingOnGoodInput) {
  StringScanner s = StringScanner{"Hello World"};
  s.generateScannedOutput();
  EXPECT_STREQ("Hello World", s.printOutputString().c_str());
}

TEST(Scanner, RemovesSpaces) {
  StringScanner s = StringScanner{"Hello  World"};
  s.generateScannedOutput();
  EXPECT_STREQ("Hello World", s.printOutputString().c_str());
}

TEST(Scanner, ReplacesNewLineWithSpace) {
  StringScanner s = StringScanner{"Hello\nWorld"};
  s.generateScannedOutput();
  EXPECT_STREQ("Hello World", s.printOutputString().c_str());
}

TEST(Scanner, AssortmentOfSpaces) {
  StringScanner s = StringScanner{"Hello W or    ld I  l   o   v e c++ !"};
  s.generateScannedOutput();
  EXPECT_STREQ("Hello W or ld I l o v e c++ !", s.printOutputString().c_str());
}

TEST(Scanner, StopsOnNullTerminator) {
  StringScanner s = StringScanner{"Hello\0world"};
  s.generateScannedOutput();
  EXPECT_STREQ("Hello", s.printOutputString().c_str());
}
