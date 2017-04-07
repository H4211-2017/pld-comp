#ifndef OPTIONSCANNER_H
#define OPTIONSCANNER_H

#include "IR/config/Enums.h"

namespace lake
{
	
	class OptionScanner
	{
		public:
			
			OptionScanner();
			virtual ~OptionScanner();
			
			void parseConsoleOptions(int argc, char *argv[]);
			void printOptions();//for debugging purposes
			
			std::string srcFile = "";
			std::string target = "";
			std::string ASTtarget = "";
			bool verbose = false;
			IR::OptimisationLevel optimisationLevel = IR::OptimisationLevel::O0;
		
		protected:
			void reset();
	};
}

#endif // OPTIONSCANNER_H
