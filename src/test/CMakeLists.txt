file(GLOB_RECURSE TESTCPPFILES
    "./*.cpp"
    "../main/sum/*.cpp"
)

add_executable(tests
    ${TESTCPPFILES}
)

# 链接 Google Test 和主项目库
target_link_libraries(tests gtest gmock)

# 添加测试
include(GoogleTest)
gtest_discover_tests(tests)
