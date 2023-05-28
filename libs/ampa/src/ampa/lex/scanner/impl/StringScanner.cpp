//
// Created by theo on 5/27/23.
//

// Project includes
#include "ampa/lex/scanner/impl/StringScanner.h"

StringScanner::StringScanner(
    const std::string &inputString,
    std::unique_ptr<std::ostream> outputStream
)
    : Scanner(
    std::make_unique<std::istringstream>(inputString),
    std::move(outputStream)
) {};

std::string StringScanner::printOutputString() {
  std::string ret;
  {
    ret = ((std::ostringstream*)outputStream.get())->str();
  }
  return ret;
}
