cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory("chhoti-lib")
#BUILD_SHARED_LIBS 
#add_library("${proj_name}" SHARED "")


set(proj_name "ZeroKatta")

Project(proj_name)

# configuration types

add_executable(game main.cpp sabDefs.cpp)
#target_include_directories(calculate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
