#ifndef FONCTIONSCOPE
#define FONCTIONSCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

namespace AST{	
	
	class Fonction;
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


	class FonctionScope
	{
	public:
		FonctionScope();
		
		FonctionScope( const FonctionScope & fonctionScope); // declared but not defined
		
		virtual ~FonctionScope();
		
        void declareFonction(std::string name, std::shared_ptr<Fonction> decl);
		
        std::shared_ptr<Fonction> findFonction(std::string identifiant);
		
	protected:
		
		std::map<std::string, std::shared_ptr<Fonction> > scope; 
    };
}

#endif // FONCTIONSCOPE
