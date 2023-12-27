add_executable(runTests Tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread UniqueLib)