cmake_minimum_required(VERSION 3.20)  # CMake version check
project(test_DST)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # Output all the executable to ./bin directory

# Setup variable
set(EXE_NAME ${PROJECT_NAME}) # setup the executable output name

# Setup compile files
include_directories(include/) #Add include files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.c src/*.cpp)# Add source files automatically

# Define the source files explicitly
# set(SOURCE_FILES  # Add source files
#     src/main.cpp
# )

# Building process
add_executable(${EXE_NAME} ${SOURCE_FILES}) # Make executable

