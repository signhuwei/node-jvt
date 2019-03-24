//
//  "$Id: PoolAllocator.h 786 2010-07-23 13:48:27Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __POOL_ALLOCATOR_H__
#define __POOL_ALLOCATOR_H__

#include "Mutex.h"
#include "Types.h"
#include <exception>
#include <algorithm>
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Pool based on Chunk
class Pool
{
	struct Link
	{
		Link* next;
	};
	struct Chunk
	{
		char *mem;					// allocation area first to get stringent alignment
		Chunk *next;
	};

	enum
	{
		ecount_default = 1024,		//defaut element count in a chunk
	};

	Chunk *chunks;
	const uint esize;
	uint ecount;
	Link* head;
	CMutex mutex;

	Pool(Pool&);					// copy protection
	void operator=(Pool&);			// copy protection
	void grow();					// make pool larger

public:
	Pool(uint sz);			// sz is the size of elements
	~Pool();

	void* alloc();					// allocate one element
	void free(void *b);				// put an element back into the pool
	void setec(uint n);		//set max element count in a chunk
	uint getec();			//get max element count in a chunk
};

inline void *Pool::alloc()
{
	mutex.Enter();
	if(head == 0) grow();
	Link *p = head;					// return first element
	head = p->next;
	mutex.Leave();
	return p;
}

inline void Pool::free(void *b)
{
	mutex.Enter();
	Link *p = static_cast<Link*>(b);
	p->next = head;					// put b back as first element
	head = p;
	mutex.Leave();
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// pool_allocator
template <class T> class pool_allocator;

template<> class pool_allocator<void>
{
public:
	typedef void        value_type;
	typedef void*       pointer;
	typedef const void* const_pointer;
	
	template <class U> 
		struct rebind { typedef pool_allocator<U> other; };
};

template <class T> class pool_allocator
{
private:
	static Pool mem;				// pool of elements of sizeof(T)

public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;
	
	template <class U> 
		struct rebind { typedef pool_allocator<U> other; };
	
	
	pool_allocator() {}
	template <class U> 
		pool_allocator(const pool_allocator<U>&) {}
	~pool_allocator() {}

	
	pointer address(reference x) const { return &x; }
	const_pointer address(const_reference x) const
	{ 
		return x;
	}

	static void setchunksize(uint n)
	{
		mem.setec(n);
	}

	static uint getchunksize()
	{
		return mem.getec();
	}

	pointer allocate(size_type n, pool_allocator<void>::const_pointer hint = 0)
	{
		assert(n == 1);
		return static_cast<T*>(mem.alloc());
	}

	void deallocate(pointer p, size_type n)
	{
		assert(n == 1);
		mem.free(p);
	}
	
	size_type max_size() const
	{ 
		return static_cast<size_type>(-1) / sizeof(T);
	}
	
	void construct(pointer p, const value_type& x)
	{ 
		new(p) value_type(x); 
	}
	void destroy(pointer p) { p->~T(); }
};

	template<class T>Pool pool_allocator<T>::mem(sizeof(T));

template <class T>
inline bool operator==(const pool_allocator<T>&, 
                       const pool_allocator<T>&)
{
	return true;
}


template <class T>
inline bool operator!=(const pool_allocator<T>&, 
                       const pool_allocator<T>&)
{
	return false;
}

/////////////////////////////////////////////////////
///////////////// 内存池模式，内联实现
#define USE_POOL_ALLOCATOR(classname)				\
static void * operator new(size_t size)				\
{													\
	static	pool_allocator<classname> a;			\
	if (size != sizeof(classname))					\
	return ::operator new(size);					\
	return a.allocate(1);							\
}													\
static void operator delete(void *p, size_t size)	\
{													\
	static	pool_allocator<classname> a;			\
	if (p == 0) return;								\
	if (size != sizeof(classname)) {				\
	::operator delete(p);							\
	return;                        					\
	}												\
	a.deallocate((classname *) p, size);			\
}													\
static void setAllocatorChunk(size_t n)				\
{													\
	static	pool_allocator<classname> a;			\
	a.setchunksize(n);								\
}													\
/////////////////////////////////////////////////////

#endif 
