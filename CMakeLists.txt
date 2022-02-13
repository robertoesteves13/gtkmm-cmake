cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project("GtkTest")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED IMPORTED_TARGET gtkmm-4.0)

list(
  APPEND CMAKE_MODULE_PATH
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros
)
include(GlibCompileResourcesSupport)

set(
  RESOURCE_LIST
  style.css
  main_window.ui
)

compile_gresources(RESOURCE_FILE XML_OUT TYPE EMBED_C RESOURCES ${RESOURCE_LIST} SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)

include_directories("src/include")
add_executable(
  ${PROJECT_NAME}
  "src/main.cpp"
  "src/window.cpp"
  "src/application.cpp"
  ${RESOURCE_FILE}
)

target_link_libraries(${PROJECT_NAME} PUBLIC PkgConfig::GTKMM)
