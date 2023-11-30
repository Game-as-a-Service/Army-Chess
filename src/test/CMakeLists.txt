enable_testing()

file(GLOB_RECURSE TESTCPPFILES
    "./*.cpp"
    "../main/sum/*.cpp"
)

add_executable(Tests
    ${TESTCPPFILES}
)

# 链接 Google Test 和主项目库
target_link_libraries(Tests gtest gmock)

# 添加测试
include(GoogleTest)
gtest_discover_tests(Tests)

foreach(_file ${TESTCPPFILES})
    message(STATUS "Test file: ${_file}")
endforeach()
