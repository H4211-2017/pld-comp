#ifndef SCOPE
#define SCOPE

#include <memory>
#include <string>
#include <exception>

#include "Variable/VariableScope.h"
#include "Function/FunctionScope.h"

#include "../../IR/generator/Generator.h"

namespace AST{	
	
	class AbstractExpression;

	class Scope
	{
	public:
	
		/**
		 * @brief Scope constructor
		 */
		Scope();
		
		/**
		 * @brief Scope constructor
		 * @param scope a shared_ptr to the mother scope
		 */
		Scope( std::shared_ptr<Scope> scope );
		
		/**
		 * @brief Blocking the copy constructor
		 */
		Scope(const Scope & scope); // declared but not defined
		
		/**
		 * @brief Scope destructor
		 */
		virtual ~Scope();
		
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
        
        /**
         * @brief declareFunction adds a function to the dictionnary of the scope
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
         * @return  the mother of this scope, is the larger scope
         */
		std::shared_ptr<Scope> getMother() const;

        /**
         * @brief setMother to change the mother scope
         * @param newMother the new mother scope
         */
		void setMother(std::shared_ptr<Scope> newMother);
       	
       	/**
       	 * @brief Deprecated Function
       	 * 
       	 * TODO DELETE
       	 */
       	IR::Generator &getGenerator();
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
        FunctionScope fScope;
        
    private:
       	IR::Generator generator; //TODO Deprecated attribute
    };
}

#endif // SCOPE
