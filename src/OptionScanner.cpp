#include <iostream>
#include <cstring>

#include "OptionScanner.h"

using namespace lake;

OptionScanner::OptionScanner()
{
	srcFile = "";
	target = "";
	ASTtarget = "";
	verbose = false;
}

OptionScanner::~OptionScanner(){}


/* *************************
 *  	Public Methods	   *
 * *************************/

/**
 * @brief : OptionScanner::parseConsoleOptions parses the command line options and
 * 		modifies the instance's attributes to translate the parsed options.
 * @param argc the count of arguments taken (taking in account that the call to the 
 * 		compiler itself is considered an argument)
 * @param argv the list of arguments
 */
void OptionScanner::parseConsoleOptions(int argc, char *argv[])
{
	int i = 1;
	if( argc > 7 )
	{
		std::cerr << "ERROR : Too many arguments" << std::endl;
		exit(-1);
	}
	for(; i<argc; i++)
	{
		if(strcmp(argv[i], "-o") == 0)
		{
			i++;
			if(i == argc || argv[i][0] == '-')
			{
				std::cerr << "ERROR : no target defined" << std::endl;
				exit(-1);
			}
			target = argv[i];
		}
		else if(strcmp(argv[i], "-t") == 0)
		{
			i++;
			if(i == argc || argv[i][0] == '-')
			{
				std::cerr << "ERROR : no AST-target defined" << std::endl;
				exit(-1);
			}
			ASTtarget = argv[i];
		}
		else if(strcmp(argv[i], "-v") == 0)
		{
			verbose = true;
		}
		else
		{
			srcFile = argv[i];
		}
	}
	
}


/**
 * @brief : OptionScanner::printOptions print the current value of the instance's attributes
 */
void OptionScanner::printOptions()
{
	if( srcFile.length() > 0 ) 
		std::cout << "Fichier Source : " << srcFile << std::endl;
	if( target.length() > 0 ) 
		std::cout << "Fichier Construit : " << target << std::endl;
	if( ASTtarget.length() > 0 ) 
		std::cout << "Fichier Source : " << ASTtarget << std::endl;
	if( verbose ){
		std::cout << "Verbose Enabled" << std::endl;
	} else {
		std::cout << "Verbose Disabled" << std::endl;
	}	
}

/* *************************
 *  Protected Methods	   *
 * *************************/

/**
 * @brief : OptionScanner::reset reset the instance's attributes to their default values
 */
void OptionScanner::reset()
{
	srcFile = "";
	target = "";
	ASTtarget = "";
	verbose = false;
}
