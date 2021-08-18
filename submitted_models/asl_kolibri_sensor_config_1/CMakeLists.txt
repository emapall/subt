cmake_minimum_required(VERSION 2.8.3)
project(asl_kolibri_sensor_config_1) # TODO

find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY launch meshes urdf materials
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(FILES model.sdf model.config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

