#include <iostream>
#include <cstring>
#include "CString.h"

namespace w1{

	CString::CString(){
		words[0] = '\0';
	}

	CString::CString(const char* value){

		if(value[0] != '\0'){
			strncpy(words,value, MAX);
			words[MAX] = '\0';
		}else{
			*this = CString();
		}
	}

	void CString::disply(std::ostream& os) const{
		os << words;
	}

	std::ostream& operator<<(std::ostream& os, const CString& obj){
		obj.disply(os);

	return os;
	}
}
