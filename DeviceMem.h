#ifndef DEVICEMEM_H
#define DEVICEMEM_H

#include <cuda_runtime.h>
#include <cuda.h>

class DeviceMem
{
private:
    /* data */
    float *val_dev;
    void allocDeviceMemory(unsigned int numPoints_h);
    void copyHtoD(float *hostVal, unsigned int numPoints_h);
public:
    DeviceMem(unsigned int numPoints_h, float *hostVal);
    ~DeviceMem();
};

#endif // !DEVICEMEM_H