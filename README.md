# Advanced Mathematics Proof Assistant

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

