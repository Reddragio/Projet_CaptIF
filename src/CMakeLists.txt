set(core_SRCS Modele/Point.h Modele/Point.cpp Modele/RequestView.h Modele/RequestView.cpp Modele/Sensor.h Modele/Sensor.cpp Controleur/Services.h Controleur/Services.cpp Modele/Attribute.h Controleur/CaptIF.h Controleur/CaptIF.cpp Modele/Date.h Vue/Input.h Vue/Input.cpp Modele/Measure.h Vue/Output.h Vue/Output.cpp Modele/Parser.h Modele/Parser.cpp Modele/Date.cpp Modele/Attribute.cpp Modele/Measure.cpp)
add_library(core ${core_SRCS})


