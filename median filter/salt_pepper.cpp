#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void saltandpepper(Mat& img, double noise)
{
	int rows = img.rows;
	int cols = img.cols;
	int channel = img.channels();
	int num_noise_pixel = (int)((double)(rows*cols*channel)*noise);
	for (int i = 0; i < num_noise_pixel; i++){
		int r = rand() % rows;
		int c = rand() % cols;
		int _ch = rand() % channel;
		uchar* pixel = img.ptr<uchar>(r) + (c*channel) + _ch;
		*pixel = (rand() % 2 == 1) ? 255 : 0;

	}
}

int main()
{
	Mat img;
	Mat result;

	img = imread("result_image.jpg",CV_LOAD_IMAGE_COLOR);
	
	result = img.clone();
	saltandpepper(result,0.05);

	imshow("original", img);
	imwrite("result.jpg", result);
}
