/**
 * @file Skier.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of class Skier methods
 *
 */

#include <simlib.h>
#include <cstdlib>

#include "Skier.hpp"

/**
 * @brief Construct a new Skier::Skier object
 *
 * @param stats Pointer to the statistics
 * @param turnstileQueue Pointer to the Turnstile Queue
 * @param shiftTime Shift duration (in seconds)
 * @param skiliftGap Gap between each skilift car (in seconds)
 * @param numOfCars Number of cars on the skilift
 */
Skier::Skier(class Stats *stats, simlib3::Queue *turnstileQueue, const int shiftTime, const int skiliftGap, const int numOfCars)
    : simlib3::Process(), Stats(stats), TurnstileQueue(turnstileQueue), ShiftTime(shiftTime), SkiliftGap(skiliftGap), NumOfCars(numOfCars)
{
}

/**
 * @brief Destroy the Skier::Skier object
 *
 */
Skier::~Skier() = default;

/**
 * @brief Behavior of the Skier process
 *
 */
void Skier::Behavior()
{
    // Simulating arrival time, only during the first ~1-2 hours of shift
    double arrivalTime = simlib3::Normal(60 * 60, 30 * 60);
    arrivalTime = std::abs(arrivalTime); // flipping sign, if the generated number is negative
    Wait(arrivalTime);
    this->Stats->UpdateArrival(arrivalTime);
    while (true)
    {
        Into(*this->TurnstileQueue);
        Passivate();
        // (skilift cars * gap between each car) / 2 (we only need the duration uphill)
        double rideUphill = (double)(this->NumOfCars * this->SkiliftGap) / 2;
        Wait(rideUphill);
        this->Stats->UpdateRidesStarted(Time);
        double chanceOfGoingFast = simlib3::Random(); // Randomizing decision of pace downhill
        if (chanceOfGoingFast < 0.3)
            Wait(simlib3::Uniform(1 * 60, 2 * 60)); // Fast pace downhill
        else
            Wait(simlib3::Uniform(3 * 60, 4 * 60)); // "Average Joe's" pace downhill
        this->Stats->UpdateRidesFinished(Time);
    }
}
