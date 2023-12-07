/**
 * @file Shift.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of class Shift methods
 *
 */

#include <simlib.h>

#include "Shift.hpp"
#include "Skier.hpp"
#include "Skilift.hpp"

/**
 * @brief Construct a new Shift::Shift object
 *
 * @param turnstileQueue Turnstile Queue pointer
 * @param stats Pointer to the statistics
 * @param numOfSkiers Number of skiers to be generated
 * @param skiliftGap Gap between each skilift car (in seconds)
 * @param shiftTime Shift duration (in seconds)
 * @param strictValue Strict seats to be used
 * @param numOfCars Number of cars on the skilift
 */
Shift::Shift(simlib3::Queue *turnstileQueue, class Stats *stats, const int numOfSkiers, const int skiliftGap,
             const int shiftTime, const int strictValue, const int numOfCars)
    : simlib3::Event(), TurnstileQueue(turnstileQueue), Stats(stats), NumOfSkiers(numOfSkiers), SkiliftGap(skiliftGap),
      ShiftTime(shiftTime), StrictValue(strictValue), NumOfCars(numOfCars)
{
}

/**
 * @brief Destroy the Shift::Shift object
 *
 */
Shift::~Shift() = default;

/**
 * @brief Behavior of the Shift event
 *
 */
void Shift::Behavior()
{
    // Generate skiers with normal distribution
    for (int i = 0; i < (int)simlib3::Normal(this->NumOfSkiers, 20); i++)
        (new Skier(this->Stats, this->TurnstileQueue, this->ShiftTime, this->SkiliftGap, this->NumOfCars))->Activate();

    // Activate Skilift
    (new Skilift(this->Stats, this->TurnstileQueue, this->ShiftTime, this->SkiliftGap, this->StrictValue))->Activate();
}
