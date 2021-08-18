cmake_minimum_required(VERSION 2.8.3)
project(asl_kolibri_ignition_gazebo_plugin_1)

find_package(catkin REQUIRED)

catkin_package()

install(FILES lib/libSampleSystem.so
  DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})
