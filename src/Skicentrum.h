#pragma once

#include <tuple>
class Skicentrum {
    public:
        Skicentrum() = delete;
        ~Skicentrum();
        static void Simulate(std::tuple<int, int, int, int, int, int>);
};
