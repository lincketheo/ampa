//
// Created by theo on 6/8/23.
//

#ifndef PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_DOUBLEBUFFERLEXICALANALYZER_H
#define PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_DOUBLEBUFFERLEXICALANALYZER_H

// Local includes
#include "ampa/lex/analyzer/LexicalAnalyzer.h"

// External includes
#include <memory>

#define DOUBLE_BUFFER_LEXICAL_ANALYZER_BUFFER_SIZE 4096

/**
 * @brief An abstract version of LexicalAnalyzer
 * that uses two buffers to scan some input for tokens
 * Abstract because implementations should choose how to
 * implement the function to _fill_ the buffers.
 */
class DoubleBufferLexicalAnalyzer : public LexicalAnalyzer {
private:
  // Buffers to hold data
  char buffer1[DOUBLE_BUFFER_LEXICAL_ANALYZER_BUFFER_SIZE]{};
  char buffer2[DOUBLE_BUFFER_LEXICAL_ANALYZER_BUFFER_SIZE]{};

  // The current size (data read on last read) of each buffer
  uint32_t buffer1Size;
  uint32_t buffer2Size;

  // Reference to left and right to find next token
  char *left{buffer1};
  char *right{buffer1};

protected:
  virtual long fillBuffer(
      char* bufferStart,
      long numElements) = 0;

  explicit DoubleBufferLexicalAnalyzer(std::unique_ptr<Lexicon> _lexicon);

public:
  GetNextTokenResult getNextToken() override;
};

#endif //PROOF_LIBS_AMPA_INCLUDE_AMPA_ANALYZER_IMPL_DOUBLEBUFFERLEXICALANALYZER_H
