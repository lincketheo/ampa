//
// Created by theo on 6/8/23.
//

// Local includes
#include "ampa/lex/lexicon/impl/SimpleMapLexicon.h"

SimpleMapLexicon::SimpleMapLexicon() {
  for (const auto &key : initialTokens) {
    insertToken(key, Token(key));
  }
}

SimpleMapLexicon::SimpleMapLexicon(const std::unordered_map<std::string, const Token> &initialLexicon) {
  for (const auto &pair : initialLexicon) {
    insertToken(pair.first, pair.second);
  }
}

LexiconLexemeHit SimpleMapLexicon::prodToken(const std::string &tokenCandidate) {
  LexiconLexemeHit ret;
  ret.hit = false;

  auto result = tokenNameToTokenMap.find(tokenCandidate);
  if (result != tokenNameToTokenMap.end()) {
    ret.token = result->second;
    ret.hit = true;
  }

  return ret;
}

void SimpleMapLexicon::insertToken(const std::string &key, const Token &token) {
  if (key.size() > maxTokenStringSize) {
    maxTokenStringSize = key.size();
  }
  tokenNameToTokenMap.insert({key, token});
}
