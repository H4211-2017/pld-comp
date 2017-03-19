#include "IFor.h"

IFor::IFor() : m_pIIntComp(nullptr);
{
	
}

IFor::IFor(std::shared_ptr<IIntComp> pIIntComp) : m_pIIntComp(pIIntComp);
{
	
}
