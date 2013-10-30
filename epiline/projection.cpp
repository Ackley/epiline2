#include "projection.h"
#include "boost\foreach.hpp"
#define foreach BOOST_FOREACH

int Projection::proj_size(){
	return proj_result.size();
}

projection Projection::get_proj_vertex(int index){
	return proj_result[index];
}

projection Projection::get_proj_GLvertex(int index){
	
	projection result = proj_result[index];
	
	foreach(Point::xy &it,result.d2){
		it.x /= IMGX;
		it.y /= IMGY;
	}
	
	return result;
}

bool Projection::get_proj_d3point(int index,int cam,Point::xyz &data){
	if(proj_result[index].d2[cam].status != 0)
		return false;

	data = proj_result[index].d3;
	return true;
}

void Projection::del_badview(int cam,int point,int value){
	this->proj_result[point].d2[cam].status = value;
}


void Projection::init(CMPMVS *cmp){
	m_cmp = cmp;
	read_ppm();
}

void Projection::run(){
	proj_result.resize(m_cmp->vertex_size);
	
	thm.init();

	boost::ptr_vector<boost::thread> ths;
	for(int i = 0;i < CPUs;++i)
		ths.push_back(new boost::thread(boost::bind(&Projection::run_thread,this,i) ));
	for(int i = 0;i < CPUs;++i)
		ths[i].join();
}


void Projection::input_proj_result(projection data,int index){
	proj_result[index] = data;
}


void Projection::read_ppm(){
	for(int i = 0;;++i){
		char f_name[64];
		sprintf(f_name,"data\\%05d_P.txt",i+1);
		std::ifstream ifs(f_name);
		if(ifs.fail()){
			std::cout << "read " << i << " files" << std::endl;
			IMG_NUM = i;
			break;
		}

		double fdata[12];
		for(int i = 0;i < 12;++i)
			ifs >> fdata[i];

		Eigen::MatrixXd tmp(3,4);
		tmp << fdata[0], fdata[1], fdata[2], fdata[3],
			fdata[4], fdata[5], fdata[6], fdata[7],
			fdata[8], fdata[9], fdata[10], fdata[11];

		ppm.push_back(tmp);

	}
}



void Projection::write(){
	std::ofstream ofs("data\\Texture2d.proj");

	using namespace std;
	ofs << proj_result.size() << " " << this->IMG_NUM << endl;
	
	foreach(projection proj,proj_result){
		foreach(Point::xy &it,proj.d2){
			if(it.x < 0.0 || it.x > IMGX || it.y < 0.0 || it.y > IMGY){
				ofs << "-3 "<< it.x << " " << it.y << " " ;
			}
			else{
				ofs << "0 " << it.x << " " << it.y << " ";
			}
		
		}
		ofs << endl;
	}
	cout << "written data" << endl;

}

void Projection::write_vis(){
	std::ofstream ofs("data\\Texture2d.proj");

	using namespace std;
	ofs << proj_result.size() << " " << this->IMG_NUM << endl;
	
	foreach(projection proj,proj_result){
		foreach(Point::xy &it,proj.d2){
			ofs << it.status << " " << it.x << " " << it.y << " ";
		}
		ofs << endl;
	}
	cout << "written data" << endl;

}

void Projection::read_noinit(){
	std::ifstream ifs("data\\Texture2d.proj");

	using namespace std;
	int proj_size;
	ifs >> proj_size >> this->IMG_NUM;

	for(int i = 0;i < proj_size;++i){
		projection tmp;
		for(int j = 0;j < IMG_NUM;++j){
			Point::xy p;
			ifs >> p.status >> p.x >> p.y;
			

			tmp.d2.push_back(p);
		}
		proj_result.push_back(tmp);
	}

}

void Projection::read(){
	std::ifstream ifs("data\\Texture2d.proj");

	using namespace std;
	int proj_size;
	ifs >> proj_size >> this->IMG_NUM;

	for(int i = 0;i < proj_size;++i){
		projection tmp;
		tmp.d3 = m_cmp->get_point(i);
		for(int j = 0;j < IMG_NUM;++j){
			Point::xy p;
			ifs >> p.status >> p.x >> p.y;
			

			tmp.d2.push_back(p);
		}
		proj_result.push_back(tmp);
	}

}

//=========================================================================
void thread_mutex::init(){
	index = 0;	
}
void Projection::run_thread(int num){

	while(true){

		int m_index;
		if(!thm.sync.try_lock())
			continue;
		//boost::mutex::scoped_lock lock(sync);

		if(thm.index >= m_cmp->vertex_size){
			thm.sync.unlock();
			using namespace std;
			cout << num << " " << "finish!" << endl; 
			break;
		}
		else{
			m_index = thm.index;
			thm.index++;
		}
		thm.sync.unlock();
		

		projection result;
		Point::xyz m_p3 = m_cmp->get_point(m_index);
		result.d3 = m_p3;
		for(int i = 0;i < IMG_NUM;++i){
			Point::xy tmp = compute_proj(m_p3,i);
			//tmp.x /= IMGX; tmp.y /= IMGY;
			result.d2.push_back(tmp);
		}


		//sync.lock();
		input_proj_result(result,m_index);
		using namespace std;
		cout << "computed 3d point : " << m_index << " by " << num << endl; 
		//sync.unlock();

	}

}

Point::xy Projection::compute_proj(Point::xyz p,int img){
	Point::xy result;

	Eigen::MatrixXd ans;
	Eigen::MatrixXd m_d3(4,1);
	

	m_d3 << p.x, p.y, p.z, 1;
	ans = ppm[img]*m_d3;
	ans = ans/ans(2,0);

	result.x = ans(0,0);
	result.y = ans(1,0);

	result.x += DIFX;
	result.y += DIFY;
	return result;
}