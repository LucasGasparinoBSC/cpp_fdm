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
}

// Destructor
Grid::~Grid()
{
}

// Getters
float Grid::getPointX(unsigned int ipoin)
{
    return points[ipoin].getX();
}

float Grid::getPointY(unsigned int ipoin)
{
    return points[ipoin].getY();
}

float Grid::getPointVal(unsigned int ipoin)
{
    return points[ipoin].getVal();
}

unsigned int Grid::getPointId(unsigned int ipoin)
{
    return points[ipoin].getId();
}

unsigned int Grid::getPointIdx_x(unsigned int ipoin)
{
    return points[ipoin].getIdx_x();
}

unsigned int Grid::getPointIdx_y(unsigned int ipoin)
{
    return points[ipoin].getIdx_y();
}

unsigned int Grid::getGridnumPoints()
{
    return numPoints;
}

float Grid::getGridNodeSpacing()
{
    return nodeSpacing;
}

// Setters
void Grid::setPointData(unsigned int ipoin, float val)
{
    points[ipoin].setVal(val);
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
void Grid::printPoint(unsigned int ipoin)
{
    std::cout << "Point " << ipoin << ": " << points[ipoin].getX() << ", " << points[ipoin].getY() << ", " << points[ipoin].getVal();
    std::cout << " , " << points[ipoin].getId() << ", " << points[ipoin].getIdx_x() << ", " << points[ipoin].getIdx_y() << std::endl;
}