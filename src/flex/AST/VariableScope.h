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
	public:
	
		UndeclaredIdException()
		{
			this->text = "Error : Undeclared Identifier";
		}
		
		UndeclaredIdException(std::string text)
		{
			this->text = text;
		}
		
		virtual const char* what() const throw()
		{
			return text.c_str();
	    }
	    
	protected :
		std::string text;    
		
	};


	class VariableScope
	{
	public:
		VariableScope();
		
		VariableScope( const VariableScope & variableScope); // declared but not defined
		
		virtual ~VariableScope();
		
        void declareVariable(std::string identifiant, std::shared_ptr<AbstractExpression> variable);
		
        std::shared_ptr<AbstractExpression> findVariable(std::string identifiant);
        
        void setVariable(std::string identifiant, std::shared_ptr<AbstractExpression> newExpr);
		
	protected:
		//tree hierarchy
		std::shared_ptr<VariableScope> mother;
		
		std::map< std::string, std::shared_ptr<AbstractExpression> > scope;
    };
}

#endif // VARIABLESCOPE
