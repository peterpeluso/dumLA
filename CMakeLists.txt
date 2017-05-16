cmake_minimum_required(VERSION 3.5)
project(DumLA)
add_subdirectory(main) 

enable_testing ()

add_subdirectory(test)

add_test(NAME MyTest COMMAND Test)