set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
add_library( Matrix matrix.cpp array.cpp excpt.cpp complex.cpp matrix.hpp complex.hpp array.hpp)
add_executable(main main.cpp)
target_link_libraries(main Matrix)