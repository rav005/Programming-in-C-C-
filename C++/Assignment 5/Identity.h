#pragma once
#include <iostream>
#include "Object.h"

class Identity : public Object{

	public:
		void set(List<NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT>list) { }; //assigns values to data members -no data member for Identity class
		const std::string getDSV(char c = VALUE_DELIMITER) const { return ""; } //returns the values of the data members delimied by char c - no data to return
		~Identity() { }; //Identity destructor - no data member to destroy
};

std::ostream& operator<<(std::ostream& os, const Identity& src) {  return os; } //Displays Identity class information - no data for identity class
