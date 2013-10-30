// -------------------------------------------------------------------
//                        ExImage Ver.0.1.4
//                    IplImage�̃��b�p�[�N���X
// -------------------------------------------------------------------
// 
// ExImage
// The MIT License
// Copyright (c) 2009 Sunao Hashimoto
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//
// ExImage
// MIT���C�Z���X
// Copyright (c) 2009 Sunao Hashimoto
//
// �ȉ��ɒ�߂�����ɏ]���A�{�\�t�g�E�F�A����ъ֘A�����̃t�@�C���i�ȉ��u�\�t�g
// �E�F�A�v�j�̕������擾���邷�ׂĂ̐l�ɑ΂��A�\�t�g�E�F�A�𖳐����Ɉ������Ƃ�
// �����ŋ����܂��B����ɂ́A�\�t�g�E�F�A�̕������g�p�A���ʁA�ύX�A�����A�f�ځA
// �Еz�A�T�u���C�Z���X�A�����/�܂��͔̔����錠���A����у\�t�g�E�F�A��񋟂���
// ����ɓ������Ƃ������錠�����������Ɋ܂܂�܂��B 
//
// ��L�̒��쌠�\������і{�����\�����A�\�t�g�E�F�A�̂��ׂĂ̕����܂��͏d�v�ȕ���
// �ɋL�ڂ�����̂Ƃ��܂��B 
// 
// �\�t�g�E�F�A�́u����̂܂܁v�ŁA�����ł��邩�Öقł��邩���킸�A����̕ۏ�
// ���Ȃ��񋟂���܂��B�����ł����ۏ؂Ƃ́A���i���A����̖ړI�ւ̓K�����A�����
// ������N�Q�ɂ��Ă̕ۏ؂��܂݂܂����A����Ɍ��肳�����̂ł͂���܂���B 
// ��҂܂��͒��쌠�҂́A�_��s�ׁA�s�@�s�ׁA�܂��͂���ȊO�ł��낤�ƁA�\�t�g
// �E�F�A�ɋN���܂��͊֘A���A���邢�̓\�t�g�E�F�A�̎g�p�܂��͂��̑��̈�����
// ����Đ������؂̐����A���Q�A���̑��̋`���ɂ��ĉ���̐ӔC������Ȃ�����
// �Ƃ��܂��B 
//
//
// �^���� EX_ + [�\�F�n] + [�f�v�X] �̑g�ݍ��킹�Œ�`�����D
// �\�F�n�Ń`�����l���������܂�C�f�v�X�ŏ��ʂ����܂�D
//
// ��FEX_GRAY8U�CEX_BGR8U�CEX_GRAY32F
//
// [�\�F�n] : �`�����l����
// GRAY  : 1�`�����l��
// BGR   : 3�`�����l���iB,G,R�j
// BGRA  : 4�`�����l���iB,G,R,A�j
// RGB   : 3�`�����l���iR,G,B�j
// RGBA  : 4�`�����l���iR,G,B,A�j
// XYZ   : 3�`�����l���iX,Y,Z�j
// YUV   : 3�`�����l���iY,U,V�j
// YCrCb : 3�`�����l���iY,Cr,Cb�j
// HSV   : 3�`�����l���iH,S,V�j
// HLS   : 3�`�����l���iH,L,S�j
// Lab   : 3�`�����l���iL,a,b�j
// Luv   : 3�`�����l���iL,u,v�j
//
// [�f�v�X] : �Ή�����^
// 8U  : unsigned char
// 8S  : char
// 16U : unsigned short
// 16S : short
// 32S : int
// 32F : float
// 64F : double


#ifndef __EX_IMAGE_H__
#define __EX_IMAGE_H__

#include <typeinfo>
#include <opencv\\cv.h>
#include <opencv\\cxcore.h>
#include <opencv\\highgui.h>


typedef IplImage* IplImagePointer;

//-----------------------------------------------------------------------------
// gray

typedef unsigned char	EX_GRAY8U;
typedef char			EX_GRAY8S;
typedef unsigned short	EX_GRAY16U;
typedef short			EX_GRAY16S;
typedef int				EX_GRAY32S;
typedef float			EX_GRAY32F;
typedef double			EX_GRAY64F;

//-----------------------------------------------------------------------------
// BGR

typedef struct tagEX_BGR8U {
	unsigned char B;
	unsigned char G;
	unsigned char R;
} EX_BGR8U;

typedef struct tagEX_BGR8S {
	char B;
	char G;
	char R;
} EX_BGR8S;

typedef struct tagEX_BGR16U {
	unsigned short B;
	unsigned short G;
	unsigned short R;
} EX_BGR16U;

typedef struct tagEX_BGR16S {
	short B;
	short G;
	short R;
} EX_BGR16S;

typedef struct tagEX_BGR32S {
	int B;
	int G;
	int R;
} EX_BGR32S;

typedef struct tagEX_BGR32F {
	float B;
	float G;
	float R;
} EX_BGR32F;

typedef struct tagEX_BGR64F {
	double B;
	double G;
	double R;
} EX_BGR64F;

//-----------------------------------------------------------------------------
// BGRA

typedef struct tagEX_BGRA8U {
	unsigned char B;
	unsigned char G;
	unsigned char R;
	unsigned char A;
} EX_BGRA8U;

typedef struct tagEX_BGRA8S {
	char B;
	char G;
	char R;
	char A;
} EX_BGRA8S;

typedef struct tagEX_BGRA16U {
	unsigned short B;
	unsigned short G;
	unsigned short R;
	unsigned short A;
} EX_BGRA16U;

typedef struct tagEX_BGRA16S {
	short B;
	short G;
	short R;
	short A;
} EX_BGRA16S;

typedef struct tagEX_BGRA32S {
	int B;
	int G;
	int R;
	int A;
} EX_BGRA32S;

typedef struct tagEX_BGRA32F {
	float B;
	float G;
	float R;
	float A;
} EX_BGRA32F;

typedef struct tagEX_BGRA64F {
	double B;
	double G;
	double R;
	double A;
} EX_BGRA64F;


//-----------------------------------------------------------------------------
// RGB

typedef struct tagEX_RGB8U {
	unsigned char R;
	unsigned char G;
	unsigned char B;
} EX_RGB8U;

typedef struct tagEX_RGB8S {
	char R;
	char G;
	char B;
} EX_RGB8S;

typedef struct tagEX_RGB16U {
	unsigned short R;
	unsigned short G;
	unsigned short B;
} EX_RGB16U;

typedef struct tagEX_RGB16S {
	short R;
	short G;
	short B;
} EX_RGB16S;

typedef struct tagEX_RGB32S {
	int R;
	int G;
	int B;
} EX_RGB32S;

typedef struct tagEX_RGB32F {
	float R;
	float G;
	float B;
} EX_RGB32F;

typedef struct tagEX_RGB64F {
	double R;
	double G;
	double B;
} EX_RGB64F;

//-----------------------------------------------------------------------------
// RGBA

typedef struct tagEX_RGBA8U {
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A;
} EX_RGBA8U;

typedef struct tagEX_RGBA8S {
	char R;
	char G;
	char B;
	char A;
} EX_RGBA8S;

typedef struct tagEX_RGBA16U {
	unsigned short R;
	unsigned short G;
	unsigned short B;
	unsigned short A;
} EX_RGBA16U;

typedef struct tagEX_RGBA16S {
	short R;
	short G;
	short B;
	short A;
} EX_RGBA16S;

typedef struct tagEX_RGBA32S {
	int R;
	int G;
	int B;
	int A;
} EX_RGBA32S;

typedef struct tagEX_RGBA32F {
	float R;
	float G;
	float B;
	float A;
} EX_RGBA32F;

typedef struct tagEX_RGBA64F {
	double R;
	double G;
	double B;
	double A;
} EX_RGBA64F;

//-----------------------------------------------------------------------------
// XYZ

typedef struct tagEX_XYZ8U {
	unsigned char X;
	unsigned char Y;
	unsigned char Z;
} EX_XYZ8U;

typedef struct tagEX_XYZ8S {
	char X;
	char Y;
	char Z;
} EX_XYZ8S;

typedef struct tagEX_XYZ16U {
	unsigned short X;
	unsigned short Y;
	unsigned short Z;
} EX_XYZ16U;

typedef struct tagEX_XYZ16S {
	short X;
	short Y;
	short Z;
} EX_XYZ16S;

typedef struct tagEX_XYZ32S {
	int X;
	int Y;
	int Z;
} EX_XYZ32S;

typedef struct tagEX_XYZ32F {
	float X;
	float Y;
	float Z;
} EX_XYZ32F;

typedef struct tagEX_XYZ64F {
	double X;
	double Y;
	double Z;
} EX_XYZ64F;

//-----------------------------------------------------------------------------
// YUV

typedef struct tagEX_YUV8U {
	unsigned char Y;
	unsigned char U;
	unsigned char V;
} EX_YUV8U;

typedef struct tagEX_YUV8S {
	char Y;
	char U;
	char V;
} EX_YUV8S;

typedef struct tagEX_YUV16U {
	unsigned short Y;
	unsigned short U;
	unsigned short V;
} EX_YUV16U;

typedef struct tagEX_YUV16S {
	short Y;
	short U;
	short V;
} EX_YUV16S;

typedef struct tagEX_YUV32S {
	int Y;
	int U;
	int V;
} EX_YUV32S;

typedef struct tagEX_YUV32F {
	float Y;
	float U;
	float V;
} EX_YUV32F;

typedef struct tagEX_YUV64F {
	double Y;
	double U;
	double V;
} EX_YUV64F;

//-----------------------------------------------------------------------------
// YCrCb

typedef struct tagEX_YCrCb8U {
	unsigned char Y;
	unsigned char Cr;
	unsigned char Cb;
} EX_YCrCb8U;

typedef struct tagEX_YCrCb8S {
	char Y;
	char Cr;
	char Cb;
} EX_YCrCb8S;

typedef struct tagEX_YCrCb16U {
	unsigned short Y;
	unsigned short Cr;
	unsigned short Cb;
} EX_YCrCb16U;

typedef struct tagEX_YCrCb16S {
	short Y;
	short Cr;
	short Cb;
} EX_YCrCb16S;

typedef struct tagEX_YCrCb32S {
	int Y;
	int Cr;
	int Cb;
} EX_YCrCb32S;

typedef struct tagEX_YCrCb32F {
	float Y;
	float Cr;
	float Cb;
} EX_YCrCb32F;

typedef struct tagEX_YCrCb64F {
	double Y;
	double Cr;
	double Cb;
} EX_YCrCb64F;

//-----------------------------------------------------------------------------
// HSV

typedef struct tagEX_HSV8U {
	unsigned char H;
	unsigned char S;
	unsigned char V;
} EX_HSV8U;

typedef struct tagEX_HSV8S {
	char H;
	char S;
	char V;
} EX_HSV8S;

typedef struct tagEX_HSV16U {
	unsigned short H;
	unsigned short S;
	unsigned short V;
} EX_HSV16U;

typedef struct tagEX_HSV16S {
	short H;
	short S;
	short V;
} EX_HSV16S;

typedef struct tagEX_HSV32S {
	int H;
	int S;
	int V;
} EX_HSV32S;

typedef struct tagEX_HSV32F {
	float H;
	float S;
	float V;
} EX_HSV32F;

typedef struct tagEX_HSV64F {
	double H;
	double S;
	double V;
} EX_HSV64F;

//-----------------------------------------------------------------------------
// HLS

typedef struct tagEX_HLS8U {
	unsigned char H;
	unsigned char L;
	unsigned char S;
} EX_HLS8U;

typedef struct tagEX_HLS8S {
	char H;
	char L;
	char S;
} EX_HLS8S;

typedef struct tagEX_HLS16U {
	unsigned short H;
	unsigned short L;
	unsigned short S;
} EX_HLS16U;

typedef struct tagEX_HLS16S {
	short H;
	short L;
	short S;
} EX_HLS16S;

typedef struct tagEX_HLS32S {
	int H;
	int L;
	int S;
} EX_HLS32S;

typedef struct tagEX_HLS32F {
	float H;
	float L;
	float S;
} EX_HLS32F;

typedef struct tagEX_HLS64F {
	double H;
	double L;
	double S;
} EX_HLS64F;

//-----------------------------------------------------------------------------
// Lab

typedef struct tagEX_Lab8U {
	unsigned char L;
	unsigned char a;
	unsigned char b;
} EX_Lab8U;

typedef struct tagEX_Lab8S {
	char L;
	char a;
	char b;
} EX_Lab8S;

typedef struct tagEX_Lab16U {
	unsigned short L;
	unsigned short a;
	unsigned short b;
} EX_Lab16U;

typedef struct tagEX_Lab16S {
	short L;
	short a;
	short b;
} EX_Lab16S;

typedef struct tagEX_Lab32S {
	int L;
	int a;
	int b;
} EX_Lab32S;

typedef struct tagEX_Lab32F {
	float L;
	float a;
	float b;
} EX_Lab32F;

typedef struct tagEX_Lab64F {
	double L;
	double a;
	double b;
} EX_Lab64F;

//-----------------------------------------------------------------------------
// Luv

typedef struct tagEX_Luv8U {
	unsigned char L;
	unsigned char u;
	unsigned char v;
} EX_Luv8U;

typedef struct tagEX_Luv8S {
	char L;
	char u;
	char v;
} EX_Luv8S;

typedef struct tagEX_Luv16U {
	unsigned short L;
	unsigned short u;
	unsigned short v;
} EX_Luv16U;

typedef struct tagEX_Luv16S {
	short L;
	short u;
	short v;
} EX_Luv16S;

typedef struct tagEX_Luv32S {
	int L;
	int u;
	int v;
} EX_Luv32S;

typedef struct tagEX_Luv32F {
	float L;
	float u;
	float v;
} EX_Luv32F;

typedef struct tagEX_Luv64F {
	double L;
	double u;
	double v;
} EX_Luv64F;


// �^��񂩂炢�낢��ȏ��𔲂��o�����߂̃N���X�e���v���[�g
template <typename type> class ExTypeCheck {

public:
	ExTypeCheck() {}
	~ExTypeCheck() {}

	// �O���C�X�P�[������
	static int IsGray(void) {
		if ( typeid(type) == typeid(EX_GRAY8U)  ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY16U) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY16S) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY32S) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY32F) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY64F) ) return TRUE;
		return FALSE;
	}

	// �`�����l����
	static int Channels(void) {
		if ( typeid(type) == typeid(EX_GRAY8U) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY8S) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY16U) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY16S) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY32S) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY32F) )	return 1;
		if ( typeid(type) == typeid(EX_GRAY64F) )	return 1;
		if ( typeid(type) == typeid(EX_BGRA8U) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA8S) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA16U) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA16S) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA32S) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA32F) )	return 4;
		if ( typeid(type) == typeid(EX_BGRA64F) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA8U) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA8S) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA16U) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA16S) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA32S) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA32F) )	return 4;
		if ( typeid(type) == typeid(EX_RGBA64F) )	return 4;
		return 3;
	}

	// �f�v�X
	static int Depth(void) {
		if ( typeid(type) == typeid(EX_GRAY8U) )   return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_GRAY8S) )   return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_GRAY16U) )  return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_GRAY16S) )  return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_GRAY32S) )  return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_GRAY32F) )  return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_GRAY64F) )  return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_BGR8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_BGR8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_BGR16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_BGR16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_BGR32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_BGR32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_BGR64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_BGRA8U) )   return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_BGRA8S) )   return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_BGRA16U) )  return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_BGRA16S) )  return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_BGRA32S) )  return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_BGRA32F) )  return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_BGRA64F) )  return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_RGB8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_RGB8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_RGB16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_RGB16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_RGB32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_RGB32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_RGB64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_RGBA8U) )   return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_RGBA8S) )   return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_RGBA16U) )  return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_RGBA16S) )  return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_RGBA32S) )  return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_RGBA32F) )  return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_RGBA64F) )  return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_XYZ8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_XYZ8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_XYZ16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_XYZ16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_XYZ32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_XYZ32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_XYZ64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_YUV8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_YUV8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_YUV16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_YUV16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_YUV32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_YUV32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_YUV64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_YCrCb8U) )  return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_YCrCb8S) )  return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_YCrCb16U) ) return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_YCrCb16S) ) return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_YCrCb32S) ) return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_YCrCb32F) ) return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_YCrCb64F) ) return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_HSV8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_HSV8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_HSV16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_HSV16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_HSV32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_HSV32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_HSV64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_HLS8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_HLS8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_HLS16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_HLS16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_HLS32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_HLS32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_HLS64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_Lab8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_Lab8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_Lab16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_Lab16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_Lab32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_Lab32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_Lab64F) )   return IPL_DEPTH_64F;
		if ( typeid(type) == typeid(EX_Luv8U) )    return IPL_DEPTH_8U;
		if ( typeid(type) == typeid(EX_Luv8S) )    return IPL_DEPTH_8S;
		if ( typeid(type) == typeid(EX_Luv16U) )   return IPL_DEPTH_16U;
		if ( typeid(type) == typeid(EX_Luv16S) )   return IPL_DEPTH_16S;
		if ( typeid(type) == typeid(EX_Luv32S) )   return IPL_DEPTH_32S;
		if ( typeid(type) == typeid(EX_Luv32F) )   return IPL_DEPTH_32F;
		if ( typeid(type) == typeid(EX_Luv64F) )   return IPL_DEPTH_64F;
		return IPL_DEPTH_8U;
	}

};


// ExImage�N���X�e���v���[�g
template <typename type> class ExImage {

private:
	IplImagePointer	m_img;	// ����IplImage
							// �i�K���R���X�g���N�^��NULL������邱�ƁI�j

public:

	// �R���X�g���N�^(1)
	ExImage(void) {
		m_img = NULL;
	}

	// �f�X�g���N�^
	~ExImage(void) {
		Release();
	}

	// �R���X�g���N�^(2) �摜�T�C�Y���w��
	ExImage <typename type> (int width, int height) {		
		m_img = NULL;
		Create(width, height);
	}

	// �R���X�g���N�^(3) �摜�t�@�C�����w��
	ExImage(const char *filename) {
		m_img = NULL;
		// cvLoadImage��CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR������Ă��܂��ƁC
		// �e���v���[�g�Ŏw�肵�Ă���^�Ƃ͈قȂ�^�ŉ摜������������鋰�ꂪ����̂�
		// CV_LOAD_IMAGE_GRAYSCALE �� CV_LOAD_IMAGE_COLOR ��2���ɂ��Ă����D
		if (ExTypeCheck<type>::IsGray()) {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
		} else {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_COLOR);
		}
	}

	// �R�s�[�R���X�g���N�^
	ExImage(const ExImage &obj) {
		m_img = NULL;
		m_img = cvCloneImage( obj.Ipl() );
	}

	// �R�s�[����iExImage = ExImage�j
	ExImage & operator = (const ExImage &obj) {
		if ( this != &obj ) {
			Release();
			m_img = cvCloneImage( obj.Ipl() );
		}
		return *this;
	}

	// �R�s�[����iExImage = IplImage*�j
	ExImage & operator = (const IplImage *obj) {
		if ( this->Ipl() != obj ) {
			Release();
			m_img = cvCloneImage(obj);
		}
		return *this;
	}

	// �摜�̉��
	void Release(void) {
		cvReleaseImage(&m_img);
		m_img = NULL;	// �K�{
	}

	// �摜�̍쐬
	void Create(int width, int height) {
		Release();
		ExTypeCheck<type> tc;
		m_img = cvCreateImage( cvSize(width,height), tc.Depth(), tc.Channels() );
	}

	// �摜�̓ǂݍ���
	// GRAY*�̏ꍇ�͎����I�ɃO���C�X�P�[���ǂݍ��݂���
	void Load(const char *format, ... ) {

		char filename[256];
		va_list ap;
		va_start(ap, format);
		#if _MSC_VER < 1400
		// VC8.0���O�̏ꍇ
			vsprintf(filename, format, ap);
		#else
			vsprintf_s(filename, format, ap);
		#endif
		va_end(ap);

		// cvLoadImage��CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR������Ă��܂��ƁC
		// �e���v���[�g�Ŏw�肵�Ă���^�Ƃ͈قȂ�^�ŉ摜������������鋰�ꂪ����̂�
		// CV_LOAD_IMAGE_GRAYSCALE �� CV_LOAD_IMAGE_COLOR ��2���ɂ��Ă����D

		Release();
		if ( ExTypeCheck<type>::IsGray()) {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
		} else {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_COLOR);
		}
	}

	// �摜�̕ۑ�
	void Save(const char *format, ... ) {
		char filename[256];
		va_list ap;
		va_start(ap, format);
		#if _MSC_VER < 1400
		// VC8.0���O�̏ꍇ
			vsprintf(filename, format, ap);
		#else
			vsprintf_s(filename, format, ap);
		#endif
		va_end(ap);
		cvSaveImage(filename, m_img);
	}

	// ��f�A�N�Z�X�i[y][x]�̏��ŋL�q�j
	type * operator [] (int y) {
		return (type*)&(m_img->imageData[y * m_img->widthStep]);
	}

	// ��f�A�N�Z�X�i[y][x]�̏��ŋL�q�j
	const type * operator [] (int y) const {
		return (type*)&(m_img->imageData[y * m_img->widthStep]);
	}

	// ��f�A�N�Z�X
	type & operator () (int y, int x) {
		return (type&)(m_img->imageData[y * m_img->widthStep + x * m_img->nChannels]);
	}

	// ��f�A�N�Z�X
	const type & operator () (int y, int x) const {
		return (type&)(m_img->imageData[y * m_img->widthStep + x * m_img->nChannels]);
	}

	// ����IplImage�ւ̎Q��
	IplImagePointer & Ipl(void) {
		return m_img;
	}

	// ����IplImage�ւ̎Q��
	const IplImagePointer & Ipl(void) const {
		return m_img;
	}

	// �摜�f�[�^�ւ̃|�C���^
	type * ImageData(void) {
		return (type*)(m_img->imageData);
	}

	// �摜�f�[�^�ւ̃|�C���^
	const type * ImageData(void) const {
		return (type*)(m_img->imageData);
	}

	// �摜�̉���
	int Width(void) const {
		return m_img->width;
	}

	// �摜�̍���
	int Height(void) const {
		return m_img->height;
	}

	// �摜�̃`�����l����
	int Channels(void) const {
		return m_img->nChannels;
	}

	// �摜�̃f�v�X
	int Depth(void) const {
		return m_img->depth;
	}

	// ���_�ʒu
	int Origin(void) const {
		return m_img->origin;
	}

	// ���㌴�_�ł���
	int IsOriginTopLeft(void) const {
		return ( m_img->origin == IPL_ORIGIN_TL );
	}

	// �A�N�Z�X�\��f�ł���
	int IsSafePixel(int y, int x) const {
		return ( y>=0 && x>=0 && y<Height() && x<Width() );
	}

	// �摜�T�C�Y
	int ImageSize(void) const {
		return m_img->imageSize;
	}

	// �N���A�i���ׂẲ�f�l���[���ɂ���j
	void Clear(void) {
		memset( ImageData(), 0, ImageSize() );
	}

};

#endif