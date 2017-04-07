#ifndef FONCTIONSCOPE
#define FONCTIONSCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

namespace AST
{	
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
		
		/**
		 * @brief FunctionScope default constructor
		 */
        FunctionScope();
				
		/**
		 * @brief FunctionScope destructor
		 */
        virtual ~FunctionScope();
		
		/**
         * @brief declareFunction adds a function to the dictionnary of the FunctionScope
         * @param identifiant the id of the function to add to the dictionary.
         * @param decl the function to add to the dictionary
         * @remark ends the compilation if the function is already defined in this scope or
         * one of its ancestors
         */
        void declareFunction(std::string name, std::shared_ptr<Function> decl);
		
		/**
         * @brief findVariable to find a function in the scope.
         * @param identifiant the id of the function to find.
         * @return a shared pointer on the function in the scope, ends compilation if function not found.
         */
        std::shared_ptr<Function> findFunction(std::string identifiant);
		
	protected:
		
		std::map<std::string, std::shared_ptr<Function> > scope; 
    };
}

#endif // FONCTIONSCOPE
