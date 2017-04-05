#ifndef VARIABLESCOPE
#define VARIABLESCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

#include "AbstractNode.h"
#include "Value.h"

namespace AST{	
	
	class AbstractVariable;
	
	class UndeclaredIdException: public std::exception
	{
	public:
		/**
		 * @brief UndeclaredIdException constructor
		 */
        UndeclaredIdException();
        
        /**
		 * @brief UndeclaredIdException constructor
		 * @param text string the error message
		 */
        UndeclaredIdException(std::string text);
		
		/**
		 * @brief fetch Thrown value
		 * @return a char* c_string
		 */
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
		/**
		* @brief VariableScope constructor
		*/ 
		VariableScope();
	
		/**
		* @brief VariableScope destructor
		*/ 
		virtual ~VariableScope();

		/**
         * @brief declareVariable adds a variable to the dictionary
         * @param identifiant the id of the variable to add to the dictionary
         * @param variable the variable to add to the dictionary
         */
        void declareVariable(std::string identifiant, std::shared_ptr<AbstractVariable> variable);
        
        /**
         * @brief findVariable to find a variable in the scope.
         * @param identifiant the id of the variable to find.
         * @return a shared pointer on the variable in the scope, ends compilation if variable not found.
         */
        std::shared_ptr<AbstractVariable> findVariable(std::string identifiant);
        
        /**
         * @brief findVariable to find a variable in the scope.
         * @param identifiant the id of the variable to find.
         * @return a pointer on a shared pointer on the variable in the scope, ends compilation if variable not found.
         */
        std::shared_ptr<AbstractVariable>* findVariableAddress(std::string identifiant);
		
	protected:
		std::map< std::string, std::shared_ptr<AbstractVariable> > scope;
    };
}

#endif // VARIABLESCOPE
