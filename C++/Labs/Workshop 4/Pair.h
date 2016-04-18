#pragma once
#include <iostream>
#include <string>

template <class A, class B>
class Pair{
	A obj1;
	B obj2;

	public:
		Pair() {};
		Pair(const A& aa, const B& bb) :obj1(aa), obj2(bb) {}
		const A& first() const { return obj1; }
		const B& second() const{ return obj2; }
		int width() const { return obj1.size(); }
};
