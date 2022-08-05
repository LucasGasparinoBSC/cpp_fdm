#ifndef GRID_H
#define GRID_H

#include "Point.h"
#include <vector>

class Grid
{
private:
    // Class data
    unsigned int npx; // Nodes in x direction
    unsigned int npy; // Nodes in y direction
    float xMin; // Minimum x value
    float xMax; // Maximum x value
    unsigned int numPoints; // Number of points in grid
    float sideLength; // Side length of grid
    float nodeSpacing; // Node spacing
    std::vector<Point> points; // Cell points
    // Private methods
    float cellSize(); // Compute cell size
    void createPoints(); // Create cell points
public:
    // Constructor
    Grid(unsigned int npx, unsigned int npy, float xLeft, float xRight);
    // Destructor
    ~Grid();
    // Getters
    float getPointX(unsigned int ipoin);
    float getPointY(unsigned int ipoin);
    float getPointVal(unsigned int ipoin);
    unsigned int getPointId(unsigned int ipoin);
    unsigned int getPointIdx_x(unsigned int ipoin);
    unsigned int getPointIdx_y(unsigned int ipoin);
    unsigned int getGridnumPoints();
    // Setters
    void setPointData(unsigned int ipoin, float val);
    // Printers
    void printAttributes();
    void printPoint(unsigned int ipoin);
};

#endif // !GRID_H