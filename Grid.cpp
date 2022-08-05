#include "Grid.h"
#include <iostream>

/* Private section*/

// Compute nodal spacing
float Grid::cellSize()
{
    return sideLength / ((float) (npx-1));
}

// Create cell points
void Grid::createPoints()
{
    float x, y;
    unsigned int id, idx_x, idx_y;
    for (unsigned int i = 0; i < npx; i++)
    {
        for (unsigned int j = 0; j < npy; j++)
        {
            x = xMin + (float) (i * nodeSpacing);
            y = xMin + (float) (j * nodeSpacing);
            id = i * npy + j;
            idx_x = i;
            idx_y = j;
            points.push_back(Point(x, y, 0, id, idx_x, idx_y));
        }
    }
}

/* Public section */

// Constructor
Grid::Grid(unsigned int npx, unsigned int npy, float xLeft, float xRight):
npx(npx), npy(npy), xMin(xLeft), xMax(xRight), numPoints(npx*npy), sideLength(xRight-xLeft), nodeSpacing(cellSize())
{
    printAttributes();
    createPoints();
    printPoints();
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

// Print points
void Grid::printPoints()
{
    for (unsigned int i = 0; i < numPoints; i++)
    {
        std::cout << "Point " << i << ": " << points[i].getX() << ", " << points[i].getY() << ", " << points[i].getVal();
        std::cout << " , " << points[i].getId() << ", " << points[i].getIdx_x() << ", " << points[i].getIdx_y() << std::endl;
    }
}