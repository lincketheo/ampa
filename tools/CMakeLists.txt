######## Scanner
option(BUILD_SCANNER_EXECUTABLE "Build the scanner executable" ON)
set(SCANNER_EXECUTABLE_NAME ampa_scanner)
if(BUILD_SCANNER_EXECUTABLE)
    add_executable(${SCANNER_EXECUTABLE_NAME} ampa_scanner.cpp)
    target_include_directories(${SCANNER_EXECUTABLE_NAME} PRIVATE "${PROJECT_BINARY_DIR}/src")
    target_link_libraries(${SCANNER_EXECUTABLE_NAME} ${PROJECT_LIBS})
endif()

configure_file(Executable_Config.h.in Executable_Config.h)
