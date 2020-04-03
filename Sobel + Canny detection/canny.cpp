#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;


Mat src_gray;
Mat dst, detected_edges;

int lowThreshold = 50;
int highThreshold = 150;


int main(int argc, char** argv)
{

	Mat src = imread("lena.png", IMREAD_COLOR); // Load an image
	if (src.empty())
	{
		std::cout << "Could not open or find the image!\n" << std::endl;
		std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
		return -1;
	}

	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	blur(src_gray, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold, highThreshold, 3);

	namedWindow("Canny Edge", WINDOW_AUTOSIZE);
	imwrite("Canny_Edge.png", detected_edges);


	waitKey(0);
	return 0;
}
