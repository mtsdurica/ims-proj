#include "Skicentrum.h"

#include "Shift.h"
#include "Stats.h"
#include "utils.h"
#include <ctime>
#include <simlib.h>
#include <tuple>

Skicentrum::~Skicentrum() = default;

void Skicentrum::Simulate(std::tuple<int, int, int, int, int, int> params)
{
    int skiliftGap, skiers, iterations, shiftTime, strict, numOfCars;
    std::tie(skiliftGap, skiers, iterations, shiftTime, strict, numOfCars) = params;
    // Seeding random number generators
    simlib3::RandomSeed(time(nullptr));
    printSimulationBegin();
    // Simulating multiple runs
    for (int i = 1; i <= iterations; i++)
    {
        Stats statistics;
        simlib3::Queue turnstileQueue("Turnstiles");
        printSimulationRunStart(i);
        simlib3::Init(SIMULATION_START, SIMULATION_END);
        Shift skicentrumShift(turnstileQueue, &statistics, skiers, skiliftGap, shiftTime, strict, numOfCars);
        skicentrumShift.Activate();
        simlib3::Run();
        // Statistict output
        statistics.Output();
        printSimulationRunEnd(i);
    }
    printSimulationEnd();
}
