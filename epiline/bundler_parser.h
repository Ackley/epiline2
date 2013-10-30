#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#define IMGX 1280
#define IMGY 720

typedef struct BundlerCamera{
	double f,k1,k2;
	double R[9];
	double t[3];
}BundlerCamera;

typedef struct D2Point{
	int camera_num;
	int feature_num;
	double x,y;
}D2Point;

typedef struct BundlerFeaturePoints{
	double pos[3];
	int color[3];
	std::vector<D2Point> d2point;
}BundlerFeaturePoints;

typedef struct MatchFeat{
	D2Point p1,p2;
	int d3index;
}MatchFeat;

class BUNDLER{
public:
	int camera_size,feat_size;
	
	void read(std::string filename);
	BundlerCamera get_camera(int index);
	BundlerFeaturePoints get_feat(int index);
	std::vector<MatchFeat> find_FeatMatch_2view(int cam1,int cam2);
	

	//void write(std::string filename);
private:
	std::vector<BundlerCamera> camera;
	std::vector<BundlerFeaturePoints> points;

	void read_camera(std::ifstream *ifs);
	void read_feat(std::ifstream *ifs);
};