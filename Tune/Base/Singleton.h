#include <assert.h>

template <class T>
class Singleton
{
public:

	Singleton()
	{
		assert(!m_Instance);
		m_Instance = static_cast<T*>(this);
	}
	virtual ~Singleton() 
	{
		assert(m_Instance == static_cast<T*>(this));
		m_Instance = 0;
	}

	static T* InstancePtr() 
	{ 
		return m_InstancePtr; 
	}

	static T& Instance()
	{
		assert(m_Instance);
		return *m_Instance;
	}

protected:
	static T* m_Instance;
};
 
template <class T>
T* Singleton<T>::m_Instance = 0;