cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(BaseGraphExample LANGUAGES CXX VERSION 0.1.0
        DESCRIPTION "A BaseGraph extension example.")

option(BUILD_TESTS "build gtest unit tests" off)
option(BUILD_BINDINGS "build python bindings" off)

if (BUILD_TESTS)
    set(CXX_STANDARD 14)
else()
    set(CXX_STANDARD 11)
endif()
set(CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)
if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++${CXX_STANDARD} -stdlib=libc++")
endif()


find_package(BaseGraph REQUIRED)

add_subdirectory(src)
if (BUILD_BINDINGS OR SKBUILD)
    add_subdirectory(python)
endif()
if (BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if (NOT SKBUILD)
    include(CMakePackageConfigHelpers)
    include(GNUInstallDirs)

    # Install headers
    install(
        DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/BaseGraph"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # Install targets
    install(
        TARGETS ${EXPORTED_TARGETS}
        EXPORT ${PROJECT_NAME}-targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # Install export target and config for find_package
    set(BASEGRAPH_EXPORT_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
    install(
        EXPORT ${PROJECT_NAME}-targets
        NAMESPACE BaseGraph::
        DESTINATION ${BASEGRAPH_EXPORT_DIR}
    )

    configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
        "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION ${BASEGRAPH_EXPORT_DIR}
    )
    write_basic_package_version_file(
        "${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion
    )
    install(FILES
        "${CMAKE_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${BASEGRAPH_EXPORT_DIR}
    )
endif()
