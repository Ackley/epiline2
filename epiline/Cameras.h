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
	int corner_count;
	std::vector<CvPoint2D32f> img_corners;
};

class Camera{
public:
	void init(std::string name);
	void find_corner();
	void read_corner();
	ExImage<tagEX_BGR8U> get_img_data(int index);

private:
	std::vector<SfM_camera> cameras;
	std::string filepass;

	void read_camera_param();
	void read_img();
	void conner_min_eigenval(SfM_camera &cam);

};
