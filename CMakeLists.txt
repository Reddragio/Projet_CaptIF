cmake_minimum_required(VERSION 3.14)
project(Projet_CaptIF)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projet_CaptIF main.cpp Point.h Point.cpp RequestView.h RequestView.cpp Sensor.h Sensor.cpp Services.h Services.cpp Attribute.h CaptIF.h CaptIF.cpp Date.h Input.h Input.cpp Measure.h Output.h Output.cpp Parser.h Parser.cpp)