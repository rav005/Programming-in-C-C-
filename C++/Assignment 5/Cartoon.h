#pragma once
#include "Object.h"

class Cartoon : public Object{ //Cartoon class with it's data members
	std::string type;
	std::string name;
	std::string likes;

	public:
		void set(List<NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT>list) { //assigns values to the data members from List
			for(int i=0; i < list.size(); i++){
			   if(list[i].name() == "type"){
                    type = list[i].value();
                }
                if(list[i].name() == "name"){
                    name = list[i].value();
                }
                if(list[i].name() == "likes"){
                    likes = list[i].value();
                }
            }
		}
	
		const std::string getDSV(char c = VALUE_DELIMITER) const { //returns the values of the data members delimied by char c
            std::string out;
            out = type + c + name + c + likes;
            
            return out;
        }

		const std::string getType() const { return type; } //returns Type to help display Course class data
		const std::string getName() const { return name; } //returns Name to help display Course class data
		const std::string getLikes() const { return likes; } //returns Likes to help display Course class data
};

std::ostream& operator<<(std::ostream& os, const Cartoon& src){ //Displays Passed in Cartoon data members organized
    std::string type = src.getType();
	std::string name = src.getName();
	std::string like = src.getLikes();

	os << "type  " << type << "\nname  " << name << "\nlike  " << like << std::endl;
	return os;
}
