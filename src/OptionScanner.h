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
            std::string execTarget = "";
            std::string astTarget = "";
            std::string asmTarget = "a.s";
			bool verbose = false;
            bool deleteAsm = true;
			IR::OptimisationLevel optimisationLevel = IR::OptimisationLevel::O0;
		
		protected:
			void reset();
	};
}

#endif // OPTIONSCANNER_H
