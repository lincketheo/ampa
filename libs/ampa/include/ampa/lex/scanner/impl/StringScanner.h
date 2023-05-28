//
// Created by theo on 5/27/23.
//

#ifndef PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_STRINGSCANNER_H
#define PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_STRINGSCANNER_H

// Project includes
#include "ampa/lex/scanner/Scanner.h"

// External includes
#include <sstream>
#include <memory>

class StringScanner : public Scanner {
private:
public:
  StringScanner() = delete;
  explicit StringScanner(
      const std::string &inputString,
      std::unique_ptr<std::ostream> outputStream = std::make_unique<std::ostringstream>("")
  );
  std::string printOutputString();
};

#endif //PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_STRINGSCANNER_H
