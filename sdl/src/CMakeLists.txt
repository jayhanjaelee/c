# Add executable target for main program
add_executable(main main.c)

# Link SDL3 library to the executable
target_link_libraries(main SDL3::SDL3)

# Include SDL3 headers
target_include_directories(main PRIVATE ${SDL3_INCLUDE_DIRS})
