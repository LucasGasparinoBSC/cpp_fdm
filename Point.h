#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x; // X coordinate
    float y; // Y coordinate
    float val; // Scalar value
    unsigned int id; // Global index
    unsigned int idx_x; // Index in x direction
    unsigned int idx_y; // Index in y direction
public:
    // Constructor
    Point(float x, float y, float val, unsigned int id, unsigned int idx_x, unsigned int idx_y);
    // Destructor
    ~Point();
    // Getters
    float getX();
    float getY();
    float getVal();
    unsigned int getId();
    unsigned int getIdx_x();
    unsigned int getIdx_y();
    // Setters
    void setVal(float val);
};

#endif // !POINT_H