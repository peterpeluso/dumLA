set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(${DumLA_SOURCE_DIR}/main/inc)
include_directories(${DumLA_SOURCE_DIR}/library/inc)
link_directories(${DumLA_SOURCE_DIR}/library/src)

add_executable(main main.cpp)
target_link_libraries(main library)