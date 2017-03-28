#ifndef SCOPE
#define SCOPE

#include <memory>
#include <string>
#include <exception>

#include "Variable/VariableScope.h"
#include "Function/FunctionScope.h"

namespace AST{	
	
	class AbstractExpression;

	class Scope
	{
	public:
		Scope();
		
		Scope( std::shared_ptr<Scope> Scope );
		
		Scope( const Scope & Scope); // declared but not defined
		
		virtual ~Scope();
		
        void declareVariable(std::string identifiant, std::shared_ptr<Variable> );
        std::shared_ptr<Variable> findVariable(std::string identifiant);
        
        void declareFunction(std::string identifiant, std::shared_ptr<Function> decl);
        std::shared_ptr<Function> findFunction(std::string identifiant);
		
		std::shared_ptr<Scope> getMother() const;
		void setMother(std::shared_ptr<Scope> newMother);
		
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
        FunctionScope fScope;
    };
}

#endif // SCOPE
