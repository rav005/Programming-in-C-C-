#include <iomanip>
#include <string>
#include "Product.h"

namespace w7{
	Product::Product(){
		number = 0;
		price = 0.00;
	}

	Product::Product(int n, double p){
		if(n > 0 && p > 0){
			number = n;
			price = p;
		}else{
			std::cerr << "Product number or price must be positive and above 0.\n";
		}
	}

    double Product::getPrice() const{
		return price;
    }

    void Product::display(std::ostream& os) const{
		os << std::setw(10) << number << std::setw(10) << price;
    }

	TaxableProduct::TaxableProduct(char t, int n, double p) : Product(n, p){
		if(t == '\0' || t == 'H' || t == 'P'){
			type_tax = t;
		}else{
			std::cerr << "Incorrect type of tax provided.";
		}
	}

    double TaxableProduct::getPrice() const{
		double price = Product::getPrice();

		if(type_tax == 'H'){
			price = price * H_TAX;
		}else if(type_tax == 'P'){
			price = price * P_TAX;
		}

		return price; 
    }
    void TaxableProduct::display(std::ostream& os) const{
		Product::display(os);

		if(type_tax == 'H'){
			os << " HST";
		}else if(type_tax == 'P'){
			os << " PST";
		}
    }

    std::ostream& operator<<(std::ostream& os, const iProduct& product){
		product.display(os);
		return os;
    }

    iProduct* readProduct(std::ifstream& in){
		iProduct* ret = nullptr;
		
		if(in.is_open()){
			std::string line;

			if(!in.eof()){
				getline(in, line);
				std::string product; 
				std::string price;
				char tax = 'N';
				int total_pos = 0;
				
				int pos = line.find_first_of(' ');
				product = line.substr(0, pos);
				pos++;
				total_pos += pos;

				line = line.substr(pos);
				pos = line.find_first_of(' ');
				price = line.substr(0, pos);
				

				if(line.length() >= 1){
					pos++;
					total_pos += pos;
					line = line.substr(pos);
					tax = line[0];
				}

				int obj_num = atoi(product.c_str());
				double obj_price = atof(price.c_str());
				char obj_tax = 'N';

				if(obj_num > 0 && obj_price > 0){
					if(tax == 'H' || tax == 'P'){
						obj_tax = tax;
						ret = new TaxableProduct(tax, obj_num, obj_price);
					}else{
						ret = new Product(obj_num, obj_price);
					}
				}//closing if(obj_num > 0 && obj_price > 0)
			}//closing if(!in.eof())
		}//closing is(in.is_open())
		return ret;
	}
}
