#pragma once

#include <simlib.h>

#include "Stats.h"

class SkiliftCars final : public simlib3::Process
{
    private:
        class Stats* Statistics;
        simlib3::Queue* TurnstileQueue;
        const int ShiftTime;
        const int SkiliftGap;
        const int StrictValue;
    public:
        SkiliftCars(class Stats*, simlib3::Queue*, const int, const int, const int);
        ~SkiliftCars();
        void Behavior();
};
