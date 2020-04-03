#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

const Vec3b HSV_YELLOW_LOWER = Vec3b(10, 70, 130);
const Vec3b HSV_YELLOW_UPPER = Vec3b(50, 255, 255);

const Vec3b HSV_RED_LOWER = Vec3b(0, 100, 100);
const Vec3b HSV_RED_UPPER = Vec3b(10, 255, 255);
const Vec3b HSV_RED_LOWER1 = Vec3b(160, 100, 100);
const Vec3b HSV_RED_UPPER1 = Vec3b(179, 255, 255);

const Vec3b HSV_GREEN_LOWER = Vec3b(60, 100, 150);
const Vec3b HSV_GREEN_UPPER = Vec3b(100, 255, 255);

void get_center_point(Mat& binaryImg, Point * p){

    int cnt_x = 0;
    int cnt_y = 0;
    int count = 0;

    for(int i = 0; i < binaryImg.cols; i++){
        for(int j = 0; j < binaryImg.rows; j++){
            if (binaryImg.at<uchar>(j, i) == 255){
                cnt_x += i;
                cnt_y += j;
                count++;
            }
        }
    }

    if(count > 50){
        p->x = cnt_x / count;
        p->y = cnt_y / count;
    }
}

int main(){

	VideoCapture cap("_talkv_wm2vK5CHJH_DqPSRZmQ7lho4AKdnLXfs1_talkv_high(1).MP4");
	
	while(1){

		Mat frame;
		cap >> frame;
		Mat hsv;
		cvtColor(frame, hsv, COLOR_BGR2HSV);
		//imshow("hsv", hsv);
		Mat red, red1, yellow, green;

   		inRange(hsv, HSV_RED_LOWER, HSV_RED_UPPER, red);
   		inRange(hsv, HSV_RED_LOWER1, HSV_RED_UPPER1, red1);

		red = red | red1;
		//imshow("red", red);

   		inRange(hsv, HSV_YELLOW_LOWER, HSV_YELLOW_UPPER, yellow);
		//imshow("yellow", yellow);
   		inRange(hsv, HSV_GREEN_LOWER, HSV_GREEN_UPPER, green);
		//imshow("green", green);

		Point redCenter(0, 0), yellowCenter(0, 0) , greenCenter(0, 0);

  		get_center_point(red, & redCenter);
  		get_center_point(yellow, & yellowCenter);
		get_center_point(green, & greenCenter);

		cout << redCenter << endl;
		cout << yellowCenter << endl;
		cout << greenCenter << endl;

		Mat output;
		cvtColor(red, red, COLOR_GRAY2BGR);
		cvtColor(yellow, yellow, COLOR_GRAY2BGR);
		cvtColor(green, green, COLOR_GRAY2BGR);
		imshow("Src", frame);
		imshow("Red", red);
		imshow("Yellow", yellow);
		imshow("Green", green);

		if(waitKey(27) == 1) break;


		
	
		
	}


}
