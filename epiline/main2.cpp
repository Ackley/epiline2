#include <iostream>
#include <vector>
#include <string>
#include <opencv\\cv.h>
#include <opencv\\highgui.h>

//-------- 各種外部変数 -----------//
const std::string filename[2] = {"0.jpg","100.jpg"};
//const std::string filename[2] = {"left.png","right.png"};
//チェスボードのコーナー数
const CvSize CornerData = cvSize(9,6);//(x×y) => (4×3)


//----------- プロトタイプ宣言 -----------------//
void CalcSubPix(IplImage *imgA,CvPoint2D32f *corners,int FindNum);
void DrawEpiLine(CvMat *points1,CvMat *points2, CvMat *F,int Finds,int From,IplImage *imgA,int Target = 0);



//---- エピポーラ線のy座標を取得関数 ---//
double GetYCoord(double x, double a,double b,double c)
{
	return -(a*x+c)/b;
}


//------------ ここからメイン関数 -----------------//
int main(int argc, char **argv)
{

	std::vector<IplImage *> imgA(2);
	std::vector<CvPoint2D32f *> corners(2);
	std::vector<CvMat> ImgPoints(2);
	int Finds; //検出点の合計


	for(int loop = 0; loop < 2;++loop){
		//画像を読み込む
		imgA[loop] = cvLoadImage(filename[loop].c_str(),CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
		if(imgA[loop] == NULL){
			std::cerr << filename[loop] << " Can't Load Image\n";
		}

		//検出コーナー格納メモリ確保
		corners[loop] = new CvPoint2D32f[CornerData.width*CornerData.height];
		
		//コーナー検出
		cvFindChessboardCorners(imgA[loop],CornerData,corners[loop],&Finds,CV_CALIB_CB_ADAPTIVE_THRESH);
		CalcSubPix(imgA[loop],corners[loop],Finds);	//高精度化
		
		//検出点の行列を作成
		ImgPoints[loop] = cvMat(1,Finds,CV_32FC2,corners[loop]);
//		cvFlip(&ImgPoints[loop]);		//上下の座標反転
	}

	CvMat* status = cvCreateMat(1,12,CV_8UC1);
	//F行列の取得
	CvMat *Matrix_F = cvCreateMat(3,3,CV_64FC1);
	if(cvFindFundamentalMat(&ImgPoints[0], &ImgPoints[1], Matrix_F, CV_FM_RANSAC,1.00,0.99) == 0)
	{
		std::cerr << "Can't Get F Matrix\n";
		return -1;
	}
	
	//「1」枚目を使って2枚目(imgA[1])に描画。(3番目の対応点に関して)
	DrawEpiLine(&ImgPoints[0], &ImgPoints[1], Matrix_F,Finds,1,imgA[1],0);
	cvCircle(imgA[0],cvPoint(corners[0]->x,corners[0]->y),8,cvScalar(255,0,0,0),-1,8);
	cvCircle(imgA[1],cvPoint(corners[1]->x,corners[1]->y),8,cvScalar(255,0,0,0),-1,8);
	
	//「2」枚目を使って1枚目(imgA[0])に描画。(3番目の対応点に関して)
	//DrawEpiLine(&ImgPoints[0], &ImgPoints[1], Matrix_F,Finds,2,imgA[0],3);
	


	//表示とメモリ解放
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

//----------- ここから各種関数 ---------------//
void CalcSubPix(IplImage *imgA,CvPoint2D32f *corners,int FindNum)
{
	IplImage *gray = cvCreateImage (cvGetSize (imgA), IPL_DEPTH_8U, 1);

	cvCvtColor (imgA, gray, CV_BGR2GRAY);

	//サブピクセル計算
	cvFindCornerSubPix (gray, corners, FindNum, cvSize (3, 3), cvSize (-1, -1),
		cvTermCriteria (CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03));  //20回の反復、目標精度：0.03

	cvReleaseImage(&gray);
}



//エピポーラ線の描画
void DrawEpiLine(CvMat *points1,CvMat *points2, CvMat *F,int Finds,int From,IplImage *imgA,int Target)
{
	
	
	//エピポーラ線の計算
	CvMat *EpiLines = cvCreateMat(3,Finds,CV_64FC1);
	From == 1 ?
		cvComputeCorrespondEpilines(points1,From,F,EpiLines) :
		cvComputeCorrespondEpilines(points2,From,F,EpiLines) ;
	

	if(Target < Finds){
		//エピポーラ線の描画
		cvLine(imgA,
			cvPoint( //始点
			0,		// x
			cvRound(// y
			GetYCoord(0,CV_MAT_ELEM(*EpiLines,double,0,Target),
					CV_MAT_ELEM(*EpiLines,double,1,Target),CV_MAT_ELEM(*EpiLines,double,2,Target)))
			),
			cvPoint( //終点
			imgA->width,// x
			cvRound(	// y
			GetYCoord(imgA->width,CV_MAT_ELEM(*EpiLines,double,0,Target),
					CV_MAT_ELEM(*EpiLines,double,1,Target),CV_MAT_ELEM(*EpiLines,double,2,Target)))
			),
			CV_RGB(255,0,0),3);
	}
	

	cvReleaseMat(&EpiLines);
}