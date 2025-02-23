cmake_minimum_required(VERSION 3.10)

# Set the project name
project(LibraryManagement)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the includes directory to the search path for include files
include_directories(includes)

# List of source files
set(SOURCES
    src/main.cpp
    src/Menu.cpp
    src/Library.cpp
    src/Book.cpp
)

# Add the executable
add_executable(LibraryManagement ${SOURCES})

# Set the output directory for the binary
set_target_properties(LibraryManagement PROPERTIES
     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
