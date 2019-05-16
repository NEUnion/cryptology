/*-======================- Copyright (c) 2006 -======================-

程序作者:
    张鲁夺(zhangluduo) : 为所有爱我的人和我爱的人努力!

联系方式:
    oopfans@msn.com
	[oopfans]群:34064264

修改时间:
    2007-01-07

功能描述:
    利用Win32API调用系统公用对话框(文件打开,保存,目录选择..)

版权声明:
    许可任何单位,个人随意使用,拷贝,修改,散布及出售这份代码,但是必须保
    留此版权信息,以慰藉作者辛勤的劳动,及表明此代码的来源,如若此份代码
    有任何BUG,请通知作者,以便弥补作者由于水平所限而导致的一些错误和不
    足,谢谢!

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
	string str=dlg.SelectDirectory("看看你选择啥目录");
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

	//判断用户填写的文件名是否有后缀
	bool IsHaveSuffix=strFileName.find_last_of(".")==-1?false:true;

	//将const char* Filter拆成数组存放
	deque<string> FilterArray;
	while(*szFilter++)
	{
		FilterArray.push_back(szFilter-1);
		while(*szFilter++);
	}

	//如果过滤类型为"*.*",则不进行处理,直接返回
	string strFilter=FilterArray[openfilename.nFilterIndex];
	strFilter.erase(remove_if(strFilter.begin(),strFilter.end(),ptr_fun(::isspace)),strFilter.end());
	if(strFilter=="*.*")  return strFileName;

	string strSuffixName=strFilter.substr(2).c_str();
	if(IsHaveSuffix)
	{
		//如果用户输入的后缀和过滤器中的后缀一样
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
