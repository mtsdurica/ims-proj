/**
 * @file Skilift.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains declaration of class Skilift
 *
 */

#pragma once

#include <simlib.h>

#include "Stats.hpp"

class Skilift final : public simlib3::Process
{
private:
    class Stats *Statistics;
    simlib3::Queue *TurnstileQueue;
    const int ShiftTime;
    const int SkiliftGap;
    const int StrictValue;

public:
    Skilift(class Stats *, simlib3::Queue *, const int, const int, const int);
    ~Skilift();
    void Behavior() override;
};
