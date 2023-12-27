set(Unique_Src
    FindUniqueMax.h
    FindUniqueMax.cpp)

add_library(UniqueLib ${Unique_Src})
target_link_libraries(UniqueLib ${Boost_LIBRARIES})