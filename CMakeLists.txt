cmake_minimum_required(VERSION 3.10)
project(Projet_CaptIF)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projet_CaptIF main.cpp CaptIF/Modele/Point.h CaptIF/Modele/Point.cpp CaptIF/Modele/RequestView.h CaptIF/Modele/RequestView.cpp CaptIF/Modele/Sensor.h CaptIF/Modele/Sensor.cpp CaptIF/Controleur/Services.h CaptIF/Controleur/Services.cpp CaptIF/Modele/Attribute.h CaptIF/Controleur/CaptIF.h CaptIF/Controleur/CaptIF.cpp CaptIF/Modele/Date.h CaptIF/Vue/Input.h CaptIF/Vue/Input.cpp CaptIF/Modele/Measure.h CaptIF/Vue/Output.h CaptIF/Vue/Output.cpp CaptIF/Modele/Parser.h CaptIF/Modele/Parser.cpp CaptIF/Modele/Date.cpp CaptIF/Modele/Attribute.cpp CaptIF/Modele/Measure.cpp)