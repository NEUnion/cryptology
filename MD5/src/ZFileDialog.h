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
	//选择目录
	string GetSelectDirectory(const char* szTitle="Please select directory");

	/*********************************************************
	选择文件(单选或多选)
	ultiSelect文件是否可以多选
	Filter文件类型过滤
	备  注:例:Filter=="所有文件 (*.*)\0*.*\0文本文件 (*.txt)\0*.txt\0\0";
	示例:
	ZFileDialog fileDlg;
	deque<string> FileNames;
	FileNames=fileDlg.GetOpenFileName(true,"所有文件 (*.*)\0*.*\0文本文件 (*.txt)\0*.txt\0\0");
	for(int j=0;j<FileNames.size();j++)
	AfxMessageBox(((string)FileNames.at(j)).c_str());
	*********************************************************/
	deque<string> GetOpenFileName(bool MultiSelect,const char* szFilter);

	/*********************************************************
	获取用户保存的文件名
	AutoAddSuffixName是否自动添加保存的文件后缀名(根据文件框的过滤下拉框添加)
	Filter文件类型过滤
	备  注:例:Filter=="所有文件 (*.*)\0*.*\0文本文件 (*.txt)\0*.txt\0\0";
	*********************************************************/
	string GetSaveFileName(bool AutoAddSuffixName,const char* szFilter);
};

#endif
