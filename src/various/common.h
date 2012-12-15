


















// How to output colour to stdout:
#define bash_red "\e[0;31m";
#define bash_RED "\e[1;31m";
#define bash_yellow "\e[0;33m";
#define bash_YELLOW "\e[1;33m";
#define bash_blue "\e[0;34m";
#define bash_BLUE "\e[1;34m";
#define bash_cyan "\e[0;36m";
#define bash_CYAN "\e[1;36m";
#define bash_NC "\e[0m"; // No Color



/** Macro generates coloured output with file and line number */
#define WARN(TO_COUT)  {std::string strfile(__FILE__);\
	strfile = strfile.substr(strfile.rfind('/')+1, std::string::npos);\
	std::cout<<"\e[0;33mWarning: "<<strfile<<":"<<__LINE__<<" - "<<	TO_COUT << "\e[0m" << std::endl;}

/** Macro generates coloured output with file and line number and then aborts program */
#define ERROR(TO_COUT)  {std::string strfile(__FILE__);\
	strfile = strfile.substr(strfile.rfind('/')+1, std::string::npos);\
	std::cout<<"\e[0;31mERROR: "<<strfile<<":"<<__LINE__<<" - "<<	TO_COUT << "\e[0m" << std::endl;\
	abort();}
