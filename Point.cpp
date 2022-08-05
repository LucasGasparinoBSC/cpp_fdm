#include "Point.h"

// Constructor
Point::Point(float x, float y, float val, unsigned int id, unsigned int idx_x, unsigned int idx_y):
x(x), y(y), val(val), id(id), idx_x(idx_x), idx_y(idx_y)
{
}

// Destructor
Point::~Point()
{
}

// Getter members
float Point::getX()
{
    return x;
}

float Point::getY()
{
    return y;
}

float Point::getVal()
{
    return val;
}

unsigned int Point::getId()
{
    return id;
}

unsigned int Point::getIdx_x()
{
    return idx_x;
}

unsigned int Point::getIdx_y()
{
    return idx_y;
}

// Setter members
void Point::setVal(float val)
{
    this->val = val;
}