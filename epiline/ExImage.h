// -------------------------------------------------------------------
//                        ExImage Ver.0.1.4
//                    IplImageのラッパークラス
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
// MITライセンス
// Copyright (c) 2009 Sunao Hashimoto
//
// 以下に定める条件に従い、本ソフトウェアおよび関連文書のファイル（以下「ソフト
// ウェア」）の複製を取得するすべての人に対し、ソフトウェアを無制限に扱うことを
// 無償で許可します。これには、ソフトウェアの複製を使用、複写、変更、結合、掲載、
// 頒布、サブライセンス、および/または販売する権利、およびソフトウェアを提供する
// 相手に同じことを許可する権利も無制限に含まれます。 
//
// 上記の著作権表示および本許諾表示を、ソフトウェアのすべての複製または重要な部分
// に記載するものとします。 
// 
// ソフトウェアは「現状のまま」で、明示であるか暗黙であるかを問わず、何らの保証
// もなく提供されます。ここでいう保証とは、商品性、特定の目的への適合性、および
// 権利非侵害についての保証も含みますが、それに限定されるものではありません。 
// 作者または著作権者は、契約行為、不法行為、またはそれ以外であろうと、ソフト
// ウェアに起因または関連し、あるいはソフトウェアの使用またはその他の扱いに
// よって生じる一切の請求、損害、その他の義務について何らの責任も負わないもの
// とします。 
//
//
// 型名は EX_ + [表色系] + [デプス] の組み合わせで定義される．
// 表色系でチャンネル数が決まり，デプスで情報量が決まる．
//
// 例：EX_GRAY8U，EX_BGR8U，EX_GRAY32F
//
// [表色系] : チャンネル数
// GRAY  : 1チャンネル
// BGR   : 3チャンネル（B,G,R）
// BGRA  : 4チャンネル（B,G,R,A）
// RGB   : 3チャンネル（R,G,B）
// RGBA  : 4チャンネル（R,G,B,A）
// XYZ   : 3チャンネル（X,Y,Z）
// YUV   : 3チャンネル（Y,U,V）
// YCrCb : 3チャンネル（Y,Cr,Cb）
// HSV   : 3チャンネル（H,S,V）
// HLS   : 3チャンネル（H,L,S）
// Lab   : 3チャンネル（L,a,b）
// Luv   : 3チャンネル（L,u,v）
//
// [デプス] : 対応する型
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


// 型情報からいろいろな情報を抜き出すためのクラステンプレート
template <typename type> class ExTypeCheck {

public:
	ExTypeCheck() {}
	~ExTypeCheck() {}

	// グレイスケール判定
	static int IsGray(void) {
		if ( typeid(type) == typeid(EX_GRAY8U)  ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY16U) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY16S) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY32S) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY32F) ) return TRUE;
		if ( typeid(type) == typeid(EX_GRAY64F) ) return TRUE;
		return FALSE;
	}

	// チャンネル数
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

	// デプス
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


// ExImageクラステンプレート
template <typename type> class ExImage {

private:
	IplImagePointer	m_img;	// 内部IplImage
							// （必ずコンストラクタでNULL代入すること！）

public:

	// コンストラクタ(1)
	ExImage(void) {
		m_img = NULL;
	}

	// デストラクタ
	~ExImage(void) {
		Release();
	}

	// コンストラクタ(2) 画像サイズを指定
	ExImage <typename type> (int width, int height) {		
		m_img = NULL;
		Create(width, height);
	}

	// コンストラクタ(3) 画像ファイルを指定
	ExImage(const char *filename) {
		m_img = NULL;
		// cvLoadImageでCV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLORをやってしまうと，
		// テンプレートで指定している型とは異なる型で画像が初期化される恐れがあるので
		// CV_LOAD_IMAGE_GRAYSCALE か CV_LOAD_IMAGE_COLOR の2択にしておく．
		if (ExTypeCheck<type>::IsGray()) {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
		} else {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_COLOR);
		}
	}

	// コピーコンストラクタ
	ExImage(const ExImage &obj) {
		m_img = NULL;
		m_img = cvCloneImage( obj.Ipl() );
	}

	// コピー代入（ExImage = ExImage）
	ExImage & operator = (const ExImage &obj) {
		if ( this != &obj ) {
			Release();
			m_img = cvCloneImage( obj.Ipl() );
		}
		return *this;
	}

	// コピー代入（ExImage = IplImage*）
	ExImage & operator = (const IplImage *obj) {
		if ( this->Ipl() != obj ) {
			Release();
			m_img = cvCloneImage(obj);
		}
		return *this;
	}

	// 画像の解放
	void Release(void) {
		cvReleaseImage(&m_img);
		m_img = NULL;	// 必須
	}

	// 画像の作成
	void Create(int width, int height) {
		Release();
		ExTypeCheck<type> tc;
		m_img = cvCreateImage( cvSize(width,height), tc.Depth(), tc.Channels() );
	}

	// 画像の読み込み
	// GRAY*の場合は自動的にグレイスケール読み込みする
	void Load(const char *format, ... ) {

		char filename[256];
		va_list ap;
		va_start(ap, format);
		#if _MSC_VER < 1400
		// VC8.0より前の場合
			vsprintf(filename, format, ap);
		#else
			vsprintf_s(filename, format, ap);
		#endif
		va_end(ap);

		// cvLoadImageでCV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLORをやってしまうと，
		// テンプレートで指定している型とは異なる型で画像が初期化される恐れがあるので
		// CV_LOAD_IMAGE_GRAYSCALE か CV_LOAD_IMAGE_COLOR の2択にしておく．

		Release();
		if ( ExTypeCheck<type>::IsGray()) {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_GRAYSCALE);
		} else {
			m_img = cvLoadImage(filename,CV_LOAD_IMAGE_COLOR);
		}
	}

	// 画像の保存
	void Save(const char *format, ... ) {
		char filename[256];
		va_list ap;
		va_start(ap, format);
		#if _MSC_VER < 1400
		// VC8.0より前の場合
			vsprintf(filename, format, ap);
		#else
			vsprintf_s(filename, format, ap);
		#endif
		va_end(ap);
		cvSaveImage(filename, m_img);
	}

	// 画素アクセス（[y][x]の順で記述）
	type * operator [] (int y) {
		return (type*)&(m_img->imageData[y * m_img->widthStep]);
	}

	// 画素アクセス（[y][x]の順で記述）
	const type * operator [] (int y) const {
		return (type*)&(m_img->imageData[y * m_img->widthStep]);
	}

	// 画素アクセス
	type & operator () (int y, int x) {
		return (type&)(m_img->imageData[y * m_img->widthStep + x * m_img->nChannels]);
	}

	// 画素アクセス
	const type & operator () (int y, int x) const {
		return (type&)(m_img->imageData[y * m_img->widthStep + x * m_img->nChannels]);
	}

	// 内部IplImageへの参照
	IplImagePointer & Ipl(void) {
		return m_img;
	}

	// 内部IplImageへの参照
	const IplImagePointer & Ipl(void) const {
		return m_img;
	}

	// 画像データへのポインタ
	type * ImageData(void) {
		return (type*)(m_img->imageData);
	}

	// 画像データへのポインタ
	const type * ImageData(void) const {
		return (type*)(m_img->imageData);
	}

	// 画像の横幅
	int Width(void) const {
		return m_img->width;
	}

	// 画像の高さ
	int Height(void) const {
		return m_img->height;
	}

	// 画像のチャンネル数
	int Channels(void) const {
		return m_img->nChannels;
	}

	// 画像のデプス
	int Depth(void) const {
		return m_img->depth;
	}

	// 原点位置
	int Origin(void) const {
		return m_img->origin;
	}

	// 左上原点である
	int IsOriginTopLeft(void) const {
		return ( m_img->origin == IPL_ORIGIN_TL );
	}

	// アクセス可能画素である
	int IsSafePixel(int y, int x) const {
		return ( y>=0 && x>=0 && y<Height() && x<Width() );
	}

	// 画像サイズ
	int ImageSize(void) const {
		return m_img->imageSize;
	}

	// クリア（すべての画素値をゼロにする）
	void Clear(void) {
		memset( ImageData(), 0, ImageSize() );
	}

};

#endif