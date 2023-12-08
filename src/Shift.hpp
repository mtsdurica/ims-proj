/**
 * @file Shift.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains declaration of class Shift
 *
 */

#pragma once

#include <simlib.h>

#include "Stats.hpp"

class Shift final : public simlib3::Event
{
private:
    simlib3::Queue *TurnstileQueue;
    class Stats *Stats;
    const int NumOfSkiers;
    const int SkiliftGap;
    const int ShiftTime;
    const int StrictValue;
    const int NumOfCars;

public:
    Shift(simlib3::Queue *, class Stats *, const int, const int, const int, const int, const int);
    ~Shift();
    void Behavior() override;
};
