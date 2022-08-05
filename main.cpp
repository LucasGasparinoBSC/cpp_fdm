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

    // Set the GPU memory
    float *tmp = new float[grid1.getGridnumPoints()];
    for (unsigned int i = 0; i < grid1.getGridnumPoints(); i++)
    {
        tmp[i] = grid1.getPointVal(i);
    }

    DeviceMem gpuObj(grid1.getGridnumPoints(), tmp);

    return 0;
}
