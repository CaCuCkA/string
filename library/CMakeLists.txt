add_library(${LIB_NAME} SHARED
        src/mystring.cpp
        include/mystring.h)
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/library/include)
set_target_properties(${LIB_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
