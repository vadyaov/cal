cmake_minimum_required(VERSION 3.16)

project(smartcalc VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 CONFIG REQUIRED COMPONENTS Widgets PrintSupport)

add_executable(smartcalc
  gui/smartcalc.cpp
  gui/main.cpp
  gui/qcustomplot.cpp
  calclogic/polish.c
  calclogic/calc.c
  calclogic/credit.c
  calclogic/deposit.c
  calclogic/stack_symb.c
  calclogic/stack_numb.c)

target_link_libraries(smartcalc Qt5::Widgets Qt5::PrintSupport)
