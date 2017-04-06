#ifndef OPTIONSCANNER_H
#define OPTIONSCANNER_H

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
		
		protected:
			void reset();
	};
}

#endif // OPTIONSCANNER_H
