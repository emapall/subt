cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
find_package(ignition-cmake2 REQUIRED)
project(KolibriController)

find_package(ignition-plugin1 REQUIRED COMPONENTS register)
find_package(ignition-transport8 QUIET REQUIRED OPTIONAL_COMPONENTS log)

set(IGN_PLUGIN_VER ${ignition-plugin1_VERSION_MAJOR})
find_package(ignition-gazebo4 REQUIRED)
add_library(KolibriController SHARED voliro_controller_plugin/kolibri_controller.cc )
set_property(TARGET KolibriController PROPERTY CXX_STANDARD 17)
target_link_libraries(KolibriController
  PRIVATE ignition-plugin${IGN_PLUGIN_VER}::ignition-plugin${IGN_PLUGIN_VER}
  PRIVATE ignition-gazebo4::ignition-gazebo4)

install(FILES ../../../../devel/lib/libKolibriController.so
  DESTINATION lib)
