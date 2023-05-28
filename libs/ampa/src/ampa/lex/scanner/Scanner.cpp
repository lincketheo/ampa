//
// Created by theo on 5/27/23.
//

// Project includes
#include "ampa/lex/scanner/Scanner.h"

Scanner::Scanner(
    char _inputStreamTerminal,
    std::unique_ptr<std::istream> _inputStream,
    std::unique_ptr<std::ostream> _outputStream
)
    : inputStreamTerminal{_inputStreamTerminal},
      inputStream{std::move(_inputStream)},
      outputStream{std::move(_outputStream)} {}

void Scanner::generateScannedOutput() {
  char prevOutputChar{'\0'};
  char readC;
  bool inComment = false;
  while (inputStream->peek() != inputStreamTerminal) {
    (*inputStream) >> std::noskipws >> readC;

    // Convert new lines to spaces
    if (readC == '\n') {
      readC = ' ';
    }

    // Eliminate multiple spaces
    if (prevOutputChar != '\0') {
      if (prevOutputChar == ' ' && readC == ' ') {
        continue;
      }
    }

    prevOutputChar = readC;
    (*outputStream) << readC;
  }
}
