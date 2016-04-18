#pragma once
#include <iostream>
#include <string>

template <typename A, typename B>
class NVPair{ //NVPair class with it's data members
	A n_name;
	B n_value;
	
	public:
		NVPair() { }; //Constructor - does nothing
		NVPair(const A& a, const B& b) : n_name(a), n_value(b) { } //Constructor - assigns value to data members
		const A& name() const { return n_name; }  //Returns unmodifiable referance of n_name data member 
		const B& value() const { return n_value; } //Returns unmodifiable referance of n_value data member 
};
