/**
 * @file Stats.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains declaration of class Stats
 *
 */

#pragma once

#include <simlib.h>

class Stats final
{
private:
    simlib3::Stat *NumOfRidesStarted;
    simlib3::Stat *NumOfRidesFinished;
    simlib3::Stat *NumOfSeatsTakenOne;
    simlib3::Stat *NumOfSeatsTakenTwo;
    simlib3::Stat *NumOfSeatsTakenThree;
    simlib3::Stat *NumOfSeatsTakenFour;
    simlib3::Histogram *Arrival;

public:
    Stats();
    ~Stats();
    void Output() const;
    void UpdateArrival(double) const;
    void UpdateRidesStarted(double) const;
    void UpdateRidesFinished(double) const;
    void UpdateSeatsTakenOne() const;
    void UpdateSeatsTakenTwo() const;
    void UpdateSeatsTakenThree() const;
    void UpdateSeatsTakenFour() const;
};
