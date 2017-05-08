#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

__constant__ float arraySum[255];
__global__ void sumOfThePixels(unsigned char *source, int width, int height,unsigned char *destination)
{
	// Calculate our pixel's location
	int x = (blockIdx.x * blockDim.x) + threadIdx.x;

	float sum = 0.0f;
	float tmp_sum[255];//alocat

	for (int i = 0; i <= width; i++)
	{
		tmp_sum[x] += source[x][i] ;
	}
	for (int j = 0; j <= ; j++)
		//parcurg tmp_sum => suma finala
		sum += tmp_sum[j];

	destination[(y * width) + x] = (unsigned char)sum;
}
int main(int argc, char** argv)
{
	
	cv::VideoCapture camera(0);
	cv::Mat          frame;
	if (!camera.isOpened())
		return -1;
}