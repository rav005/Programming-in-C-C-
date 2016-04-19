#pragma once
#include "Object.h"

class Course : public Object{ //Course class with it's data members
	std::string name; 
	std::string CPA; 
	std::string BSD;

	public:
		void set(List<NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT> list) { //assigns values to the data members from List
			for(int i=0; i < list.size(); i++){
                if(list[i].name() == "name"){
                    name = list[i].value();
                }
				if(list[i].name() == "CPA"){
                    CPA = list[i].value();
                }
				if(list[i].name() == "BSD"){
                    BSD = list[i].value();
                }
			}
		}
		
        const std::string getDSV(char c = VALUE_DELIMITER) const { //returns the values of the data members delimied by char c 
            return name + c + CPA + c + BSD;
		}

		const std::string getName() const{ return name; } //returns Name to help display Course class data
		const std::string getCPA() const{ return CPA; } //returns CPA to help display Course class data
		const std::string getBSD() const{ return BSD; } //returns BSD to help display Course class data
};

std::ostream& operator<<(std::ostream& os, const Course& src){ //Displays Passed in Course data members organized
	std::string name = src.getName();
	std::string CPA = src.getCPA();
	std::string BSD = src.getBSD();

	os << "Name  " << name << "\nCPA   " << CPA << "\nBSD   " << BSD << std::endl;
	return os;
}
