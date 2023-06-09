//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_LEX_ANALYZER_IMPL_STRINGDOUBLEBUFFERLEXICALANALYZER_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_LEX_ANALYZER_IMPL_STRINGDOUBLEBUFFERLEXICALANALYZER_H

#include "DoubleBufferLexicalAnalyzer.h"

#include <sstream>

/**
 * @brief A concrete implementation of a lexical analyzer that stores a
 * string in memory and analyzes it for tokens
 */
class StringDoubleBufferLexicalAnalyzer : public DoubleBufferLexicalAnalyzer {
private:
  std::istringstream data{""};

protected:
  long fillBuffer(
      char* bufferStart,
      long numElements
  ) override;

public:
  StringDoubleBufferLexicalAnalyzer(const std::string& _data, std::unique_ptr<Lexicon> _lexicon);
};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_LEX_ANALYZER_IMPL_STRINGDOUBLEBUFFERLEXICALANALYZER_H
