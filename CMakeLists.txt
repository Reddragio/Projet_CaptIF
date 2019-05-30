cmake_minimum_required(VERSION 3.14)
project(Projet_CaptIF)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet_CaptIF main.cpp Modele/Point.h Modele/Point.cpp Modele/RequestView.h Modele/RequestView.cpp Modele/Sensor.h Modele/Sensor.cpp Controleur/Services.h Controleur/Services.cpp Modele/Attribute.h Controleur/CaptIF.h Controleur/CaptIF.cpp Modele/Date.h Vue/Input.h Vue/Input.cpp Modele/Measure.h Vue/Output.h Vue/Output.cpp Modele/Parser.h Modele/Parser.cpp Modele/Date.cpp Modele/Attribute.cpp Modele/Measure.cpp)