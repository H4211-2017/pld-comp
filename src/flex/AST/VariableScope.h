//#ifndef VARIABLESCOPE
//#define VARIABLESCOPE

//#include <memory>
//#include <map>
//#include <string>
//#include <exception>


//#include "AbstractNode.h"

//namespace AST{

//	class UndeclaredIdException: public std::exception
//	{
//	  virtual const char* what() const throw()
//	  {
//		return "Error : Undeclared Identifier";
//	  }
		
//	};


//	class VariableScope
//	{
//	public:
//		VariableScope();
		
//		VariableScope( VariableScope & );
		
//		VariableScope( const VariableScope & variableScope); // declared but not defined
		
//		virtual ~VariableScope();
		
//		void declareVariable( std::string identifiant, std::pair<Type, TypeValue> variable);
		
//		std::pair<Type, TypeValue> findVariable( std::string identifiant );
		
		
		
//	protected:
//		//tree hierarchy
//		std::shared_ptr<VariableScope> mother;
		
//		// map<id, pair<type, valeur>>
//		std::map< std::string, std::pair<Type, TypeValue> > scope;
		
		
//	};


//}

//#endif // VARIABLESCOPE
