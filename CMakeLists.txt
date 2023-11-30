cmake_minimum_required(VERSION 3.14)

project(ArmyChess LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
    Core
    LinguistTools
    HttpServer
)

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    LinguistTools
    HttpServer
)

set(TS_FILES ArmyChess_zh_TW.ts)

file(GLOB_RECURSE HPPFILES "src/*.hpp")
file(GLOB_RECURSE CPPFILES "src/*.cpp")
file(GLOB_RECURSE MARKDOWNFILES "*.md")

add_executable( ArmyChess
    ${HPPFILES}
    ${CPPFILES}
    ${MARKDOWNFILES}
    ${TS_FILES}
)

target_link_libraries( ArmyChess
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::HttpServer
    gtest
    gmock
)

add_test(NAME ArmyChess COMMAND ArmyChess)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

install(TARGETS ArmyChess
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
