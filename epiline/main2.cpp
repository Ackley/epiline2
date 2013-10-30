#include <iostream>
#include <vector>
#include <string>
#include <opencv\\cv.h>
#include <opencv\\highgui.h>

//-------- �e��O���ϐ� -----------//
const std::string filename[2] = {"0.jpg","100.jpg"};
//const std::string filename[2] = {"left.png","right.png"};
//�`�F�X�{�[�h�̃R�[�i�[��
const CvSize CornerData = cvSize(9,6);//(x�~y) => (4�~3)


//----------- �v���g�^�C�v�錾 -----------------//
void CalcSubPix(IplImage *imgA,CvPoint2D32f *corners,int FindNum);
void DrawEpiLine(CvMat *points1,CvMat *points2, CvMat *F,int Finds,int From,IplImage *imgA,int Target = 0);



//---- �G�s�|�[������y���W���擾�֐� ---//
double GetYCoord(double x, double a,double b,double c)
{
	return -(a*x+c)/b;
}


//------------ �������烁�C���֐� -----------------//
int main(int argc, char **argv)
{

	std::vector<IplImage *> imgA(2);
	std::vector<CvPoint2D32f *> corners(2);
	std::vector<CvMat> ImgPoints(2);
	int Finds; //���o�_�̍��v


	for(int loop = 0; loop < 2;++loop){
		//�摜��ǂݍ���
		imgA[loop] = cvLoadImage(filename[loop].c_str(),CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
		if(imgA[loop] == NULL){
			std::cerr << filename[loop] << " Can't Load Image\n";
		}

		//���o�R�[�i�[�i�[�������m��
		corners[loop] = new CvPoint2D32f[CornerData.width*CornerData.height];
		
		//�R�[�i�[���o
		cvFindChessboardCorners(imgA[loop],CornerData,corners[loop],&Finds,CV_CALIB_CB_ADAPTIVE_THRESH);
		CalcSubPix(imgA[loop],corners[loop],Finds);	//�����x��
		
		//���o�_�̍s����쐬
		ImgPoints[loop] = cvMat(1,Finds,CV_32FC2,corners[loop]);
//		cvFlip(&ImgPoints[loop]);		//�㉺�̍��W���]
	}

	CvMat* status = cvCreateMat(1,12,CV_8UC1);
	//F�s��̎擾
	CvMat *Matrix_F = cvCreateMat(3,3,CV_64FC1);
	if(cvFindFundamentalMat(&ImgPoints[0], &ImgPoints[1], Matrix_F, CV_FM_RANSAC,1.00,0.99) == 0)
	{
		std::cerr << "Can't Get F Matrix\n";
		return -1;
	}
	
	//�u1�v���ڂ��g����2����(imgA[1])�ɕ`��B(3�Ԗڂ̑Ή��_�Ɋւ���)
	DrawEpiLine(&ImgPoints[0], &ImgPoints[1], Matrix_F,Finds,1,imgA[1],0);
	cvCircle(imgA[0],cvPoint(corners[0]->x,corners[0]->y),8,cvScalar(255,0,0,0),-1,8);
	cvCircle(imgA[1],cvPoint(corners[1]->x,corners[1]->y),8,cvScalar(255,0,0,0),-1,8);
	
	//�u2�v���ڂ��g����1����(imgA[0])�ɕ`��B(3�Ԗڂ̑Ή��_�Ɋւ���)
	//DrawEpiLine(&ImgPoints[0], &ImgPoints[1], Matrix_F,Finds,2,imgA[0],3);
	


	//�\���ƃ��������
	for(int loop = 0; loop < 2; ++loop)
	{
		cvNamedWindow(filename[loop].c_str(),CV_WINDOW_AUTOSIZE);
		cvShowImage(filename[loop].c_str(),imgA[loop]);

		delete [] corners[loop];
		cvReleaseImage( &imgA[loop] );
	}
	cvReleaseMat(&Matrix_F);
	

	cvWaitKey(0);
	cvDestroyAllWindows();

	return EXIT_SUCCESS;
}

//----------- ��������e��֐� ---------------//
void CalcSubPix(IplImage *imgA,CvPoint2D32f *corners,int FindNum)
{
	IplImage *gray = cvCreateImage (cvGetSize (imgA), IPL_DEPTH_8U, 1);

	cvCvtColor (imgA, gray, CV_BGR2GRAY);

	//�T�u�s�N�Z���v�Z
	cvFindCornerSubPix (gray, corners, FindNum, cvSize (3, 3), cvSize (-1, -1),
		cvTermCriteria (CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03));  //20��̔����A�ڕW���x�F0.03

	cvReleaseImage(&gray);
}



//�G�s�|�[�����̕`��
void DrawEpiLine(CvMat *points1,CvMat *points2, CvMat *F,int Finds,int From,IplImage *imgA,int Target)
{
	
	
	//�G�s�|�[�����̌v�Z
	CvMat *EpiLines = cvCreateMat(3,Finds,CV_64FC1);
	From == 1 ?
		cvComputeCorrespondEpilines(points1,From,F,EpiLines) :
		cvComputeCorrespondEpilines(points2,From,F,EpiLines) ;
	

	if(Target < Finds){
		//�G�s�|�[�����̕`��
		cvLine(imgA,
			cvPoint( //�n�_
			0,		// x
			cvRound(// y
			GetYCoord(0,CV_MAT_ELEM(*EpiLines,double,0,Target),
					CV_MAT_ELEM(*EpiLines,double,1,Target),CV_MAT_ELEM(*EpiLines,double,2,Target)))
			),
			cvPoint( //�I�_
			imgA->width,// x
			cvRound(	// y
			GetYCoord(imgA->width,CV_MAT_ELEM(*EpiLines,double,0,Target),
					CV_MAT_ELEM(*EpiLines,double,1,Target),CV_MAT_ELEM(*EpiLines,double,2,Target)))
			),
			CV_RGB(255,0,0),3);
	}
	

	cvReleaseMat(&EpiLines);
}