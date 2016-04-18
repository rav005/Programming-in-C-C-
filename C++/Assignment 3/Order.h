#include "EAN.h"

class Order {
	EAN orderedEAN;
	int noOrdered;
	int noDelivered;
public:
	Order();
	Order(const EAN& ean);
	EAN& getEAN();
	int outstanding() const;
	bool add(std::istream& is);
	bool add(int n);
	bool receive(std::istream& is);
	void display(std::ostream& os) const;
};
std::ostream& operator<<(std::ostream& os, const Order& order); 
