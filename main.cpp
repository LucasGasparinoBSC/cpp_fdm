#include "Grid.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        cerr << "Usage: " << argv[0] << " <npx> <npy> <xLeft> <xRight>" << endl;
        return 1;
    }

    unsigned int npx = atoi(argv[1]);
    unsigned int npy = atoi(argv[2]);
    float xLeft = atof(argv[3]);
    float xRight = atof(argv[4]);

    Grid grid1(npx, npy, xLeft, xRight);

    // Create grid points

    return 0;
}
