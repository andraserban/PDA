#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

__global__ void motionDetection(unsigned char *source, int width, int height)
{

	int x = (blockIdx.x * blockDim.x) + threadIdx.x;

	float *sum;
	float *tmp_sum;

	for (int i = 0; i <= width; i++)
	{
		tmp_sum[x] += source[x][i] ;
	}
	for (int j = 0; j <= N ; j++)
		
		sum += tmp_sum[j];

}
int main(int argc, char** argv)
{
	cv::VideoCapture camera(0);
	if (!camera.isOpened()){
		return -1;
	}
	int *d_width;
	int *d_height;
	
	size_t size = height * width;
	
	cudaMalloc(&d_width, sizeof(int));
	cudaMalloc(&d_height, sizeof(int));
	
	cudaMemcpy(d_width, &width, sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy(d_height, &height, sizeof(int), cudaMemcpyHostToDevice);
	// Invoke kernel
	motionDetection<< <width, height >> >();

}