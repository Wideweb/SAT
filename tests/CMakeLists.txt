set(SOURCE_EXE 
    CollisionDetectionTest.cpp
)	

add_executable(test ${SOURCE_EXE})

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/vendor)

target_link_libraries(test PRIVATE sat)
