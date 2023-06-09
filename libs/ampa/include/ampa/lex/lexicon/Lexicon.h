//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICON_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICON_H

// External includes
#include <cstdio>
#include <map>
#include <memory>

// Local includes
#include "ampa/lex/Token.h"

/**
 * @brief A result for fetch token in Lexicon. If
 * hit is true, there was a token that was found that matches the
 * string, otherwise, token should be ignored.
 */
struct LexiconLexemeHit {
  bool hit{false};
  Token token = Token("");
};

class Lexicon {
protected:
public:
  virtual ~Lexicon() = default;
  virtual LexiconLexemeHit prodToken(const std::string&) = 0;
};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICON_H
