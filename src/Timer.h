#pragma once

#include "SkiliftCars.h"
#include <simlib.h>
class Timer final : public simlib3::Event
{
    private:
        class SkiliftCars *SkiliftCars;
    public:
        Timer(class SkiliftCars*);
        ~Timer();
        void Behavior();
};
