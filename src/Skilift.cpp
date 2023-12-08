/**
 * @file Skilift.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of class Skilift methods
 *
 */

#include <simlib.h>

#include "Skilift.hpp"
#include "Timer.hpp"
#include "utils.hpp"

/**
 * @brief Construct a new Skilift:: Skilift object
 *
 * @param stats Pointer to the statistics
 * @param turnstileQueue Turnstile Queue pointer
 * @param shiftTime Shift duration (in seconds)
 * @param skiliftGap Gap between each skilift car (in seconds)
 * @param strictValue Strict seats to be used
 */
Skilift::Skilift(class Stats *stats, simlib3::Queue *turnstileQueue, const int shiftTime, const int skiliftGap,
                 const int strictValue)
    : simlib3::Process(), Statistics(stats), TurnstileQueue(turnstileQueue), ShiftTime(shiftTime),
      SkiliftGap(skiliftGap), StrictValue(strictValue)
{
}

/**
 * @brief Destroy the Skilift::Skilift object
 *
 */
Skilift::~Skilift() = default;

/**
 * @brief Behavior of the Skilift process
 *
 */
void Skilift::Behavior()
{
    // Cant fix memory leak, whatever done, it just keeps segfaulting
    (new Timer(this))->Activate(Time + (this->ShiftTime - SKILIFT_STOPPED_MARGIN));
    while (true)
    {
        Wait(this->SkiliftGap);

        // Strict mode is off, seats are assigned by percentage
        if (this->StrictValue == -1)
        {
            auto seatsOccupiedPercentage = simlib3::Random();

            if (seatsOccupiedPercentage < 0.05)
            {
                if (this->TurnstileQueue->Length() >= 1)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenOne();
                }
            }
            else if (seatsOccupiedPercentage < 0.1)
            {
                if (this->TurnstileQueue->Length() >= 2)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenTwo();
                }
                else if (this->TurnstileQueue->Length() == 1)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenOne();
                }
            }
            else if (seatsOccupiedPercentage < 0.5)
            {
                if (this->TurnstileQueue->Length() >= 3)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenThree();
                }
                else if (this->TurnstileQueue->Length() == 2)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenTwo();
                }
                else if (this->TurnstileQueue->Length() == 1)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenOne();
                }
            }
            else
            {
                if (this->TurnstileQueue->Length() >= 4)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenFour();
                }
                else if (this->TurnstileQueue->Length() == 3)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenThree();
                }
                else if (this->TurnstileQueue->Length() == 2)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenTwo();
                }
                else if (this->TurnstileQueue->Length() == 1)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenOne();
                }
            }
        }
        else
        {
            // Strict mode is on, assigning seats based on the specified value
            switch (this->StrictValue)
            {
            case 4:
                if (this->TurnstileQueue->Length() >= 4)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenFour();
                }
                break;
            case 3:
                if (this->TurnstileQueue->Length() >= 3)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenThree();
                }
                break;
            case 2:
                if (this->TurnstileQueue->Length() >= 2)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenTwo();
                }
                break;
            case 1:
                if (this->TurnstileQueue->Length() >= 1)
                {
                    (*this->TurnstileQueue).GetFirst()->Activate();
                    this->Statistics->UpdateSeatsTakenOne();
                }
                break;
            default:
                break;
            }
        }
    }
}