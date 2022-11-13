cmake_minimum_required(VERSION 3.10.0)

project(smartcalc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets PrintSupport)

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

target_link_libraries(smartcalc Qt6::Widgets Qt6::PrintSupport)
