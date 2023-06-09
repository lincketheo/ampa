//
// Created by theo on 6/8/23.
//

#include "ampa/lex/analyzer/impl/StringDoubleBufferLexicalAnalyzer.h"

StringDoubleBufferLexicalAnalyzer::StringDoubleBufferLexicalAnalyzer(
    const std::string &_data,
    std::unique_ptr<Lexicon> _lexicon)
    : DoubleBufferLexicalAnalyzer(std::move(_lexicon)),
      data(std::istringstream(_data)) {}

long StringDoubleBufferLexicalAnalyzer::fillBuffer(
    char *bufferStart,
    long numElements
) {
  data.read(bufferStart, numElements);
  return data.gcount();
}
