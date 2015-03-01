cmake_minimum_required(VERSION 2.8.3)
project(trikset)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES trikset
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)
set (CMAKE_POSITION_INDEPENDENT_CODE TRUE)
FIND_LIBRARY(TRIKCONTROL_LIB trikControl-x86-d /home/ujohnny/workspace/trikRuntime/bin/x86-debug/)

include_directories(
  ${catkin_INCLUDE_DIRS}
  /home/ujohnny/workspace/trikRuntime/trikControl/include/ 
  /home/ujohnny/workspace/trikRuntime/bin/x86-debug/ 
  /usr/include/qt5 
)

add_executable(listener src/listener.cpp)
target_link_libraries(listener 
  ${catkin_LIBRARIES}
  ${TRIKCONTROL_LIB}
  Qt5Core
  Qt5Widgets
)


