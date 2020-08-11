set(SOURCE_LIB 
    Math.cpp
    CollisionShape.cpp
    CollisionDetection.cpp
)	

add_library(sat SHARED ${SOURCE_LIB})

target_include_directories(sat PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})