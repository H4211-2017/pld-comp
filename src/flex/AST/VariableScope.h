#ifndef VARIABLESCOPE
#define VARIABLESCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>


#include "AbstractNode.h"
#include "Value.h"

namespace AST{

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
		
		VariableScope( VariableScope & );
		
		VariableScope( const VariableScope & variableScope); // declared but not defined
		
		virtual ~VariableScope();
		
        void declareVariable(std::string identifiant, Value variable);
		
        std::shared_ptr<Value> findVariable(std::string identifiant);
		
		
		
	protected:
		//tree hierarchy
		std::shared_ptr<VariableScope> mother;
		
		std::map< std::string, std::shared_ptr<Value> > scope;
    };
}

#endif // VARIABLESCOPE
