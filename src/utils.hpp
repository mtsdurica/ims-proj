/**
 * @file utils.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains utility declarations
 *
 */

#pragma once

#include <tuple>
#include <simlib.h>

#define DEFAULT_SKILIFT_GAP 7
#define DEFAULT_NUM_OF_SKIERS 500
#define DEFAULT_NUM_OF_ITERATIONS 5
#define DEFAULT_STRICT_VALUE -1
#define DEFAULT_NUM_OF_CARS 48
#define DEFAULT_SHIFT_DURATION (7 * 60 * 60)
#define SKILIFT_STOPPED_MARGIN (10 * 60)
#define SIMULATION_START 0
#define SIMULATION_END (24 * 60 * 60)

void printHelp();

void printSimulationBegin();

void printSimulationRunStart(const int);

void printSimulationRunEnd(const int);

void printSimulationEnd();

std::tuple<int, int, int, int, int, int> parseArgs(int argc, char *argv[]);
