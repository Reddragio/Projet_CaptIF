cmake_minimum_required(VERSION 3.10)
project(Projet_CaptIF)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet_CaptIF main.cpp src/Modele/Point.h src/Modele/Point.cpp src/Modele/RequestView.h src/Modele/RequestView.cpp src/Modele/Sensor.h src/Modele/Sensor.cpp src/Controleur/Services.h src/Controleur/Services.cpp src/Modele/Attribute.h src/Controleur/CaptIF.h src/Controleur/CaptIF.cpp src/Modele/Date.h src/Vue/Input.h src/Vue/Input.cpp src/Modele/Measure.h src/Vue/Output.h src/Vue/Output.cpp src/Modele/Parser.h src/Modele/Parser.cpp src/Modele/Date.cpp src/Modele/Attribute.cpp src/Modele/Measure.cpp)