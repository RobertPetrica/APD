#include <io.h>
#include <malloc.h>
#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>
#include <cuda_runtime.h>

#define n 10

__global__ void quickSort(int arr[], int first, int last);

int main(){

	int index;
	int size;
	size = n * sizeof(int);
	// Allocate input vector h_arr in host memory

	int* h_arr = (int*)malloc(size); 
	
	//// Allocate vector d_arr in device memory
	int* d_arr;
	cudaMalloc(&d_arr, size); 

	for(index=0;index<n;index++){
		printf("enter the %d number from arr",index);
		scanf("%d",&h_arr[index]);
	}

		// Copy vector from host memory to device memory

	cudaMemcpy(d_arr, h_arr, size, cudaMemcpyHostToDevice); 

	//// Kernel invocation with one block of N * N * 1 threads
	//and modifying the host code by replacing the <<<...>>> syntax introduced in Kernels 

	// Invoke kernel
	quickSort <<< 1, n >>>(d_arr, 0, n-1);
	 
	// Copy result from device memory to host memory // h_C contains the result in host memory
    //<<<blocksPerGrid, threadsPerBlock>>>
	cudaMemcpy(h_arr, d_arr, size, cudaMemcpyDeviceToHost);

	 // Free device memory
	cudaFree(d_arr);

}


 __global__void quickSort(int arr,int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(arr[i]<=arr[pivot]&&i<last)
                 i++;
             while(arr[j]>arr[pivot])
                 j--;
             if(i<j){
                 temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
             }
         }

         temp=arr[pivot];
         arr[pivot]=arr[j];
         arr[j]=temp;
         quickSort(arr,first,j-1);
         quickSort(arr,j+1,last);

    }

}