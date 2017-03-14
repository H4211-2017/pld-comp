#ifndef IFOR_H
#define IFOR_H

#include <memory>
#include "IIntComp.h"

class IFor
{
public:
	IFor();
    IFor(std::shared_ptr<IIntComp> pIIntComp);

private:
    std::shared_ptr<IIntComp> m_pIIntComp;
};

#endif // IFOR_H
