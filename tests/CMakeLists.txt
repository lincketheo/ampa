######### Fetch Remotes from Git
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
########

######## Testing Config
enable_testing()
add_executable(tests
        ampa/lex/scanner/impl/ScannerTest.cpp
        ampa/lex/lexicon/impl/SimpleMapLexiconTest.cpp)
target_link_libraries(
        tests
        GTest::gtest_main
        ${PROJECT_LIBS}
)
include(GoogleTest)
gtest_discover_tests(tests)
########

