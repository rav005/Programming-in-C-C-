#include <iostream>
#include <string>
#include "Stations.h"


w2::Station::Station(){
	name = '\0';
	student = 0;
	adult = 0;
}

void w2::Station::set(const std::string& nm, unsigned stud, unsigned adu){

	if(nm[0] != '\0'){
		name = nm;
		student = stud;
		adult = adu;
	}else
		*this = Station();
}

const std::string& w2::Station::getName() const{
	return name;
}

void w2::Station::update(PassType n, int value){
	if(n == Student){
		student += value;
	}else if(n == Adult){
		adult += value;
	}else
		std::cout << "Provided PassType member doesn't exist." << std::endl;
}

unsigned w2::Station::inStock(PassType n) const{
	unsigned int ret = 0;
	if(n == Student || n == Adult){
		if(n == Student)
			ret = student;
		else if(n == Adult)
			ret = adult;
	}
	return ret;
}
