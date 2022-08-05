#ifndef DEVICEMEM_H
#define DEVICEMEM_H

#include <cuda_runtime.h>
#include <cuda.h>
class DeviceMem
{
private:
    /* data */
    float *deviceVal;
    void allocDeviceMemory(unsigned int numPoints);
    void copyHtoD(float *hostVal, unsigned int numPoints);
public:
    DeviceMem(unsigned int numPoints, float *hostVal);
    ~DeviceMem();
};

#endif // !DEVICEMEM_H