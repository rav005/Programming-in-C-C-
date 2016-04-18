const int MAX = 700;

class Prefix {
	int no;
	int area[MAX];
	char pubLow[MAX][8];
	char pubHgh[MAX][8];
	char pubLen[MAX];
public:
	Prefix();
	Prefix(const char* f);
	bool isRegistered(int a) const;
	int minNoDigits(int a) const;
	bool isRegistered(int a, const char* p) const;
};