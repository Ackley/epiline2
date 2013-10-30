#include "Cameras.h"
#include <string>
#include <iostream>
#include "boost\foreach.hpp"
#include <stdlib.h>

#define foreach BOOST_FOREACH

ExImage<tagEX_BGR8U> Camera::get_img_data(int index){
	return cameras[index].img;
}

void Camera::init(std::string name){
	filepass = name;
	read_camera_param();

}

void Camera::read_camera_param(){
	std::ifstream ifs(filepass+"\\cameras_v2.txt");
	std::string dummy;

	for(int i = 0;i < 19;++i){
		std::getline(ifs,dummy);
	}

	int size;
	ifs >> size;


	for(int i = 0;i < size;++i){
		SfM_camera tmp;
		ifs >> tmp.filename >> dummy >> tmp.focal >> tmp.img_center[0] >> tmp.img_center[1];

		ifs >> dummy >> dummy >> dummy;
		ifs >> tmp.d3pos.x >> tmp.d3pos.y >> tmp.d3pos.z;
		for(int j = 0;j < 7;++j)
			ifs >> dummy;
		for(int j = 0;j < 9;++j)
			ifs >> tmp.R[j];

		for(int j = 0;j < 4;++j)
			ifs >> dummy;

		std::string filename = filepass + "\\visualize\\" + tmp.filename;
		tmp.img.Load(filename.c_str());
		cameras.push_back(tmp);
	}

}
/*
void Camera::conner_min_eigenval(SfM_camera &cam){
	ExImage<EX_GRAY8U> gray,eig,tmp;
	CvPoint2D32f *corners = new CvPoint2D32f;

	gray = cvCreateImage(cvGetSize(cam.img.Ipl()),IPL_DEPTH_8U,1);
	eig = cvCreateImage(cvGetSize(cam.img.Ipl()),IPL_DEPTH_8U,1);
	tmp = cvCreateImage(cvGetSize(cam.img.Ipl()),IPL_DEPTH_8U,1);

	cvCvtColor(cam.img.Ipl(),gray.Ipl(),CV_BGR2GRAY);

	cam.corner_count = 50;
	cvGoodFeaturesToTrack(gray.Ipl(),eig.Ipl(),tmp.Ipl(),corners,&cam.corner_count,0.1,15);
	cvFindCornerSubPix (gray.Ipl(), corners, cam.corner_count,
		cvSize (3, 3), cvSize (-1, -1), cvTermCriteria (CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03));

	cam.img_corners = corners;

}*/

void Camera::find_corner(){
	foreach(SfM_camera &it,cameras){
		std::string pass = filepass + "\\visualize\\" + it.filename;
		std::string cmd = "find_corner.exe " + pass;
		system(cmd.c_str());
	}
	read_corner();
}

void Camera::read_corner(){
	foreach(SfM_camera &it,cameras){
		std::string pass = filepass + "\\visualize\\" + it.filename + ".txt";

		std::ifstream ifs(pass);

		int size;
		ifs >> size;

		for(int i = 0;i < size;++i){
			CvPoint2D32f tmp;
			ifs >> tmp.x >> tmp.y;
			it.img_corners.push_back(tmp);
		}
	}


}