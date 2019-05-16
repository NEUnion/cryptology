#if !defined(AFX_RSAA_H__081D9EE0_1245_11D5_80AC_0000E8810675__INCLUDED_)
#define AFX_RSAA_H__081D9EE0_1245_11D5_80AC_0000E8810675__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 
// _MSC_VER > 1000
// RsaA.h : header file
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

const DATALENGTH=350;   //�������͵ĳ���
const MLENGTH=10;       //�����ĳ���
const TESTNUM=30;       //��������ʱ�ıȽϵĴ���
const SKLENGTH=4;       //˽Կ�ĳ���

typedef signed char byteint[DATALENGTH];   //�����������
typedef signed char mtype[MLENGTH];        //���������Ĵ�������


//extern "C" __declspec(dllexport) void RsaAGenKeys(CString& pk,CString& sk,CString& R); //�ṩ��������ʹ�õ���Կ��������
//extern "C" __declspec(dllexport) int RsaAEncrypt(CString& source,const char* key,const char* R,CStringArray& result);//����
//extern "C" __declspec(dllexport) CString RsaADecrypt(CStringArray& source,const char* sk,const char* R);//����

/////////////////////////////////////////////////////////////////////////////
// CRsaA command target
//ʵ��RSA�㷨����
class CRsaA : public CCmdTarget
{
	DECLARE_DYNCREATE(CRsaA)

	CRsaA();    // protected constructor used by dynamic creation

// ��Ա����
private:
	void InitInt(void);                      //�������ݳ����ĳ�ʼ��
	int IntValid(byteint validtemp);         //���ش���validtemp�ķ���λ�ĸ���
	int IntCmp(byteint A,byteint B);         //�Ƚϴ���A��B�Ƿ����
	//�Զ������͵Ļ�������
	void Plus(byteint A,byteint B,byteint C);             //C=A+B
	void Substract(byteint SA,byteint SB,byteint SC);     //SC=SA-SB
	void Multiply(byteint A,byteint B,byteint C);         //C=A*B
	void SetMode(byteint A,byteint B,byteint C,byteint D);//C=A%B
	int PowerMode(byteint A,byteint C,byteint D,signed char flag[400]);//computing A^B mod C-->D
	
	void IntRandom(byteint RandomA,int num);                //�������һ������
	void LoadInt(byteint A,mtype B);                        //����������ת��Ϊ��������
	void TransBi(byteint B,signed char flag[400]);          //������Bת��Ϊ��������ʽ
	void Mdata();                                           //�����������������н��бȽϵ���
	int Prime(byteint Prm);                                 //����һ������ΪMLENGTH������
	int ComputingPK(byteint Rvalue,byteint SK,byteint PK);  //���㹫ԿPK
	void ComputingR(byteint p,byteint q,byteint R);         //����ģֵR
	void ComputingRvalue(byteint p,byteint q,byteint Rvalue); //����$(r)
	void IntCpy(byteint A1,byteint B1);      //������B1��ֵ����������A1��
	void SetZero(byteint A);                 //������A����
	CString PrtInt(byteint A);               //��һ����������ת��Ϊһ��CString����
	int Getinput(byteint result,CString input);             //���ַ���ת��Ϊ��Ӧ�Ĵ�����ʽ
	int Getinput1(byteint result,unsigned long input);               //����������ת��Ϊ��Ӧ�Ĵ�����ʽ
	void RsaDo(byteint source,byteint R,byteint key,byteint desti); //ʵ�ּӽ���
	unsigned long Os2ip(unsigned char* pstr);
	CString Ip2os(CString str);
	
public:
	void GenKeys(CString& pk,CString& sk,CString& R); //�ṩ��������ʹ�õ���Կ��������
	int RsaEncrypt(CString& source,const char* key,const char* R,CStringArray& result);//����
	CString RsaDecrypt(CStringArray& source,const char* sk,const char* R);//����
	void GenKeysTable();             //������Կ���ļ�
	void LoadKeysFromFile(CString& r,CString& sk,CString& pk);

//��Ա����	
private:
	byteint ONEVALUE;
	byteint ZEROVALUE;
	byteint TWOVALUE;
	byteint EIGHTVALUE; //O,1,2,8 constant
	
	mtype Model[TESTNUM];  //TESTNUM big number to be compared
	mtype mZEROVALUE,tempModel;  //0 constant
	
	signed char flag[400];
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRsaA)
	//}}AFX_VIRTUAL

// Implementation
//protected:
	virtual ~CRsaA();

	// Generated message map functions
	//{{AFX_MSG(CRsaA)
//	afx_msg LONG OnComputing(WPARAM wParam, LPARAM lParam);
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RSAA_H__081D9EE0_1245_11D5_80AC_0000E8810675__INCLUDED_)