#include "Order.h"

Order::Order(){ //Safe-empty state constructor....
	noOrdered = 0;
	noDelivered = 0;
}

Order::Order(const EAN& ean){ //Constructor.....

	if(ean.empty() == false){
		orderedEAN = ean;
		noOrdered = 0;
		noDelivered = 0;
	}else{
		*this = Order();
	}
}

EAN& Order::getEAN(){ //return EAN object from Order class....
	
	return orderedEAN;
}

int Order::outstanding() const{ //returns the remaing books left to delivered for current object.....
	return noOrdered - noDelivered;
}

bool Order::add(std::istream& is){ //allows user to add/place valid number of order to exciting object if it's
									//not in safe-empty state....
	bool check = false;
	int neworder = 0;
	if(orderedEAN.empty() == false){
		do{ 
			std::cout << "Quantity (0 to quit) : ";
			is >> neworder;
			if(neworder > 0){
				noOrdered += neworder;
				neworder = 0;
				check = true;
			}else if(neworder < 0){
				std::cout << "Enter a positive number.  Try again." << std::endl;
			}else if(neworder == 0){
				std::cout << "**No delivery recorded!" << std::endl;
			}
		}while(neworder != 0);
	}else{
		std::cout << "Currrent object is EMPTY!" << std::endl;
	}

return check;
}

bool Order::add(int n){  //if orderedEAN is not in safe-empty state allows to add copy to order for orderedEAN....
	bool check = orderedEAN.empty();

	if(n > 0 && check == false){
		noOrdered += n;
		return true;
	}else
		return false;
}
bool Order::receive(std::istream& is){ //allows user to enter number book has delivered to current object also
									   //checks if it's valid or not, if it's not valid it keeps asking user...
	bool check = false;
	int deliver;

	do{
		std::cout << "Quantity (0 to quit) : ";
		is >> deliver;
		if(deliver > 0 && deliver <= outstanding()){
			noDelivered += deliver;
			check = true;
		}else if(deliver > outstanding()){
			std::cout << deliver << " not on order. Only " << outstanding() << " are remaining on order. Try Again" << std::endl;
		}else if(deliver == 0){
			std::cout << "**No delivery recorded!" << std::endl;
			check = true;
		}else if(deliver < 0){
			std::cout << "Enter a positive number.  Try again." << std::endl;
		}
	}while(check != true);

return check;
}

void Order::display(std::ostream& os) const{ //calls  EAN class operator and displays noOrdered and noDelivered............

	os << orderedEAN << setw(8) << right << noOrdered << setw(11) << right << noDelivered;
}

std::ostream& operator<<(std::ostream& os, const iOrder& order){ //helper function to help call display function for passed in object....

	order.display(os);
return os;
}

Order::Order(const Order& source){ //Copy constructor calls Assignment operator to copy the source value into current object......
	*this = source;
}
Order& Order::operator=(const Order& source){ //Order assignment operator= copies values from source Order into current object......
	orderedEAN = source.orderedEAN;
	noOrdered = source.noOrdered;
	noDelivered = source.noDelivered;
return *this;
}

Order::~Order(){ //Order Destructor Required for Special Order Dynamic memory deletation. iOrder needed to see that there is Order destructor to jump to.......
}