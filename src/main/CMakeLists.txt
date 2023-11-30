file(GLOB_RECURSE HPPFILES "./*.hpp")
file(GLOB_RECURSE CPPFILES "./*.cpp")

add_executable(ArmyChess
    ${HPPFILES}
    ${CPPFILES}
    ${TS_FILES}
)

target_link_libraries(ArmyChess
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::HttpServer
)

if(COMMAND qt_create_translation)
    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

install(TARGETS ArmyChess LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
