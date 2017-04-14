cmake_minimum_required (VERSION 2.6)

project (COSC345)
  
add_executable(planner Source.cpp)
install(TARGETS planner DESTINATION bin)