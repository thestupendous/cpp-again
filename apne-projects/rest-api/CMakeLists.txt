cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(proj_name "ItemsListApp")

Project(proj_name)

# dependencies
# Find and include dependencies
# find_package(Boost 1.70 REQUIRED COMPONENTS filesystem system)
find_package(Poco  REQUIRED )
# Link libraries to the executable
# target_link_libraries(item-list.out Poco::Poco)

# Add source directory
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

# Add include directory
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# cereal is header only library, so no need to link
add_executable(item-list.out ${SOURCE_DIR}/main.cpp ${SOURCE_DIR}/book.cpp ${SOURCE_DIR}/appender.cpp ${SOURCE_DIR}/reader.cpp)
target_include_directories(item-list.out PUBLIC ${INCLUDE_DIR})
target_link_libraries(item-list.out Poco::Poco)


