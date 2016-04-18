#pragma once
#include <iostream>
#include <string>


template <class T, int N>
class List{
	T *list;
	int  count;
	int  capacity;

	public:
		List() {list = new T[N]; count = 0; capacity = N;}

		size_t size() const { return count; }

		int width() const {	int ret = 0; 
							for(int i=0; i < count; i++){
								if(list[i].width() > ret){
									ret = list[i].width();
								}
							}
							return ret;
		}

		const T& operator[](int i) const{ if (i >=0 && i < count) return list[i]; }

		void operator+=(const T& D) {if(count >= 0 && count < capacity) list[count++] = D;}
};
