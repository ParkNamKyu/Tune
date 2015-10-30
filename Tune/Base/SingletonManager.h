#pragma once

#include <vector>
#include "Singleton.h"

class SingletonManager
{
public:
	SingletonManager()						{									}
	SingletonManager(unsigned int iSize)	{ m_InstanceList.reserve(iSize);	}
	~SingletonManager()						{ AllDelete();						}

	void Reserve(unsigned int iSize)			{	m_InstanceList.reserve(iSize);		}
	void Register(SingletonInterface* pData)	{	m_InstanceList.push_back(pData);	}

	void AllDelete()
	{
		if(!m_InstanceList.empty())
		{
			vector<SingletonInterface*>::iterator it = m_InstanceList.begin();
			for(;it != m_InstanceList.end();++it)
			{
				if(*it != NULL)
					delete (*it);
			}
			m_InstanceList.clear();
		}
	}

private:
	vector<SingletonInterface*> m_InstanceList;
};