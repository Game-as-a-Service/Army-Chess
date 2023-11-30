cmake_minimum_required(VERSION 3.14)
project(ArmyChess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

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

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE YML_FILES "*.yml")
file(GLOB_RECURSE MD_FILES "*.md")

add_custom_target(ProjectFiles SOURCES
    ${YML_FILES}
    ${MD_FILES}
)

add_subdirectory(src/main)
add_subdirectory(src/test)

