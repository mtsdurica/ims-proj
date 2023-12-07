/**
 * @file Skicentrum.hpp
 * @author Romana Ďuráčiová (xdurac01)
 * @author Matúš Ďurica (xduric06)
 * @brief Contains declaration of class Skicentrum
 *
 */

#pragma once

#include <tuple>
class Skicentrum
{
public:
    Skicentrum() = delete;
    ~Skicentrum();
    static void Simulate(std::tuple<int, int, int, int, int, int>);
};
