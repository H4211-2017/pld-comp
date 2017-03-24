#ifndef VARIABLESCOPE
#define VARIABLESCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>


#include "AbstractNode.h"
#include "Value.h"

namespace AST{
	
	class AbstractExpression;	
	
	class UndeclaredIdException: public std::exception
	{
	  virtual const char* what() const throw()
	  {
		return "Error : Undeclared Identifier";
	  }
		
	};


	class VariableScope
	{
	public:
		VariableScope();
		
		VariableScope( std::shared_ptr<VariableScope> variableScope );
		
		VariableScope( const VariableScope & variableScope); // declared but not defined
		
		virtual ~VariableScope();
		
        void declareVariable(std::string identifiant, std::shared_ptr<AbstractExpression> variable);
		
        std::shared_ptr<AbstractExpression> findVariable(std::string identifiant);
		
		std::shared_ptr<VariableScope> getMother() const;
		
	protected:
		//tree hierarchy
		std::shared_ptr<VariableScope> mother;
		
		std::map< std::string, std::shared_ptr<AbstractExpression> > scope;
    };
}

#endif // VARIABLESCOPE
