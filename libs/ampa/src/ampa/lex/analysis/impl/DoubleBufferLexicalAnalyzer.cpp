#include "ampa/lex/analyzer/impl/DoubleBufferLexicalAnalyzer.h"
//
// Created by theo on 6/8/23.
//

DoubleBufferLexicalAnalyzer::DoubleBufferLexicalAnalyzer(std::unique_ptr<Lexicon> _lexicon)
: LexicalAnalyzer(std::move(_lexicon)){
  buffer1Size = fillBuffer(left, DOUBLE_BUFFER_LEXICAL_ANALYZER_BUFFER_SIZE);

}

GetNextTokenResult DoubleBufferLexicalAnalyzer::getNextToken() {
  GetNextTokenResult result;

  return result;
}
