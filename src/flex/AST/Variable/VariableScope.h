#ifndef VARIABLESCOPE
#define VARIABLESCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

#include "AbstractNode.h"
#include "Value.h"

namespace AST{	
	
	class Variable;
	
	class UndeclaredIdException: public std::exception
	{
	public:
	
        UndeclaredIdException();
        UndeclaredIdException(std::string text);
		
        virtual const char* what() const throw();
	    
	protected :
		std::string text;    
		
	};


	class VariableScope
	{
	public:
		VariableScope();
		VariableScope( const VariableScope & variableScope); // declared but not defined		
		virtual ~VariableScope();

        void declareVariable(std::string identifiant, std::shared_ptr<Variable> variable);
        std::shared_ptr<Variable> findVariable(std::string identifiant);
		
	protected:
		std::map< std::string, std::shared_ptr<Variable> > scope;
    };
}

#endif // VARIABLESCOPE
