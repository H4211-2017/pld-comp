#ifndef FONCTIONSCOPE
#define FONCTIONSCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

namespace AST{	
	
	class Function;
	class ListArg;
	
	class UndeclaredIdFctException: public std::exception
	{
	public:
	
		UndeclaredIdFctException()
		{
			this->text = "Error : Undeclared Function Identifier";
		}
		
		UndeclaredIdFctException(std::string text)
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


    class FunctionScope
	{
	public:
        FunctionScope();
		
        FunctionScope( const FunctionScope & fonctionScope); // declared but not defined
		
        virtual ~FunctionScope();
		
        void declareFunction(std::string name, std::shared_ptr<Function> decl);
		
        std::shared_ptr<Function> findFunction(std::string identifiant);
		
	protected:
		
		std::map<std::string, std::shared_ptr<Function> > scope; 
    };
}

#endif // FONCTIONSCOPE
