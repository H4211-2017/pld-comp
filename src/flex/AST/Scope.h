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
		Scope();
		
		Scope( std::shared_ptr<Scope> Scope );
		
		Scope(const Scope & Scope); // declared but not defined
		
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
         * @return a shared pointer on the variable in the scope, ends compilation if varaiable not found.
         */
        std::shared_ptr<AbstractVariable> findVariable(std::string identifiant);
        
        std::shared_ptr<AbstractVariable>* findVariableAddress(std::string identifiant);
        
        /**
         * @brief declareFunction adds a function to the dictionnary of the scope
         * @param identifiant the id of the function to add to the dictionary.
         * @param decl the function to add to the dictionary
         */
        void declareFunction(std::string identifiant, std::shared_ptr<Function> decl);
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
       			
       	IR::Generator &getGenerator();
	protected:
		//tree hierarchy
		std::shared_ptr<Scope> mother;
		
		VariableScope vScope;
        FunctionScope fScope;
        
    private:
       	IR::Generator generator;
    };
}

#endif // SCOPE
