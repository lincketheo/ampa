//
// Created by theo on 5/27/23.
//

#ifndef PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_FILESCANNER_H
#define PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_FILESCANNER_H

// Project includes
#include "ampa/lex/scanner/Scanner.h"

// External includes
#include <fstream>
#include <memory>

class FileScanner : public Scanner {
private:
  static std::unique_ptr<std::istream> openAndVerifyInputFile(const std::string &fileName);
  static std::unique_ptr<std::ostream> openAndVerifyOutputFile(const std::string &fileName);

public:
  FileScanner() = delete;
  explicit FileScanner(const std::string &inputFileName,
                       const std::string &outputFileName
  );
};

#endif //PROOF_SRC_AMPA_LEX_DATA_SCANNER_IMPL_FILESCANNER_H
