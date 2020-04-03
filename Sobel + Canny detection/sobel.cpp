#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "iostream"


using namespace cv;

using namespace std;


int main()

{

	Mat src1;

	src1 = imread("lena.png", CV_LOAD_IMAGE_COLOR);

	namedWindow("Original image", CV_WINDOW_AUTOSIZE);

	imshow("Original image", src1);


	Mat grey;

	cvtColor(src1, grey, CV_BGR2GRAY); // 그레이 영상으로 변환


	Mat sobelx, sobely;

	Sobel(grey, sobelx, CV_32F, 1, 0); // Sobel 엣지 검출

	Sobel(grey, sobely, CV_32F, 0, 1);

	///

	namedWindow("vertical edge", CV_WINDOW_AUTOSIZE);

	imshow("vertical edge", sobelx);
	imwrite("vertical.png", sobelx);

	namedWindow("horizontal edge", CV_WINDOW_AUTOSIZE);

	imshow("horizontal edge", sobely);
	imwrite("horizontal.png", sobely);

	waitKey(0);


	return 0;

}
