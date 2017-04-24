cmake_minimum_required(VERSION 3.6)
project(nrs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        code/main.cpp
        code/json.hpp
        code/Scenario.h code/Scenario.cpp
        code/History.h code/History.cpp
        code/WeekData.h code/WeekData.cpp
        code/ShiftType.cpp code/ShiftType.h code/Contract.cpp code/Contract.h code/Nurse.cpp code/Nurse.h code/Reader.cpp code/Reader.h code/Exception.cpp code/Exception.h code/Requirement.cpp code/Requirement.h code/DayRequirement.cpp code/DayRequirement.h code/ShiftOffRequest.cpp code/ShiftOffRequest.h code/Assignement.h code/Assignment.cpp code/Week.cpp code/Week.h code/Day.cpp code/Day.h code/Shift.cpp code/Shift.h)
add_executable(nrs ${SOURCE_FILES})