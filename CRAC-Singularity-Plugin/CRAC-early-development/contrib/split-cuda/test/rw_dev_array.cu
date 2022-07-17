#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// reading and writing a device variable (with array)
__device__ int incr_idx = 0;
__device__ int incr_arr [] = {10, 11};

__global__ void add(int a, int b, int *c)
{
	*c = a+b+incr_arr[incr_idx++];
	printf("c = %d at %p\n", *c, c);
}

__global__ void addd(int a, int b, int *c)
{	
	printf("👿cuda_d addd start \n ");

	*c = a+b+5;
	printf("👿d = %d at %p\n", *c, c);
	printf("👿cuda_d addd end \n ");
}
__global__ void aprint(int a, int b, int *c)
{
	*c = a+b+5;
	printf("d = %d at %p\n", *c, c);
}

int main(int argc, char **argv)
{
	// test
	int a = 2, b = 3, c=2 ,d =2;
	int *cuda_c = NULL;
	int *cuda_d = NULL;
	printf("c val = %d\n", c);


	printf("cuda_c before malloc= %p\n", cuda_c);

	cudaMalloc(&cuda_c, sizeof(int));
	cudaMalloc(&cuda_d, sizeof(int));


	printf("cuda_c = %p\n", cuda_c);
	printf("cuda_d = %p\n", cuda_d);
	// add<<<1,1>>>(a, b, cuda_c);
	add<<<1,1>>>(a, b, cuda_c);
	cudaDeviceSynchronize();

	printf("cuda_c add = %p\n", cuda_c);
	printf("c val = %d\n", c);





	printf("before checkpoint\n");
    sleep(4);
	printf("after checkpoint\n");
	


	printf("cuda_c add = %p\n", cuda_c);
	printf("c val = %d\n", c);

	// 这个有问题
	cudaMemcpy(&c, cuda_c, sizeof(int), cudaMemcpyDeviceToHost);
	printf("cuda_d add = %p\n", cuda_d);


	addd<<<1,1>>>(a, b, cuda_d);
	// printf("cuda_d add = %d\n", *(int*)cuda_d);
	cudaDeviceSynchronize();
	cudaMemcpy(&d, cuda_d, sizeof(int), cudaMemcpyDeviceToHost);
	cudaDeviceSynchronize();
	printf("d val = %d\n", d);
	
	

	cudaFree(cuda_c);
	cudaFree(cuda_d);

	printf("%d + %d + 11= %d\n", a, b, c);

	exit(EXIT_SUCCESS);
}
