/*-======================- Copyright (c) 2006 -======================-

��������:
    ��³��(zhangluduo) : Ϊ���а��ҵ��˺��Ұ�����Ŭ��!

��ϵ��ʽ:
    oopfans@msn.com
	[oopfans]Ⱥ:34064264

�޸�ʱ��:
    2007-01-07

��������:
    ����Win32API����ϵͳ���öԻ���(�ļ���,����,Ŀ¼ѡ��..)

��Ȩ����:
    ����κε�λ,��������ʹ��,����,�޸�,ɢ����������ݴ���,���Ǳ��뱣
    ���˰�Ȩ��Ϣ,��ο���������ڵ��Ͷ�,�������˴������Դ,�����˷ݴ���
    ���κ�BUG,��֪ͨ����,�Ա��ֲ���������ˮƽ���޶����µ�һЩ����Ͳ�
    ��,лл!

-======================- Copyright (c) 2006 -======================-*/

#ifndef _ZFILEDIALOG
#define _ZFILEDIALOG

#pragma warning(disable:4786) 
#include <string>
#include <deque>
#include <functional>
#include <algorithm>
using namespace std;

class ZFileDialog  
{
public:
	ZFileDialog();
	virtual ~ZFileDialog();
public:
	//ѡ��Ŀ¼
	string GetSelectDirectory(const char* szTitle="Please select directory");

	/*********************************************************
	ѡ���ļ�(��ѡ���ѡ)
	ultiSelect�ļ��Ƿ���Զ�ѡ
	Filter�ļ����͹���
	��  ע:��:Filter=="�����ļ� (*.*)\0*.*\0�ı��ļ� (*.txt)\0*.txt\0\0";
	ʾ��:
	ZFileDialog fileDlg;
	deque<string> FileNames;
	FileNames=fileDlg.GetOpenFileName(true,"�����ļ� (*.*)\0*.*\0�ı��ļ� (*.txt)\0*.txt\0\0");
	for(int j=0;j<FileNames.size();j++)
	AfxMessageBox(((string)FileNames.at(j)).c_str());
	*********************************************************/
	deque<string> GetOpenFileName(bool MultiSelect,const char* szFilter);

	/*********************************************************
	��ȡ�û�������ļ���
	AutoAddSuffixName�Ƿ��Զ���ӱ�����ļ���׺��(�����ļ���Ĺ������������)
	Filter�ļ����͹���
	��  ע:��:Filter=="�����ļ� (*.*)\0*.*\0�ı��ļ� (*.txt)\0*.txt\0\0";
	*********************************************************/
	string GetSaveFileName(bool AutoAddSuffixName,const char* szFilter);
};

#endif
