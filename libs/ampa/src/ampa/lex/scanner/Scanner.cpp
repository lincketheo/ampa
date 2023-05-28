//
// Created by theo on 5/27/23.
//

// Project includes
#include <iostream>
#include "ampa/lex/scanner/Scanner.h"

Scanner::Scanner(
    std::unique_ptr<std::istream> _inputStream,
    std::unique_ptr<std::ostream> _outputStream
)
    : inputStream{std::move(_inputStream)},
      outputStream{std::move(_outputStream)} {}

void Scanner::generateScannedOutput() {
  // Keep track of the char most recently output to outputStream
  char prevOutputChar{'\0'};

  // Keep track of the index in the buffer that we are writing to
  int write_i;

  do {
    inputStream->read(readBuffer, SCANNER_BUFFER_SIZE);
    write_i = 0;

    // Go through char by char skipping chars if needed
    for (int read_i = 0; read_i < inputStream->gcount(); ++read_i) {
      // Replace new lines with spaces
      if (readBuffer[read_i] == '\n') {
        readBuffer[read_i] = ' ';
      }

      // Skip if previously output was a white space
      if (readBuffer[read_i] == ' ' && prevOutputChar == ' ') {
        continue;
      }

      writeBuffer[write_i] = readBuffer[read_i];
      prevOutputChar = readBuffer[read_i];
      write_i++;
    }
    outputStream->write(writeBuffer, write_i);
  } while (inputStream->gcount() == SCANNER_BUFFER_SIZE);
}
