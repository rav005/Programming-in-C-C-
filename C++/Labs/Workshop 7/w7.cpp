// Workshop 7 - STL Containers
// w7.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"

int main(int argc, char** argv) {
    std::cout << "\nCommand Line : ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    // open a product file - name is the first command line argument 
    std::ifstream in(argv[1]);

	// declare an STL container to hold the entries on file
	std::vector<w7::iProduct*> container;

	if(in.is_open()){

		// read each record and move it to the container - catch any exception
		do{
			w7::iProduct* temp = w7::readProduct(in);
			if(temp != nullptr){
				container.push_back(temp);
			}
		}while(!in.eof());
	}else{
		std::cerr << "\n****Unable to open the file.****\n";
	}

    // total the product prices including any taxes
    double total = 0.0;
    std::cout << "\nProduct No     Price Taxable\n";
    std::cout << std::fixed << std::setprecision(2);
    // retrieve the price for each product in turn

	for(int i = 0; i < container.size(); i++){
		std::cout << *container[i] << std::endl;
		total += container[i]->getPrice();
	}

    // display total
    std::cout << "     Total";
    std::cout << std::setw(10) << total << std::endl;

    std::cout << "\nPress any key to continue ... ";
    std::cin.get();
}
