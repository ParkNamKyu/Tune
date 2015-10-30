#pragma once

//--------------------------------------------------------------------------------
// RTTI Class
//--------------------------------------------------------------------------------
class CRTTI
{
public:
	CRTTI(const CRTTI* pParentRTTI) : m_pParentRTTI(pParentRTTI)
	{
	}
    const CRTTI* GetParentRTTI() const
	{
		return m_pParentRTTI;
	}

private:
    const CRTTI* m_pParentRTTI;
};

//--------------------------------------------------------------------------------
// ��Ʈ Ŭ������ ����
//--------------------------------------------------------------------------------
#define DeclareRootRTTI(Class)													\
    public:																		\
        static const CRTTI m_RTTI;												\
        virtual const CRTTI* GetRTTI() const { return &m_RTTI; }				\
        static bool FindRTTI( const CRTTI* srcRTTI, const Class* desClass )		\
        {																		\
			if(desClass)														\
			{																	\
				const CRTTI* pDesRTTI = desClass->GetRTTI();					\
				while(NULL != pDesRTTI)											\
				{																\
					if(srcRTTI == pDesRTTI)										\
						return true;											\
					pDesRTTI = pDesRTTI->GetParentRTTI();						\
				}																\
			}																	\
			return false;														\
        }
//--------------------------------------------------------------------------------
// �ڽ� Ŭ������ ����
//--------------------------------------------------------------------------------
#define DeclareRTTI																\
    public:																		\
		static const CRTTI m_RTTI;												\
		virtual const CRTTI* GetRTTI() const {	return &m_RTTI;	}

//--------------------------------------------------------------------------------
// RTTI ���
//--------------------------------------------------------------------------------
#define RegisterRootRTTI(Class)					const CRTTI ClassName::m_RTTI(NULL)					// ��Ʈ Ŭ������ �θ� Ŭ������ �����Ƿ� ����д�
#define RegisterParentRTTI(Class, ParentClass)	const CRTTI ClassName::m_RTTI(&ParentClass::m_RTTI)	// �θ� Ŭ������ RTTI�� ����صд�

/*
//--------------------------------------------------------------------------------
// ��� ��
//--------------------------------------------------------------------------------
class Parent  
{  
    DeclareRootRTTI(Parent);	// ��Ʈ ����
};
const CRTTI Parent::m_RTTI(NULL);	// ��Ʈ ���
//RegisterRootRTTI(Parent);  
  
class Child : public Parent  
{  
    DeclareRTTI;	// ����
};
const CRTTI Child::m_RTTI(&Parent::m_RTTI);	// �θ� ���
//RegisterParentRTTI(Child, Parent);

#define FindRTTI(srcClass, desClass)		srcClass::FindRTTI(&srcClass::m_RTTI, desClass)


int main()
{  
    Parent *pParent = new Child;  

	if(FindRTTI(Child, pParent))
	{
		Child* pChild = (Child*)pParent;
	}
	return 0;
}
*/