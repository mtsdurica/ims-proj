#pragma once 

#include <simlib.h>

#include "Stats.h"

class Skier final : public simlib3::Process
{
    private:
        class Stats* Stats;
        simlib3::Queue* TurnstileQueue;
        const int ShiftTime;
        const int SkiliftGap;
        const int NumOfCars;
    public: 
        Skier(class Stats*, simlib3::Queue*, const int, const int, const int);
        ~Skier();
        void Behavior();
};
