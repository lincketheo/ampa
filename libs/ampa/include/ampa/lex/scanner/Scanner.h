//
// Created by theo on 5/27/23.
//

#ifndef PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H
#define PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H

// External includes
#include <istream>
#include <memory>

#define SCANNER_BUFFER_SIZE 10

class Scanner {
private:
  /**
   * @brief A read buffer used to minimize system read calls
   * @note This is not guaranteed null-ed (prior to initialization)
   * and callers should know how much _to read_ before reading.
   */
  char readBuffer[SCANNER_BUFFER_SIZE]{};

  /**
   * @brief A write buffer used to minimize system write calls
   * @note This is not guaranteed null-ed (prior to initialization)
   * and callers should know how much _to write_ before writing.
   */
  char writeBuffer[SCANNER_BUFFER_SIZE]{};

protected:
  std::unique_ptr<std::istream> inputStream; // The input file/string/whatever
  std::unique_ptr<std::ostream> outputStream; // Where to output the scanned input

public:
  Scanner() = delete;
  explicit Scanner(
      std::unique_ptr<std::istream> _inputStream,
      std::unique_ptr<std::ostream> _outputStream
  );

  /**
   * @brief The primary function in this class
   * Outputs input stream into output stream with scanned
   * output
   */
  void generateScannedOutput();
};

#endif //PROOF_SRC_AMPA_LEX_DATA_SOURCE_SCANNER_H
