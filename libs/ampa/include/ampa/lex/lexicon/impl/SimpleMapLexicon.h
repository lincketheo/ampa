//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_SIMPLEMAPLEXICON_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_SIMPLEMAPLEXICON_H

// External includes
#include <unordered_map>
#include <utility>
#include <vector>

// Local includes
#include "ampa/lex/lexicon/Lexicon.h"

class SimpleMapLexicon : Lexicon {
private:
  std::unordered_map<std::string, const Token> tokenNameToTokenMap{};
  void insertToken(const std::string &key, const Token &token);

public:
  SimpleMapLexicon();
  explicit SimpleMapLexicon(const std::unordered_map<std::string, const Token>& initialLexicon);
  LexiconLexemeHit prodToken(const std::string &) override;
  size_t maxTokenStringSize{0};
};

const std::vector<std::string> initialTokens = {"and", "or"};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_SIMPLEMAPLEXICON_H
