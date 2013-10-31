#include <iostream>
#include <vector>
#include "ExImage.h"
#include "projection.h"
#include "opencv\highgui.h"
#include "bundler_parser.h"
#include "Cameras.h"



int main(){
	Camera cam;

	cam.init("G:\\epiline2\\epiline\\data");
	cam.find_corner();


	

	
}

