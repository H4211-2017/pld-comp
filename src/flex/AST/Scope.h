#ifndef SCOPE_H
#define SCOPE_H

#include <memory>
#include <string>
#include <exception>

#include "Variable/VariableScope.h"
#include "Function/FunctionScope.h"

#include "../../IR/generator/Generator.h"

namespace AST
{	
	class AbstractExpression;

	class Scope
	{
	public:
	
		/**
		 * @brief default Scope constructor, used for global Scope building,
		 * 		add putchar and getchar as functions declarations in the global scope 
		 * 		of all compiled programs
		 */
		Scope();
		
		/**
		 * @brief Scope constructor
		 * @param scope a shared_ptr to the mother scope
		 */
		Scope( std::shared_ptr<Scope> scope );
		
		/**
		 * @brief Scope destructor
		 */
		virtual ~Scope();
		
        /**
         * @brief declareVariable adds a variable to the scope, with testing
         * 		if variable not already declared. Ends compilation if variable
         * 		already defined.
         * @param identifiant the id of the variable to add to the scope
         * @param variable the variable to add to the scope
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
        
        /**
         * @brief declareFunction adds a function to the dictionnary of the scope,
         * 		with testing if function already declared : ends compilation if
         * 		fuction already declared.
         * @param identifiant the id of the function to add to the dictionary.
         * @param decl the function to add to the dictionary
         */
        void declareFunction(std::string identifiant, std::shared_ptr<Function> decl);
        
        /**
         * @brief findVariable to find a function in the scope.
         * @param identifiant the id of the function to find.
         * @return a shared pointer on the function in the scope, ends compilation if function not found.
         */
        std::shared_ptr<Function> findFunction(std::string identifiant);
		
        /**
         * @brief getMother
         * @return the mother scope of this scope, which is the larger scope
         */
		std::shared_ptr<Scope> getMother() const;
         
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
        FunctionScope fScope;
    };
}

#endif // SCOPE_H
