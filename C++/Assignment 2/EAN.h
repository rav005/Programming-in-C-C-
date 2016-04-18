#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Prefix;

class EAN{
	char dec;
	char ean[14];
	char area[6];
	char publisher[8];
	char title[7];
	char style_ean[18];
public:
	EAN();
	EAN(const char* str, const Prefix& list);
	bool read(std::istream& is, const Prefix& list);
	bool isRegistered(const Prefix& list);
	bool empty() const;
	bool isRegistered() const;
	void style(char);
	void toStr(char* str) const;
	void toStrWithStyle(char* str) const;
	void display(std::ostream& os) const;
};
bool isValid(const char* str);
