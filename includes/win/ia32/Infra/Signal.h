//
//  "$Id: Signal.h 1606 2011-05-08 13:19:15Z chenchangbao $"
//
//  Copyright (c)1992-2007, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

/// \class SIGNAL_SIGNAL
/// \brief �ź���ģ�顣
///
/// һ���źű�����ʱ��������������ӵ����ϵ�TFunctionN����ֻ֧��
/// ����ֵΪvoid��TFunctionN��SIGNAL_SIGNAL��һ���꣬���ݲ��������ᱻ�滻��
/// TSignalN���û�ͨ�� TSignalN<T1, T2, T3,..,TN>��ʽ��ʹ�ã�TN��ʾ�������ͣ� 
/// N��ʾ��������������Ŀǰ������Ϊ6��
/// \see FUNCTION_FUNCTION

#define SIGNAL_SIGNAL MACRO_JOIN(TSignal,SIGNAL_NUMBER)
#define FUNCTION_FUNCTION MACRO_JOIN(TFunction, SIGNAL_NUMBER)

#if (SIGNAL_NUMBER != 0)
template <SIGNAL_CLASS_TYPES>
#endif
class SIGNAL_SIGNAL
{
	/// �źŽڵ�״̬
	enum SlotState
	{
		slotStateEmpty,		///< �ڵ�Ϊ��
		slotStateNormal,	///< �ڵ�������
	};

public:
	/// �źŲ���������
	enum ErrorCode
	{
		errorNoFound = -1,		///< û���ҵ�ָ���Ķ���
		errorExsist = -2,		///< �����Ѿ�����
		errorFull = -3,			///< �Ѿ������ܹ����ӵĶ����������
		errorEmptyProc = -4,	///< ��������ĺ���ָ��Ϊ�գ�û������
	};

	/// ���ź�ģ���������ƥ��ĺ���ָ���������
	typedef FUNCTION_FUNCTION<void SIGNAL_TYPES_COMMA> SigProc;

private:
	/// �źŽڵ�ṹ
	struct SignalSlot
	{
		SigProc proc;
		SlotState state;
	};

	int m_numberMax;
	int m_number;
	SignalSlot* m_slots;
	CMutex m_mutex;

public:
	/// ���캯��
	/// \param maxSlots �ܹ����ӵ������ָ�����ĸ���
	SIGNAL_SIGNAL(int maxSlots) :
	  m_numberMax(maxSlots), m_number(0)
	{
		m_slots = new SignalSlot[maxSlots];
		for(int i = 0; i < m_numberMax; i++)
		{
			m_slots[i].state = slotStateEmpty;
		}
	}
	
	 /// ��������
	~SIGNAL_SIGNAL()
	{
		delete []m_slots;
	}

	/// ������лص�
	void Clear()
	{
		m_mutex.Enter();
		for(int i = 0; i < m_numberMax; i++)
		{
			m_slots[i].state = slotStateEmpty;
		}
		m_mutex.Leave();
	}

	/// ���غ���ָ�����
	int Attach(SigProc proc)
	{
		if(proc.empty())
		{
			return errorEmptyProc;
		}

		if(IsAttached(proc))
		{
			return errorExsist;
		}
		
		m_mutex.Enter();
			
		for(int i = 0; i < m_numberMax; i++)
		{
			if(m_slots[i].state == slotStateEmpty)
			{
				m_slots[i].proc  = proc;
				m_slots[i].state = slotStateNormal;
				m_number++;
				m_mutex.Leave();
				return m_number;
			}
		}
		m_mutex.Leave();
		return errorFull;
	}			

	/// ж�غ���ָ����󣬸��ݶ����б���ĺ���ָ����ƥ�䡣
	int Detach(SigProc proc)
	{
		if(proc.empty())
		{
			return errorEmptyProc;
		}
		m_mutex.Enter();

		for(int i = 0; i < m_numberMax; i++)
		{
			if(m_slots[i].proc ==  proc && m_slots[i].state != slotStateEmpty)
			{
				m_slots[i].state = slotStateEmpty;
				m_number--;
				m_mutex.Leave();
				return m_number;
			}
		};
		m_mutex.Leave();
		return errorNoFound;
	}

	/// �ж�ж�غ���ָ������Ƿ���أ����ݶ����б���ĺ���ָ����ƥ�䡣
	bool IsAttached(SigProc proc)
	{
		m_mutex.Enter();
		if(proc.empty())
		{
			m_mutex.Leave();
			return false;
		}

		for(int i = 0; i < m_numberMax; i++)
		{
			if(m_slots[i].proc ==  proc
				&& m_slots[i].state == slotStateNormal)
			{
				m_mutex.Leave();
				return true;
			}
		}
		m_mutex.Leave();
		return false;
	}

	// ������������������ε��ø�����ע��Ļص�����
	// �����ڻص�������Detach()�Լ������
	inline void operator()(SIGNAL_TYPE_ARGS)
	{
		for(int i = 0; i < m_numberMax; i++)
		{
			if(m_slots[i].state == slotStateNormal)
			{		
				m_slots[i].proc(SIGNAL_ARGS);

				// �ص������ڲ��Լ�Detach()�Լ������
				m_mutex.Enter();
				if (m_slots[i].state != slotStateNormal)
				{
					m_slots[i].proc = 0;
				}
				m_mutex.Leave();
			}
		}
	}
};

#undef SIGNAL_SIGNAL
#undef FUNCTION_FUNCTION
