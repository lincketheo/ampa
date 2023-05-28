//
// Created by theo on 5/27/23.
//

#ifndef PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H
#define PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H

// External includes
#include <istream>
#include <memory>

class Scanner {
private:
  /// Char to know that the input has reached the end
  const char inputStreamTerminal;

protected:
  // Input output pairs
  std::unique_ptr<std::istream> inputStream;
  std::unique_ptr<std::ostream> outputStream;

public:
  Scanner() = delete;
  explicit Scanner(
      char _inputStreamTerminal,
      std::unique_ptr<std::istream> _inputStream,
      std::unique_ptr<std::ostream> _outputStream
  );

  void generateScannedOutput();
};

#endif //PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H
