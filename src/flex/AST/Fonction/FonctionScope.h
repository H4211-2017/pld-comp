#ifndef FONCTIONSCOPE
#define FONCTIONSCOPE

#include <memory>
#include <map>
#include <string>
#include <exception>

namespace AST{	
	
	class Block;
	class DeclarationFonction;
	class ListArg;
	
	class UndeclaredIdException: public std::exception
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
		
        void declareFonction(std::shared_ptr<DeclarationFonction> decl, std::shared_ptr<Block> bloc);
		
        std::shared_ptr<Block> findVariable(std::string identifiant, std::shared_ptr<ListArg> args);
		
		std::shared_ptr<FonctionScope> getMother() const;
		
	protected:
		//tree hierarchy
		std::shared_ptr<FonctionScope> mother;
		
		std::map<std::pair<std::string,  std::shared_ptr<ListArg> args> decl, std::shared_ptr<Block> > scope; // TODO définir la clé de la map
    };
}

#endif // FONCTIONSCOPE
