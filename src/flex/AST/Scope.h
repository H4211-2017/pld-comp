#ifndef SCOPE
#define SCOPE

#include <memory>
#include <string>
#include <exception>

#include "Variable/VariableScope.h"
#include "Fonction/FonctionScope.h"

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
        
        void declareFonction(std::string identifiant, std::shared_ptr<Fonction> decl);
        std::shared_ptr<Fonction> findFonction(std::string identifiant);
		
		std::shared_ptr<Scope> getMother() const;
		void setMother(std::shared_ptr<Scope> newMother);
		
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
		FonctionScope fScope;
    };
}

#endif // SCOPE
