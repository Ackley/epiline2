#include "CMPMVS_DATA.h"

void CMPMVS::init(){
	std::ifstream ifs("data\\meshAvImgCol.ply");
	std::string dummy;

	while(1){
		ifs >> dummy;
		if(dummy == "vertex")
			ifs >> vertex_size;
		else if(dummy == "face")
			ifs >> face_size;
		if(dummy == "end_header")
			break;
	}

	for(int i = 0;i < vertex_size;++i){
		Point::xyz p;
		ifs >> p.x >> p.y >> p.z;
		//ifs >> dummy >> dummy >> dummy;
		vertex.push_back(p);
	}
	for(int i = 0;i < face_size;++i){
		SURFACE::triagnle t;
		ifs >> dummy >> t.no[0] >> t.no[1] >> t.no[2];
		face.push_back(t);
	}

}

std::vector<Point::xyz> CMPMVS::get_face_corr(int face_num){
	std::vector<int> p = get_face_index(face_num);

	std::vector<Point::xyz> result;
	for(int i = 0;i < 3;++i){
		Point::xyz tmp = get_point(p[i]);
		result.push_back(tmp);
	}
	return result;
}

std::vector<int> CMPMVS::get_face_index(int face_num){
	std::vector<int> result;

	int v1,v2,v3;
	v1 = face[face_num].no[0];
	v2 = face[face_num].no[1];
	v3 = face[face_num].no[2];

	result.push_back(v1);
	result.push_back(v2);
	result.push_back(v3);

	return result;
}

Point::xyz CMPMVS::get_point(int p_num){
	if(p_num >= vertex.size())
		exit(1);
	return vertex[p_num];
}