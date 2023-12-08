/**
 * @file Timer.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of class Timer methods
 *
 */

#include <simlib.h>

#include "Timer.hpp"
#include "utils.hpp"

/**
 * @brief Construct a new Timer::Timer object
 *
 * @param skilift Pointer to the skilift
 */
Timer::Timer(class Skilift *skilift)
    : simlib3::Event(), Skilift(skilift)
{
}

/**
 * @brief Destroy the Timer::Timer object
 *
 */
Timer::~Timer() = default;

/**
 * @brief Behavior of the Timer event
 *
 */
void Timer::Behavior()
{
    delete this->Skilift;
}
