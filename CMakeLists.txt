cmake_minimum_required(VERSION 2.8.3)
project(event_server)

find_package(catkin_simple REQUIRED)

catkin_simple()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

find_package(Boost REQUIRED)
find_package(Protobuf REQUIRED)


#########################
# make 
#########################

cs_add_executable(event_server
  event_server.cpp
  event_array.pb.cc
)

# link the executable to the necesarry libs
target_link_libraries(event_server
   ${catkin_LIBRARIES}
   ${Protobuf_LIBRARIES}
)
