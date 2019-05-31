cmake_minimum_required(VERSION 3.10)
project(Projet_CaptIF)

set(CMAKE_CXX_STANDARD 17)

#Executable final
add_subdirectory(src)
add_executable(Projet_CaptIF src/main.cpp)
target_link_libraries(Projet_CaptIF core)

#Executable Google Test
add_subdirectory(Tests/lib/googletest-master)
include_directories(Tests/lib/googletest-master/googletest/include)
include_directories(Tests/lib/googletest-master/googlemock/include)
add_executable(CaptIF_Tests Tests/main_test.cpp Tests/Test_Modele/Date_test.cpp Tests/Test_Modele/Point_test.cpp Tests/Test_Modele/Attribute_test.cpp Tests/Test_Modele/Measure_test.cpp Tests/Test_Modele/Parser_test.cpp Tests/Test_Modele/RequestView_test.cpp Tests/Test_Modele/Sensor_test.cpp Tests/Test_Controleur/CaptIF_test.cpp Tests/Test_Controleur/Services_test.cpp Tests/Test_Vue/Output_test.cpp)
target_link_libraries(CaptIF_Tests core)
target_link_libraries(CaptIF_Tests gtest gtest_main)
target_link_libraries(CaptIF_Tests gmock gmock_main)

