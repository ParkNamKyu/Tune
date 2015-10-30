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
// 루트 클래스에 선언
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
// 자식 클래스에 선언
//--------------------------------------------------------------------------------
#define DeclareRTTI																\
    public:																		\
		static const CRTTI m_RTTI;												\
		virtual const CRTTI* GetRTTI() const {	return &m_RTTI;	}

//--------------------------------------------------------------------------------
// RTTI 등록
//--------------------------------------------------------------------------------
#define RegisterRootRTTI(Class)					const CRTTI ClassName::m_RTTI(NULL)					// 루트 클래스는 부모 클래스가 없으므로 비워둔다
#define RegisterParentRTTI(Class, ParentClass)	const CRTTI ClassName::m_RTTI(&ParentClass::m_RTTI)	// 부모 클래스의 RTTI를 등록해둔다

/*
//--------------------------------------------------------------------------------
// 사용 예
//--------------------------------------------------------------------------------
class Parent  
{  
    DeclareRootRTTI(Parent);	// 루트 선언
};
const CRTTI Parent::m_RTTI(NULL);	// 루트 등록
//RegisterRootRTTI(Parent);  
  
class Child : public Parent  
{  
    DeclareRTTI;	// 선언
};
const CRTTI Child::m_RTTI(&Parent::m_RTTI);	// 부모 등록
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