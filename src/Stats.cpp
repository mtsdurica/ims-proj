#include "Stats.h"

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

void Stats::Output()
{
    this->Arrival->Output();
    this->NumOfRidesStarted->Output();
    this->NumOfRidesFinished->Output();
    this->NumOfSeatsTakenOne->Output();
    this->NumOfSeatsTakenTwo->Output();
    this->NumOfSeatsTakenThree->Output();
    this->NumOfSeatsTakenFour->Output();
}

void Stats::UpdateArrival(double time)
{
    (*this->Arrival)(time);
}

void Stats::UpdateRidesStarted(double time)
{
    (*this->NumOfRidesStarted)(time);
}

void Stats::UpdateRidesFinished(double time)
{
    (*this->NumOfRidesFinished)(time);
}

void Stats::UpdateSeatsTakenOne()
{
    (*this->NumOfSeatsTakenOne)(1);
}

void Stats::UpdateSeatsTakenTwo()
{
    (*this->NumOfSeatsTakenTwo)(1);
}

void Stats::UpdateSeatsTakenThree()
{
    (*this->NumOfSeatsTakenThree)(1);
}

void Stats::UpdateSeatsTakenFour()
{
    (*this->NumOfSeatsTakenFour)(1);
}
