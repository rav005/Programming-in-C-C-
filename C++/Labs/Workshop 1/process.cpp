#include <iostream>
#include "CString.h"


void process(char *arg){

/*FOR TESTING...	
	std::cout << "words are: " << words << std::endl;
	for(int i=0; i < words; i++)
	std::cout << "parameter is : " << para[i] << std::endl;
*/
	w1::CString obj(arg);
	
	std::cout << obj << std::endl;
}