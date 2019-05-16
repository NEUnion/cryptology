// ZMD5Ex.h: interface for the ZMD5Ex class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ZMD5EX_H__6B046932_5C89_4A9D_B949_6205E2D057AE__INCLUDED_)
#define AFX_ZMD5EX_H__6B046932_5C89_4A9D_B949_6205E2D057AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ZMD5.h"

class ZMD5Ex : public ZMD5
{
public:
	ZMD5Ex();
	virtual ~ZMD5Ex();
public:

	/*
	因为此类继承自ZMD5类,所以必须实现这个纯虚函数
	参数:
	    ProcessNum 此参数由父类传进来,这个值在1~100
		之间,表明在进行文件MD5计算时,的计算进度
	*/
	void OnProcessing(int ProcessNum);

private:

	//保存这个窗口句柄是为了向窗口发送用户自定义消息USER_PROCESSING
	HWND m_hWnd; // 用于保存窗口的句柄

public:

	//窗口类通过调用这个函数将句柄传入这个类中
	void SetHwnd(HWND hwnd);
};

#endif // !defined(AFX_ZMD5EX_H__6B046932_5C89_4A9D_B949_6205E2D057AE__INCLUDED_)
