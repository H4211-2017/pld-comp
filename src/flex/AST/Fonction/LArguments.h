#ifndef L_ARGUMENTS_H
#define L_ARGUMENTS_H

#include <memory>
#include <vector>

#include "AbstractNode.h"
#include "VariableSignature.h"

namespace AST
{

	class LArguments : public AbstractNode
	{
	public:
		
		LArguments();
		LArguments(std::shared_ptr<VariableSignature> argument);
		
		void addArgument(std::shared_ptr<VariableSignature> argument);
		
		bool compareSignature(std::shared_ptr<LArguments> larg2) const;
		bool isForDeclaration() const;
		
		virtual Value evaluate() const;
		virtual void printTree(int tabulationNumber) const;
		virtual void buildIR() const;
		
	protected:
		
		std::vector<std::shared_ptr<VariableSignature> > arguments;
		bool isForDecl;
		
	};

}

#endif
