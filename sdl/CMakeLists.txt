cmake_minimum_required(VERSION 3.10)
project(SDL3_Example C)

# Generate compile_commands.json for LSP/clangd support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Set runtime output directory to build root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

# Find SDL3
find_package(SDL3 REQUIRED)

# Add SDL3 include directories for all targets
include_directories(/usr/local/include)

# Add executable
add_subdirectory(src)

# Note: target_link_libraries and target_include_directories should be
# called from src/CMakeLists.txt where the target is defined
