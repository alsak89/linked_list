# locate gtest
find_package(GTest REQUIRED)
find_library(LinkedList REQUIRED)
# create tests executable
add_executable(LinkedListTests LinkedListTests.cpp)
# include gtest headers
target_include_directories(LinkedListTests PUBLIC ${GTEST_INCLUDE_DIRS})

target_link_libraries(LinkedListTests LinkedList ${GTEST_LIBRARIES} pthread)