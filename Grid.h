#ifndef GRID_H
#define GRID_H

#include "Point.h"
#include <vector>

class Grid
{
private:
    unsigned int npx; // Nodes in x direction
    unsigned int npy; // Nodes in y direction
    float xMin; // Minimum x value
    float xMax; // Maximum x value
    unsigned int numPoints; // Number of points in grid
    float sideLength; // Side length of grid
    float nodeSpacing; // Node spacing
    float cellSize();
    std::vector<Point> points;
public:
    Grid(unsigned int npx, unsigned int npy, float xLeft, float xRight);
    ~Grid();
    void printAttributes();
};

#endif // !GRID_H