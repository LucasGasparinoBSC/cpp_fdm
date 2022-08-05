#include "Grid.h"
#include <iostream>

/* Private section*/

// Compute nodal spacing
float Grid::cellSize()
{
    return sideLength / ((float) (npx-1));
}

/* Public section */

// Constructor
Grid::Grid(unsigned int npx, unsigned int npy, float xLeft, float xRight):
npx(npx), npy(npy), xMin(xLeft), xMax(xRight), numPoints(npx*npy), sideLength(xRight-xLeft), nodeSpacing(cellSize())
{
    printAttributes();
}

// Destructor
Grid::~Grid()
{
}

// Print attributes
void Grid::printAttributes()
{
    std::cout << "Number of points: " << numPoints << std::endl;
    std::cout << "xMin: " << xMin << std::endl;
    std::cout << "xMax: " << xMax << std::endl;
    std::cout << "Side length: " << sideLength << std::endl;
    std::cout << "Node spacing: " << nodeSpacing << std::endl;
}