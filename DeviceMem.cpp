#include "DeviceMem.h"

void DeviceMem::allocDeviceMemory(unsigned int numPoints)
{
    cudaMalloc((void**) &deviceVal, numPoints * sizeof(float));
}

// Constructor
DeviceMem::DeviceMem(unsigned int numPoints)
{
    allocDeviceMemory(numPoints);
}

// Destructor
DeviceMem::~DeviceMem()
{
}