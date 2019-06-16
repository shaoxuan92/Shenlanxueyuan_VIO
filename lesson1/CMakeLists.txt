cmake_minimum_required(VERSION 3.0)

project(PoseUpdate)


include_directories(
/home/lin/Desktop/js_308/Sophus/sophus
/usr/include/eigen3
)


add_executable(poseupdate lesson_1.cpp )
target_link_libraries(poseupdate /home/lin/Desktop/js_308/Sophus/build/libSophus.so)