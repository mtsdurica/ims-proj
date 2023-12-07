#include "Timer.h"
#include "utils.h"
#include <simlib.h>

Timer::Timer(class SkiliftCars *skiliftCars)
    : simlib3::Event(), SkiliftCars(skiliftCars)
{
}

Timer::~Timer()
{
}

void Timer::Behavior()
{
    delete this->SkiliftCars;
}
