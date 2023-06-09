add_library(ampa
        src/ampa/lex/scanner/Scanner.cpp
        src/ampa/lex/scanner/impl/FileScanner.cpp
        src/ampa/lex/scanner/impl/StringScanner.cpp
        src/ampa/lex/analysis/impl/DoubleBufferLexicalAnalyzer.cpp
        src/ampa/lex/lexicon/impl/SimpleMapLexicon.cpp
        include/ampa/lex/analyzer/impl/StringDoubleBufferLexicalAnalyzer.h src/ampa/lex/analysis/impl/StringDoubleBufferLexicalAnalyzer.cpp)
target_include_directories(ampa PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include") 

