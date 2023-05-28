add_library(ampa
        src/ampa/lex/scanner/Scanner.cpp
        src/ampa/lex/scanner/impl/FileScanner.cpp
        src/ampa/lex/scanner/impl/StringScanner.cpp
)
target_include_directories(ampa PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include") 

