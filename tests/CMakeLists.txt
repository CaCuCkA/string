include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(tests
        size.cpp
        find.cpp
        constructor.cpp
        compare.cpp
        append.cpp insert.cpp erase.cpp substr.cpp index.cpp input_output.cpp swap.cpp extra_operators.cpp)
target_link_libraries(tests ${LIB_NAME} GTest::gtest_main)
set_target_properties(tests PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include(GoogleTest)
gtest_discover_tests(tests)
