#ifndef FONCTIONSCOPE
#define FONCTIONSCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

namespace AST{	
	
	class DeclarationFonction;
	class ListArg;
	
	class UndeclaredIdFctException: public std::exception
	{
	  virtual const char* what() const throw()
	  {
		return "Error : Undeclared Function Identifier";
	  }
		
	};


	class FonctionScope
	{
	public:
		FonctionScope();
		
		FonctionScope( std::shared_ptr<FonctionScope> fonctionScope );
		
		FonctionScope( const FonctionScope & fonctionScope); // declared but not defined
		
		virtual ~FonctionScope();
		
        void declareFonction(std::string name, std::shared_ptr<DeclarationFonction> decl);
		
        std::shared_ptr<DeclarationFonction> findFonction(std::string identifiant, std::shared_ptr<ListArg> args);
        
        void setFonction(std::string identifiant, std::shared_ptr<DeclarationFonction> decl);
		
	protected:
		
		std::multimap<std::string, std::shared_ptr<DeclarationFonction> > scope; // TODO définir la clé de la map
    };
}

#endif // FONCTIONSCOPE
