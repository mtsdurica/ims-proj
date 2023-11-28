#include "Shift.h"

#include <simlib.h>

#include "Skier.h"
#include "SkiliftCars.h"

Shift::Shift(simlib3::Queue *turnstileQueue, class Stats *stats, const int numOfSkiers, const int skiliftGap,
             const int shiftTime, const int strictValue, const int numOfCars)
    : simlib3::Event(), TurnstileQueue(turnstileQueue), Stats(stats), NumOfSkiers(numOfSkiers), SkiliftGap(skiliftGap),
      ShiftTime(shiftTime), StrictValue(strictValue), NumOfCars(numOfCars)
{
}

Shift::~Shift() = default;

void Shift::Behavior()
{
    for (int i = 0; i < (int)simlib3::Normal(this->NumOfSkiers, 20); i++)
        (new Skier(this->Stats, this->TurnstileQueue, this->ShiftTime, this->SkiliftGap, this->NumOfCars))->Activate();

    (new SkiliftCars(this->Stats, this->TurnstileQueue, this->ShiftTime, this->SkiliftGap, this->StrictValue))->Activate();
}
