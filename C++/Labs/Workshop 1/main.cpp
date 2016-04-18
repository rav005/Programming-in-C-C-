#include <iostream>
#include "CString.h"
#include "process.h"
using namespace w1;

int main(int argc, char *argv[]){
	
	if(argc > 1){
		std::cout << "Maximum number of characters stored : " << MAX << std::endl;
		for(int i=1; i < argc; i++){
			std::cout << i - 1 << ": ";
			process(argv[i]);
		}
	}else
		std::cout << "Insufficient number of arguments (min 1)." << std::endl;
	
return 0;
}