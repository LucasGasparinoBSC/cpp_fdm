#include "DeviceMem.h"
#include <cstdio>
#include <iostream>

// Error checking function for CUDA API.
#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

void DeviceMem::allocDeviceMemory(unsigned int numPoints_h)
{
    gpuErrchk(cudaMalloc((void**) &val_dev, numPoints_h * sizeof(float)));
}

void DeviceMem::copyHtoD(float *hostVal, unsigned int numPoints_h)
{
    gpuErrchk(cudaMemcpy(val_dev, hostVal, numPoints_h * sizeof(float), cudaMemcpyHostToDevice));
}

// Constructor
DeviceMem::DeviceMem(unsigned int numPoints_h, float *hostVal)
{
    std::cout << "Constructor called" << std::endl;
    allocDeviceMemory(numPoints_h);
    copyHtoD(hostVal, numPoints_h);
}

// Destructor
DeviceMem::~DeviceMem()
{
}