#include "Grid.h"
#include "DeviceMem.h"
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

    /// Initialize grid with command line inputs
    unsigned int npx = atoi(argv[1]);
    unsigned int npy = atoi(argv[2]);
    float xLeft = atof(argv[3]);
    float xRight = atof(argv[4]);

    // Create a grid
    Grid grid1(npx, npy, xLeft, xRight);

    DeviceMem gpuObj(grid1.getGridnumPoints());

    return 0;
}
