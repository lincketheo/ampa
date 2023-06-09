//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_TOKEN_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_TOKEN_H

#include <string>
struct Token {
public:
  std::string tokenString;
  explicit Token(std::string tokenString)
      : tokenString{std::move(tokenString)} {}
};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_TOKEN_H
