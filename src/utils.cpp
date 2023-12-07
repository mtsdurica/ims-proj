/**
 * @file utils.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of utility functions
 *
 */

#include "utils.hpp"

#include <cstdlib>
#include <exception>
#include <getopt.h>
#include <iostream>
#include <simlib.h>
#include <tuple>

/**
 * @brief Print help
 *
 */
void printHelp()
{
    std::cout << "Made by Romana Ďuráčiová (xdurac01) & Matúš Ďurica (xduric06) | VUT FIT v Brně 2023" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1mNAME\033[0m" << std::endl;
    std::cout << "skicentrum-sim\t - Simulation of skipark Ski Kraliky" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[1mSYNOPSIS\033[0m" << std::endl;
    std::cout << "./skicentrum-sim\t[-h | --help] [-i iterations | --iterations iterations]" << std::endl
              << "\t\t\t[-s skiers | --skiers skiers] [-t time | --shift-time time]" << std::endl
              << "\t\t\t[-g gap | --skilift-gap gap] [-r strict_seats | --strict strict_seats]" << std::endl
              << "\t\t\t[-c skilift_cars | --skilift-cars skilift_cars]" << std::endl;
    std::cout << std::endl;
    std::cout << "-i | --iterations iterations     - Specifies the number of iterations the simulation will be run for."
              << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m " << DEFAULT_NUM_OF_ITERATIONS
              << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 1" << std::endl;
    std::cout << "-s | --skiers skiers             - Specifies the number of skiers skiing in the skipark" << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m " << DEFAULT_NUM_OF_SKIERS
              << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 1" << std::endl;
    std::cout << "-t | --shift-time time           - Specifies the duration of the workshift (duration of the "
                 "simulation) (in seconds)."
              << std::endl;
    std::cout
        << "                                   From this duration a 10 minute margin will be subtracted, to simulate "
           "turning off the skilift."
        << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m " << DEFAULT_SHIFT_DURATION
              << " (7 hours)" << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 3600 (1 hour)" << std::endl;
    std::cout << "-g | --skilift-gap gap           - Specifies the gap between each skilift car (in seconds)."
              << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m " << DEFAULT_SKILIFT_GAP << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 1" << std::endl;
    std::cout << "-r | --strict strict_seats       - Specifies the number of seats that will be occupied at all times, "
                 "meaning simulation will not allow seating by less or more seats than specified."
              << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m OFF" << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 1" << std::endl;
    std::cout << "                                   \033[1mMAXIMAL VALUE:\033[0m 4" << std::endl;
    std::cout << "-c | --skilift-cars skilift_cars - Specifies the number of skilift cars on the skilift." << std::endl;
    std::cout << "                                   \033[1mDEFAULT VALUE:\033[0m " << DEFAULT_NUM_OF_CARS << std::endl;
    std::cout << "                                   \033[1mMINIMUM VALUE:\033[0m 48" << std::endl;
    std::cout << "-h | --help                      - Prints help" << std::endl;
}

/**
 * @brief Print simulation begin
 *
 */
void printSimulationBegin()
{
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << "|\t\tSKICENTRUM SIMULATION BEGINS\t\t   |" << std::endl;
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Print start of simulation run
 *
 * @param iteration Number of simulation run iteration
 */
void printSimulationRunStart(const int iteration)
{
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << "|\t       START OF SIMULATION RUN NUMBER " << iteration << "\t           |" << std::endl;
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
}

/**
 * @brief Print end of simulation run
 *
 * @param iteration Number of simulation run iteration
 */
void printSimulationRunEnd(const int iteration)
{

    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << "|\t\tEND OF SIMULATION RUN NUMBER " << iteration << "\t\t   |" << std::endl;
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Print simulation end
 *
 */
void printSimulationEnd()
{

    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
    std::cout << "|\t      SKICENTRUM SIMULATION RUNS ARE OVER          |" << std::endl;
    std::cout << "+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+" << std::endl;
}

/**
 * @brief Parse command-line arguments
 *
 * @param argc Number of command-line arguments
 * @param argv Array containing command-line arguments
 * @return std::tuple<int, int, int, int, int, int> skiliftGap, skiers, iterations, shiftTime, strict, numOfCars
 */
std::tuple<int, int, int, int, int, int> parseArgs(int argc, char **argv)
{
    int opt, strict = -1, skiliftGap = -1, skiers = -1, iterations = -1, shiftTime = -1, numOfCars = -1;
    opterr = 0;
    static const char *shortOpts = "r:g:c:s:i:t:h";
    static const struct option longOpts[] = {
        {"skilift-gap", required_argument, nullptr, 'g'},
        {"skiers", required_argument, nullptr, 's'},
        {"strict", required_argument, nullptr, 'r'},
        {"iterations", required_argument, nullptr, 'i'},
        {"shift-time", required_argument, nullptr, 't'},
        {"help", no_argument, nullptr, 'h'},
        {"skilift-cars", required_argument, nullptr, 'c'},
        {nullptr, 0, nullptr, 0},

    };
    while ((opt = getopt_long(argc, argv, shortOpts, longOpts, nullptr)) != -1)
    {
        try
        {
            switch (opt)
            {
            case 'g':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                skiliftGap = std::stoi(optarg);
                break;
            case 's':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                skiers = std::stoi(optarg);
                break;
            case 'i':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                iterations = std::stoi(optarg);
                break;
            case 't':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                shiftTime = std::stoi(optarg);
                break;
            case 'r':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                strict = std::stoi(optarg);
                break;
            case 'c':
                if (std::stoi(optarg) < 0)
                    throw std::exception();
                numOfCars = std::stoi(optarg);
                break;
            case 'h':
                printHelp();
                exit(EXIT_SUCCESS);
                break;
            case '?':
                printHelp();
                exit(EXIT_FAILURE);
                break;
            default:
                printHelp();
                exit(EXIT_FAILURE);
                break;
            }
        }
        catch (const std::exception &)
        {
            std::cerr << "ERROR: Wrong parameter value: " << optarg << std::endl;
            exit(1);
        }
    }
    if (skiliftGap < 1)
    {
        if (skiliftGap != -1)
            std::cout << "WARNING: Invalid skilift gap, running simulation with default value - " << DEFAULT_SKILIFT_GAP
                      << std::endl;
        skiliftGap = DEFAULT_SKILIFT_GAP;
    }
    if (skiers < 1)
    {
        if (skiers != -1)
            std::cout << "WARNING: Invalid number of skiers, running simulation with default value - "
                      << DEFAULT_NUM_OF_SKIERS << std::endl;
        skiers = DEFAULT_NUM_OF_SKIERS;
    }
    if (iterations < 1)
    {
        if (iterations != -1)
            std::cout << "WARNING: Invalid number of iterations, running simulation with default value - "
                      << DEFAULT_NUM_OF_ITERATIONS << std::endl;
        iterations = DEFAULT_NUM_OF_ITERATIONS;
    }
    if (shiftTime < 60 * 60)
    {
        if (shiftTime != -1)
            std::cout << "WARNING: Invalid shift duration, running simulation with default value - "
                      << DEFAULT_SHIFT_DURATION << std::endl;
        shiftTime = DEFAULT_SHIFT_DURATION;
    }
    if (strict < 1 || strict > 4)
    {
        if (strict != -1)
            std::cout << "WARNING: Invalid strict value, running simulation with default value - "
                      << DEFAULT_STRICT_VALUE << std::endl;
        strict = DEFAULT_STRICT_VALUE;
    }
    if (numOfCars < 48)
    {
        if (numOfCars != -1)
            std::cout << "WARNING: Invalid number of skilift cars, running simulation with default value - "
                      << DEFAULT_NUM_OF_CARS << std::endl;
        numOfCars = DEFAULT_NUM_OF_CARS;
    }
    return {skiliftGap, skiers, iterations, shiftTime, strict, numOfCars};
}
