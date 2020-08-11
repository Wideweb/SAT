set(SOURCE_EXE 
    main.cpp
    ShapeLoader.cpp
)	

add_executable(app ${SOURCE_EXE})

target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR})

target_link_libraries(app PRIVATE sat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${OUTPUT_DIRECTORY})