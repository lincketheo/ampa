//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICALANALYZER_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICALANALYZER_H

// Local includes
#include "ampa/lex/Token.h"
#include "ampa/lex/lexicon/Lexicon.h"

/**
 * @brief A result for get next token. If not complete, token
 * is valid. If complete - token should be ignored and is garbage.
 */
struct GetNextTokenResult {
  bool complete{true};
  Token token = Token("");
};

/**
 * @brief A LexicalAnalyzer simply returns the next token
 * given a lexicon.
 */
class LexicalAnalyzer {
public:
  LexicalAnalyzer() = delete;

  /**
   * @brief The primary api function. Fetches a token from some sort
   * of data source. The implementation of this data source is abstract
   * @return A Get Next Token Result
   */
  virtual GetNextTokenResult getNextToken() = 0;
};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_LEXICALANALYZER_H
