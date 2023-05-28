
// Project includes
#include "Executable_Config.h"
#include "ampa/lex/scanner/impl/FileScanner.h"

// External includes
#include <string>
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cout << "Usage: " << std::endl;
    std::cout << SCANNER_EXECUTABLE_NAME << "ampa_scanner <input_file> <output_file>" << std::endl;
    exit(1);
  }

  const auto inputFile = std::string(argv[1]);
  const auto outputFile = std::string(argv[2]);
  if (inputFile == outputFile) {
    std::cout << "input file must be different than output file" << std::endl;
    exit(1);
  }

  FileScanner fs = FileScanner{inputFile, outputFile};
  fs.generateScannedOutput();
  return 0;
}