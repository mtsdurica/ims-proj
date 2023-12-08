/**
 * @file Timer.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains declaration of class Timer
 *
 */

#pragma once

#include <simlib.h>

#include "Skilift.hpp"

class Timer final : public simlib3::Event
{
private:
    class Skilift *Skilift;

public:
    Timer(class Skilift *);
    ~Timer();
    void Behavior() override;
};
