#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_runtime_api.h>
#include "common.h"
#include "switch_context.h"
#include "upper-half-wrappers.h"
#include "upper-half-cuda-wrappers.h"
#include "cuda_autogen_wrappers.h"
#include "log_and_replay.h"
/* ------------ Cuda APIs ------------- */



#undef cudaCreateTextureObject
extern "C" cudaError_t cudaCreateTextureObject(cudaTextureObject_t * pTexObject, const struct cudaResourceDesc * pResDesc, const struct cudaTextureDesc * pTexDesc, const struct cudaResourceViewDesc * pResViewDesc) {
  typedef cudaError_t (*cudaCreateTextureObject_t)(cudaTextureObject_t * pTexObject, const struct cudaResourceDesc * pResDesc, const struct cudaTextureDesc * pTexDesc, const struct cudaResourceViewDesc * pResViewDesc);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaCreateTextureObject)(pTexObject, pResDesc, pTexDesc, pResViewDesc);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaCreateTextureObject, pTexObject, pResDesc, pTexDesc, pResViewDesc, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDestroyTextureObject
extern "C" cudaError_t cudaDestroyTextureObject(cudaTextureObject_t texObject) {
  typedef cudaError_t (*cudaDestroyTextureObject_t)(cudaTextureObject_t texObject);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDestroyTextureObject)(texObject);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaDestroyTextureObject, texObject, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaBindTexture
extern "C" cudaError_t cudaBindTexture ( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t size) {
  typedef cudaError_t (*cudaBindTexture_t)( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t size);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaBindTexture)(offset, texref, devPtr, desc, size);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaBindTexture2D
extern "C" cudaError_t cudaBindTexture2D ( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t width, size_t height, size_t pitch ) {
  typedef cudaError_t (*cudaBindTexture2D_t)( size_t* offset, const textureReference* texref, const void* devPtr, const cudaChannelFormatDesc* desc, size_t width, size_t height, size_t pitch );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaBindTexture2D)(offset, texref, devPtr, desc, width, height, pitch);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaBindTextureToArray
extern "C" cudaError_t cudaBindTextureToArray ( const textureReference* texref, cudaArray_const_t array, const cudaChannelFormatDesc* desc ) {
  typedef cudaError_t (*cudaBindTextureToArray_t)( const textureReference* texref, cudaArray_const_t array, const cudaChannelFormatDesc* desc );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaBindTextureToArray)(texref, array, desc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaUnbindTexture
extern "C" cudaError_t cudaUnbindTexture(const struct textureReference * texref) {
  typedef cudaError_t (*cudaUnbindTexture_t)(const struct textureReference * texref);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaUnbindTexture)(texref);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaCreateChannelDesc
extern "C" cudaChannelFormatDesc cudaCreateChannelDesc ( int  x, int  y, int  z, int  w, cudaChannelFormatKind f ) {
  typedef cudaChannelFormatDesc (*cudaCreateChannelDesc_t)( int  x, int  y, int  z, int  w, cudaChannelFormatKind f );
  cudaChannelFormatDesc ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaCreateChannelDesc)(x, y, z, w, f);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaCreateChannelDesc, x, y, z, w, f, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Cuda event related APIs */

#undef cudaEventCreate
extern "C" cudaError_t cudaEventCreate(cudaEvent_t * event) {
  typedef cudaError_t (*cudaEventCreate_t)(cudaEvent_t * event);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventCreate)(event);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaEventCreate, event, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventCreateWithFlags
extern "C" cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned int flags) {
  typedef cudaError_t (*cudaEventCreateWithFlags_t)(cudaEvent_t * event, unsigned int flags);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventCreateWithFlags)(event, flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaEventCreateWithFlags, event, flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventDestroy
extern "C" cudaError_t cudaEventDestroy(cudaEvent_t event) {
  typedef cudaError_t (*cudaEventDestroy_t)(cudaEvent_t event);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventDestroy)(event);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaEventDestroy, event, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventElapsedTime
extern "C" cudaError_t cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end) {
  typedef cudaError_t (*cudaEventElapsedTime_t)(float * ms, cudaEvent_t start, cudaEvent_t end);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventElapsedTime)(ms, start, end);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventQuery
extern "C" cudaError_t cudaEventQuery(cudaEvent_t event) {
  typedef cudaError_t (*cudaEventQuery_t)(cudaEvent_t event);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventQuery)(event);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventRecord
extern "C" cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream) {
  typedef cudaError_t (*cudaEventRecord_t)(cudaEvent_t event, cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventRecord)(event, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaEventSynchronize
extern "C" cudaError_t cudaEventSynchronize(cudaEvent_t event) {
  typedef cudaError_t (*cudaEventSynchronize_t)(cudaEvent_t event);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaEventSynchronize)(event);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ----- Malloc and Free related APIs ----- */

#undef cudaMalloc
extern "C" cudaError_t cudaMalloc(void ** pointer, size_t size) {
  typedef cudaError_t (*cudaMalloc_t)(void ** pointer, size_t size);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 cudamalloc  \n");

  ret_val = REAL_FNC(cudaMalloc)(pointer, size);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaMalloc, pointer, size, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaFree
extern "C" cudaError_t cudaFree ( void * pointer ) {
  typedef cudaError_t (*cudaFree_t)( void * pointer );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaFree)(pointer);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaFree, pointer, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaMallocArray
extern "C" cudaError_t cudaMallocArray(struct cudaArray ** array, const struct cudaChannelFormatDesc * desc, size_t width, size_t height, unsigned int flags) {
  typedef cudaError_t (*cudaMallocArray_t)(struct cudaArray ** array, const struct cudaChannelFormatDesc * desc, size_t width, size_t height, unsigned int flags);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMallocArray)(array, desc, width, height, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaFreeArray
extern "C" cudaError_t cudaFreeArray(struct cudaArray * array) {
  typedef cudaError_t (*cudaFreeArray_t)(struct cudaArray * array);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaFreeArray)(array);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Host related APIs */

#undef cudaHostRegister
extern "C" cudaError_t cudaHostRegister ( void* ptr, size_t size, unsigned int  flags ) {
  typedef cudaError_t (*cudaHostRegister_t)( void* ptr, size_t size, unsigned int  flags );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaHostRegister)(ptr, size, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceGetAttribute
extern "C" cudaError_t cudaDeviceGetAttribute ( int* value, cudaDeviceAttr attr, int  device ) {
  typedef cudaError_t (*cudaDeviceGetAttribute_t)( int* value, cudaDeviceAttr attr, int  device );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceGetAttribute)(value, attr, device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaMallocHost
extern "C" cudaError_t cudaMallocHost ( void ** ptr , size_t size ) {
  typedef cudaError_t (*cudaMallocHost_t)( void ** ptr , size_t size );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMallocHost)(ptr, size);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaFreeHost
extern "C" cudaError_t cudaFreeHost ( void* ptr ) {
  typedef cudaError_t (*cudaFreeHost_t)( void* ptr );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaFreeHost)(ptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaHostAlloc
extern "C" cudaError_t cudaHostAlloc ( void ** ptr , size_t size , unsigned int flags ) {
  typedef cudaError_t (*cudaHostAlloc_t)( void ** ptr , size_t size , unsigned int flags );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaHostAlloc)(ptr, size, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaMallocPitch
extern "C" cudaError_t cudaMallocPitch(void ** devPtr, size_t * pitch, size_t width, size_t height) {
  typedef cudaError_t (*cudaMallocPitch_t)(void ** devPtr, size_t * pitch, size_t width, size_t height);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMallocPitch)(devPtr, pitch, width, height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Device related APIs */

#undef cudaGetDevice
extern "C" cudaError_t cudaGetDevice(int * device) {
  typedef cudaError_t (*cudaGetDevice_t)(int * device);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetDevice)(device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaSetDevice
extern "C" cudaError_t cudaSetDevice(int device) {
  typedef cudaError_t (*cudaSetDevice_t)(int device);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaSetDevice)(device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceGetLimit
extern "C" cudaError_t cudaDeviceGetLimit ( size_t* pValue, cudaLimit limit ) {
  typedef cudaError_t (*cudaDeviceGetLimit_t)( size_t* pValue, cudaLimit limit );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceGetLimit)(pValue, limit);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceSetLimit
extern "C" cudaError_t cudaDeviceSetLimit ( cudaLimit limit, size_t value ) {
  typedef cudaError_t (*cudaDeviceSetLimit_t)( cudaLimit limit, size_t value );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceSetLimit)(limit, value);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaGetDeviceCount
extern "C" cudaError_t cudaGetDeviceCount(int * count) {
  typedef cudaError_t (*cudaGetDeviceCount_t)(int * count);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetDeviceCount)(count);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceSetCacheConfig
extern "C" cudaError_t cudaDeviceSetCacheConfig ( cudaFuncCache cacheConfig ) {
  typedef cudaError_t (*cudaDeviceSetCacheConfig_t)( cudaFuncCache cacheConfig );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceSetCacheConfig)(cacheConfig);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaGetDeviceProperties
extern "C" cudaError_t cudaGetDeviceProperties ( cudaDeviceProp* prop, int  device ) {
  typedef cudaError_t (*cudaGetDeviceProperties_t)( cudaDeviceProp* prop, int  device );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetDeviceProperties)(prop, device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceCanAccessPeer
extern "C" cudaError_t cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice) {
  typedef cudaError_t (*cudaDeviceCanAccessPeer_t)(int * canAccessPeer, int device, int peerDevice);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceCanAccessPeer)(canAccessPeer, device, peerDevice);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceGetPCIBusId
extern "C" cudaError_t cudaDeviceGetPCIBusId(char * pciBusId, int len, int device) {
  typedef cudaError_t (*cudaDeviceGetPCIBusId_t)(char * pciBusId, int len, int device);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceGetPCIBusId)(pciBusId, len, device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* @LogReplay */

#undef cudaDeviceReset
extern "C" cudaError_t cudaDeviceReset() {
  typedef cudaError_t (*cudaDeviceReset_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceReset)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaDeviceSynchronize
extern "C" cudaError_t cudaDeviceSynchronize() {
  typedef cudaError_t (*cudaDeviceSynchronize_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaDeviceSynchronize)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a device function Note: This function is deprecated as of CUDA 7.0 */
/* cudaError_t cudaLaunch(const void * func)*/

#undef cudaLaunchKernel
extern "C" cudaError_t cudaLaunchKernel ( const void* func, dim3 gridDim, dim3 blockDim, void** args, size_t sharedMem, cudaStream_t stream ) {
  typedef cudaError_t (*cudaLaunchKernel_t)( const void* func, dim3 gridDim, dim3 blockDim, void** args, size_t sharedMem, cudaStream_t stream );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf( "✋enter 拦截的  cudaLaunchKernel \n");

  ret_val = REAL_FNC(cudaLaunchKernel)(func, gridDim, blockDim, args, sharedMem, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, size_t sharedMem, cudaStream_t stream)*/
/* Cuda UVM APIs */

#undef cudaMallocManaged
extern "C" cudaError_t cudaMallocManaged ( void** devPtr, size_t size, unsigned int  flags) {
  typedef cudaError_t (*cudaMallocManaged_t)( void** devPtr, size_t size, unsigned int  flags);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMallocManaged)(devPtr, size, flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaMallocManaged, devPtr, size, flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Cuda Memory management realated APIs */

#undef cudaMemcpy
extern "C" cudaError_t cudaMemcpy ( void* dst, const void* src, size_t count, cudaMemcpyKind kind ) {
  typedef cudaError_t (*cudaMemcpy_t)( void* dst, const void* src, size_t count, cudaMemcpyKind kind );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 cudamemcpy  \n");
  ret_val = REAL_FNC(cudaMemcpy)(dst, src, count, kind);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemcpy2D
extern "C" cudaError_t cudaMemcpy2D ( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind ) {
  typedef cudaError_t (*cudaMemcpy2D_t)( void* dst, size_t dpitch, const void* src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemcpy2D)(dst, dpitch, src, spitch, width, height, kind);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemcpyToArray
extern "C" cudaError_t cudaMemcpyToArray (cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t count, cudaMemcpyKind kind ) {
  typedef cudaError_t (*cudaMemcpyToArray_t)(cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src, size_t count, cudaMemcpyKind kind );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemcpyToArray)(dst, wOffset, hOffset, src, count, kind);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemcpyToSymbol
extern "C" cudaError_t cudaMemcpyToSymbol ( const void* symbol, const void* src, size_t count, size_t offset, cudaMemcpyKind kind) {
  typedef cudaError_t (*cudaMemcpyToSymbol_t)( const void* symbol, const void* src, size_t count, size_t offset, cudaMemcpyKind kind);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemcpyToSymbol)(symbol, src, count, offset, kind);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemcpyAsync
extern "C" cudaError_t cudaMemcpyAsync ( void* dst, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream) {
  typedef cudaError_t (*cudaMemcpyAsync_t)( void* dst, const void* src, size_t count, cudaMemcpyKind kind, cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemcpyAsync)(dst, src, count, kind, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemset
extern "C" cudaError_t cudaMemset(void * devPtr, int value, size_t count) {
  typedef cudaError_t (*cudaMemset_t)(void * devPtr, int value, size_t count);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemset)(devPtr, value, count);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemset2D
extern "C" cudaError_t cudaMemset2D ( void* devPtr, size_t pitch, int value, size_t width, size_t height ) {
  typedef cudaError_t (*cudaMemset2D_t)( void* devPtr, size_t pitch, int value, size_t width, size_t height );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemset2D)(devPtr, pitch, value, width, height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemsetAsync
extern "C" cudaError_t cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream) {
  typedef cudaError_t (*cudaMemsetAsync_t)(void * devPtr, int value, size_t count, cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemsetAsync)(devPtr, value, count, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemGetInfo
extern "C" cudaError_t cudaMemGetInfo(size_t * free, size_t * total) {
  typedef cudaError_t (*cudaMemGetInfo_t)(size_t * free, size_t * total);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemGetInfo)(free, total);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemAdvise
extern "C" cudaError_t cudaMemAdvise(const void * devPtr, size_t count, enum cudaMemoryAdvise advice, int device) {
  typedef cudaError_t (*cudaMemAdvise_t)(const void * devPtr, size_t count, enum cudaMemoryAdvise advice, int device);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemAdvise)(devPtr, count, advice, device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaMemPrefetchAsync
extern "C" cudaError_t cudaMemPrefetchAsync(const void * devPtr, size_t count, int dstDevice, cudaStream_t stream) {
  typedef cudaError_t (*cudaMemPrefetchAsync_t)(const void * devPtr, size_t count, int dstDevice, cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaMemPrefetchAsync)(devPtr, count, dstDevice, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* cudaError_t cudaSetupArgument(const void * arg, size_t size, size_t offset)*/
/* ---- Cuda Stream related APIs ---- */

#undef cudaStreamCreate
extern "C" cudaError_t cudaStreamCreate(cudaStream_t * pStream) {
  typedef cudaError_t (*cudaStreamCreate_t)(cudaStream_t * pStream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamCreate)(pStream);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaStreamCreate, pStream, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaStreamCreateWithPriority
extern "C" cudaError_t cudaStreamCreateWithPriority ( cudaStream_t* pStream, unsigned int  flags, int  priority ) {
  typedef cudaError_t (*cudaStreamCreateWithPriority_t)( cudaStream_t* pStream, unsigned int  flags, int  priority );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamCreateWithPriority)(pStream, flags, priority);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaStreamCreateWithPriority, pStream, flags, priority, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaStreamCreateWithFlags
extern "C" cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned int flags) {
  typedef cudaError_t (*cudaStreamCreateWithFlags_t)(cudaStream_t * pStream, unsigned int flags);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamCreateWithFlags)(pStream, flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaStreamCreateWithFlags, pStream, flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaStreamDestroy
extern "C" cudaError_t cudaStreamDestroy(cudaStream_t stream) {
  typedef cudaError_t (*cudaStreamDestroy_t)(cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamDestroy)(stream);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cudaStreamDestroy, stream, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaStreamSynchronize
extern "C" cudaError_t cudaStreamSynchronize(cudaStream_t stream) {
  typedef cudaError_t (*cudaStreamSynchronize_t)(cudaStream_t stream);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamSynchronize)(stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaStreamWaitEvent
extern "C" cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned int flags) {
  typedef cudaError_t (*cudaStreamWaitEvent_t)(cudaStream_t stream, cudaEvent_t event, unsigned int flags);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaStreamWaitEvent)(stream, event, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Thread related APIs (deprecated) */

#undef cudaThreadSynchronize
extern "C" cudaError_t cudaThreadSynchronize () {
  typedef cudaError_t (*cudaThreadSynchronize_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaThreadSynchronize)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaThreadExit
extern "C" cudaError_t cudaThreadExit () {
  typedef cudaError_t (*cudaThreadExit_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaThreadExit)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Miscellaneous API */

#undef cudaPointerGetAttributes
extern "C" cudaError_t cudaPointerGetAttributes ( cudaPointerAttributes* attributes, const void* ptr ) {
  typedef cudaError_t (*cudaPointerGetAttributes_t)( cudaPointerAttributes* attributes, const void* ptr );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaPointerGetAttributes)(attributes, ptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaGetErrorString
extern "C" const char* cudaGetErrorString ( cudaError_t error ) {
  typedef const char* (*cudaGetErrorString_t)( cudaError_t error );
  const char* ret_val = NULL;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetErrorString)(error);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaGetErrorName
extern "C" const char* cudaGetErrorName ( cudaError_t error ) {
  typedef const char* (*cudaGetErrorName_t)( cudaError_t error );
  const char* ret_val = NULL;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetErrorName)(error);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaGetLastError
extern "C" cudaError_t cudaGetLastError() {
  typedef cudaError_t (*cudaGetLastError_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaGetLastError)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaPeekAtLastError
extern "C" cudaError_t cudaPeekAtLastError() {
  typedef cudaError_t (*cudaPeekAtLastError_t)();
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaPeekAtLastError)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaFuncSetCacheConfig
extern "C" cudaError_t cudaFuncSetCacheConfig ( const void* func, cudaFuncCache cacheConfig ) {
  typedef cudaError_t (*cudaFuncSetCacheConfig_t)( const void* func, cudaFuncCache cacheConfig );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaFuncSetCacheConfig)(func, cacheConfig);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ---------- CUDART INTERNAL APIs ----------- */

#undef __cudaInitModule
extern "C" char __cudaInitModule(void **fatCubinHandle) {
  typedef char (*__cudaInitModule_t)(void **fatCubinHandle);
  char ret_val = 0;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(__cudaInitModule)(fatCubinHandle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaInitModule, fatCubinHandle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef __cudaPopCallConfiguration
extern "C" cudaError_t __cudaPopCallConfiguration( dim3 *gridDim, dim3 *blockDim, size_t *sharedMem, void *stream ) {
  typedef cudaError_t (*__cudaPopCallConfiguration_t)( dim3 *gridDim, dim3 *blockDim, size_t *sharedMem, void *stream );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 popcallconfiguration  \n");
  ret_val = REAL_FNC(__cudaPopCallConfiguration)(gridDim, blockDim, sharedMem, stream);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaPopCallConfiguration, gridDim, blockDim, sharedMem, stream, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef __cudaPushCallConfiguration
extern "C" unsigned int __cudaPushCallConfiguration( dim3 gridDim, dim3 blockDim, size_t sharedMem, void * stream ) {
  typedef unsigned int (*__cudaPushCallConfiguration_t)( dim3 gridDim, dim3 blockDim, size_t sharedMem, void * stream );
  unsigned int ret_val = 0;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 pushcallconfiguration  \n");
  ret_val = REAL_FNC(__cudaPushCallConfiguration)(gridDim, blockDim, sharedMem, stream);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaPushCallConfiguration, gridDim, blockDim, sharedMem, stream, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef __cudaRegisterFatBinary
extern "C" void** __cudaRegisterFatBinary(void *fatCubin) {
  typedef void** (*__cudaRegisterFatBinary_t)(void *fatCubin);
  void** ret_val = NULL;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 registerfatbinary  \n");
  ret_val = REAL_FNC(__cudaRegisterFatBinary)(fatCubin);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterFatBinary, fatCubin, ret_val);
  global_fatCubinHandle = ret_val;
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef __cudaUnregisterFatBinary
extern "C" void __cudaUnregisterFatBinary(void **fatCubinHandle) {
  typedef void (*__cudaUnregisterFatBinary_t)(void **fatCubinHandle);
  fatHandle_t fat= NULL;
 // fat = (fatHandle_t)lhInfo.new_getFatCubinHandle;
  fat = (fatHandle_t)lhInfo.getFatCubinHandle;
  DMTCP_PLUGIN_DISABLE_CKPT();
  if (fat() == NULL) {
   fatCubinHandle = global_fatCubinHandle;
  } else {
   fatCubinHandle = fat();
  }
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  REAL_FNC(__cudaUnregisterFatBinary)( fatCubinHandle );
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaUnregisterFatBinary, fatCubinHandle);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef __cudaRegisterFunction
extern "C" void __cudaRegisterFunction( void **fatCubinHandle, const char *hostFun, char *deviceFun, const char *deviceName, int thread_limit, uint3 *tid, uint3 *bid, dim3 *bDim, dim3 *gDim, int *wSize ) {
  typedef void (*__cudaRegisterFunction_t)( void **fatCubinHandle, const char *hostFun, char *deviceFun, const char *deviceName, int thread_limit, uint3 *tid, uint3 *bid, dim3 *bDim, dim3 *gDim, int *wSize );
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 registerfunction  \n");
  REAL_FNC(__cudaRegisterFunction)(fatCubinHandle, hostFun, deviceFun, deviceName, thread_limit, tid, bid, bDim, gDim, wSize);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterFunction, fatCubinHandle, hostFun, deviceFun, deviceName, thread_limit, tid, bid, bDim, gDim, wSize);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef __cudaRegisterManagedVar
extern "C" void __cudaRegisterManagedVar( void **fatCubinHandle, void **hostVarPtrAddress, char  *deviceAddress, const char  *deviceName, int    ext, size_t size, int    constant, int    global ) {
  typedef void (*__cudaRegisterManagedVar_t)( void **fatCubinHandle, void **hostVarPtrAddress, char  *deviceAddress, const char  *deviceName, int    ext, size_t size, int    constant, int    global );
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  REAL_FNC(__cudaRegisterManagedVar)(fatCubinHandle, hostVarPtrAddress, deviceAddress, deviceName, ext, size, constant, global);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterManagedVar, fatCubinHandle, hostVarPtrAddress, deviceAddress, deviceName, ext, size, constant, global);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef __cudaRegisterTexture
extern "C" void __cudaRegisterTexture( void  **fatCubinHandle, const struct textureReference  *hostVar, const void **deviceAddress, const char *deviceName, int dim, int norm, int ext ) {
  typedef void (*__cudaRegisterTexture_t)( void  **fatCubinHandle, const struct textureReference  *hostVar, const void **deviceAddress, const char *deviceName, int dim, int norm, int ext );
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  REAL_FNC(__cudaRegisterTexture)(fatCubinHandle, hostVar, deviceAddress, deviceName, dim, norm, ext);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterTexture, fatCubinHandle, hostVar, deviceAddress, deviceName, dim, norm, ext);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef __cudaRegisterSurface
extern "C" void __cudaRegisterSurface( void **fatCubinHandle, const struct surfaceReference  *hostVar, const void **deviceAddress, const char *deviceName, int dim, int ext ) {
  typedef void (*__cudaRegisterSurface_t)( void **fatCubinHandle, const struct surfaceReference  *hostVar, const void **deviceAddress, const char *deviceName, int dim, int ext );
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  REAL_FNC(__cudaRegisterSurface)(fatCubinHandle, hostVar, deviceAddress, deviceName, dim, ext);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterSurface, fatCubinHandle, hostVar, deviceAddress, deviceName, dim, ext);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef __cudaRegisterVar
extern "C" void __cudaRegisterVar(void **fatCubinHandle, char *hostVar, char  *deviceAddress, const char  *deviceName, int ext, size_t size, int constant, int global) {
  typedef void (*__cudaRegisterVar_t)(void **fatCubinHandle, char *hostVar, char  *deviceAddress, const char  *deviceName, int ext, size_t size, int constant, int global);
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 __cudaRegisterVar  \n");
  
  REAL_FNC(__cudaRegisterVar)(fatCubinHandle, hostVar, deviceAddress, deviceName, ext, size, constant, global);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterVar, fatCubinHandle, hostVar, deviceAddress, deviceName, ext, size, constant, global);
  DMTCP_PLUGIN_ENABLE_CKPT();
}


#undef cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
extern "C" cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags ( int* numBlocks, const void* func, int  blockSize, size_t dynamicSMemSize, unsigned int  flags ) {
  typedef cudaError_t (*cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_t)( int* numBlocks, const void* func, int  blockSize, size_t dynamicSMemSize, unsigned int  flags );
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags)(numBlocks, func, blockSize, dynamicSMemSize, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cudaFuncGetAttributes
extern "C" cudaError_t cudaFuncGetAttributes(struct cudaFuncAttributes *attr, const void *func) {
  typedef cudaError_t (*cudaFuncGetAttributes_t)(struct cudaFuncAttributes *attr, const void *func);
  cudaError_t ret_val = cudaSuccess;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cudaFuncGetAttributes)(attr, func);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ----------- CUBLAS APIs ------------ */

#undef cublasCreate_v2
extern "C" cublasStatus_t cublasCreate_v2(cublasHandle_t * handle) {
  typedef cublasStatus_t (*cublasCreate_v2_t)(cublasHandle_t * handle);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasCreate_v2)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cublasCreate_v2, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasSetStream_v2
extern "C" cublasStatus_t cublasSetStream_v2(cublasHandle_t handle, cudaStream_t streamId) {
  typedef cublasStatus_t (*cublasSetStream_v2_t)(cublasHandle_t handle, cudaStream_t streamId);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasSetStream_v2)(handle, streamId);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDdot_v2
extern "C" cublasStatus_t cublasDdot_v2(cublasHandle_t handle, int n, const double * x, int incx, const double * y, int incy, double * result) {
  typedef cublasStatus_t (*cublasDdot_v2_t)(cublasHandle_t handle, int n, const double * x, int incx, const double * y, int incy, double * result);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDdot_v2)(handle, n, x, incx, y, incy, result);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDestroy_v2
extern "C" cublasStatus_t cublasDestroy_v2(cublasHandle_t handle) {
  typedef cublasStatus_t (*cublasDestroy_v2_t)(cublasHandle_t handle);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDestroy_v2)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cublasDestroy_v2, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDaxpy_v2
extern "C" cublasStatus_t cublasDaxpy_v2(cublasHandle_t handle, int n, const double * alpha, const double * x, int incx, double * y, int incy) {
  typedef cublasStatus_t (*cublasDaxpy_v2_t)(cublasHandle_t handle, int n, const double * alpha, const double * x, int incx, double * y, int incy);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDaxpy_v2)(handle, n, alpha, x, incx, y, incy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDasum_v2
extern "C" cublasStatus_t cublasDasum_v2(cublasHandle_t handle, int n, const double *x, int incx, double *result) {
  typedef cublasStatus_t (*cublasDasum_v2_t)(cublasHandle_t handle, int n, const double *x, int incx, double *result);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDasum_v2)(handle, n, x, incx, result);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDgemm_v2
extern "C" cublasStatus_t cublasDgemm_v2 (cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, const double *alpha, const double *A, int lda, const double *B, int ldb, const double *beta, double *C, int ldc) {
  typedef cublasStatus_t (*cublasDgemm_v2_t)(cublasHandle_t handle, cublasOperation_t transa, cublasOperation_t transb, int m, int n, int k, const double *alpha, const double *A, int lda, const double *B, int ldb, const double *beta, double *C, int ldc);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDgemm_v2)(handle, transa, transb, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDgemv_v2
extern "C" cublasStatus_t cublasDgemv_v2 (cublasHandle_t handle, cublasOperation_t trans, int m, int n, const double *alpha, const double *A, int lda, const double *x, int incx, const double *beta, double *y, int incy) {
  typedef cublasStatus_t (*cublasDgemv_v2_t)(cublasHandle_t handle, cublasOperation_t trans, int m, int n, const double *alpha, const double *A, int lda, const double *x, int incx, const double *beta, double *y, int incy);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDgemv_v2)(handle, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDnrm2_v2
extern "C" cublasStatus_t cublasDnrm2_v2(cublasHandle_t handle, int n, const double *x, int incx, double *result) {
  typedef cublasStatus_t (*cublasDnrm2_v2_t)(cublasHandle_t handle, int n, const double *x, int incx, double *result);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDnrm2_v2)(handle, n, x, incx, result);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDscal_v2
extern "C" cublasStatus_t cublasDscal_v2(cublasHandle_t handle, int n, const double *alpha, double *x, int incx) {
  typedef cublasStatus_t (*cublasDscal_v2_t)(cublasHandle_t handle, int n, const double *alpha, double *x, int incx);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDscal_v2)(handle, n, alpha, x, incx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasDswap_v2
extern "C" cublasStatus_t cublasDswap_v2 (cublasHandle_t handle, int n, double *x, int incx, double *y, int incy) {
  typedef cublasStatus_t (*cublasDswap_v2_t)(cublasHandle_t handle, int n, double *x, int incx, double *y, int incy);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasDswap_v2)(handle, n, x, incx, y, incy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cublasIdamax_v2
extern "C" cublasStatus_t cublasIdamax_v2(cublasHandle_t handle, int n, const double *x, int incx, int *result) {
  typedef cublasStatus_t (*cublasIdamax_v2_t)(cublasHandle_t handle, int n, const double *x, int incx, int *result);
  cublasStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cublasIdamax_v2)(handle, n, x, incx, result);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ----------- CUSPARSE APIs ------------ */

#undef cusparseCreate
extern "C" cusparseStatus_t cusparseCreate(cusparseHandle_t *handle) {
  typedef cusparseStatus_t (*cusparseCreate_t)(cusparseHandle_t *handle);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseCreate)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseCreate, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetStream
extern "C" cusparseStatus_t cusparseSetStream(cusparseHandle_t handle, cudaStream_t streamId) {
  typedef cusparseStatus_t (*cusparseSetStream_t)(cusparseHandle_t handle, cudaStream_t streamId);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetStream)(handle, streamId);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseCreateMatDescr
extern "C" cusparseStatus_t cusparseCreateMatDescr(cusparseMatDescr_t *descrA) {
  typedef cusparseStatus_t (*cusparseCreateMatDescr_t)(cusparseMatDescr_t *descrA);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseCreateMatDescr)(descrA);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseCreateMatDescr, descrA, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetMatType
extern "C" cusparseStatus_t cusparseSetMatType(cusparseMatDescr_t descrA, cusparseMatrixType_t type) {
  typedef cusparseStatus_t (*cusparseSetMatType_t)(cusparseMatDescr_t descrA, cusparseMatrixType_t type);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetMatType)(descrA, type);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetMatIndexBase
extern "C" cusparseStatus_t cusparseSetMatIndexBase(cusparseMatDescr_t descrA, cusparseIndexBase_t base) {
  typedef cusparseStatus_t (*cusparseSetMatIndexBase_t)(cusparseMatDescr_t descrA, cusparseIndexBase_t base);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetMatIndexBase)(descrA, base);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDestroy
extern "C" cusparseStatus_t cusparseDestroy(cusparseHandle_t handle) {
  typedef cusparseStatus_t (*cusparseDestroy_t)(cusparseHandle_t handle);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDestroy)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseDestroy, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDestroyMatDescr
extern "C" cusparseStatus_t cusparseDestroyMatDescr (cusparseMatDescr_t descrA) {
  typedef cusparseStatus_t (*cusparseDestroyMatDescr_t)(cusparseMatDescr_t descrA);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDestroyMatDescr)(descrA);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseDestroyMatDescr, descrA, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* hybrid (HYB) format */

#undef cusparseCreateHybMat
extern "C" cusparseStatus_t cusparseCreateHybMat(cusparseHybMat_t *hybA) {
  typedef cusparseStatus_t (*cusparseCreateHybMat_t)(cusparseHybMat_t *hybA);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseCreateHybMat)(hybA);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseCreateHybMat, hybA, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDestroyHybMat
extern "C" cusparseStatus_t cusparseDestroyHybMat(cusparseHybMat_t hybA) {
  typedef cusparseStatus_t (*cusparseDestroyHybMat_t)(cusparseHybMat_t hybA);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDestroyHybMat)(hybA);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseDestroyHybMat, hybA, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* sparse triangular solve and incomplete-LU and Cholesky (algorithm 1) */

#undef cusparseCreateSolveAnalysisInfo
extern "C" cusparseStatus_t cusparseCreateSolveAnalysisInfo(cusparseSolveAnalysisInfo_t *info) {
  typedef cusparseStatus_t (*cusparseCreateSolveAnalysisInfo_t)(cusparseSolveAnalysisInfo_t *info);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseCreateSolveAnalysisInfo)(info);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseCreateSolveAnalysisInfo, info, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDestroySolveAnalysisInfo
extern "C" cusparseStatus_t cusparseDestroySolveAnalysisInfo(cusparseSolveAnalysisInfo_t info) {
  typedef cusparseStatus_t (*cusparseDestroySolveAnalysisInfo_t)(cusparseSolveAnalysisInfo_t info);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDestroySolveAnalysisInfo)(info);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusparseDestroySolveAnalysisInfo, info, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDcsr2csc
extern "C" cusparseStatus_t cusparseDcsr2csc(cusparseHandle_t handle, int m, int n, int nnz, const double  *csrSortedVal, const int *csrSortedRowPtr, const int *csrSortedColInd, double *cscSortedVal, int *cscSortedRowInd, int *cscSortedColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase) {
  typedef cusparseStatus_t (*cusparseDcsr2csc_t)(cusparseHandle_t handle, int m, int n, int nnz, const double  *csrSortedVal, const int *csrSortedRowPtr, const int *csrSortedColInd, double *cscSortedVal, int *cscSortedRowInd, int *cscSortedColPtr, cusparseAction_t copyValues, cusparseIndexBase_t idxBase);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDcsr2csc)(handle, m, n, nnz, csrSortedVal, csrSortedRowPtr, csrSortedColInd, cscSortedVal, cscSortedRowInd, cscSortedColPtr, copyValues, idxBase);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDcsr2hyb
extern "C" cusparseStatus_t cusparseDcsr2hyb(cusparseHandle_t handle, int m, int n, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseHybMat_t hybA, int userEllWidth, cusparseHybPartition_t partitionType) {
  typedef cusparseStatus_t (*cusparseDcsr2hyb_t)(cusparseHandle_t handle, int m, int n, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseHybMat_t hybA, int userEllWidth, cusparseHybPartition_t partitionType);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDcsr2hyb)(handle, m, n, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, hybA, userEllWidth, partitionType);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDcsrmv
extern "C" cusparseStatus_t cusparseDcsrmv(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, const double *alpha, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, const double *x, const double *beta, double *y) {
  typedef cusparseStatus_t (*cusparseDcsrmv_t)(cusparseHandle_t handle, cusparseOperation_t transA, int m, int n, int nnz, const double *alpha, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, const double *x, const double *beta, double *y);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDcsrmv)(handle, transA, m, n, nnz, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, x, beta, y);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDcsrsv_analysis
extern "C" cusparseStatus_t cusparseDcsrsv_analysis(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseSolveAnalysisInfo_t info) {
  typedef cusparseStatus_t (*cusparseDcsrsv_analysis_t)(cusparseHandle_t handle, cusparseOperation_t transA, int m, int nnz, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseSolveAnalysisInfo_t info);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDcsrsv_analysis)(handle, transA, m, nnz, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDcsrsv_solve
extern "C" cusparseStatus_t cusparseDcsrsv_solve(cusparseHandle_t handle, cusparseOperation_t transA, int m, const double *alpha, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseSolveAnalysisInfo_t info, const double *f, double *x) {
  typedef cusparseStatus_t (*cusparseDcsrsv_solve_t)(cusparseHandle_t handle, cusparseOperation_t transA, int m, const double *alpha, const cusparseMatDescr_t descrA, const double *csrSortedValA, const int *csrSortedRowPtrA, const int *csrSortedColIndA, cusparseSolveAnalysisInfo_t info, const double *f, double *x);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDcsrsv_solve)(handle, transA, m, alpha, descrA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA, info, f, x);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDhyb2csr
extern "C" cusparseStatus_t cusparseDhyb2csr(cusparseHandle_t handle, const cusparseMatDescr_t descrA, const cusparseHybMat_t hybA, double *csrSortedValA, int *csrSortedRowPtrA, int *csrSortedColIndA) {
  typedef cusparseStatus_t (*cusparseDhyb2csr_t)(cusparseHandle_t handle, const cusparseMatDescr_t descrA, const cusparseHybMat_t hybA, double *csrSortedValA, int *csrSortedRowPtrA, int *csrSortedColIndA);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDhyb2csr)(handle, descrA, hybA, csrSortedValA, csrSortedRowPtrA, csrSortedColIndA);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseDhybmv
extern "C" cusparseStatus_t cusparseDhybmv(cusparseHandle_t handle, cusparseOperation_t transA, const double *alpha, const cusparseMatDescr_t descrA, const cusparseHybMat_t hybA, const double *x, const double *beta, double *y) {
  typedef cusparseStatus_t (*cusparseDhybmv_t)(cusparseHandle_t handle, cusparseOperation_t transA, const double *alpha, const cusparseMatDescr_t descrA, const cusparseHybMat_t hybA, const double *x, const double *beta, double *y);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseDhybmv)(handle, transA, alpha, descrA, hybA, x, beta, y);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseGetMatType
extern "C" cusparseMatrixType_t cusparseGetMatType(const cusparseMatDescr_t descrA) {
  typedef cusparseMatrixType_t (*cusparseGetMatType_t)(const cusparseMatDescr_t descrA);
  cusparseMatrixType_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseGetMatType)(descrA);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetMatFillMode
extern "C" cusparseStatus_t cusparseSetMatFillMode(cusparseMatDescr_t descrA, cusparseFillMode_t fillMode) {
  typedef cusparseStatus_t (*cusparseSetMatFillMode_t)(cusparseMatDescr_t descrA, cusparseFillMode_t fillMode);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetMatFillMode)(descrA, fillMode);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseGetMatFillMode
extern "C" cusparseFillMode_t cusparseGetMatFillMode(const cusparseMatDescr_t descrA) {
  typedef cusparseFillMode_t (*cusparseGetMatFillMode_t)(const cusparseMatDescr_t descrA);
  cusparseFillMode_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseGetMatFillMode)(descrA);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetMatDiagType
extern "C" cusparseStatus_t cusparseSetMatDiagType(cusparseMatDescr_t  descrA, cusparseDiagType_t diagType) {
  typedef cusparseStatus_t (*cusparseSetMatDiagType_t)(cusparseMatDescr_t  descrA, cusparseDiagType_t diagType);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetMatDiagType)(descrA, diagType);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseGetMatDiagType
extern "C" cusparseDiagType_t cusparseGetMatDiagType(const cusparseMatDescr_t descrA) {
  typedef cusparseDiagType_t (*cusparseGetMatDiagType_t)(const cusparseMatDescr_t descrA);
  cusparseDiagType_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseGetMatDiagType)(descrA);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseGetMatIndexBase
extern "C" cusparseIndexBase_t cusparseGetMatIndexBase(const cusparseMatDescr_t descrA) {
  typedef cusparseIndexBase_t (*cusparseGetMatIndexBase_t)(const cusparseMatDescr_t descrA);
  cusparseIndexBase_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseGetMatIndexBase)(descrA);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusparseSetPointerMode
extern "C" cusparseStatus_t cusparseSetPointerMode(cusparseHandle_t handle, cusparsePointerMode_t mode) {
  typedef cusparseStatus_t (*cusparseSetPointerMode_t)(cusparseHandle_t handle, cusparsePointerMode_t mode);
  cusparseStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusparseSetPointerMode)(handle, mode);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ==== cusolverDn API ==== */

#undef cusolverDnCreate
extern "C" cusolverStatus_t cusolverDnCreate(cusolverDnHandle_t *handle) {
  typedef cusolverStatus_t (*cusolverDnCreate_t)(cusolverDnHandle_t *handle);
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnCreate)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusolverDnCreate, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDestroy
extern "C" cusolverStatus_t cusolverDnDestroy(cusolverDnHandle_t handle) {
  typedef cusolverStatus_t (*cusolverDnDestroy_t)(cusolverDnHandle_t handle);
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDestroy)(handle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cusolverDnDestroy, handle, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnSetStream
extern "C" cusolverStatus_t cusolverDnSetStream (cusolverDnHandle_t handle, cudaStream_t streamId) {
  typedef cusolverStatus_t (*cusolverDnSetStream_t)(cusolverDnHandle_t handle, cudaStream_t streamId);
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnSetStream)(handle, streamId);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnGetStream
extern "C" cusolverStatus_t cusolverDnGetStream(cusolverDnHandle_t handle, cudaStream_t *streamId) {
  typedef cusolverStatus_t (*cusolverDnGetStream_t)(cusolverDnHandle_t handle, cudaStream_t *streamId);
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnGetStream)(handle, streamId);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDgetrf_bufferSize
extern "C" cusolverStatus_t cusolverDnDgetrf_bufferSize( cusolverDnHandle_t handle, int m, int n, double *A, int lda, int *Lwork ) {
  typedef cusolverStatus_t (*cusolverDnDgetrf_bufferSize_t)( cusolverDnHandle_t handle, int m, int n, double *A, int lda, int *Lwork );
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDgetrf_bufferSize)(handle, m, n, A, lda, Lwork);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDgetrf
extern "C" cusolverStatus_t cusolverDnDgetrf( cusolverDnHandle_t handle, int m, int n, double *A, int lda, double *Workspace, int *devIpiv, int *devInfo ) {
  typedef cusolverStatus_t (*cusolverDnDgetrf_t)( cusolverDnHandle_t handle, int m, int n, double *A, int lda, double *Workspace, int *devIpiv, int *devInfo );
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDgetrf)(handle, m, n, A, lda, Workspace, devIpiv, devInfo);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDgetrs
extern "C" cusolverStatus_t cusolverDnDgetrs( cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, const double *A, int lda, const int *devIpiv, double *B, int ldb, int *devInfo ) {
  typedef cusolverStatus_t (*cusolverDnDgetrs_t)( cusolverDnHandle_t handle, cublasOperation_t trans, int n, int nrhs, const double *A, int lda, const int *devIpiv, double *B, int ldb, int *devInfo );
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDgetrs)(handle, trans, n, nrhs, A, lda, devIpiv, B, ldb, devInfo);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDpotrf_bufferSize
extern "C" cusolverStatus_t cusolverDnDpotrf_bufferSize( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double *A, int lda, int *Lwork ) {
  typedef cusolverStatus_t (*cusolverDnDpotrf_bufferSize_t)( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double *A, int lda, int *Lwork );
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDpotrf_bufferSize)(handle, uplo, n, A, lda, Lwork);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDpotrf
extern "C" cusolverStatus_t cusolverDnDpotrf( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double *A, int lda, double *Workspace, int Lwork, int *devInfo ) {
  typedef cusolverStatus_t (*cusolverDnDpotrf_t)( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, double *A, int lda, double *Workspace, int Lwork, int *devInfo );
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDpotrf)(handle, uplo, n, A, lda, Workspace, Lwork, devInfo);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}


#undef cusolverDnDpotrs
extern "C" cusolverStatus_t cusolverDnDpotrs( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, const double *A, int lda, double *B, int ldb, int *devInfo) {
  typedef cusolverStatus_t (*cusolverDnDpotrs_t)( cusolverDnHandle_t handle, cublasFillMode_t uplo, int n, int nrhs, const double *A, int lda, double *B, int ldb, int *devInfo);
  cusolverStatus_t ret_val ;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cusolverDnDpotrs)(handle, uplo, n, nrhs, A, lda, B, ldb, devInfo);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ==== Device APIs ==== */
/* ==== Initialization ==== */

#undef cuInit
extern "C" CUresult cuInit ( unsigned int  Flags ) {
  typedef CUresult (*cuInit_t)( unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuInit)(Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ==== Version Management ==== */

#undef cuDriverGetVersion
extern "C" CUresult cuDriverGetVersion ( int* driverVersion ) {
  typedef CUresult (*cuDriverGetVersion_t)( int* driverVersion );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDriverGetVersion)(driverVersion);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Device Management */
/* Returns a handle to a compute device. */

#undef cuDeviceGet
extern "C" CUresult cuDeviceGet ( CUdevice* device, int  ordinal ) {
  typedef CUresult (*cuDeviceGet_t)( CUdevice* device, int  ordinal );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGet)(device, ordinal);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns information about the device. */

#undef cuDeviceGetAttribute
extern "C" CUresult cuDeviceGetAttribute ( int* pi, CUdevice_attribute attrib, CUdevice dev ) {
  typedef CUresult (*cuDeviceGetAttribute_t)( int* pi, CUdevice_attribute attrib, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetAttribute)(pi, attrib, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the number of compute-capable devices. */

#undef cuDeviceGetCount
extern "C" CUresult cuDeviceGetCount ( int* count ) {
  typedef CUresult (*cuDeviceGetCount_t)( int* count );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetCount)(count);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* CUresult cuDeviceGetLuid ( char* luid, unsigned int* deviceNodeMask, CUdevice dev ) */
/* Return an LUID and device node mask for the device. */

#undef cuDeviceGetName
extern "C" CUresult cuDeviceGetName ( char* name, int  len, CUdevice dev ) {
  typedef CUresult (*cuDeviceGetName_t)( char* name, int  len, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetName)(name, len, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns an identifer string for the device. */

#undef cuDeviceGetUuid
extern "C" CUresult cuDeviceGetUuid ( CUuuid* uuid, CUdevice dev ) {
  typedef CUresult (*cuDeviceGetUuid_t)( CUuuid* uuid, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetUuid)(uuid, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Return an UUID for the device. */
/* Returns the total amount of memory on the device. */

#undef cuDeviceTotalMem_v2
extern "C" CUresult cuDeviceTotalMem_v2 ( size_t* bytes, CUdevice dev ) {
  typedef CUresult (*cuDeviceTotalMem_v2_t)( size_t* bytes, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceTotalMem_v2)(bytes, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* ==== Device Management (deprecated) ==== */

#undef cuDeviceComputeCapability
extern "C" CUresult cuDeviceComputeCapability ( int* major, int* minor, CUdevice dev ) {
  typedef CUresult (*cuDeviceComputeCapability_t)( int* major, int* minor, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceComputeCapability)(major, minor, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the compute capability of the device. */

#undef cuDeviceGetProperties
extern "C" CUresult cuDeviceGetProperties ( CUdevprop* prop, CUdevice dev ) {
  typedef CUresult (*cuDeviceGetProperties_t)( CUdevprop* prop, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetProperties)(prop, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns properties for a selected device. */
/* ==== Primary Context Management ==== */

#undef cuDevicePrimaryCtxGetState
extern "C" CUresult cuDevicePrimaryCtxGetState ( CUdevice dev, unsigned int* flags, int* active ) {
  typedef CUresult (*cuDevicePrimaryCtxGetState_t)( CUdevice dev, unsigned int* flags, int* active );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDevicePrimaryCtxGetState)(dev, flags, active);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get the state of the primary context. */

#undef cuDevicePrimaryCtxRelease
extern "C" CUresult cuDevicePrimaryCtxRelease ( CUdevice dev ) {
  typedef CUresult (*cuDevicePrimaryCtxRelease_t)( CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDevicePrimaryCtxRelease)(dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Release the primary context on the GPU. */

#undef cuDevicePrimaryCtxReset
extern "C" CUresult cuDevicePrimaryCtxReset ( CUdevice dev ) {
  typedef CUresult (*cuDevicePrimaryCtxReset_t)( CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDevicePrimaryCtxReset)(dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroy all allocations and reset all state on the primary context. */

#undef cuDevicePrimaryCtxRetain
extern "C" CUresult cuDevicePrimaryCtxRetain ( CUcontext* pctx, CUdevice dev ) {
  typedef CUresult (*cuDevicePrimaryCtxRetain_t)( CUcontext* pctx, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDevicePrimaryCtxRetain)(pctx, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Retain the primary context on the GPU. */

#undef cuDevicePrimaryCtxSetFlags
extern "C" CUresult cuDevicePrimaryCtxSetFlags ( CUdevice dev, unsigned int  flags ) {
  typedef CUresult (*cuDevicePrimaryCtxSetFlags_t)( CUdevice dev, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDevicePrimaryCtxSetFlags)(dev, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Set flags for the primary context. */
/* ==== Context Management ==== */

#undef cuCtxCreate_v2
extern "C" CUresult cuCtxCreate_v2 ( CUcontext* pctx, unsigned int  flags, CUdevice dev ) {
  typedef CUresult (*cuCtxCreate_v2_t)( CUcontext* pctx, unsigned int  flags, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxCreate_v2)(pctx, flags, dev);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuCtxCreate_v2, pctx, flags, dev, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Create a CUDA context. */

#undef cuCtxDestroy_v2
extern "C" CUresult cuCtxDestroy_v2 ( CUcontext ctx ) {
  typedef CUresult (*cuCtxDestroy_v2_t)( CUcontext ctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxDestroy_v2)(ctx);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuCtxDestroy_v2, ctx, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroy a CUDA context. */

#undef cuCtxGetApiVersion
extern "C" CUresult cuCtxGetApiVersion ( CUcontext ctx, unsigned int* version ) {
  typedef CUresult (*cuCtxGetApiVersion_t)( CUcontext ctx, unsigned int* version );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetApiVersion)(ctx, version);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the context's API version. */

#undef cuCtxGetCacheConfig
extern "C" CUresult cuCtxGetCacheConfig ( CUfunc_cache* pconfig ) {
  typedef CUresult (*cuCtxGetCacheConfig_t)( CUfunc_cache* pconfig );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetCacheConfig)(pconfig);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the preferred cache configuration for the current context. */

#undef cuCtxGetCurrent
extern "C" CUresult cuCtxGetCurrent ( CUcontext* pctx ) {
  typedef CUresult (*cuCtxGetCurrent_t)( CUcontext* pctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetCurrent)(pctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the CUDA context bound to the calling CPU thread. */

#undef cuCtxGetDevice
extern "C" CUresult cuCtxGetDevice ( CUdevice* device ) {
  typedef CUresult (*cuCtxGetDevice_t)( CUdevice* device );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetDevice)(device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the device ID for the current context. */

#undef cuCtxGetFlags
extern "C" CUresult cuCtxGetFlags ( unsigned int* flags ) {
  typedef CUresult (*cuCtxGetFlags_t)( unsigned int* flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetFlags)(flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the flags for the current context. */

#undef cuCtxGetLimit
extern "C" CUresult cuCtxGetLimit ( size_t* pvalue, CUlimit limit ) {
  typedef CUresult (*cuCtxGetLimit_t)( size_t* pvalue, CUlimit limit );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetLimit)(pvalue, limit);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns resource limits. */

#undef cuCtxGetSharedMemConfig
extern "C" CUresult cuCtxGetSharedMemConfig ( CUsharedconfig* pConfig ) {
  typedef CUresult (*cuCtxGetSharedMemConfig_t)( CUsharedconfig* pConfig );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetSharedMemConfig)(pConfig);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns the current shared memory configuration for the current context. */

#undef cuCtxGetStreamPriorityRange
extern "C" CUresult cuCtxGetStreamPriorityRange ( int* leastPriority, int* greatestPriority ) {
  typedef CUresult (*cuCtxGetStreamPriorityRange_t)( int* leastPriority, int* greatestPriority );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxGetStreamPriorityRange)(leastPriority, greatestPriority);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns numerical values that correspond to the least and greatest stream priorities. */

#undef cuCtxPopCurrent_v2
extern "C" CUresult cuCtxPopCurrent_v2 ( CUcontext* pctx ) {
  typedef CUresult (*cuCtxPopCurrent_v2_t)( CUcontext* pctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxPopCurrent_v2)(pctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Pops the current CUDA context from the current CPU thread. */

#undef cuCtxPushCurrent_v2
extern "C" CUresult cuCtxPushCurrent_v2 ( CUcontext ctx ) {
  typedef CUresult (*cuCtxPushCurrent_v2_t)( CUcontext ctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxPushCurrent_v2)(ctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Pushes a context on the current CPU thread. */

#undef cuCtxSetCacheConfig
extern "C" CUresult cuCtxSetCacheConfig ( CUfunc_cache config ) {
  typedef CUresult (*cuCtxSetCacheConfig_t)( CUfunc_cache config );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxSetCacheConfig)(config);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the preferred cache configuration for the current context. */

#undef cuCtxSetCurrent
extern "C" CUresult cuCtxSetCurrent ( CUcontext ctx ) {
  typedef CUresult (*cuCtxSetCurrent_t)( CUcontext ctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxSetCurrent)(ctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Binds the specified CUDA context to the calling CPU thread. */

#undef cuCtxSetLimit
extern "C" CUresult cuCtxSetLimit ( CUlimit limit, size_t value ) {
  typedef CUresult (*cuCtxSetLimit_t)( CUlimit limit, size_t value );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxSetLimit)(limit, value);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Set resource limits. */

#undef cuCtxSetSharedMemConfig
extern "C" CUresult cuCtxSetSharedMemConfig ( CUsharedconfig config ) {
  typedef CUresult (*cuCtxSetSharedMemConfig_t)( CUsharedconfig config );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxSetSharedMemConfig)(config);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the shared memory configuration for the current context. */

#undef cuCtxSynchronize
extern "C" CUresult cuCtxSynchronize () {
  typedef CUresult (*cuCtxSynchronize_t)();
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxSynchronize)();
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Block for a context's tasks to complete. */
/* ==== Context Management [DEPRECATED] ==== */

#undef cuCtxAttach
extern "C" CUresult cuCtxAttach ( CUcontext* pctx, unsigned int  flags ) {
  typedef CUresult (*cuCtxAttach_t)( CUcontext* pctx, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxAttach)(pctx, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Increment a context's usage-count. */

#undef cuCtxDetach
extern "C" CUresult cuCtxDetach ( CUcontext ctx ) {
  typedef CUresult (*cuCtxDetach_t)( CUcontext ctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxDetach)(ctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Decrement a context's usage-count. */
/* ==== Module Management ==== */

#undef cuLinkAddData_v2
extern "C" CUresult cuLinkAddData_v2 ( CUlinkState state, CUjitInputType type, void* data, size_t size, const char* name, unsigned int  numOptions, CUjit_option* options, void** optionValues ) {
  typedef CUresult (*cuLinkAddData_v2_t)( CUlinkState state, CUjitInputType type, void* data, size_t size, const char* name, unsigned int  numOptions, CUjit_option* options, void** optionValues );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLinkAddData_v2)(state, type, data, size, name, numOptions, options, optionValues);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Add an input to a pending linker invocation. */

#undef cuLinkAddFile_v2
extern "C" CUresult cuLinkAddFile_v2 ( CUlinkState state, CUjitInputType type, const char* path, unsigned int  numOptions, CUjit_option* options, void** optionValues ) {
  typedef CUresult (*cuLinkAddFile_v2_t)( CUlinkState state, CUjitInputType type, const char* path, unsigned int  numOptions, CUjit_option* options, void** optionValues );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLinkAddFile_v2)(state, type, path, numOptions, options, optionValues);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Add a file input to a pending linker invocation. */

#undef cuLinkComplete
extern "C" CUresult cuLinkComplete ( CUlinkState state, void** cubinOut, size_t* sizeOut ) {
  typedef CUresult (*cuLinkComplete_t)( CUlinkState state, void** cubinOut, size_t* sizeOut );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLinkComplete)(state, cubinOut, sizeOut);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Complete a pending linker invocation. */

#undef cuLinkCreate_v2
extern "C" CUresult cuLinkCreate_v2 ( unsigned int  numOptions, CUjit_option* options, void** optionValues, CUlinkState* stateOut ) {
  typedef CUresult (*cuLinkCreate_v2_t)( unsigned int  numOptions, CUjit_option* options, void** optionValues, CUlinkState* stateOut );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLinkCreate_v2)(numOptions, options, optionValues, stateOut);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuLinkCreate_v2, numOptions, options, optionValues, stateOut, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a pending JIT linker invocation. */

#undef cuLinkDestroy
extern "C" CUresult cuLinkDestroy ( CUlinkState state ) {
  typedef CUresult (*cuLinkDestroy_t)( CUlinkState state );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLinkDestroy)(state);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuLinkDestroy, state, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys state for a JIT linker invocation. */

#undef cuModuleGetFunction
extern "C" CUresult cuModuleGetFunction ( CUfunction* hfunc, CUmodule hmod, const char* name ) {
  typedef CUresult (*cuModuleGetFunction_t)( CUfunction* hfunc, CUmodule hmod, const char* name );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleGetFunction)(hfunc, hmod, name);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a function handle. */

#undef cuModuleGetGlobal_v2
extern "C" CUresult cuModuleGetGlobal_v2 ( CUdeviceptr* dptr, size_t* bytes, CUmodule hmod, const char* name ) {
  typedef CUresult (*cuModuleGetGlobal_v2_t)( CUdeviceptr* dptr, size_t* bytes, CUmodule hmod, const char* name );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleGetGlobal_v2)(dptr, bytes, hmod, name);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a global pointer from a module. */

#undef cuModuleGetSurfRef
extern "C" CUresult cuModuleGetSurfRef ( CUsurfref* pSurfRef, CUmodule hmod, const char* name ) {
  typedef CUresult (*cuModuleGetSurfRef_t)( CUsurfref* pSurfRef, CUmodule hmod, const char* name );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleGetSurfRef)(pSurfRef, hmod, name);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a handle to a surface reference. */

#undef cuModuleGetTexRef
extern "C" CUresult cuModuleGetTexRef ( CUtexref* pTexRef, CUmodule hmod, const char* name ) {
  typedef CUresult (*cuModuleGetTexRef_t)( CUtexref* pTexRef, CUmodule hmod, const char* name );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleGetTexRef)(pTexRef, hmod, name);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a handle to a texture reference. */

#undef cuModuleLoad
extern "C" CUresult cuModuleLoad ( CUmodule* module, const char* fname ) {
  typedef CUresult (*cuModuleLoad_t)( CUmodule* module, const char* fname );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleLoad)(module, fname);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Loads a compute module. */

#undef cuModuleLoadData
extern "C" CUresult cuModuleLoadData ( CUmodule* module, const void* image ) {
  typedef CUresult (*cuModuleLoadData_t)( CUmodule* module, const void* image );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleLoadData)(module, image);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Load a module's data. */

#undef cuModuleLoadDataEx
extern "C" CUresult cuModuleLoadDataEx ( CUmodule* module, const void* image, unsigned int  numOptions, CUjit_option* options, void** optionValues ) {
  typedef CUresult (*cuModuleLoadDataEx_t)( CUmodule* module, const void* image, unsigned int  numOptions, CUjit_option* options, void** optionValues );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleLoadDataEx)(module, image, numOptions, options, optionValues);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Load a module's data with options. */

#undef cuModuleLoadFatBinary
extern "C" CUresult cuModuleLoadFatBinary ( CUmodule* module, const void* fatCubin ) {
  typedef CUresult (*cuModuleLoadFatBinary_t)( CUmodule* module, const void* fatCubin );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleLoadFatBinary)(module, fatCubin);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Load a module's data. */

#undef cuModuleUnload
extern "C" CUresult cuModuleUnload ( CUmodule hmod ) {
  typedef CUresult (*cuModuleUnload_t)( CUmodule hmod );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuModuleUnload)(hmod);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Unloads a module. */
/* ==== Memory Management ==== */

#undef cuArray3DCreate_v2
extern "C" CUresult cuArray3DCreate_v2 ( CUarray* pHandle, const CUDA_ARRAY3D_DESCRIPTOR* pAllocateArray ) {
  typedef CUresult (*cuArray3DCreate_v2_t)( CUarray* pHandle, const CUDA_ARRAY3D_DESCRIPTOR* pAllocateArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuArray3DCreate_v2)(pHandle, pAllocateArray);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuArray3DCreate_v2, pHandle, pAllocateArray, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a 3D CUDA array. */

#undef cuArray3DGetDescriptor_v2
extern "C" CUresult cuArray3DGetDescriptor_v2 ( CUDA_ARRAY3D_DESCRIPTOR* pArrayDescriptor, CUarray hArray ) {
  typedef CUresult (*cuArray3DGetDescriptor_v2_t)( CUDA_ARRAY3D_DESCRIPTOR* pArrayDescriptor, CUarray hArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuArray3DGetDescriptor_v2)(pArrayDescriptor, hArray);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get a 3D CUDA array descriptor. */

#undef cuArrayCreate_v2
extern "C" CUresult cuArrayCreate_v2 ( CUarray* pHandle, const CUDA_ARRAY_DESCRIPTOR* pAllocateArray ) {
  typedef CUresult (*cuArrayCreate_v2_t)( CUarray* pHandle, const CUDA_ARRAY_DESCRIPTOR* pAllocateArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuArrayCreate_v2)(pHandle, pAllocateArray);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuArrayCreate_v2, pHandle, pAllocateArray, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a 1D or 2D CUDA array. */

#undef cuArrayDestroy
extern "C" CUresult cuArrayDestroy ( CUarray hArray ) {
  typedef CUresult (*cuArrayDestroy_t)( CUarray hArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuArrayDestroy)(hArray);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuArrayDestroy, hArray, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a CUDA array. */

#undef cuArrayGetDescriptor_v2
extern "C" CUresult cuArrayGetDescriptor_v2 ( CUDA_ARRAY_DESCRIPTOR* pArrayDescriptor, CUarray hArray ) {
  typedef CUresult (*cuArrayGetDescriptor_v2_t)( CUDA_ARRAY_DESCRIPTOR* pArrayDescriptor, CUarray hArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuArrayGetDescriptor_v2)(pArrayDescriptor, hArray);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get a 1D or 2D CUDA array descriptor. */

#undef cuDeviceGetByPCIBusId
extern "C" CUresult cuDeviceGetByPCIBusId ( CUdevice* dev, const char* pciBusId ) {
  typedef CUresult (*cuDeviceGetByPCIBusId_t)( CUdevice* dev, const char* pciBusId );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetByPCIBusId)(dev, pciBusId);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a handle to a compute device. */

#undef cuDeviceGetPCIBusId
extern "C" CUresult cuDeviceGetPCIBusId ( char* pciBusId, int  len, CUdevice dev ) {
  typedef CUresult (*cuDeviceGetPCIBusId_t)( char* pciBusId, int  len, CUdevice dev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetPCIBusId)(pciBusId, len, dev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a PCI Bus Id string for the device. */

#undef cuIpcCloseMemHandle
extern "C" CUresult cuIpcCloseMemHandle ( CUdeviceptr dptr ) {
  typedef CUresult (*cuIpcCloseMemHandle_t)( CUdeviceptr dptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuIpcCloseMemHandle)(dptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Close memory mapped with cuIpcOpenMemHandle. */

#undef cuIpcGetEventHandle
extern "C" CUresult cuIpcGetEventHandle ( CUipcEventHandle* pHandle, CUevent event ) {
  typedef CUresult (*cuIpcGetEventHandle_t)( CUipcEventHandle* pHandle, CUevent event );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuIpcGetEventHandle)(pHandle, event);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets an interprocess handle for a previously allocated event. */

#undef cuIpcGetMemHandle
extern "C" CUresult cuIpcGetMemHandle ( CUipcMemHandle* pHandle, CUdeviceptr dptr ) {
  typedef CUresult (*cuIpcGetMemHandle_t)( CUipcMemHandle* pHandle, CUdeviceptr dptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuIpcGetMemHandle)(pHandle, dptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets an interprocess memory handle for an existing device memory allocation. */

#undef cuIpcOpenEventHandle
extern "C" CUresult cuIpcOpenEventHandle ( CUevent* phEvent, CUipcEventHandle handle ) {
  typedef CUresult (*cuIpcOpenEventHandle_t)( CUevent* phEvent, CUipcEventHandle handle );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuIpcOpenEventHandle)(phEvent, handle);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Opens an interprocess event handle for use in the current process. */

#undef cuIpcOpenMemHandle
extern "C" CUresult cuIpcOpenMemHandle ( CUdeviceptr* pdptr, CUipcMemHandle handle, unsigned int  Flags ) {
  typedef CUresult (*cuIpcOpenMemHandle_t)( CUdeviceptr* pdptr, CUipcMemHandle handle, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuIpcOpenMemHandle)(pdptr, handle, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Opens an interprocess memory handle exported from another process and returns a device pointer usable in the local process. */

#undef cuMemAlloc_v2
extern "C" CUresult cuMemAlloc_v2 ( CUdeviceptr* dptr, size_t bytesize ) {
  typedef CUresult (*cuMemAlloc_v2_t)( CUdeviceptr* dptr, size_t bytesize );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemAlloc_v2)(dptr, bytesize);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Allocates device memory. */

#undef cuMemAllocHost_v2
extern "C" CUresult cuMemAllocHost_v2 ( void** pp, size_t bytesize ) {
  typedef CUresult (*cuMemAllocHost_v2_t)( void** pp, size_t bytesize );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemAllocHost_v2)(pp, bytesize);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Allocates page-locked host memory. */

#undef cuMemAllocManaged
extern "C" CUresult cuMemAllocManaged ( CUdeviceptr* dptr, size_t bytesize, unsigned int  flags ) {
  typedef CUresult (*cuMemAllocManaged_t)( CUdeviceptr* dptr, size_t bytesize, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemAllocManaged)(dptr, bytesize, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Allocates memory that will be automatically managed by the Unified Memory system. */

#undef cuMemAllocPitch_v2
extern "C" CUresult cuMemAllocPitch_v2 ( CUdeviceptr* dptr, size_t* pPitch, size_t WidthInBytes, size_t Height, unsigned int  ElementSizeBytes ) {
  typedef CUresult (*cuMemAllocPitch_v2_t)( CUdeviceptr* dptr, size_t* pPitch, size_t WidthInBytes, size_t Height, unsigned int  ElementSizeBytes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemAllocPitch_v2)(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Allocates pitched device memory. */

#undef cuMemFree_v2
extern "C" CUresult cuMemFree_v2 ( CUdeviceptr dptr ) {
  typedef CUresult (*cuMemFree_v2_t)( CUdeviceptr dptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemFree_v2)(dptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Frees device memory. */

#undef cuMemFreeHost
extern "C" CUresult cuMemFreeHost ( void* p ) {
  typedef CUresult (*cuMemFreeHost_t)( void* p );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemFreeHost)(p);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Frees page-locked host memory. */

#undef cuMemGetAddressRange_v2
extern "C" CUresult cuMemGetAddressRange_v2 ( CUdeviceptr* pbase, size_t* psize, CUdeviceptr dptr ) {
  typedef CUresult (*cuMemGetAddressRange_v2_t)( CUdeviceptr* pbase, size_t* psize, CUdeviceptr dptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemGetAddressRange_v2)(pbase, psize, dptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get information on memory allocations. */

#undef cuMemGetInfo_v2
extern "C" CUresult cuMemGetInfo_v2 ( size_t* free, size_t* total ) {
  typedef CUresult (*cuMemGetInfo_v2_t)( size_t* free, size_t* total );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemGetInfo_v2)(free, total);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets free and total memory. */

#undef cuMemHostAlloc
extern "C" CUresult cuMemHostAlloc ( void** pp, size_t bytesize, unsigned int  Flags ) {
  typedef CUresult (*cuMemHostAlloc_t)( void** pp, size_t bytesize, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemHostAlloc)(pp, bytesize, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Allocates page-locked host memory. */

#undef cuMemHostGetDevicePointer_v2
extern "C" CUresult cuMemHostGetDevicePointer_v2 ( CUdeviceptr* pdptr, void* p, unsigned int  Flags ) {
  typedef CUresult (*cuMemHostGetDevicePointer_v2_t)( CUdeviceptr* pdptr, void* p, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemHostGetDevicePointer_v2)(pdptr, p, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Passes back device pointer of mapped pinned memory. */

#undef cuMemHostGetFlags
extern "C" CUresult cuMemHostGetFlags ( unsigned int* pFlags, void* p ) {
  typedef CUresult (*cuMemHostGetFlags_t)( unsigned int* pFlags, void* p );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemHostGetFlags)(pFlags, p);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Passes back flags that were used for a pinned allocation. */

#undef cuMemHostRegister_v2
extern "C" CUresult cuMemHostRegister_v2 ( void* p, size_t bytesize, unsigned int  Flags ) {
  typedef CUresult (*cuMemHostRegister_v2_t)( void* p, size_t bytesize, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemHostRegister_v2)(p, bytesize, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Registers an existing host memory range for use by CUDA. */

#undef cuMemHostUnregister
extern "C" CUresult cuMemHostUnregister ( void* p ) {
  typedef CUresult (*cuMemHostUnregister_t)( void* p );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemHostUnregister)(p);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Unregisters a memory range that was registered with cuMemHostRegister. */

#undef cuMemcpy
extern "C" CUresult cuMemcpy ( CUdeviceptr dst, CUdeviceptr src, size_t ByteCount ) {
  typedef CUresult (*cuMemcpy_t)( CUdeviceptr dst, CUdeviceptr src, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy)(dst, src, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory. */

#undef cuMemcpy2D_v2
extern "C" CUresult cuMemcpy2D_v2 ( const CUDA_MEMCPY2D* pCopy ) {
  typedef CUresult (*cuMemcpy2D_v2_t)( const CUDA_MEMCPY2D* pCopy );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy2D_v2)(pCopy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory for 2D arrays. */

#undef cuMemcpy2DAsync_v2
extern "C" CUresult cuMemcpy2DAsync_v2 ( const CUDA_MEMCPY2D* pCopy, CUstream hStream ) {
  typedef CUresult (*cuMemcpy2DAsync_v2_t)( const CUDA_MEMCPY2D* pCopy, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy2DAsync_v2)(pCopy, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory for 2D arrays. */

#undef cuMemcpy2DUnaligned_v2
extern "C" CUresult cuMemcpy2DUnaligned_v2 ( const CUDA_MEMCPY2D* pCopy ) {
  typedef CUresult (*cuMemcpy2DUnaligned_v2_t)( const CUDA_MEMCPY2D* pCopy );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy2DUnaligned_v2)(pCopy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory for 2D arrays. */

#undef cuMemcpy3D_v2
extern "C" CUresult cuMemcpy3D_v2 ( const CUDA_MEMCPY3D* pCopy ) {
  typedef CUresult (*cuMemcpy3D_v2_t)( const CUDA_MEMCPY3D* pCopy );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy3D_v2)(pCopy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory for 3D arrays. */

#undef cuMemcpy3DAsync_v2
extern "C" CUresult cuMemcpy3DAsync_v2 ( const CUDA_MEMCPY3D* pCopy, CUstream hStream ) {
  typedef CUresult (*cuMemcpy3DAsync_v2_t)( const CUDA_MEMCPY3D* pCopy, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy3DAsync_v2)(pCopy, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory for 3D arrays. */

#undef cuMemcpy3DPeer
extern "C" CUresult cuMemcpy3DPeer ( const CUDA_MEMCPY3D_PEER* pCopy ) {
  typedef CUresult (*cuMemcpy3DPeer_t)( const CUDA_MEMCPY3D_PEER* pCopy );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy3DPeer)(pCopy);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory between contexts. */

#undef cuMemcpy3DPeerAsync
extern "C" CUresult cuMemcpy3DPeerAsync ( const CUDA_MEMCPY3D_PEER* pCopy, CUstream hStream ) {
  typedef CUresult (*cuMemcpy3DPeerAsync_t)( const CUDA_MEMCPY3D_PEER* pCopy, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpy3DPeerAsync)(pCopy, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory between contexts asynchronously. */

#undef cuMemcpyAsync
extern "C" CUresult cuMemcpyAsync ( CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyAsync_t)( CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyAsync)(dst, src, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory asynchronously. */

#undef cuMemcpyAtoA_v2
extern "C" CUresult cuMemcpyAtoA_v2 ( CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyAtoA_v2_t)( CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyAtoA_v2)(dstArray, dstOffset, srcArray, srcOffset, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Array to Array. */

#undef cuMemcpyAtoD_v2
extern "C" CUresult cuMemcpyAtoD_v2 ( CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyAtoD_v2_t)( CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyAtoD_v2)(dstDevice, srcArray, srcOffset, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Array to Device. */

#undef cuMemcpyAtoH_v2
extern "C" CUresult cuMemcpyAtoH_v2 ( void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyAtoH_v2_t)( void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyAtoH_v2)(dstHost, srcArray, srcOffset, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Array to Host. */

#undef cuMemcpyAtoHAsync_v2
extern "C" CUresult cuMemcpyAtoHAsync_v2 ( void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyAtoHAsync_v2_t)( void* dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyAtoHAsync_v2)(dstHost, srcArray, srcOffset, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Array to Host. */

#undef cuMemcpyDtoA_v2
extern "C" CUresult cuMemcpyDtoA_v2 ( CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyDtoA_v2_t)( CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyDtoA_v2)(dstArray, dstOffset, srcDevice, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Device to Array. */

#undef cuMemcpyDtoD_v2
extern "C" CUresult cuMemcpyDtoD_v2 ( CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyDtoD_v2_t)( CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyDtoD_v2)(dstDevice, srcDevice, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Device to Device. */

#undef cuMemcpyDtoDAsync_v2
extern "C" CUresult cuMemcpyDtoDAsync_v2 ( CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyDtoDAsync_v2_t)( CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyDtoDAsync_v2)(dstDevice, srcDevice, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Device to Device. */

#undef cuMemcpyDtoH_v2
extern "C" CUresult cuMemcpyDtoH_v2 ( void* dstHost, CUdeviceptr srcDevice, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyDtoH_v2_t)( void* dstHost, CUdeviceptr srcDevice, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyDtoH_v2)(dstHost, srcDevice, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Device to Host. */

#undef cuMemcpyDtoHAsync_v2
extern "C" CUresult cuMemcpyDtoHAsync_v2 ( void* dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyDtoHAsync_v2_t)( void* dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyDtoHAsync_v2)(dstHost, srcDevice, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Device to Host. */

#undef cuMemcpyHtoA_v2
extern "C" CUresult cuMemcpyHtoA_v2 ( CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyHtoA_v2_t)( CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyHtoA_v2)(dstArray, dstOffset, srcHost, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Host to Array. */

#undef cuMemcpyHtoAAsync_v2
extern "C" CUresult cuMemcpyHtoAAsync_v2 ( CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyHtoAAsync_v2_t)( CUarray dstArray, size_t dstOffset, const void* srcHost, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyHtoAAsync_v2)(dstArray, dstOffset, srcHost, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Host to Array. */

#undef cuMemcpyHtoD_v2
extern "C" CUresult cuMemcpyHtoD_v2 ( CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyHtoD_v2_t)( CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyHtoD_v2)(dstDevice, srcHost, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Host to Device. */

#undef cuMemcpyHtoDAsync_v2
extern "C" CUresult cuMemcpyHtoDAsync_v2 ( CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyHtoDAsync_v2_t)( CUdeviceptr dstDevice, const void* srcHost, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyHtoDAsync_v2)(dstDevice, srcHost, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies memory from Host to Device. */

#undef cuMemcpyPeer
extern "C" CUresult cuMemcpyPeer ( CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount ) {
  typedef CUresult (*cuMemcpyPeer_t)( CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyPeer)(dstDevice, dstContext, srcDevice, srcContext, ByteCount);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies device memory between two contexts. */

#undef cuMemcpyPeerAsync
extern "C" CUresult cuMemcpyPeerAsync ( CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream ) {
  typedef CUresult (*cuMemcpyPeerAsync_t)( CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemcpyPeerAsync)(dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Copies device memory between two contexts asynchronously. */

#undef cuMemsetD16_v2
extern "C" CUresult cuMemsetD16_v2 ( CUdeviceptr dstDevice, unsigned short us, size_t N ) {
  typedef CUresult (*cuMemsetD16_v2_t)( CUdeviceptr dstDevice, unsigned short us, size_t N );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD16_v2)(dstDevice, us, N);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD16Async
extern "C" CUresult cuMemsetD16Async ( CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream ) {
  typedef CUresult (*cuMemsetD16Async_t)( CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD16Async)(dstDevice, us, N, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMemsetD2D16_v2
extern "C" CUresult cuMemsetD2D16_v2 ( CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height ) {
  typedef CUresult (*cuMemsetD2D16_v2_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D16_v2)(dstDevice, dstPitch, us, Width, Height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD2D16Async
extern "C" CUresult cuMemsetD2D16Async ( CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream ) {
  typedef CUresult (*cuMemsetD2D16Async_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D16Async)(dstDevice, dstPitch, us, Width, Height, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMemsetD2D32_v2
extern "C" CUresult cuMemsetD2D32_v2 ( CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height ) {
  typedef CUresult (*cuMemsetD2D32_v2_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D32_v2)(dstDevice, dstPitch, ui, Width, Height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD2D32Async
extern "C" CUresult cuMemsetD2D32Async ( CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height, CUstream hStream ) {
  typedef CUresult (*cuMemsetD2D32Async_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned int  ui, size_t Width, size_t Height, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D32Async)(dstDevice, dstPitch, ui, Width, Height, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMemsetD2D8_v2
extern "C" CUresult cuMemsetD2D8_v2 ( CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height ) {
  typedef CUresult (*cuMemsetD2D8_v2_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D8_v2)(dstDevice, dstPitch, uc, Width, Height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD2D8Async
extern "C" CUresult cuMemsetD2D8Async ( CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height, CUstream hStream ) {
  typedef CUresult (*cuMemsetD2D8Async_t)( CUdeviceptr dstDevice, size_t dstPitch, unsigned char  uc, size_t Width, size_t Height, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD2D8Async)(dstDevice, dstPitch, uc, Width, Height, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMemsetD32_v2
extern "C" CUresult cuMemsetD32_v2 ( CUdeviceptr dstDevice, unsigned int  ui, size_t N ) {
  typedef CUresult (*cuMemsetD32_v2_t)( CUdeviceptr dstDevice, unsigned int  ui, size_t N );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD32_v2)(dstDevice, ui, N);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD32Async
extern "C" CUresult cuMemsetD32Async ( CUdeviceptr dstDevice, unsigned int  ui, size_t N, CUstream hStream ) {
  typedef CUresult (*cuMemsetD32Async_t)( CUdeviceptr dstDevice, unsigned int  ui, size_t N, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD32Async)(dstDevice, ui, N, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMemsetD8_v2
extern "C" CUresult cuMemsetD8_v2 ( CUdeviceptr dstDevice, unsigned char  uc, size_t N ) {
  typedef CUresult (*cuMemsetD8_v2_t)( CUdeviceptr dstDevice, unsigned char  uc, size_t N );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD8_v2)(dstDevice, uc, N);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Initializes device memory. */

#undef cuMemsetD8Async
extern "C" CUresult cuMemsetD8Async ( CUdeviceptr dstDevice, unsigned char  uc, size_t N, CUstream hStream ) {
  typedef CUresult (*cuMemsetD8Async_t)( CUdeviceptr dstDevice, unsigned char  uc, size_t N, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemsetD8Async)(dstDevice, uc, N, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets device memory. */

#undef cuMipmappedArrayCreate
extern "C" CUresult cuMipmappedArrayCreate ( CUmipmappedArray* pHandle, const CUDA_ARRAY3D_DESCRIPTOR* pMipmappedArrayDesc, unsigned int  numMipmapLevels ) {
  typedef CUresult (*cuMipmappedArrayCreate_t)( CUmipmappedArray* pHandle, const CUDA_ARRAY3D_DESCRIPTOR* pMipmappedArrayDesc, unsigned int  numMipmapLevels );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMipmappedArrayCreate)(pHandle, pMipmappedArrayDesc, numMipmapLevels);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuMipmappedArrayCreate, pHandle, pMipmappedArrayDesc, numMipmapLevels, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a CUDA mipmapped array. */

#undef cuMipmappedArrayDestroy
extern "C" CUresult cuMipmappedArrayDestroy ( CUmipmappedArray hMipmappedArray ) {
  typedef CUresult (*cuMipmappedArrayDestroy_t)( CUmipmappedArray hMipmappedArray );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMipmappedArrayDestroy)(hMipmappedArray);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuMipmappedArrayDestroy, hMipmappedArray, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a CUDA mipmapped array. */

#undef cuMipmappedArrayGetLevel
extern "C" CUresult cuMipmappedArrayGetLevel ( CUarray* pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int  level ) {
  typedef CUresult (*cuMipmappedArrayGetLevel_t)( CUarray* pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int  level );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMipmappedArrayGetLevel)(pLevelArray, hMipmappedArray, level);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets a mipmap level of a CUDA mipmapped array. */
/* ==== Unified Addressing ==== */

#undef cuMemAdvise
extern "C" CUresult cuMemAdvise ( CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device ) {
  typedef CUresult (*cuMemAdvise_t)( CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemAdvise)(devPtr, count, advice, device);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Advise about the usage of a given memory range. */

#undef cuMemPrefetchAsync
extern "C" CUresult cuMemPrefetchAsync ( CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream ) {
  typedef CUresult (*cuMemPrefetchAsync_t)( CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemPrefetchAsync)(devPtr, count, dstDevice, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Prefetches memory to the specified destination device. */

#undef cuMemRangeGetAttribute
extern "C" CUresult cuMemRangeGetAttribute ( void* data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count ) {
  typedef CUresult (*cuMemRangeGetAttribute_t)( void* data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemRangeGetAttribute)(data, dataSize, attribute, devPtr, count);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Query an attribute of a given memory range. */

#undef cuMemRangeGetAttributes
extern "C" CUresult cuMemRangeGetAttributes ( void** data, size_t* dataSizes, CUmem_range_attribute* attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count ) {
  typedef CUresult (*cuMemRangeGetAttributes_t)( void** data, size_t* dataSizes, CUmem_range_attribute* attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuMemRangeGetAttributes)(data, dataSizes, attributes, numAttributes, devPtr, count);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Query attributes of a given memory range. */

#undef cuPointerGetAttribute
extern "C" CUresult cuPointerGetAttribute ( void* data, CUpointer_attribute attribute, CUdeviceptr ptr ) {
  typedef CUresult (*cuPointerGetAttribute_t)( void* data, CUpointer_attribute attribute, CUdeviceptr ptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuPointerGetAttribute)(data, attribute, ptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns information about a pointer. */

#undef cuPointerGetAttributes
extern "C" CUresult cuPointerGetAttributes ( unsigned int  numAttributes, CUpointer_attribute* attributes, void** data, CUdeviceptr ptr ) {
  typedef CUresult (*cuPointerGetAttributes_t)( unsigned int  numAttributes, CUpointer_attribute* attributes, void** data, CUdeviceptr ptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuPointerGetAttributes)(numAttributes, attributes, data, ptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns information about a pointer. */

#undef cuPointerSetAttribute
extern "C" CUresult cuPointerSetAttribute ( const void* value, CUpointer_attribute attribute, CUdeviceptr ptr ) {
  typedef CUresult (*cuPointerSetAttribute_t)( const void* value, CUpointer_attribute attribute, CUdeviceptr ptr );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuPointerSetAttribute)(value, attribute, ptr);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Set attributes on a previously allocated memory region. */
/* ==== Stream Management ==== */

#undef cuStreamAddCallback
extern "C" CUresult cuStreamAddCallback ( CUstream hStream, CUstreamCallback callback, void* userData, unsigned int  flags ) {
  typedef CUresult (*cuStreamAddCallback_t)( CUstream hStream, CUstreamCallback callback, void* userData, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamAddCallback)(hStream, callback, userData, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Add a callback to a compute stream. */

#undef cuStreamAttachMemAsync
extern "C" CUresult cuStreamAttachMemAsync ( CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int  flags ) {
  typedef CUresult (*cuStreamAttachMemAsync_t)( CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamAttachMemAsync)(hStream, dptr, length, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Attach memory to a stream asynchronously. */
/* CUresult cuStreamBeginCapture_v2 ( CUstream hStream )*/
/* Begins graph capture on a stream. */

#undef cuStreamCreate
extern "C" CUresult cuStreamCreate ( CUstream* phStream, unsigned int  Flags ) {
  typedef CUresult (*cuStreamCreate_t)( CUstream* phStream, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamCreate)(phStream, Flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuStreamCreate, phStream, Flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Create a stream. */

#undef cuStreamCreateWithPriority
extern "C" CUresult cuStreamCreateWithPriority ( CUstream* phStream, unsigned int  flags, int  priority ) {
  typedef CUresult (*cuStreamCreateWithPriority_t)( CUstream* phStream, unsigned int  flags, int  priority );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamCreateWithPriority)(phStream, flags, priority);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuStreamCreateWithPriority, phStream, flags, priority, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Create a stream with the given priority. */

#undef cuStreamDestroy_v2
extern "C" CUresult cuStreamDestroy_v2 ( CUstream hStream ) {
  typedef CUresult (*cuStreamDestroy_v2_t)( CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamDestroy_v2)(hStream);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuStreamDestroy_v2, hStream, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a stream. */

#undef cuStreamEndCapture
extern "C" CUresult cuStreamEndCapture ( CUstream hStream, CUgraph* phGraph ) {
  typedef CUresult (*cuStreamEndCapture_t)( CUstream hStream, CUgraph* phGraph );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamEndCapture)(hStream, phGraph);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Ends capture on a stream, returning the captured graph. */
/* CUresult cuStreamGetCaptureInfo ( CUstream hStream, CUstreamCaptureStatus* captureStatus, cuuint64_t* id ) */
/* Query capture status of a stream. */

#undef cuStreamGetCtx
extern "C" CUresult cuStreamGetCtx ( CUstream hStream, CUcontext* pctx ) {
  typedef CUresult (*cuStreamGetCtx_t)( CUstream hStream, CUcontext* pctx );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamGetCtx)(hStream, pctx);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Query the context associated with a stream. */

#undef cuStreamGetFlags
extern "C" CUresult cuStreamGetFlags ( CUstream hStream, unsigned int* flags ) {
  typedef CUresult (*cuStreamGetFlags_t)( CUstream hStream, unsigned int* flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamGetFlags)(hStream, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Query the flags of a given stream. */

#undef cuStreamGetPriority
extern "C" CUresult cuStreamGetPriority ( CUstream hStream, int* priority ) {
  typedef CUresult (*cuStreamGetPriority_t)( CUstream hStream, int* priority );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamGetPriority)(hStream, priority);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Query the priority of a given stream. */

#undef cuStreamIsCapturing
extern "C" CUresult cuStreamIsCapturing ( CUstream hStream, CUstreamCaptureStatus* captureStatus ) {
  typedef CUresult (*cuStreamIsCapturing_t)( CUstream hStream, CUstreamCaptureStatus* captureStatus );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamIsCapturing)(hStream, captureStatus);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a stream's capture status. */

#undef cuStreamQuery
extern "C" CUresult cuStreamQuery ( CUstream hStream ) {
  typedef CUresult (*cuStreamQuery_t)( CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamQuery)(hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Determine status of a compute stream. */

#undef cuStreamSynchronize
extern "C" CUresult cuStreamSynchronize ( CUstream hStream ) {
  typedef CUresult (*cuStreamSynchronize_t)( CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamSynchronize)(hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Wait until a stream's tasks are completed. */

#undef cuStreamWaitEvent
extern "C" CUresult cuStreamWaitEvent ( CUstream hStream, CUevent hEvent, unsigned int  Flags ) {
  typedef CUresult (*cuStreamWaitEvent_t)( CUstream hStream, CUevent hEvent, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamWaitEvent)(hStream, hEvent, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Make a compute stream wait on an event. */
/* CUresult cuThreadExchangeStreamCaptureMode ( CUstreamCaptureMode* mode ) */
/* Swaps the stream capture interaction mode for a thread. Cuda 10.1 API */
/* ==== Event Management ==== */

#undef cuEventCreate
extern "C" CUresult cuEventCreate ( CUevent* phEvent, unsigned int  Flags ) {
  typedef CUresult (*cuEventCreate_t)( CUevent* phEvent, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventCreate)(phEvent, Flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuEventCreate, phEvent, Flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates an event. */

#undef cuEventDestroy_v2
extern "C" CUresult cuEventDestroy_v2 ( CUevent hEvent ) {
  typedef CUresult (*cuEventDestroy_v2_t)( CUevent hEvent );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventDestroy_v2)(hEvent);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuEventDestroy_v2, hEvent, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys an event. */

#undef cuEventElapsedTime
extern "C" CUresult cuEventElapsedTime ( float* pMilliseconds, CUevent hStart, CUevent hEnd ) {
  typedef CUresult (*cuEventElapsedTime_t)( float* pMilliseconds, CUevent hStart, CUevent hEnd );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventElapsedTime)(pMilliseconds, hStart, hEnd);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Computes the elapsed time between two events. */

#undef cuEventQuery
extern "C" CUresult cuEventQuery ( CUevent hEvent ) {
  typedef CUresult (*cuEventQuery_t)( CUevent hEvent );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventQuery)(hEvent);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Queries an event's status. */

#undef cuEventRecord
extern "C" CUresult cuEventRecord ( CUevent hEvent, CUstream hStream ) {
  typedef CUresult (*cuEventRecord_t)( CUevent hEvent, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventRecord)(hEvent, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Records an event. */

#undef cuEventSynchronize
extern "C" CUresult cuEventSynchronize ( CUevent hEvent ) {
  typedef CUresult (*cuEventSynchronize_t)( CUevent hEvent );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuEventSynchronize)(hEvent);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Waits for an event to complete. */
/* ==== External Resource Interoperability ==== */

#undef cuDestroyExternalMemory
extern "C" CUresult cuDestroyExternalMemory ( CUexternalMemory extMem ) {
  typedef CUresult (*cuDestroyExternalMemory_t)( CUexternalMemory extMem );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDestroyExternalMemory)(extMem);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuDestroyExternalMemory, extMem, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys an external memory object. */

#undef cuDestroyExternalSemaphore
extern "C" CUresult cuDestroyExternalSemaphore ( CUexternalSemaphore extSem ) {
  typedef CUresult (*cuDestroyExternalSemaphore_t)( CUexternalSemaphore extSem );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDestroyExternalSemaphore)(extSem);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuDestroyExternalSemaphore, extSem, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys an external semaphore. */

#undef cuExternalMemoryGetMappedBuffer
extern "C" CUresult cuExternalMemoryGetMappedBuffer ( CUdeviceptr* devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC* bufferDesc ) {
  typedef CUresult (*cuExternalMemoryGetMappedBuffer_t)( CUdeviceptr* devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC* bufferDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuExternalMemoryGetMappedBuffer)(devPtr, extMem, bufferDesc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Maps a buffer onto an imported memory object. */

#undef cuExternalMemoryGetMappedMipmappedArray
extern "C" CUresult cuExternalMemoryGetMappedMipmappedArray ( CUmipmappedArray* mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC* mipmapDesc ) {
  typedef CUresult (*cuExternalMemoryGetMappedMipmappedArray_t)( CUmipmappedArray* mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC* mipmapDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuExternalMemoryGetMappedMipmappedArray)(mipmap, extMem, mipmapDesc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Maps a CUDA mipmapped array onto an external memory object. */

#undef cuImportExternalMemory
extern "C" CUresult cuImportExternalMemory ( CUexternalMemory* extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC* memHandleDesc ) {
  typedef CUresult (*cuImportExternalMemory_t)( CUexternalMemory* extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC* memHandleDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuImportExternalMemory)(extMem_out, memHandleDesc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Imports an external memory object. */

#undef cuImportExternalSemaphore
extern "C" CUresult cuImportExternalSemaphore ( CUexternalSemaphore* extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC* semHandleDesc ) {
  typedef CUresult (*cuImportExternalSemaphore_t)( CUexternalSemaphore* extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC* semHandleDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuImportExternalSemaphore)(extSem_out, semHandleDesc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Imports an external semaphore. */

#undef cuSignalExternalSemaphoresAsync
extern "C" CUresult cuSignalExternalSemaphoresAsync ( const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream ) {
  typedef CUresult (*cuSignalExternalSemaphoresAsync_t)( const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSignalExternalSemaphoresAsync)(extSemArray, paramsArray, numExtSems, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Signals a set of external semaphore objects. */

#undef cuWaitExternalSemaphoresAsync
extern "C" CUresult cuWaitExternalSemaphoresAsync ( const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream ) {
  typedef CUresult (*cuWaitExternalSemaphoresAsync_t)( const CUexternalSemaphore* extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS* paramsArray, unsigned int  numExtSems, CUstream stream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuWaitExternalSemaphoresAsync)(extSemArray, paramsArray, numExtSems, stream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Waits on a set of external semaphore objects. */
/*  ==== Stream memory operations  ==== */

#undef cuStreamBatchMemOp
extern "C" CUresult cuStreamBatchMemOp ( CUstream stream, unsigned int  count, CUstreamBatchMemOpParams* paramArray, unsigned int  flags ) {
  typedef CUresult (*cuStreamBatchMemOp_t)( CUstream stream, unsigned int  count, CUstreamBatchMemOpParams* paramArray, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamBatchMemOp)(stream, count, paramArray, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Batch operations to synchronize the stream via memory operations. */

#undef cuStreamWaitValue32
extern "C" CUresult cuStreamWaitValue32 ( CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags ) {
  typedef CUresult (*cuStreamWaitValue32_t)( CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamWaitValue32)(stream, addr, value, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Wait on a memory location. */

#undef cuStreamWaitValue64
extern "C" CUresult cuStreamWaitValue64 ( CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags ) {
  typedef CUresult (*cuStreamWaitValue64_t)( CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamWaitValue64)(stream, addr, value, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Wait on a memory location. */

#undef cuStreamWriteValue32
extern "C" CUresult cuStreamWriteValue32 ( CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags ) {
  typedef CUresult (*cuStreamWriteValue32_t)( CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamWriteValue32)(stream, addr, value, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Write a value to memory. */

#undef cuStreamWriteValue64
extern "C" CUresult cuStreamWriteValue64 ( CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags ) {
  typedef CUresult (*cuStreamWriteValue64_t)( CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuStreamWriteValue64)(stream, addr, value, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Write a value to memory. */
/*  ==== Execution Control  ==== */

#undef cuFuncGetAttribute
extern "C" CUresult cuFuncGetAttribute ( int* pi, CUfunction_attribute attrib, CUfunction hfunc ) {
  typedef CUresult (*cuFuncGetAttribute_t)( int* pi, CUfunction_attribute attrib, CUfunction hfunc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncGetAttribute)(pi, attrib, hfunc);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns information about a function. */

#undef cuFuncSetAttribute
extern "C" CUresult cuFuncSetAttribute ( CUfunction hfunc, CUfunction_attribute attrib, int  value ) {
  typedef CUresult (*cuFuncSetAttribute_t)( CUfunction hfunc, CUfunction_attribute attrib, int  value );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncSetAttribute)(hfunc, attrib, value);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets information about a function. */

#undef cuFuncSetCacheConfig
extern "C" CUresult cuFuncSetCacheConfig ( CUfunction hfunc, CUfunc_cache config ) {
  typedef CUresult (*cuFuncSetCacheConfig_t)( CUfunction hfunc, CUfunc_cache config );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncSetCacheConfig)(hfunc, config);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the preferred cache configuration for a device function. */

#undef cuFuncSetSharedMemConfig
extern "C" CUresult cuFuncSetSharedMemConfig ( CUfunction hfunc, CUsharedconfig config ) {
  typedef CUresult (*cuFuncSetSharedMemConfig_t)( CUfunction hfunc, CUsharedconfig config );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncSetSharedMemConfig)(hfunc, config);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the shared memory configuration for a device function. */

#undef cuLaunchCooperativeKernel
extern "C" CUresult cuLaunchCooperativeKernel ( CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams ) {
  typedef CUresult (*cuLaunchCooperativeKernel_t)( CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchCooperativeKernel)(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a CUDA function where thread blocks can cooperate and synchronize as they execute. */

#undef cuLaunchCooperativeKernelMultiDevice
extern "C" CUresult cuLaunchCooperativeKernelMultiDevice ( CUDA_LAUNCH_PARAMS* launchParamsList, unsigned int  numDevices, unsigned int  flags ) {
  typedef CUresult (*cuLaunchCooperativeKernelMultiDevice_t)( CUDA_LAUNCH_PARAMS* launchParamsList, unsigned int  numDevices, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchCooperativeKernelMultiDevice)(launchParamsList, numDevices, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches CUDA functions on multiple devices where thread blocks can cooperate and synchronize as they execute. */

#undef cuLaunchHostFunc
extern "C" CUresult cuLaunchHostFunc ( CUstream hStream, CUhostFn fn, void* userData ) {
  typedef CUresult (*cuLaunchHostFunc_t)( CUstream hStream, CUhostFn fn, void* userData );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchHostFunc)(hStream, fn, userData);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Enqueues a host function call in a stream. */

#undef cuLaunchKernel
extern "C" CUresult cuLaunchKernel ( CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams, void** extra ) {
  typedef CUresult (*cuLaunchKernel_t)( CUfunction f, unsigned int  gridDimX, unsigned int  gridDimY, unsigned int  gridDimZ, unsigned int  blockDimX, unsigned int  blockDimY, unsigned int  blockDimZ, unsigned int  sharedMemBytes, CUstream hStream, void** kernelParams, void** extra );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchKernel)(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a CUDA function. */
/* ==== Execution Control [DEPRECATED] ==== */

#undef cuFuncSetBlockShape
extern "C" CUresult cuFuncSetBlockShape ( CUfunction hfunc, int  x, int  y, int  z ) {
  typedef CUresult (*cuFuncSetBlockShape_t)( CUfunction hfunc, int  x, int  y, int  z );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncSetBlockShape)(hfunc, x, y, z);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the block-dimensions for the function. */

#undef cuFuncSetSharedSize
extern "C" CUresult cuFuncSetSharedSize ( CUfunction hfunc, unsigned int  bytes ) {
  typedef CUresult (*cuFuncSetSharedSize_t)( CUfunction hfunc, unsigned int  bytes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuFuncSetSharedSize)(hfunc, bytes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the dynamic shared-memory size for the function. */

#undef cuLaunch
extern "C" CUresult cuLaunch ( CUfunction f ) {
  typedef CUresult (*cuLaunch_t)( CUfunction f );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunch)(f);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a CUDA function. */

#undef cuLaunchGrid
extern "C" CUresult cuLaunchGrid ( CUfunction f, int  grid_width, int  grid_height ) {
  typedef CUresult (*cuLaunchGrid_t)( CUfunction f, int  grid_width, int  grid_height );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchGrid)(f, grid_width, grid_height);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a CUDA function. */

#undef cuLaunchGridAsync
extern "C" CUresult cuLaunchGridAsync ( CUfunction f, int  grid_width, int  grid_height, CUstream hStream ) {
  typedef CUresult (*cuLaunchGridAsync_t)( CUfunction f, int  grid_width, int  grid_height, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuLaunchGridAsync)(f, grid_width, grid_height, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches a CUDA function. */

#undef cuParamSetSize
extern "C" CUresult cuParamSetSize ( CUfunction hfunc, unsigned int  numbytes ) {
  typedef CUresult (*cuParamSetSize_t)( CUfunction hfunc, unsigned int  numbytes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuParamSetSize)(hfunc, numbytes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the parameter size for the function. */

#undef cuParamSetTexRef
extern "C" CUresult cuParamSetTexRef ( CUfunction hfunc, int  texunit, CUtexref hTexRef ) {
  typedef CUresult (*cuParamSetTexRef_t)( CUfunction hfunc, int  texunit, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuParamSetTexRef)(hfunc, texunit, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Adds a texture-reference to the function's argument list. */

#undef cuParamSetf
extern "C" CUresult cuParamSetf ( CUfunction hfunc, int  offset, float  value ) {
  typedef CUresult (*cuParamSetf_t)( CUfunction hfunc, int  offset, float  value );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuParamSetf)(hfunc, offset, value);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Adds a floating-point parameter to the function's argument list. */

#undef cuParamSeti
extern "C" CUresult cuParamSeti ( CUfunction hfunc, int  offset, unsigned int  value ) {
  typedef CUresult (*cuParamSeti_t)( CUfunction hfunc, int  offset, unsigned int  value );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuParamSeti)(hfunc, offset, value);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Adds an integer parameter to the function's argument list. */

#undef cuParamSetv
extern "C" CUresult cuParamSetv ( CUfunction hfunc, int  offset, void* ptr, unsigned int  numbytes ) {
  typedef CUresult (*cuParamSetv_t)( CUfunction hfunc, int  offset, void* ptr, unsigned int  numbytes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuParamSetv)(hfunc, offset, ptr, numbytes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Adds arbitrary data to the function's argument list. */
/*  ==== Graph Management  ==== */
/* CUresult cuGraphAddChildGraphNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies, CUgraph childGraph )*/
/* Creates a child graph node and adds it to a graph. */
/* CUresult cuGraphAddDependencies ( CUgraph hGraph, CUgraphNode* from, CUgraphNode* to, size_t numDependencies )*/
/* Adds dependency edges to a graph. */
/* CUresult cuGraphAddEmptyNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies )*/
/* Creates an empty node and adds it to a graph. */
/* CUresult cuGraphAddHostNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS* nodeParams )*/
/* Creates a host execution node and adds it to a graph. */
/* CUresult cuGraphAddKernelNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS* nodeParams )*/
/* Creates a kernel execution node and adds it to a graph. */
/* CUresult cuGraphAddMemcpyNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies, const CUDA_MEMCPY3D* copyParams, CUcontext ctx )*/
/* Creates a memcpy node and adds it to a graph. */
/* CUresult cuGraphAddMemsetNode ( CUgraphNode* phGraphNode, CUgraph hGraph, CUgraphNode* dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS* memsetParams, CUcontext ctx )*/
/* Creates a memset node and adds it to a graph. */
/* CUresult cuGraphChildGraphNodeGetGraph ( CUgraphNode hNode, CUgraph* phGraph )*/
/* Gets a handle to the embedded graph of a child graph node. */
/* CUresult cuGraphClone ( CUgraph* phGraphClone, CUgraph originalGraph )*/
/* Clones a graph. */

#undef cuGraphCreate
extern "C" CUresult cuGraphCreate ( CUgraph* phGraph, unsigned int  flags ) {
  typedef CUresult (*cuGraphCreate_t)( CUgraph* phGraph, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphCreate)(phGraph, flags);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuGraphCreate, phGraph, flags, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a graph. */

#undef cuGraphDestroy
extern "C" CUresult cuGraphDestroy ( CUgraph hGraph ) {
  typedef CUresult (*cuGraphDestroy_t)( CUgraph hGraph );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphDestroy)(hGraph);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuGraphDestroy, hGraph, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a graph. */

#undef cuGraphDestroyNode
extern "C" CUresult cuGraphDestroyNode ( CUgraphNode hNode ) {
  typedef CUresult (*cuGraphDestroyNode_t)( CUgraphNode hNode );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphDestroyNode)(hNode);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuGraphDestroyNode, hNode, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Remove a node from the graph. */

#undef cuGraphExecDestroy
extern "C" CUresult cuGraphExecDestroy ( CUgraphExec hGraphExec ) {
  typedef CUresult (*cuGraphExecDestroy_t)( CUgraphExec hGraphExec );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphExecDestroy)(hGraphExec);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuGraphExecDestroy, hGraphExec, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys an executable graph. */

#undef cuGraphGetEdges
extern "C" CUresult cuGraphGetEdges ( CUgraph hGraph, CUgraphNode* from, CUgraphNode* to, size_t* numEdges ) {
  typedef CUresult (*cuGraphGetEdges_t)( CUgraph hGraph, CUgraphNode* from, CUgraphNode* to, size_t* numEdges );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphGetEdges)(hGraph, from, to, numEdges);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a graph's dependency edges. */

#undef cuGraphGetNodes
extern "C" CUresult cuGraphGetNodes ( CUgraph hGraph, CUgraphNode* nodes, size_t* numNodes ) {
  typedef CUresult (*cuGraphGetNodes_t)( CUgraph hGraph, CUgraphNode* nodes, size_t* numNodes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphGetNodes)(hGraph, nodes, numNodes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a graph's nodes. */

#undef cuGraphGetRootNodes
extern "C" CUresult cuGraphGetRootNodes ( CUgraph hGraph, CUgraphNode* rootNodes, size_t* numRootNodes ) {
  typedef CUresult (*cuGraphGetRootNodes_t)( CUgraph hGraph, CUgraphNode* rootNodes, size_t* numRootNodes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphGetRootNodes)(hGraph, rootNodes, numRootNodes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a graph's root nodes. */

#undef cuGraphHostNodeGetParams
extern "C" CUresult cuGraphHostNodeGetParams ( CUgraphNode hNode, CUDA_HOST_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphHostNodeGetParams_t)( CUgraphNode hNode, CUDA_HOST_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphHostNodeGetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a host node's parameters. */

#undef cuGraphHostNodeSetParams
extern "C" CUresult cuGraphHostNodeSetParams ( CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphHostNodeSetParams_t)( CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphHostNodeSetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets a host node's parameters. */

#undef cuGraphInstantiate
extern "C" CUresult cuGraphInstantiate ( CUgraphExec* phGraphExec, CUgraph hGraph, CUgraphNode* phErrorNode, char* logBuffer, size_t bufferSize ) {
  typedef CUresult (*cuGraphInstantiate_t)( CUgraphExec* phGraphExec, CUgraph hGraph, CUgraphNode* phErrorNode, char* logBuffer, size_t bufferSize );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphInstantiate)(phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates an executable graph from a graph. */

#undef cuGraphKernelNodeGetParams
extern "C" CUresult cuGraphKernelNodeGetParams ( CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphKernelNodeGetParams_t)( CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphKernelNodeGetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a kernel node's parameters. */

#undef cuGraphKernelNodeSetParams
extern "C" CUresult cuGraphKernelNodeSetParams ( CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphKernelNodeSetParams_t)( CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphKernelNodeSetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets a kernel node's parameters. */

#undef cuGraphLaunch
extern "C" CUresult cuGraphLaunch ( CUgraphExec hGraphExec, CUstream hStream ) {
  typedef CUresult (*cuGraphLaunch_t)( CUgraphExec hGraphExec, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphLaunch)(hGraphExec, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Launches an executable graph in a stream. */

#undef cuGraphMemcpyNodeGetParams
extern "C" CUresult cuGraphMemcpyNodeGetParams ( CUgraphNode hNode, CUDA_MEMCPY3D* nodeParams ) {
  typedef CUresult (*cuGraphMemcpyNodeGetParams_t)( CUgraphNode hNode, CUDA_MEMCPY3D* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphMemcpyNodeGetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a memcpy node's parameters. */

#undef cuGraphMemcpyNodeSetParams
extern "C" CUresult cuGraphMemcpyNodeSetParams ( CUgraphNode hNode, const CUDA_MEMCPY3D* nodeParams ) {
  typedef CUresult (*cuGraphMemcpyNodeSetParams_t)( CUgraphNode hNode, const CUDA_MEMCPY3D* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphMemcpyNodeSetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets a memcpy node's parameters. */

#undef cuGraphMemsetNodeGetParams
extern "C" CUresult cuGraphMemsetNodeGetParams ( CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphMemsetNodeGetParams_t)( CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphMemsetNodeGetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a memset node's parameters. */

#undef cuGraphMemsetNodeSetParams
extern "C" CUresult cuGraphMemsetNodeSetParams ( CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS* nodeParams ) {
  typedef CUresult (*cuGraphMemsetNodeSetParams_t)( CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS* nodeParams );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphMemsetNodeSetParams)(hNode, nodeParams);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets a memset node's parameters. */

#undef cuGraphNodeFindInClone
extern "C" CUresult cuGraphNodeFindInClone ( CUgraphNode* phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph ) {
  typedef CUresult (*cuGraphNodeFindInClone_t)( CUgraphNode* phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphNodeFindInClone)(phNode, hOriginalNode, hClonedGraph);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Finds a cloned version of a node. */

#undef cuGraphNodeGetDependencies
extern "C" CUresult cuGraphNodeGetDependencies ( CUgraphNode hNode, CUgraphNode* dependencies, size_t* numDependencies ) {
  typedef CUresult (*cuGraphNodeGetDependencies_t)( CUgraphNode hNode, CUgraphNode* dependencies, size_t* numDependencies );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphNodeGetDependencies)(hNode, dependencies, numDependencies);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a node's dependencies. */

#undef cuGraphNodeGetDependentNodes
extern "C" CUresult cuGraphNodeGetDependentNodes ( CUgraphNode hNode, CUgraphNode* dependentNodes, size_t* numDependentNodes ) {
  typedef CUresult (*cuGraphNodeGetDependentNodes_t)( CUgraphNode hNode, CUgraphNode* dependentNodes, size_t* numDependentNodes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphNodeGetDependentNodes)(hNode, dependentNodes, numDependentNodes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a node's dependent nodes. */

#undef cuGraphNodeGetType
extern "C" CUresult cuGraphNodeGetType ( CUgraphNode hNode, CUgraphNodeType* type ) {
  typedef CUresult (*cuGraphNodeGetType_t)( CUgraphNode hNode, CUgraphNodeType* type );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphNodeGetType)(hNode, type);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a node's type. */
/* CUresult cuGraphRemoveDependencies ( CUgraph hGraph, CUgraphNode* from, CUgraphNode* to, size_t numDependencies )*/
/* Removes dependency edges from a graph. */
/*  ==== Occupancy ====  */

#undef cuOccupancyMaxActiveBlocksPerMultiprocessor
extern "C" CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor ( int* numBlocks, CUfunction func, int  blockSize, size_t dynamicSMemSize ) {
  typedef CUresult (*cuOccupancyMaxActiveBlocksPerMultiprocessor_t)( int* numBlocks, CUfunction func, int  blockSize, size_t dynamicSMemSize );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuOccupancyMaxActiveBlocksPerMultiprocessor)(numBlocks, func, blockSize, dynamicSMemSize);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns occupancy of a function. */

#undef cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags
extern "C" CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags ( int* numBlocks, CUfunction func, int  blockSize, size_t dynamicSMemSize, unsigned int  flags ) {
  typedef CUresult (*cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags_t)( int* numBlocks, CUfunction func, int  blockSize, size_t dynamicSMemSize, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags)(numBlocks, func, blockSize, dynamicSMemSize, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns occupancy of a function. */

#undef cuOccupancyMaxPotentialBlockSize
extern "C" CUresult cuOccupancyMaxPotentialBlockSize ( int* minGridSize, int* blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int  blockSizeLimit ) {
  typedef CUresult (*cuOccupancyMaxPotentialBlockSize_t)( int* minGridSize, int* blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int  blockSizeLimit );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuOccupancyMaxPotentialBlockSize)(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Suggest a launch configuration with reasonable occupancy. */

#undef cuOccupancyMaxPotentialBlockSizeWithFlags
extern "C" CUresult cuOccupancyMaxPotentialBlockSizeWithFlags ( int* minGridSize, int* blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int  blockSizeLimit, unsigned int  flags ) {
  typedef CUresult (*cuOccupancyMaxPotentialBlockSizeWithFlags_t)( int* minGridSize, int* blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int  blockSizeLimit, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuOccupancyMaxPotentialBlockSizeWithFlags)(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Suggest a launch configuration with reasonable occupancy. */
/* ==== Texture Reference Management [DEPRECATED] ==== */

#undef cuTexRefCreate
extern "C" CUresult cuTexRefCreate ( CUtexref* pTexRef ) {
  typedef CUresult (*cuTexRefCreate_t)( CUtexref* pTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefCreate)(pTexRef);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuTexRefCreate, pTexRef, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a texture reference. */

#undef cuTexRefDestroy
extern "C" CUresult cuTexRefDestroy ( CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefDestroy_t)( CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefDestroy)(hTexRef);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuTexRefDestroy, hTexRef, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a texture reference. */

#undef cuTexRefGetAddress_v2
extern "C" CUresult cuTexRefGetAddress_v2 ( CUdeviceptr* pdptr, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetAddress_v2_t)( CUdeviceptr* pdptr, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetAddress_v2)(pdptr, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the address associated with a texture reference. */

#undef cuTexRefGetAddressMode
extern "C" CUresult cuTexRefGetAddressMode ( CUaddress_mode* pam, CUtexref hTexRef, int  dim ) {
  typedef CUresult (*cuTexRefGetAddressMode_t)( CUaddress_mode* pam, CUtexref hTexRef, int  dim );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetAddressMode)(pam, hTexRef, dim);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the addressing mode used by a texture reference. */

#undef cuTexRefGetArray
extern "C" CUresult cuTexRefGetArray ( CUarray* phArray, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetArray_t)( CUarray* phArray, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetArray)(phArray, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the array bound to a texture reference. */

#undef cuTexRefGetBorderColor
extern "C" CUresult cuTexRefGetBorderColor ( float* pBorderColor, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetBorderColor_t)( float* pBorderColor, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetBorderColor)(pBorderColor, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the border color used by a texture reference. */

#undef cuTexRefGetFilterMode
extern "C" CUresult cuTexRefGetFilterMode ( CUfilter_mode* pfm, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetFilterMode_t)( CUfilter_mode* pfm, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetFilterMode)(pfm, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the filter-mode used by a texture reference. */

#undef cuTexRefGetFlags
extern "C" CUresult cuTexRefGetFlags ( unsigned int* pFlags, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetFlags_t)( unsigned int* pFlags, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetFlags)(pFlags, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the flags used by a texture reference. */

#undef cuTexRefGetFormat
extern "C" CUresult cuTexRefGetFormat ( CUarray_format* pFormat, int* pNumChannels, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetFormat_t)( CUarray_format* pFormat, int* pNumChannels, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetFormat)(pFormat, pNumChannels, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the format used by a texture reference. */

#undef cuTexRefGetMaxAnisotropy
extern "C" CUresult cuTexRefGetMaxAnisotropy ( int* pmaxAniso, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetMaxAnisotropy_t)( int* pmaxAniso, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetMaxAnisotropy)(pmaxAniso, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the maximum anisotropy for a texture reference. */

#undef cuTexRefGetMipmapFilterMode
extern "C" CUresult cuTexRefGetMipmapFilterMode ( CUfilter_mode* pfm, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetMipmapFilterMode_t)( CUfilter_mode* pfm, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetMipmapFilterMode)(pfm, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the mipmap filtering mode for a texture reference. */

#undef cuTexRefGetMipmapLevelBias
extern "C" CUresult cuTexRefGetMipmapLevelBias ( float* pbias, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetMipmapLevelBias_t)( float* pbias, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetMipmapLevelBias)(pbias, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the mipmap level bias for a texture reference. */

#undef cuTexRefGetMipmapLevelClamp
extern "C" CUresult cuTexRefGetMipmapLevelClamp ( float* pminMipmapLevelClamp, float* pmaxMipmapLevelClamp, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetMipmapLevelClamp_t)( float* pminMipmapLevelClamp, float* pmaxMipmapLevelClamp, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetMipmapLevelClamp)(pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the min/max mipmap level clamps for a texture reference. */

#undef cuTexRefGetMipmappedArray
extern "C" CUresult cuTexRefGetMipmappedArray ( CUmipmappedArray* phMipmappedArray, CUtexref hTexRef ) {
  typedef CUresult (*cuTexRefGetMipmappedArray_t)( CUmipmappedArray* phMipmappedArray, CUtexref hTexRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefGetMipmappedArray)(phMipmappedArray, hTexRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Gets the mipmapped array bound to a texture reference. */

#undef cuTexRefSetAddress_v2
extern "C" CUresult cuTexRefSetAddress_v2 ( size_t* ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes ) {
  typedef CUresult (*cuTexRefSetAddress_v2_t)( size_t* ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetAddress_v2)(ByteOffset, hTexRef, dptr, bytes);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Binds an address as a texture reference. */

#undef cuTexRefSetAddress2D_v3
extern "C" CUresult cuTexRefSetAddress2D_v3 ( CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR* desc, CUdeviceptr dptr, size_t Pitch ) {
  typedef CUresult (*cuTexRefSetAddress2D_v3_t)( CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR* desc, CUdeviceptr dptr, size_t Pitch );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetAddress2D_v3)(hTexRef, desc, dptr, Pitch);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Binds an address as a 2D texture reference. */

#undef cuTexRefSetAddressMode
extern "C" CUresult cuTexRefSetAddressMode ( CUtexref hTexRef, int  dim, CUaddress_mode am ) {
  typedef CUresult (*cuTexRefSetAddressMode_t)( CUtexref hTexRef, int  dim, CUaddress_mode am );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetAddressMode)(hTexRef, dim, am);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the addressing mode for a texture reference. */

#undef cuTexRefSetArray
extern "C" CUresult cuTexRefSetArray ( CUtexref hTexRef, CUarray hArray, unsigned int  Flags ) {
  typedef CUresult (*cuTexRefSetArray_t)( CUtexref hTexRef, CUarray hArray, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetArray)(hTexRef, hArray, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Binds an array as a texture reference. */

#undef cuTexRefSetBorderColor
extern "C" CUresult cuTexRefSetBorderColor ( CUtexref hTexRef, float* pBorderColor ) {
  typedef CUresult (*cuTexRefSetBorderColor_t)( CUtexref hTexRef, float* pBorderColor );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetBorderColor)(hTexRef, pBorderColor);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the border color for a texture reference. */

#undef cuTexRefSetFilterMode
extern "C" CUresult cuTexRefSetFilterMode ( CUtexref hTexRef, CUfilter_mode fm ) {
  typedef CUresult (*cuTexRefSetFilterMode_t)( CUtexref hTexRef, CUfilter_mode fm );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetFilterMode)(hTexRef, fm);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the filtering mode for a texture reference. */

#undef cuTexRefSetFlags
extern "C" CUresult cuTexRefSetFlags ( CUtexref hTexRef, unsigned int  Flags ) {
  typedef CUresult (*cuTexRefSetFlags_t)( CUtexref hTexRef, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetFlags)(hTexRef, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the flags for a texture reference. */

#undef cuTexRefSetFormat
extern "C" CUresult cuTexRefSetFormat ( CUtexref hTexRef, CUarray_format fmt, int  NumPackedComponents ) {
  typedef CUresult (*cuTexRefSetFormat_t)( CUtexref hTexRef, CUarray_format fmt, int  NumPackedComponents );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetFormat)(hTexRef, fmt, NumPackedComponents);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the format for a texture reference. */

#undef cuTexRefSetMaxAnisotropy
extern "C" CUresult cuTexRefSetMaxAnisotropy ( CUtexref hTexRef, unsigned int  maxAniso ) {
  typedef CUresult (*cuTexRefSetMaxAnisotropy_t)( CUtexref hTexRef, unsigned int  maxAniso );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetMaxAnisotropy)(hTexRef, maxAniso);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the maximum anisotropy for a texture reference. */

#undef cuTexRefSetMipmapFilterMode
extern "C" CUresult cuTexRefSetMipmapFilterMode ( CUtexref hTexRef, CUfilter_mode fm ) {
  typedef CUresult (*cuTexRefSetMipmapFilterMode_t)( CUtexref hTexRef, CUfilter_mode fm );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetMipmapFilterMode)(hTexRef, fm);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the mipmap filtering mode for a texture reference. */

#undef cuTexRefSetMipmapLevelBias
extern "C" CUresult cuTexRefSetMipmapLevelBias ( CUtexref hTexRef, float  bias ) {
  typedef CUresult (*cuTexRefSetMipmapLevelBias_t)( CUtexref hTexRef, float  bias );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetMipmapLevelBias)(hTexRef, bias);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the mipmap level bias for a texture reference. */

#undef cuTexRefSetMipmapLevelClamp
extern "C" CUresult cuTexRefSetMipmapLevelClamp ( CUtexref hTexRef, float  minMipmapLevelClamp, float  maxMipmapLevelClamp ) {
  typedef CUresult (*cuTexRefSetMipmapLevelClamp_t)( CUtexref hTexRef, float  minMipmapLevelClamp, float  maxMipmapLevelClamp );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetMipmapLevelClamp)(hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the mipmap min/max mipmap level clamps for a texture reference. */

#undef cuTexRefSetMipmappedArray
extern "C" CUresult cuTexRefSetMipmappedArray ( CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int  Flags ) {
  typedef CUresult (*cuTexRefSetMipmappedArray_t)( CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexRefSetMipmappedArray)(hTexRef, hMipmappedArray, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Binds a mipmapped array to a texture reference. */
/* ==== Surface Reference Management [DEPRECATED] ==== */

#undef cuSurfRefGetArray
extern "C" CUresult cuSurfRefGetArray ( CUarray* phArray, CUsurfref hSurfRef ) {
  typedef CUresult (*cuSurfRefGetArray_t)( CUarray* phArray, CUsurfref hSurfRef );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSurfRefGetArray)(phArray, hSurfRef);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Passes back the CUDA array bound to a surface reference. */

#undef cuSurfRefSetArray
extern "C" CUresult cuSurfRefSetArray ( CUsurfref hSurfRef, CUarray hArray, unsigned int  Flags ) {
  typedef CUresult (*cuSurfRefSetArray_t)( CUsurfref hSurfRef, CUarray hArray, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSurfRefSetArray)(hSurfRef, hArray, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Sets the CUDA array for a surface reference. */
/* ==== Texture Object Management ==== */

#undef cuTexObjectCreate
extern "C" CUresult cuTexObjectCreate ( CUtexObject* pTexObject, const CUDA_RESOURCE_DESC* pResDesc, const CUDA_TEXTURE_DESC* pTexDesc, const CUDA_RESOURCE_VIEW_DESC* pResViewDesc ) {
  typedef CUresult (*cuTexObjectCreate_t)( CUtexObject* pTexObject, const CUDA_RESOURCE_DESC* pResDesc, const CUDA_TEXTURE_DESC* pTexDesc, const CUDA_RESOURCE_VIEW_DESC* pResViewDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexObjectCreate)(pTexObject, pResDesc, pTexDesc, pResViewDesc);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuTexObjectCreate, pTexObject, pResDesc, pTexDesc, pResViewDesc, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a texture object. */

#undef cuTexObjectDestroy
extern "C" CUresult cuTexObjectDestroy ( CUtexObject texObject ) {
  typedef CUresult (*cuTexObjectDestroy_t)( CUtexObject texObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexObjectDestroy)(texObject);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuTexObjectDestroy, texObject, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a texture object. */

#undef cuTexObjectGetResourceDesc
extern "C" CUresult cuTexObjectGetResourceDesc ( CUDA_RESOURCE_DESC* pResDesc, CUtexObject texObject ) {
  typedef CUresult (*cuTexObjectGetResourceDesc_t)( CUDA_RESOURCE_DESC* pResDesc, CUtexObject texObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexObjectGetResourceDesc)(pResDesc, texObject);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a texture object's resource descriptor. */

#undef cuTexObjectGetResourceViewDesc
extern "C" CUresult cuTexObjectGetResourceViewDesc ( CUDA_RESOURCE_VIEW_DESC* pResViewDesc, CUtexObject texObject ) {
  typedef CUresult (*cuTexObjectGetResourceViewDesc_t)( CUDA_RESOURCE_VIEW_DESC* pResViewDesc, CUtexObject texObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexObjectGetResourceViewDesc)(pResViewDesc, texObject);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a texture object's resource view descriptor. */

#undef cuTexObjectGetTextureDesc
extern "C" CUresult cuTexObjectGetTextureDesc ( CUDA_TEXTURE_DESC* pTexDesc, CUtexObject texObject ) {
  typedef CUresult (*cuTexObjectGetTextureDesc_t)( CUDA_TEXTURE_DESC* pTexDesc, CUtexObject texObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuTexObjectGetTextureDesc)(pTexDesc, texObject);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a texture object's texture descriptor. */
/* ==== Surface Object Management ==== */

#undef cuSurfObjectCreate
extern "C" CUresult cuSurfObjectCreate ( CUsurfObject* pSurfObject, const CUDA_RESOURCE_DESC* pResDesc ) {
  typedef CUresult (*cuSurfObjectCreate_t)( CUsurfObject* pSurfObject, const CUDA_RESOURCE_DESC* pResDesc );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSurfObjectCreate)(pSurfObject, pResDesc);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuSurfObjectCreate, pSurfObject, pResDesc, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Creates a surface object. */

#undef cuSurfObjectDestroy
extern "C" CUresult cuSurfObjectDestroy ( CUsurfObject surfObject ) {
  typedef CUresult (*cuSurfObjectDestroy_t)( CUsurfObject surfObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSurfObjectDestroy)(surfObject);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc_cuSurfObjectDestroy, surfObject, ret_val);
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Destroys a surface object. */

#undef cuSurfObjectGetResourceDesc
extern "C" CUresult cuSurfObjectGetResourceDesc ( CUDA_RESOURCE_DESC* pResDesc, CUsurfObject surfObject ) {
  typedef CUresult (*cuSurfObjectGetResourceDesc_t)( CUDA_RESOURCE_DESC* pResDesc, CUsurfObject surfObject );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuSurfObjectGetResourceDesc)(pResDesc, surfObject);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Returns a surface object's resource descriptor. */
/* ==== Peer Context Memory Access  ==== */

#undef cuCtxDisablePeerAccess
extern "C" CUresult cuCtxDisablePeerAccess ( CUcontext peerContext ) {
  typedef CUresult (*cuCtxDisablePeerAccess_t)( CUcontext peerContext );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxDisablePeerAccess)(peerContext);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Disables direct access to memory allocations in a peer context and unregisters any registered allocations. */

#undef cuCtxEnablePeerAccess
extern "C" CUresult cuCtxEnablePeerAccess ( CUcontext peerContext, unsigned int  Flags ) {
  typedef CUresult (*cuCtxEnablePeerAccess_t)( CUcontext peerContext, unsigned int  Flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuCtxEnablePeerAccess)(peerContext, Flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Enables direct access to memory allocations in a peer context. */

#undef cuDeviceCanAccessPeer
extern "C" CUresult cuDeviceCanAccessPeer ( int* canAccessPeer, CUdevice dev, CUdevice peerDev ) {
  typedef CUresult (*cuDeviceCanAccessPeer_t)( int* canAccessPeer, CUdevice dev, CUdevice peerDev );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceCanAccessPeer)(canAccessPeer, dev, peerDev);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Queries if a device may directly access a peer device's memory. */

#undef cuDeviceGetP2PAttribute
extern "C" CUresult cuDeviceGetP2PAttribute ( int* value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice ) {
  typedef CUresult (*cuDeviceGetP2PAttribute_t)( int* value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuDeviceGetP2PAttribute)(value, attrib, srcDevice, dstDevice);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Queries attributes of the link between two devices. */
/* ==== Graphics Interoperability ==== */

#undef cuGraphicsMapResources
extern "C" CUresult cuGraphicsMapResources ( unsigned int  count, CUgraphicsResource* resources, CUstream hStream ) {
  typedef CUresult (*cuGraphicsMapResources_t)( unsigned int  count, CUgraphicsResource* resources, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsMapResources)(count, resources, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Map graphics resources for access by CUDA. */

#undef cuGraphicsResourceGetMappedMipmappedArray
extern "C" CUresult cuGraphicsResourceGetMappedMipmappedArray ( CUmipmappedArray* pMipmappedArray, CUgraphicsResource resource ) {
  typedef CUresult (*cuGraphicsResourceGetMappedMipmappedArray_t)( CUmipmappedArray* pMipmappedArray, CUgraphicsResource resource );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsResourceGetMappedMipmappedArray)(pMipmappedArray, resource);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get a mipmapped array through which to access a mapped graphics resource. */

#undef cuGraphicsResourceGetMappedPointer_v2
extern "C" CUresult cuGraphicsResourceGetMappedPointer_v2 ( CUdeviceptr* pDevPtr, size_t* pSize, CUgraphicsResource resource ) {
  typedef CUresult (*cuGraphicsResourceGetMappedPointer_v2_t)( CUdeviceptr* pDevPtr, size_t* pSize, CUgraphicsResource resource );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsResourceGetMappedPointer_v2)(pDevPtr, pSize, resource);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get a device pointer through which to access a mapped graphics resource. */

#undef cuGraphicsResourceSetMapFlags_v2
extern "C" CUresult cuGraphicsResourceSetMapFlags_v2 ( CUgraphicsResource resource, unsigned int  flags ) {
  typedef CUresult (*cuGraphicsResourceSetMapFlags_v2_t)( CUgraphicsResource resource, unsigned int  flags );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsResourceSetMapFlags_v2)(resource, flags);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Set usage flags for mapping a graphics resource. */

#undef cuGraphicsSubResourceGetMappedArray
extern "C" CUresult cuGraphicsSubResourceGetMappedArray ( CUarray* pArray, CUgraphicsResource resource, unsigned int  arrayIndex, unsigned int  mipLevel ) {
  typedef CUresult (*cuGraphicsSubResourceGetMappedArray_t)( CUarray* pArray, CUgraphicsResource resource, unsigned int  arrayIndex, unsigned int  mipLevel );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsSubResourceGetMappedArray)(pArray, resource, arrayIndex, mipLevel);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Get an array through which to access a subresource of a mapped graphics resource. */

#undef cuGraphicsUnmapResources
extern "C" CUresult cuGraphicsUnmapResources ( unsigned int  count, CUgraphicsResource* resources, CUstream hStream ) {
  typedef CUresult (*cuGraphicsUnmapResources_t)( unsigned int  count, CUgraphicsResource* resources, CUstream hStream );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsUnmapResources)(count, resources, hStream);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Unmap graphics resources. */

#undef cuGraphicsUnregisterResource
extern "C" CUresult cuGraphicsUnregisterResource ( CUgraphicsResource resource ) {
  typedef CUresult (*cuGraphicsUnregisterResource_t)( CUgraphicsResource resource );
  CUresult ret_val = CUDA_SUCCESS;
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  ret_val = REAL_FNC(cuGraphicsUnregisterResource)(resource);
  RETURN_TO_UPPER_HALF();
  DMTCP_PLUGIN_ENABLE_CKPT();
  return ret_val;
}

/* Unregisters a graphics resource for access by CUDA. */

#undef __cudaRegisterFatBinaryEnd
extern "C" void                                                                             __cudaRegisterFatBinaryEnd(void **fatCubinHandle) {
  typedef void (*__cudaRegisterFatBinaryEnd_t)(void **fatCubinHandle);
  DMTCP_PLUGIN_DISABLE_CKPT();
  JUMP_TO_LOWER_HALF(lhInfo.lhFsAddr);
  printf("✋enter 拦截的 fatbinaryend  \n");
  REAL_FNC(__cudaRegisterFatBinaryEnd)(fatCubinHandle);
  RETURN_TO_UPPER_HALF();
/* Insert logging code here */
  logAPI(Cuda_Fnc___cudaRegisterFatBinaryEnd, fatCubinHandle);
  DMTCP_PLUGIN_ENABLE_CKPT();
}

