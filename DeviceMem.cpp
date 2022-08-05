#include "DeviceMem.h"
#include <cstdio>
#include <iostream>

#define gpuErrchk(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char *file, int line, bool abort=true)
{
   if (code != cudaSuccess) 
   {
      fprintf(stderr,"GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
      if (abort) exit(code);
   }
}

void DeviceMem::allocDeviceMemory(unsigned int numPoints)
{
    gpuErrchk(cudaMalloc((void**) &deviceVal, numPoints * sizeof(float)));
}

void DeviceMem::copyHtoD(float *hostVal, unsigned int numPoints)
{
    gpuErrchk(cudaMemcpy(deviceVal, hostVal, numPoints * sizeof(float), cudaMemcpyHostToDevice));
}

// Constructor
DeviceMem::DeviceMem(unsigned int numPoints, float *hostVal)
{
    std::cout << "Constructor called" << std::endl;
    allocDeviceMemory(numPoints);
    copyHtoD(hostVal, numPoints);
}

// Destructor
DeviceMem::~DeviceMem()
{
}