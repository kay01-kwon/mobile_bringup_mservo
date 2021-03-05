cmake_minimum_required(VERSION 2.8.3)
project(mobile_bringup_mservo)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  std_msgs
  tf
)

catkin_package(
#  INCLUDE_DIRS include
   LIBRARIES 
    mobile_bringup_mservo
   CATKIN_DEPENDS 
    geometry_msgs 
    nav_msgs 
    roscpp 
    std_msgs

)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_INCLUDE_DESTINATION}
)

add_executable(bringup_publisher_mservo src/bringup_publisher_mservo.cpp)
target_link_libraries(bringup_publisher_mservo ${catkin_LIBRARIES})