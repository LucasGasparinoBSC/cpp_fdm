#include "ExplicitTime.h"

__host__ __device__ void ExplicitTime::forwardEuler(float *rhs_dev, float *val_dev, unsigned int numPoints_h, float dt)
{
    // Set point index based on thread ID
    unsigned int ipoin = blockIdx.x * blockDim.x + threadIdx.x;

    // Update the value of the point
    if (ipoin < numPoints_h)
    {
        val_dev[ipoin] += dt * rhs_dev[ipoin];
    }
}