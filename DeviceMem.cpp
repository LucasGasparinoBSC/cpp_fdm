#include "DeviceMem.h"

void DeviceMem::allocDeviceMemory(unsigned int numPoints)
{
    cudaMalloc((void**) &deviceVal, numPoints * sizeof(float));
}

void DeviceMem::copyHtoD(float *hostVal, unsigned int numPoints)
{
    cudaMemcpy(deviceVal, & hostVal, numPoints * sizeof(float), cudaMemcpyHostToDevice);
}

// Constructor
DeviceMem::DeviceMem(unsigned int numPoints, float *hostVal)
{
    allocDeviceMemory(numPoints);
    copyHtoD(hostVal, numPoints);
}

// Destructor
DeviceMem::~DeviceMem()
{
}