#include <cstring>
#include "Order.h"

iOrder::~iOrder(){ //iOrder Destructor Required so it goes to Special Order destructor........
}
SpecialOrder::SpecialOrder(){ //Safe-empty state for SpecialOrder........
	instructions = nullptr;
}

SpecialOrder::~SpecialOrder(){ //SpcialOrder destructor to delete dynamic memory and then nullptr the variable......
	delete [] instructions;
	instructions = nullptr;
}

SpecialOrder::SpecialOrder(const EAN& isbn, const char* instr) : Order(isbn){ //Special Order constructor sends Ean object to Base class Order Construcor and 
																			  //dynamically allocate special instructions to order......
	if(strlen(instr) > 0){
		instructions = new char [strlen(instr) + 1];
		strcpy(instructions,instr);
	}else{
		instructions = nullptr;
	}
}

bool SpecialOrder::add(std::istream& is){ //Add functions calls Base class Order funtion to receive number of orders to place and if it's successfull it
										  //allows user to enter new instructions to Order and returns true if it's successfully added, false otherwise.....
	bool check = false;
	char temp[60];

	if(Order::add(is) == true){
		is.ignore();
		std::cout << "Instructions : ";
		is.getline(temp,60);
		if(temp[0] != '\0' || temp[0] != ' '){
			if(instructions != nullptr){
				delete [] instructions;
				check;
			}
			instructions = new char[strlen(temp) + 1];
			strcpy(instructions,temp);
			check = true;
		}else{
			check = false;
		}
	}

return check;
}

void SpecialOrder::display(std::ostream& os) const{ //Display function calls Base class Order display then includes special instructions of the order to it......
		Order::display(os);
		os << " " << instructions;
}

SpecialOrder::SpecialOrder(const SpecialOrder& source){  //Copy Constructor which nullptr the new pointer variable then call's assignment operator 
														 //to copy all variables to current one from source.......
	instructions = nullptr;
	*this =  source;
}
SpecialOrder& SpecialOrder::operator=(const SpecialOrder& source){ //SpecialOrder assignment operator= does deep and shadow copy from passed in object
																   // to current variable.......
	if(this != &source){
		Order::operator=(source);
		if(instructions != nullptr)
		delete [] instructions;

		if(source.instructions != nullptr){
			instructions = new char[strlen(source.instructions) + 1];
			strcpy(instructions, source.instructions);
		}else{
			instructions = nullptr;
		}
	}
return *this;
}