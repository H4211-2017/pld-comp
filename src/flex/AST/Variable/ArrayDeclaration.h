#ifndef VARIABLEDECLARATION_H
#define VARIABLEDECLARATION_H

#include "Instruction/AbstractInstruction.h"

#include <exception>

#include "AbstractExpression.h"
#include "VariableSignature.h"
#include "Array.h"
#include "Scope.h"

namespace AST {
	
	class IllegalSizeExpressionException: public std::exception
	{
	public:
	
		IllegalSizeExpressionException()
		{
			this->text = "Error : Illegal size expression for table declaration";
		}
		
		IllegalSizeExpressionException(std::string text)
		{
			this->text = "Error : Illegal size expression for table declaration \n";
			this->text += text;
		}
		
		virtual const char* what() const throw()
		{
			return text.c_str();
	    }
	    
	protected :
		std::string text;    
		
	};
	
    class ArrayDeclaration : public AbstractInstruction
    {
    public:
    
		// WARNING : utilise evalute(), fonction a verifier 
        ArrayDeclaration(std::shared_ptr<VariableSignature> signature, 
				long int size, std::shared_ptr<Scope> scope);
        
        virtual void printTree(int tabulationNumber) const;
        virtual Value evaluate() const;
        virtual void buildIR(IR::sh_BasicBlock & currentBasicBlock) const;
        
    protected:
        std::shared_ptr<Array> array;
    };
}


#endif // VARIABLEDECLARATION_H
