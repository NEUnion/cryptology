
/*-======================- Copyright (c) 2006 -======================-

程序作者:
    张鲁夺(zhangluduo) : 为所有爱我的人和我爱的人努力!

联系方式:
    oopfans@msn.com
	[oopfans]群:34064264

修改时间:
    2007-02-01

功能描述:
    thunk技术实现.利用这个类可以把回调函数完全封装成类成员函数.使用这
    个类时,一定要确保类实例的生命周期,如下所示:

    -----------------------------------------------------------------

    正确调用如下(一):
    class T
	{
		private:
		    ZThunk m_thunk; // 将ZThunk声明为数据成员
        public:
		    void MemberFunction()
			{
				m_thunk.CallBack(parameters ... ); // ok!
            }
    }

    -----------------------------------------------------------------

    正确调用如下(二):
    ZThunk m_thunk; // 将ZThunk声明全局对像
    class T
	{
        public:
		    void MemberFunction()
			{
				m_thunk.CallBack(parameters ... ); // ok!
            }
    }

    -----------------------------------------------------------------

    错误调用如下:

    class T
	{
        public:
		    void MemberFunction()
			{
                ZThunk m_thunk; // 将ZThunk声明为局部对像,
				                // 不会有语法错误,但是下面的调用会失败!
				m_thunk.CallBack(parameters ... ); // error!
            }
    }

    -----------------------------------------------------------------

	调用综合示例:
	class CTimer  
	{
	private:

		//thunk对像
		ZThunk m_thunk;

		//定时器回调函数
		void TimerProc(HWND hWnd, DWORD dwMsg , WPARAM wPa, LPARAM lPa);

	public:
		
		//安装定时器
		void Set(HWND hWnd,int TimerID,int TimerSpeed)
		{
			//(TIMERPROC)m_thunk.CallBack(this,&CTimer::TimerProc,ZThunk::THISCALL)
			//上面一句指示了定时器回调函数为CTimer类的TimerProc成员函数,也可以指定
			//其他类中的成员函数
			::SetTimer(hWnd,TimerID,TimerSpeed, 
			(TIMERPROC)m_thunk.CallBack(this,&CTimer::TimerProc,ZThunk::THISCALL));
		}
	};


版权声明:
    许可任何单位,个人随意使用,拷贝,修改,散布及出售这份代码,但是必须保
    留此版权信息,以慰藉作者辛勤的劳动,及表明此代码的来源,如若此份代码
    有任何BUG,请通知作者,以便弥补作者由于水平所限而导致的一些错误和不
    足,谢谢!

    此份代码是作者跟据一位网友[JERKII.SHANG (JERKII@HOTMAIL.COM)]的一
    篇文章[一种实现Win32窗口过程函数(Window Procedure)的新方法--
    基于Thunk实现的类成员消息处理函数]修改而成,在此对原作者开源的精神
    致敬!

-======================- Copyright (c) 2006 -======================-*/

#ifndef _ZTHUNK
#define _ZTHUNK

class ZThunk  
{
private:
	unsigned char m_ThiscallCode[10];
	unsigned char m_StdcallCode[16];
public:
	enum CALLINGCONVENTIONS
	{
		STDCALL = 1,
		THISCALL= 2
	};
public:
	template <class T>
	void* CallBack(void* pThis,T MemberAddr,CALLINGCONVENTIONS WhichCalling=STDCALL)
	{
		// these codes only use in stdcall
		if(WhichCalling==STDCALL)
		{
			// Encoded machine instruction   Equivalent assembly languate notation
			// ---------------------------   -------------------------------------
			// FF 34 24                      push  dword ptr [esp]          ; Save (or duplicate)                                                                    ; the Return Addr into stack
			// C7 44 24 04 ?? ?? ?? ??       mov   dword ptr [esp+4], pThis ; Overwite the old                                                                    ; Return Addr with 'this pointer'
			// E9 ?? ?? ?? ??                jmp   target addr              ; Jump to target message handler

			char Buf[33]={0};
			sprintf(Buf,"%d",MemberAddr);
			unsigned long JmpAddr = (unsigned long) atol(Buf) - (unsigned long) &m_StdcallCode[0] - 16;

			m_StdcallCode[11] = 0xE9; 
			*((unsigned long *)  &m_StdcallCode[ 0]) = 0x002434FF;
			*((unsigned long *)  &m_StdcallCode[ 3]) = 0x042444C7;
			*((unsigned long *)  &m_StdcallCode[ 7]) = (unsigned long) pThis;
			*((unsigned long *)  &m_StdcallCode[12]) = JmpAddr;

			return (void*)m_StdcallCode;
		}
		// these codes only use in thiscall
		else if(WhichCalling==THISCALL)
		{
			// Encoded machine instruction   Equivalent assembly languate notation
			// ---------------------------   -------------------------------------
			// B9 ?? ?? ?? ??                mov    ecx, pThis  ; Load ecx with this pointer
			// E9 ?? ?? ?? ??                jmp    target addr ; Jump to target message handler

			char Buf[33]={0};
			sprintf(Buf,"%d",MemberAddr);
			unsigned long JmpAddr = (unsigned long) atol(Buf) - (unsigned long) &m_ThiscallCode[0] - 10;

			m_ThiscallCode[0] = 0xB9;
			m_ThiscallCode[5] = 0xE9;
			*((unsigned long *) &m_ThiscallCode[1]) = (unsigned long) pThis;
			*((unsigned long *) &m_ThiscallCode[6]) = JmpAddr;

			return (void*)m_ThiscallCode;
		}return 0;
	}
};

#endif
