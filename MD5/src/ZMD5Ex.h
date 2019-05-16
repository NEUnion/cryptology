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
	��Ϊ����̳���ZMD5��,���Ա���ʵ��������麯��
	����:
	    ProcessNum �˲����ɸ��ഫ����,���ֵ��1~100
		֮��,�����ڽ����ļ�MD5����ʱ,�ļ������
	*/
	void OnProcessing(int ProcessNum);

private:

	//����������ھ����Ϊ���򴰿ڷ����û��Զ�����ϢUSER_PROCESSING
	HWND m_hWnd; // ���ڱ��洰�ڵľ��

public:

	//������ͨ�����������������������������
	void SetHwnd(HWND hwnd);
};

#endif // !defined(AFX_ZMD5EX_H__6B046932_5C89_4A9D_B949_6205E2D057AE__INCLUDED_)
