/**
 * @file main.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Entry point of application
 *
 */

#include <cstdlib>

#include "Skicentrum.hpp"
#include "utils.hpp"

int main(int argc, char *argv[])
{
    Skicentrum::Simulate(parseArgs(argc, argv));
    return EXIT_SUCCESS;
}
