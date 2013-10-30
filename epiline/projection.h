#pragma once

#include <vector>
#include <fstream>
#include <set>
#include <iostream>
#include <string>

#include "CMPMVS_DATA.h"
#include "boost\thread.hpp"
#include "boost\ptr_container\ptr_vector.hpp"

#define DIFX 10.654
#define DIFY 0.976

#define CPUs 12

#define IMGX 1280
#define IMGY 720

/*
#define IMGX 3872
#define IMGY 2592
*/
/*
#define IMGX 320
#define IMGY 240
*/
/*
typedef struct vertex2d{
	Point::xy vertex[3];
	int img;
}vertex2d;
*/

typedef struct projection{
	//image index
	std::vector<Point::xy> d2;
	Point::xyz d3;
	int gomi_n;
	Point::xy gomi_p;
}projection;



class thread_mutex{
public:
	void init();
	boost::mutex sync;
	int index;
};



class Projection{
public:
	void init(CMPMVS *cmp);
	void run();
	void write();
	void write_vis();
	void read();
	void read_noinit();
	void input_proj_result(projection data,int index);
	void del_badview(int cam,int point,int value);
	projection get_proj_vertex(int index);
	projection get_proj_GLvertex(int index);
	bool get_proj_d3point(int index,int cam,Point::xyz &data);
	int proj_size();

	int IMG_NUM;
	boost::mutex sync;


private:
	CMPMVS *m_cmp;
	std::vector<Eigen::MatrixXd> ppm;
	std::vector<projection> proj_result;
	thread_mutex thm;

	void run_thread(int num);
	Point::xy compute_proj(Point::xyz p,int img);
	void read_ppm();

};

