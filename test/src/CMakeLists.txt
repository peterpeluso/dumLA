set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${DumLA_SOURCE_DIR}/main/src)
include_directories(${DumLA_SOURCE_DIR}/test/src)
include_directories(${DumLA_SOURCE_DIR}/test/inc)
add_executable(Test test.cpp)

target_link_libraries(Test Matrix)
