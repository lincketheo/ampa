# Advanced Mathematics Proof Assistant
Mathematics shouldn't have to be formally verified using complex formal logic and type theory. One of the strongest reasons (I believe) formal verification 
of mathematics proofs (HOL, COQ, Lean etc) is just due to the nature of the complexity of the programming language. My intention is to write a software that 
can parse more human readable mathematics proofs (treating the proofs as a programming language sort of).

This project is a work in progress

# Usage 
## Scanner
```
$ cmake -S . -B build
$ cmake --build build
$ ./outputs/x86_64/bin/ampa_scanner <input file> <output file>
```

# Project Structure
## tests
GTest tests

## tools
Executables and tooling to compile / run programs that use ampa syntax

## libs
Libraries - only one (`ampa`). Not sure if there will be more in the future. I might also split lexer parser etc into different libraries. Not sure yet

## outputs
Generated libraries and executables from CMake. I'll probably fiddle with this in the future. For now, I just want one place for bins.

