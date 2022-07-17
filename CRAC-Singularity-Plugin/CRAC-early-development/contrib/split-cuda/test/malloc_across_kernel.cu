#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

// using device-side mallocs that persist across kernel invocations
// based off of http://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html#allocation-persisting-kernel-launches
#define NUM_BLOCKS 1
__device__ int* tenptr[NUM_BLOCKS];

__global__ void alloc_and_set_ten()
{
    // Only the first thread in the block does the allocation
    // since we want only one allocation per block.
    if (threadIdx.x == 0) {
        tenptr[blockIdx.x] = (int*)malloc(sizeof(int));
        printf("tenptr[blockIdx.x] = %p\n", tenptr[blockIdx.x]);
        *tenptr[blockIdx.x] = 10;  // set the value
        printf("*tenptr[blockIdx.x] = %d\n", *tenptr[blockIdx.x]);
    }
    __syncthreads();
}
__global__ void copydata(int *dest) 
{
    if (threadIdx.x == 0) {
        // *(dest + blockIdx.x) = *tenptr[blockIdx.x];
        *dest  = 5;
    }
    
}


__global__ void add(int a, int b, int *c)
{   
    printf("add func called \n");
    printf("*tenptr[blockIdx.x] = %d\n", *tenptr[0]);
	*c = a+b+*tenptr[blockIdx.x];
    
}

__global__ void free_ten()
{
    // Free from the leader thread in each thread block
    if (threadIdx.x == 0)
        free(tenptr[blockIdx.x]);
}

int main(int argc, char **argv)
{
	// test
    int a = 2, b = 3, c, *e;
    // uint64_t d;
	int *cuda_c = NULL;
    cudaMallocHost(&e, sizeof(int));
    *e=1;

    // 设置设备变量cuda_c
	cudaMalloc(&cuda_c, sizeof(int));
    // 设置device变量tenptr为10
    alloc_and_set_ten<<<NUM_BLOCKS,1>>>();
    // cudaDeviceSynchronize();
    printf("sleep start now\n");
    sleep(4);
    printf("sleep end\n");
    
// 这块东西在干什么？
    // void * ptr = (void *)0x7fffe4bd4697;
    // cudaMemcpy(&d, ptr, 8, cudaMemcpyDeviceToHost);
	// printf("%zx\n", d);
    
    add<<<NUM_BLOCKS,1>>>(a, b, cuda_c);

    // printf("cuda_c:%d\n",*cuda_c);   加上这一句出现段错误

    //这里cuda_c 变成15
    
	cudaMemcpy(&c, cuda_c, sizeof(int), cudaMemcpyDeviceToHost);
	// cudaMemcpy(&e, tenptr[0], sizeof(int), cudaMemcpyDeviceToHost);
    // copydata<<<1,1>>>(e);

    // printf("e:%d\n",*e);
	printf("%d + %d + 10 = %d\n", a, b, c);

	cudaFree(cuda_c);
    free_ten<<<NUM_BLOCKS,1>>>();
    printf("end\n");
	exit(EXIT_SUCCESS);
}
