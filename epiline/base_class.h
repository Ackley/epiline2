#pragma once

#include <vector>
#include <fstream>
#include <set>
#include <iostream>

namespace Point{
	class xy{
	public:
		float x,y;
		int status;
		bool operator != (const xy& p)const{
			if(x == p.x && y == p.y)
				return false;
			else
				return true;
		}

		bool operator<(const xy& v) const{
			if(x < v.x)
				return true;
			else if(x == v.x){
				if(y < v.y){
					return true;
				}
				return false;
			}
			return false;
		}
	};
	class xyz{
	public:

		xyz(float n1,float n2,float n3){
			x = n1;
			y = n2;
			z = n3;
		}
		

		xyz(){
			x = 0; y = 0; z = 0;
		};

		float x,y,z;
		bool operator != (const xyz& p)const{
			if(x == p.x && y == p.y && z == p.z)
				return false;
			else
				return true;
		}

		bool operator == (const xyz& p)const{
			if(x == p.x && y == p.y && z == p.z)
				return true;
			else
				return false;
		}
		bool operator < (const xyz& v)const{
			return
				x != v.x ? x < v.x : 
				y != v.y ? y < v.y :
				z < v.z;
		}

		float operator - (const xyz& p)const{
			float ans = (fabs(x)-fabs(p.x)) + (fabs(y)-fabs(p.y)) + (fabs(z)-fabs(p.z));
			return ans/3;
		}

	};

}

namespace SURFACE{
	class triagnle{
	public:
		int no[3];
	};

	class f_triangle{
	public:
		Point::xyz p[3];

		f_triangle(Point::xyz p1, Point::xyz p2, Point::xyz p3){
			this->p[0] = p1; this->p[1] = p2; this->p[2] = p3;
		}
		f_triangle();
	};
}

class camera_angle{
public:
	int camera;
	float angle;


	camera_angle(){}
	camera_angle(int cam,float ang){
		camera = cam;
		angle = ang;
	}
	bool operator<(const camera_angle& v) const{
		return 
			//orz
			angle > v.angle ? true : false;
	}
};