#pragma once

#include <vector>
#include <fstream>
#include <set>
#include <iostream>
#include <string>

#include "Eigen\Core"
#include "Eigen\Dense"
#include "boost\filesystem.hpp"


#include "base_class.h"


class CMPMVS{
public:
	void init();
	std::vector<int> get_face_index(int face_num);
	std::vector<Point::xyz> get_face_corr(int face_num);
	Point::xyz get_point(int p_num);

	int vertex_size,face_size;
private:
	std::vector<Point::xyz> vertex;
	std::vector<SURFACE::triagnle> face;
	
};

