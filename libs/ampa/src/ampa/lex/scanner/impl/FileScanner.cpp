//
// Created by theo on 5/27/23.
//

// Project includes
#include "ampa/lex/scanner/impl/FileScanner.h"

using namespace std;

FileScanner::FileScanner(const string &inputFileName,
                         const string &outputFileName
) : Scanner(
    EOF,
    openAndVerifyInputFile(inputFileName),
    openAndVerifyOutputFile(outputFileName)
) {};

unique_ptr<istream> FileScanner::openAndVerifyInputFile(const string &fileName) {
  auto inputFile = make_unique<ifstream>(fileName);
  if (inputFile->fail()) {
    throw runtime_error("Error opening input file: " + fileName);
  }
  return std::move(inputFile);
}

unique_ptr<ostream> FileScanner::openAndVerifyOutputFile(const string &fileName) {
  auto inputFile = make_unique<ofstream>(fileName);
  if (inputFile->fail()) {
    throw runtime_error("Error opening input file: " + fileName);
  }
  return std::move(inputFile);
}
