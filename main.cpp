
#include <iostream>
#include "ampa/lex/scanner/impl/StringScanner.h"

int main() {
  StringScanner s2 = StringScanner{"Helo aa l jn lkn    ln  \n  lknas  l  l l nl  l l ll ll l ll llll;"};
  s2.generateScannedOutput();
  std::cout << s2.printOutputString() << std::endl;
  return 0;
}
