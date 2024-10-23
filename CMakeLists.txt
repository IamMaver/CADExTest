cmake_minimum_required(VERSION 3.29)
project(CADExTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

include_directories(include)

add_library(curves SHARED
        src/Curves.cpp
)

target_include_directories(curves PUBLIC
        include
)

set_target_properties(curves PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
)

add_executable(CADExTest src/main.cpp)

target_link_libraries(CADExTest curves)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})

add_custom_command(TARGET CADExTest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:curves>
        $<TARGET_FILE_DIR:CADExTest>
)
