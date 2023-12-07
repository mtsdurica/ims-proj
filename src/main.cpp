#include "Skicentrum.h"
#include "utils.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
    Skicentrum::Simulate(parseArgs(argc, argv));
    return EXIT_SUCCESS;
}
