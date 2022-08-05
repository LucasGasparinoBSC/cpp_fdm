#ifndef EXPLICITTIME_H
#define EXPLICITTIME_H

#include <cuda_runtime.h>
#include <cuda.h>

class ExplicitTime
{
private:
    float dt;
public:
    __host__ __device__ void forwardEuler(float *rhs_dev, float *val_dev, unsigned int numPoints_h, float dt);
};

#endif // !EXPLICITTIME_H