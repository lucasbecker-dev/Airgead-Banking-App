cmake_minimum_required(VERSION 3.17)
project(Project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project2 src/main.cpp src/cpp/InputForm.cpp src/headers/InputForm.h src/cpp/UserData.cpp src/headers/UserData.h src/cpp/InterestCalc.cpp src/headers/InterestCalc.h src/cpp/ReportPrinter.cpp src/headers/ReportPrinter.h)