cmake_minimum_required(VERSION 3.24)
project(raytracer)

set(CMAKE_CXX_STANDARD 17)

add_executable(raytracer main.cpp tuple.cpp tuple.h vec.cpp vec.h point.h color.cpp color.h canvas.cpp canvas.h matrix.cpp matrix.h transformations.cpp transformations.h ray.cpp ray.h sphere.cpp sphere.h object.h intersection.h light.h material.h)
