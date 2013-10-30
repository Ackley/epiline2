#include "bundler_parser.h"

void BUNDLER::read(std::string filename){
	std::ifstream ifs(filename);
	if(ifs.fail()){
		std::cout << "bundler open error" << std::endl;
		exit(1);
	}

	std::string dummy;
	std::getline(ifs,dummy);

	ifs >> this->camera_size;
	ifs >> this->feat_size;

	read_camera(&ifs);
	read_feat(&ifs);

	for(std::vector<BundlerFeaturePoints>::iterator it = points.begin();it != points.end();++it){
		for(int i = 0;i < it->d2point.size();++i){
			it->d2point[i].x += (IMGX/2);
			it->d2point[i].y = it->d2point[i].y - (IMGY/2) * -1;
		}
	}

}

void BUNDLER::read_camera(std::ifstream *ifs){
	for(int i = 0;i < this->camera_size;++i){
		BundlerCamera cam_buf;

		*ifs >> cam_buf.f >> cam_buf.k1 >> cam_buf.k2;
		
		for(int j = 0;j < 9;++j)
			*ifs >> cam_buf.R[j];
		for(int j = 0;j < 3;++j)
			*ifs >> cam_buf.t[j];
		this->camera.push_back(cam_buf);
	}
}

void BUNDLER::read_feat(std::ifstream *ifs){
	for(int fsize = 0;fsize< this->feat_size;++fsize){
		BundlerFeaturePoints point_buf;
		//read pos and color
		for(int i = 0;i < 3;++i)
			*ifs >> point_buf.pos[i];
		for(int i = 0;i < 3;++i)
			*ifs >> point_buf.color[i];

		//read 2d feature
		int d2size;
		*ifs >> d2size;
		for(int d2 = 0;d2 < d2size;++d2){
			D2Point buf;
			*ifs >> buf.camera_num >> buf.feature_num >> buf.x >> buf.y;
			point_buf.d2point.push_back(buf);
		}

		this->points.push_back(point_buf);
	}
}
BundlerCamera BUNDLER::get_camera(int index){
	return this->camera[index];
}
BundlerFeaturePoints BUNDLER::get_feat(int index){
	return this->points[index];
}
std::vector<MatchFeat> BUNDLER::find_FeatMatch_2view(int cam1,int cam2){
	std::vector<MatchFeat> result;

	for(int i = 0;i < this->feat_size;++i){
		MatchFeat buf;
		bool flag1 = false , flag2 = false;
		for(std::vector<D2Point>::iterator it = points[i].d2point.begin();
			it != points[i].d2point.end();++it){
				if(it->camera_num == cam1){
					flag1 = true;
					buf.p1 = *it;
				}else if(it->camera_num == cam2){
					flag2 = true;
					buf.p2 = *it;
				}		

		}
		if(flag1 && flag2){
			buf.d3index = i;
			result.push_back(buf);
		}
	}
	return result;
}

//=================(ÅLÅEÉ÷ÅEÅM)=====================
/*void BUNDLER::write(std::string filename){
	std::ofstream ofs(filename);

	using namespace std;
	ofs << "# Bundle file v0.3" << endl;
	ofs << camera_size << " " << feat_size;

	for(vector<BundlerCamera>::iterator it = camera.begin();it != camera.end();++it){
		ofs << it->f << " " << it->k1 << " " << it->k2 << endl;
		
		for(int i = 0;i < 3;++i){
			for(int j = 0;j < 3;++j){
				ofs << it->R[j+i*3];			
			}
		}
	//ñ ì|orz
	}

}*/