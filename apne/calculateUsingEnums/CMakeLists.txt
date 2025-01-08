cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory("chhoti-lib")
#BUILD_SHARED_LIBS 
#add_library("${proj_name}" SHARED "")


set(proj_name "calculate")

Project(Calculate)

# configuration types

add_executable(calculate main.cpp io.cpp operations.cpp)
target_include_directories(calculate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
