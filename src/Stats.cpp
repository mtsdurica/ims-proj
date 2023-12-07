/**
 * @file Stats.cpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains definition of class Stats methods
 *
 */

#include "Stats.hpp"

/**
 * @brief Construct a new Stats::Stats object
 *
 */
Stats::Stats()
{
    this->NumOfRidesStarted = new Stat("Number of Rides Started");
    this->NumOfRidesFinished = new Stat("Number of Rides Finished");
    this->NumOfSeatsTakenOne = new Stat("1 Taken Seat");
    this->NumOfSeatsTakenTwo = new Stat("2 Taken Seats");
    this->NumOfSeatsTakenThree = new Stat("3 Taken Seats");
    this->NumOfSeatsTakenFour = new Stat("4 Taken Seats");
    this->Arrival = new Histogram("Arrival of Skiers", 0, 30 * 60, 14);
}

/**
 * @brief Destroy the Stats::Stats object
 *
 */
Stats::~Stats()
{
    delete this->NumOfRidesStarted;
    delete this->NumOfRidesFinished;
    delete this->NumOfSeatsTakenOne;
    delete this->NumOfSeatsTakenTwo;
    delete this->NumOfSeatsTakenThree;
    delete this->NumOfSeatsTakenFour;
    delete this->Arrival;
}

/**
 * @brief Print statistics to standard output
 *
 */
void Stats::Output() const
{
    this->Arrival->Output();
    this->NumOfRidesStarted->Output();
    this->NumOfRidesFinished->Output();
    this->NumOfSeatsTakenOne->Output();
    this->NumOfSeatsTakenTwo->Output();
    this->NumOfSeatsTakenThree->Output();
    this->NumOfSeatsTakenFour->Output();
}

/**
 * @brief Update arrival statistic
 *
 * @param time Arrival time
 */
void Stats::UpdateArrival(double time) const
{
    (*this->Arrival)(time);
}

/**
 * @brief Update rides started statistic
 *
 * @param time Ride started time
 */
void Stats::UpdateRidesStarted(double time) const
{
    (*this->NumOfRidesStarted)(time);
}

/**
 * @brief Update rides finished statistic
 *
 * @param time Ride finished time
 */
void Stats::UpdateRidesFinished(double time) const
{
    (*this->NumOfRidesFinished)(time);
}

/**
 * @brief Update one taken seat statistic
 *
 */
void Stats::UpdateSeatsTakenOne() const
{
    (*this->NumOfSeatsTakenOne)(1);
}

/**
 * @brief Update two taken seats statistic
 *
 */
void Stats::UpdateSeatsTakenTwo() const
{
    (*this->NumOfSeatsTakenTwo)(1);
}

/**
 * @brief Update three taken seats statistic
 *
 */
void Stats::UpdateSeatsTakenThree() const
{
    (*this->NumOfSeatsTakenThree)(1);
}

/**
 * @brief Update four taken seats statistic
 *
 */
void Stats::UpdateSeatsTakenFour() const
{
    (*this->NumOfSeatsTakenFour)(1);
}
