#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Stations.h"

using namespace w2;

Stations::Stations(char *f_name){

	if(f_name != nullptr){ //Reading data from file and creating Station objects...
		passes[0] = Student; //setting values to enum object...
		passes[1] = Adult;

		filename = f_name; //Saving filename so later on can write to the file...
		std::ifstream read(f_name);
		if(read.is_open()){

			char garbage;
			int count = 0; //To keep track at which index we are on Station list obj..
			read >> total >> garbage; //reading number from file...
			std::string nm; //Creating temp variable to store data...
			int num1, num2;

			locations = new Station[total];

			while(read.good()){
				read.seekg(2,std::ios::cur);
				std::getline(read,nm,';');
				read >> num1 >> num2; 
				locations[count].set(nm,num1,num2);
				count++;
			}	
		}
	}
}

void Stations::update() const{
	int stud, adu;
	
	std::cout << "\nPasses Sold :" << std::endl;
	std::cout << "-------------" << std::endl;

	for(int i=0; i < total; i++){
		std::cout << locations[i].getName() << std::endl; 
		std::cout << "Student Passes Sold : ";
		std::cin >> stud;
		stud -= stud * 2;
		locations[i].update(passes[0],stud);

		std::cout << "Adult   Passes Sold : ";
		std::cin >> adu;
		adu -= adu * 2;
		locations[i].update(passes[1],adu);    
	}
}

void Stations::restock() const{
		int stud, adu;
	
	std::cout << "\nPasses Added :" << std::endl;
	std::cout << "--------------" << std::endl;

	for(int i=0; i < total; i++){
		std::cout << locations[i].getName() << std::endl; 
		std::cout << "Student Passes Added : ";
		std::cin >> stud;
		locations[i].update(passes[0],stud); 

		std::cout << "Adult   Passes Added : ";
		std::cin >> adu;
		locations[i].update(passes[1],adu);  
	}
}

void Stations::report() const{
	std::cout << "\nPasses in Stock :  Student  Adult" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	
	for(int i=0; i < total; i++){
		
		std::cout << std::left << std::setw(17) << locations[i].getName(); 
		
		std::cout << std::right <<std::setw(9) << locations[i].inStock(passes[0]);

		std::cout << std::right << std::setw(7) << locations[i].inStock(passes[1]) << std::endl;

	}
}

Stations::~Stations(){ //Updating the file and Destroying dynamic allocated Stations.
	std::fstream write(filename, std::ios::out | std::ios::trunc | std::ios::binary);
	if(write.is_open()){
		write << total << ";" << "\r\n";

		for(int i=0; i < total; i++){
			write << locations[i].getName();
			write << ";" << locations[i].inStock(passes[0])
			<< " " << locations[i].inStock(passes[1]) << "\r\n";
		}
	}

	if(locations) delete [] locations;
}