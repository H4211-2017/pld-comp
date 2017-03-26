#ifndef SCOPE
#define SCOPE

#include <memory>
#include <string>
#include <exception>

#include "VariableScope.h"
#include "FonctionScope.h"

namespace AST{	
	
	class AbstractExpression;

	class Scope
	{
	public:
		Scope();
		
		Scope( std::shared_ptr<Scope> Scope );
		
		Scope( const Scope & Scope); // declared but not defined
		
		virtual ~Scope();
		
        void declareVariable(std::string identifiant, std::shared_ptr<AbstractExpression> );
        std::shared_ptr<AbstractExpression> findVariable(std::string identifiant);
        void setVariable(std::string identifiant, std::shared_ptr<AbstractExpression> newExpr);
        
        void declareFonction(std::string identifiant, std::shared_ptr<DeclarationFonction> decl);
        std::shared_ptr<DeclarationFonction> findFonction(std::string identifiant, std::shared_ptr<ListArg> args);
        void setFonction(std::string name, std::shared_ptr<DeclarationFonction> decl);
		
		std::shared_ptr<Scope> getMother() const;
		
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
		FonctionScope fScope;
    };
}

#endif // SCOPE
