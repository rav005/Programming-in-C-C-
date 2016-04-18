#pragma once
#include <iostream>
#include "iProduct.h"
#define H_TAX 1.13
#define P_TAX 1.08

namespace w7{

    class Product : public iProduct{
        int number;
		double price;

        public:
			Product(); //constructor...
			Product(int, double); //constructor...
            double getPrice() const; //returns price...
            void display(std::ostream&) const; //to display...
    };

    class TaxableProduct : public Product{
        char type_tax;

        public: 
			TaxableProduct(char, int, double); //Constructor, calls base class constructor..
            double getPrice() const; //returns price with tax..
            void display(std::ostream&) const; //to display..
    };
}
