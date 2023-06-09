//
// Created by theo on 6/8/23.
//

// External includes
#include <gtest/gtest.h>
#include "ampa/lex/lexicon/impl/SimpleMapLexicon.h"

TEST(SimpleMapLexicon, GoodValuesHitImplicit) {
  SimpleMapLexicon sutImplicit{};
  for (const auto &i : initialTokens) {
    auto ret = sutImplicit.prodToken(i);
    EXPECT_TRUE(ret.hit);
    EXPECT_EQ(ret.token.tokenString, i);
  }
}

TEST(SimpleMapLexicon, BadValueMissesImplicit) {
  SimpleMapLexicon sutImplicit{};
  std::string stringThatDoesntMatch(sutImplicit.maxTokenStringSize + 1, 'a');

  auto ret = sutImplicit.prodToken(stringThatDoesntMatch);

  EXPECT_FALSE(ret.hit);
  EXPECT_NE(ret.token.tokenString, stringThatDoesntMatch);
}

TEST(SimpleMapLexicon, MaxSizeIsCorrectImplicit) {
  SimpleMapLexicon sutImplicit{};
  size_t maxSize{0};
  for (const auto &i : initialTokens) {
    if (i.size() > maxSize) {
      maxSize = i.size();
    }
  }

  EXPECT_EQ(sutImplicit.maxTokenStringSize, maxSize);
}

TEST(SimpleMapLexicon, InitializesCorrectlyExplicitly) {
  SimpleMapLexicon sutExplicit{{
                                   {"foo", Token("bar")},
                                   {"fabz", Token("baz")}}};
  auto ret = sutExplicit.prodToken("foo");
  ASSERT_TRUE(ret.hit);
  ASSERT_EQ(ret.token.tokenString, "bar");

  ret = sutExplicit.prodToken("fabz");
  ASSERT_TRUE(ret.hit);
  ASSERT_EQ(ret.token.tokenString, "baz");

  ret = sutExplicit.prodToken("faz");
  ASSERT_FALSE(ret.hit);
  ASSERT_EQ(sutExplicit.maxTokenStringSize, 4);
}
