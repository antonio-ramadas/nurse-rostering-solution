cmake_minimum_required(VERSION 3.6)
project(nrs)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        code/main.cpp
        code/json.hpp
        code/Scenario.h code/Scenario.cpp
        code/History.h code/History.cpp
        code/WeekData.h code/WeekData.cpp
        code/ShiftType.cpp code/ShiftType.h
        code/Contract.cpp code/Contract.h
        code/Nurse.cpp code/Nurse.h
        code/Reader.cpp code/Reader.h
        code/Exception.cpp code/Exception.h
        code/Requirement.cpp code/Requirement.h
        code/DayRequirement.cpp code/DayRequirement.h
        code/ShiftOffRequest.cpp code/ShiftOffRequest.h
        code/solution/Solution.cpp code/solution/Solution.h
        code/solution/NurseSolution.cpp code/solution/NurseSolution.h
        code/solution/Turn.cpp code/solution/Turn.h code/Validator.cpp code/Validator.h code/algorithms/Grasp.cpp code/algorithms/Grasp.h code/algorithms/HillClimbing.cpp code/algorithms/HillClimbing.h code/algorithms/SolutionNeighbourhood.cpp code/algorithms/SolutionNeighbourhood.h code/Writter.cpp code/Writter.h code/algorithms/Move.cpp code/algorithms/Move.h code/algorithms/Position.cpp code/algorithms/Position.h code/InputParser.cpp code/InputParser.h code/algorithms/ConstructionHeuristics.cpp code/algorithms/ConstructionHeuristics.h)

add_executable(nrs ${SOURCE_FILES})