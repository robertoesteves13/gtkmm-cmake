cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("GtkTest")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

list(
  APPEND CMAKE_MODULE_PATH
  cmake-scripts/gcr/macros
)
include(GlibCompileResourcesSupport)

set(
  RESOURCE_LIST
  assets/ui/main_window.ui
)

compile_gresources(RESOURCE_FILE XML_OUT TYPE BUNDLE RESOURCES ${RESOURCE_LIST})
add_custom_target(resource ALL DEPENDS ${RESOURCE_FILE})

add_executable(${PROJECT_NAME} "src/main.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC PkgConfig::GTKMM)
