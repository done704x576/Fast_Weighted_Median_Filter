// Fast_Weighted_Median_Filter.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include"opencv2\core\core.hpp"
#include"opencv2\highgui\highgui.hpp"
#include"opencv2\imgproc\imgproc.hpp"
#include<time.h>

#include"JointWMF.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	/***
	* PLEASE compile it in release x64 mode
	* AND execute it using run.bat in .\x64\Release
	**/

	string filename = "image1.png";

	Mat img = imread(filename);
	clock_t start;

	// Example of uchar image filtering
	{
		start = clock();
		Mat res1 = JointWMF::filter(img,img,10);
		printf("Time of Example 1: %d ms\n",clock()-start);
		imshow("res1",res1);
	}

	// Example of floating point image filtering
	{
		Mat imgf;
		img.convertTo(imgf,CV_32F);
		imgf = imgf/255;

		start = clock();
		Mat res2 = JointWMF::filter(imgf,img,10);
		printf("Time of Example 2: %d ms\n",clock()-start);
		imshow("res2",res2);
	}

	// Example of single channel feature
	{
		Mat imgg;
		cvtColor(img,imgg,CV_BGR2GRAY);
		start = clock();
		Mat res3 = JointWMF::filter(img,imgg,10);
		printf("Time of Example 1: %d ms\n",clock()-start);
		imshow("res3",res3);
	}

	waitKey();
	return 0;
}

