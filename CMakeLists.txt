cmake_minimum_required(VERSION 3.21)
project(action_c)

add_executable(main 
    main.cpp)

install(TARGETS main)

enable_testing()
add_test(NAME main COMMAND main)
