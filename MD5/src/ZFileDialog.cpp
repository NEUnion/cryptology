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

#include "stdafx.h"
#include "ZFileDialog.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ZFileDialog::ZFileDialog()
{

}

ZFileDialog::~ZFileDialog()
{

}

//////////////////////////////////////////////////////////////////////
// options
//////////////////////////////////////////////////////////////////////

string ZFileDialog::GetSelectDirectory(const char* szTitle)
{
	string ReturnValue;
	char Path[256];
	memset(Path,0,256);
	BROWSEINFO browseinfo;   
	LPCITEMIDLIST lpcitemidlist;
	browseinfo.hwndOwner=0;   
	browseinfo.pszDisplayName=Path;   
	browseinfo.pidlRoot=NULL;   
	browseinfo.ulFlags=BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS;   
	browseinfo.lpfn=NULL;   
	browseinfo.lpszTitle=szTitle;   
	browseinfo.iImage=0;   
	lpcitemidlist=SHBrowseForFolder(&browseinfo);   
	if(lpcitemidlist)
	{
		if(SHGetPathFromIDList(lpcitemidlist,Path))
			ReturnValue=Path;
	}
	return ReturnValue;
	/*
	ZFileDialog dlg;
	string str=dlg.SelectDirectory("������ѡ��ɶĿ¼");
	AfxMessageBox(str.c_str());
	*/
}

deque<string> ZFileDialog::GetOpenFileName(bool MultiSelect,const char* szFilter)
{
	deque<string> dqFileNames;

	char file[256];
	memset(file,0,256);
	OPENFILENAME openfilename; 
	memset(&openfilename,0,sizeof(openfilename));   
	openfilename.lStructSize = sizeof(openfilename);   
	openfilename.hInstance =0;
	openfilename.lpstrFilter=szFilter;
	openfilename.lpstrFile=file;
	openfilename.nMaxFile=256;
	openfilename.Flags=OFN_EXPLORER | OFN_HIDEREADONLY;
	openfilename.Flags|=MultiSelect ? OFN_ALLOWMULTISELECT:0;

	if(::GetOpenFileName(&openfilename))
	{
		char* ptr=openfilename.lpstrFile;
		int Count=0;
		bool IsMulti=false;
		while(*ptr++)
		{
			if(++Count>=2)
			{
				IsMulti=true;
				break;
			}
			while(*ptr++);
		}
		if(IsMulti)
		{
			ptr=openfilename.lpstrFile;
			int nFiles=0;
			string strTmp="";
			while(*ptr++)
			{
				nFiles++;
				if(nFiles==1)
				{
					strTmp=ptr-1;
					if(strTmp[strTmp.size()-1]!='\\')
					{
						strTmp+="\\";
					}
				}
				else if(nFiles>=2)
				{
					dqFileNames.push_back(strTmp+(ptr-1));
				}
				while(*ptr++);
			}
		}
		else
		{
			dqFileNames.push_back((char*)(LPTSTR)openfilename.lpstrFile);
		}
	}
	return dqFileNames;
}

string ZFileDialog::GetSaveFileName(bool AutoAddSuffixName,const char* szFilter)
{
	string strFileName="";

	char file[256];
	memset(file,0,256);
	OPENFILENAME openfilename;
	memset(&openfilename,0,sizeof(openfilename));
	openfilename.lStructSize=sizeof(OPENFILENAME);
	openfilename.hInstance =0;
	openfilename.lpstrFile=file;
	openfilename.nMaxFile=256;
	openfilename.lpstrFilter=szFilter;
	openfilename.Flags=OFN_EXPLORER;

	if(!::GetSaveFileName(&openfilename)) return strFileName;
	
	strFileName=file;
	if(!AutoAddSuffixName) return strFileName;

	//�ж��û���д���ļ����Ƿ��к�׺
	bool IsHaveSuffix=strFileName.find_last_of(".")==-1?false:true;

	//��const char* Filter���������
	deque<string> FilterArray;
	while(*szFilter++)
	{
		FilterArray.push_back(szFilter-1);
		while(*szFilter++);
	}

	//�����������Ϊ"*.*",�򲻽��д���,ֱ�ӷ���
	string strFilter=FilterArray[openfilename.nFilterIndex];
	strFilter.erase(remove_if(strFilter.begin(),strFilter.end(),ptr_fun(::isspace)),strFilter.end());
	if(strFilter=="*.*")  return strFileName;

	string strSuffixName=strFilter.substr(2).c_str();
	if(IsHaveSuffix)
	{
		//����û�����ĺ�׺�͹������еĺ�׺һ��
		if(strFileName.substr(strFileName.find_last_of(".")+1)==strSuffixName)
		{
			return strFileName;
		}
		else
		{
			strFileName+=".";
			strFileName+=strSuffixName;
			return strFileName;
		}
	}
	else
	{
		strFileName+=".";
		strFileName+=strSuffixName;
		return strFileName;
	}
}
