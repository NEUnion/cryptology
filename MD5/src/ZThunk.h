
/*-======================- Copyright (c) 2006 -======================-

��������:
    ��³��(zhangluduo) : Ϊ���а��ҵ��˺��Ұ�����Ŭ��!

��ϵ��ʽ:
    oopfans@msn.com
	[oopfans]Ⱥ:34064264

�޸�ʱ��:
    2007-02-01

��������:
    thunk����ʵ��.�����������԰ѻص�������ȫ��װ�����Ա����.ʹ����
    ����ʱ,һ��Ҫȷ����ʵ������������,������ʾ:

    -----------------------------------------------------------------

    ��ȷ��������(һ):
    class T
	{
		private:
		    ZThunk m_thunk; // ��ZThunk����Ϊ���ݳ�Ա
        public:
		    void MemberFunction()
			{
				m_thunk.CallBack(parameters ... ); // ok!
            }
    }

    -----------------------------------------------------------------

    ��ȷ��������(��):
    ZThunk m_thunk; // ��ZThunk����ȫ�ֶ���
    class T
	{
        public:
		    void MemberFunction()
			{
				m_thunk.CallBack(parameters ... ); // ok!
            }
    }

    -----------------------------------------------------------------

    �����������:

    class T
	{
        public:
		    void MemberFunction()
			{
                ZThunk m_thunk; // ��ZThunk����Ϊ�ֲ�����,
				                // �������﷨����,��������ĵ��û�ʧ��!
				m_thunk.CallBack(parameters ... ); // error!
            }
    }

    -----------------------------------------------------------------

	�����ۺ�ʾ��:
	class CTimer  
	{
	private:

		//thunk����
		ZThunk m_thunk;

		//��ʱ���ص�����
		void TimerProc(HWND hWnd, DWORD dwMsg , WPARAM wPa, LPARAM lPa);

	public:
		
		//��װ��ʱ��
		void Set(HWND hWnd,int TimerID,int TimerSpeed)
		{
			//(TIMERPROC)m_thunk.CallBack(this,&CTimer::TimerProc,ZThunk::THISCALL)
			//����һ��ָʾ�˶�ʱ���ص�����ΪCTimer���TimerProc��Ա����,Ҳ����ָ��
			//�������еĳ�Ա����
			::SetTimer(hWnd,TimerID,TimerSpeed, 
			(TIMERPROC)m_thunk.CallBack(this,&CTimer::TimerProc,ZThunk::THISCALL));
		}
	};


��Ȩ����:
    ����κε�λ,��������ʹ��,����,�޸�,ɢ����������ݴ���,���Ǳ��뱣
    ���˰�Ȩ��Ϣ,��ο���������ڵ��Ͷ�,�������˴������Դ,�����˷ݴ���
    ���κ�BUG,��֪ͨ����,�Ա��ֲ���������ˮƽ���޶����µ�һЩ����Ͳ�
    ��,лл!

    �˷ݴ��������߸���һλ����[JERKII.SHANG (JERKII@HOTMAIL.COM)]��һ
    ƪ����[һ��ʵ��Win32���ڹ��̺���(Window Procedure)���·���--
    ����Thunkʵ�ֵ����Ա��Ϣ������]�޸Ķ���,�ڴ˶�ԭ���߿�Դ�ľ���
    �¾�!

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
