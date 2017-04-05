#ifndef L_ARGUMENTS_H
#define L_ARGUMENTS_H

#include <memory>
#include <vector>

#include "AbstractNode.h"
#include "Variable/VariableSignature.h"

namespace AST
{

	class LParametres;
	
	class LArguments : public AbstractNode
	{
	public:
	
		LArguments();
		LArguments(std::shared_ptr<VariableSignature> argument);
		
		void addArgument(std::shared_ptr<VariableSignature> argument);
		
		bool compareSignature(std::shared_ptr<LArguments> larg2) const;
		
		bool checkParametres(std::shared_ptr<LParametres> params) const;
		
		bool isForDeclaration() const;
		
		void prepareScope(std::shared_ptr<Scope> scope) const;
		
		virtual Value evaluate() const;
		virtual void printTree(int tabulationNumber) const;
		virtual IR::sh_Memory buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        std::vector<std::shared_ptr<VariableSignature> > getArguments();
		
	protected:
		
		std::vector<std::shared_ptr<VariableSignature> > arguments;
		bool isForDecl;
		
	};

}

#endif