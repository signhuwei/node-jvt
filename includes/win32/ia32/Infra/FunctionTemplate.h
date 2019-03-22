//
//  "$Id: FunctionTemplate.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)1992-2007, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#define FUNCTION_FUNCTION MACRO_JOIN(TFunction,FUNCTION_NUMBER)

/// \class FUNCTION_FUNCTION
/// \brief ����ָ����ģ��
///
template <FUNCTION_CLASS_TYPES>
class FUNCTION_FUNCTION
{
	class X{};

	enum FunctionType
	{
		typeEmpty,
		typeMember,
		typePointer,
		typeObject,
	};
	typedef R (X::*MEM_FUNCTION)(FUNCTION_TYPES);
	typedef R (*PTR_FUNCTION)(FUNCTION_TYPES);

	union
	{
		struct
		{
			MEM_FUNCTION proc;
			X* obj;
		}memFunction;
		PTR_FUNCTION ptrFunction;
	}m_function;

	FunctionType m_type;

public:
	FUNCTION_FUNCTION( ) 
		:m_type(typeEmpty)
	{
	}

	template<typename O>
		FUNCTION_FUNCTION(R(O::*f)(FUNCTION_TYPES), const O * o)
	{
		m_type = typeMember;
		m_function.memFunction.proc = horrible_cast<MEM_FUNCTION>(f); 
		m_function.memFunction.obj = horrible_cast<X*>(o);
	}

	FUNCTION_FUNCTION(PTR_FUNCTION f)
	{
		m_type = typePointer;
		m_function.ptrFunction = f;
	}

	/// �չ��캯��
	FUNCTION_FUNCTION(int zero)
	{
		m_type = typeEmpty;
		assert(zero == 0);
	}

	FUNCTION_FUNCTION& operator=(const FUNCTION_FUNCTION& f)
	{
		if (&f == this)
			return *this;
		m_function = f.m_function;
		m_type = f.m_type;
		return *this;
	}

	/// ����ĳ�Ա������������ָ��󶨲����档�������͵ĺ���ָ�����=���������ʽת��ֱ����ɡ�
	template<typename O>
	void bind(R(O::*f)(FUNCTION_TYPES), const O * o)
	{
		*this = FUNCTION_FUNCTION(f, o);
	}

	bool empty()
	{
		return (m_type == typeEmpty);
	}

	bool operator==(const FUNCTION_FUNCTION& f)
	{
		if(m_type != f.m_type)
		{
			return false;
		}
		if(m_type == typeMember)
		{
			return (m_function.memFunction.proc == f.m_function.memFunction.proc
				&& m_function.memFunction.obj == f.m_function.memFunction.obj);
		}
		else if(m_type == typePointer)
		{
			return (m_function.ptrFunction == f.m_function.ptrFunction);
		}
		else
		{
			return true;
		}
	}

	inline R operator()(FUNCTION_TYPE_ARGS)
	{
		if(m_type == typeMember)
		{
			return (m_function.memFunction.obj->*m_function.memFunction.proc)(FUNCTION_ARGS);
		}
		else
		{
			return m_function.ptrFunction(FUNCTION_ARGS);
		}
	}
};

#undef FUNCTION_FUNCTION

