#ifndef L_PARAMETRES_H
#define L_PARAMETRES_H

#include <memory>
#include <vector>

#include "AbstractNode.h"
#include "AbstractExpression.h"

namespace AST
{

	class LParametres : public AbstractNode
	{
	public:
		
		friend class LArguments;
        friend class Function;
		
		LParametres();
		LParametres(std::shared_ptr<AbstractExpression> parametre);
		
		void addParametre(std::shared_ptr<AbstractExpression> parametre);
		
		virtual Value evaluate() const;
		virtual void printTree(int tabulationNumber) const;
		virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
		
	protected:
		
		std::vector<std::shared_ptr<AbstractExpression> > parametres;
		
	};

}

#endif
