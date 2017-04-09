#include <iostream>
#include <cstring>

#include "OptionScanner.h"

using namespace lake;

OptionScanner::OptionScanner()
{
	srcFile = "";
    execTarget = "";
    astTarget = "";
	verbose = false;
}

OptionScanner::~OptionScanner(){}


/* *************************
 *  	Public Methods	   *
 * *************************/

/**
 * @brief : OptionScanner::parseConsoleOptions parses the command line options and
 * 		modifies the instance's attributes to translate the parsed options.
 *  Command line accepted : lake [-v] [-On] [-o <nameExec>] [-S <nameAsm>] [-t <printASTfile>] [srcFile].
 *  Any order could be used.
 * @param argc the count of arguments taken (taking in account that the call to the 
 * 		compiler itself is considered an argument)
 * @param argv the list of arguments
 */
void OptionScanner::parseConsoleOptions(int argc, char *argv[])
{
    if( argc > 10 )
	{
		std::cerr << "ERROR : Too many arguments" << std::endl;
		exit(-1);
	}

    for(int i = 1; i<argc; i++)
	{
		if(strcmp(argv[i], "-o") == 0)
		{
			i++;
            if(i == argc || argv[i][0] == '-' || strcmp(argv[i], "") == 0)
			{
				std::cerr << "ERROR : no target defined" << std::endl;
				exit(-1);
			}
            execTarget = argv[i];
		}
        else if(strcmp(argv[i], "-S") == 0)
		{
			i++;
            if(i == argc || argv[i][0] == '-' || strcmp(argv[i], "") == 0)
			{
				std::cerr << "ERROR : no AST-target defined" << std::endl;
				exit(-1);
			}
            asmTarget = argv[i];
            deleteAsm = true;
		}
        else if(strcmp(argv[i], "-t") == 0)
        {
            i++;
            if(i == argc || argv[i][0] == '-' || strcmp(argv[i], "") == 0)
            {
                std::cerr << "ERROR : no AST-target defined" << std::endl;
                exit(-1);
            }
            astTarget = argv[i];
        }
		else if(strcmp(argv[i], "-v") == 0)
		{
			verbose = true;
		}
		else if(strcmp(argv[i], "-O0") == 0)
		{
			optimisationLevel = IR::OptimisationLevel::O0;
		}
		else if(strcmp(argv[i], "-O1") == 0)
		{
			optimisationLevel = IR::OptimisationLevel::O1;
		}
		else if(strcmp(argv[i], "-O2") == 0)
		{
			optimisationLevel = IR::OptimisationLevel::O2;
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
		std::cout << "Source File : " << srcFile << std::endl;
    if( execTarget.length() > 0 )
        std::cout << "Built File : " << execTarget << std::endl;
    if( astTarget.length() > 0 )
        std::cout << "Source File : " << astTarget << std::endl;
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
    execTarget = "";
    astTarget = "";
	verbose = false;
	optimisationLevel = IR::OptimisationLevel::O0;
}
