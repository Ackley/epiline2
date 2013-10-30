#pragma once
#include "base_class.h"
#include "ExImage.h"

class SfM_camera{
public:
	std::string filename;
	Point::xyz d3pos;
	float focal;
	int img_center[2];
	float R[9];

	ExImage<tagEX_BGR8U> img;
	CvPoint2D32f *corners;
};

class Camera{
public:
	void init(std::string name);
	void find_corner();

private:
	std::vector<SfM_camera> cameras;
	std::string filepass;

	void read_camera_param();
	void read_img();
	void conner_min_eigenval(SfM_camera &cam);
};
