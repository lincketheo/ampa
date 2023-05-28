cmake_minimum_required(VERSION 3.22)
project(proof)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

######### Fetch Content
include(FetchContent)
########

######## Add Project Libraries
add_subdirectory(libs/ampa)
list(APPEND PROJECT_LIBS ampa)
########

######## Build Executables
add_subdirectory(tools)
########

######## Tests
option(BUILD_TESTS "Build tests with the project" ON)
if(${BUILD_TESTS})
  add_subdirectory(tests)
  target_link_libraries(tests ${PROJECT_LIBS})
endif()
########
