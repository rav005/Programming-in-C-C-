#pragma once
#include <iostream>
#include <string>

//#define DATA_MEMBERS_PER_OBJECT 5
//#define VALUE_DELIMITER ','

template <typename T, int N>
class List{ //List class with it's data members
	T* list;
	int index;
	int capacity;

	public:
		List() { list = new T[N]; //Constructor - creates dynamically allocated list using template values
				 index = 0; 
				 capacity = N;
				}
		size_t size() const { return index; } //returns amount of size used from list
		const T& operator[](int i) const {	if (i >=0 && i < index) 
											return list[i]; //returns value saved in table at provided index
										 }
		void operator+=(const T& D){	if(index >= 0 && index < capacity) 
										list[index++] = D; //Adds data to list
								   }
		void operator+=(const T&& D) { if(index < capacity){ //Moves data to list
                                        list[index++] = D;
									  }else{
											std::cerr << "Not enough space to move another NVPair\n";
										}
									 }
};
