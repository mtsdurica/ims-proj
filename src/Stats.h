#pragma once
#include <simlib.h>

class Stats final
{
    private:
        simlib3::Stat* NumOfRidesStarted;
        simlib3::Stat* NumOfRidesFinished;
        simlib3::Stat* NumOfSeatsTakenOne;
        simlib3::Stat* NumOfSeatsTakenTwo;
        simlib3::Stat* NumOfSeatsTakenThree;
        simlib3::Stat* NumOfSeatsTakenFour;
        simlib3::Histogram* Arrival;
    public:
        Stats();
        ~Stats();
        void Output();
        void UpdateArrival(double);
        void UpdateRidesStarted(double);
        void UpdateRidesFinished(double);
        void UpdateSeatsTakenOne();
        void UpdateSeatsTakenTwo();
        void UpdateSeatsTakenThree();
        void UpdateSeatsTakenFour();
};
