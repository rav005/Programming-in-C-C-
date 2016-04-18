#include <iostream>
#include <cstdlib>
#include <memory>
#include "DArray2d.h"

using namespace w3;

DArray2d::DArray2d(){ //Constructor
	rows = 0;
	columns = 0;
	arr = nullptr;
}
DArray2d::DArray2d(int row, int col){ //Two argument Constructor
std::cout << "\nIn D2Array2d(int,int) function..." << std::endl;
	if(row > 0 && col > 0) {
		rows = row;
		columns = col;
		arr = new double*[rows];
		for(int i=0; i < rows; i++){
			arr[i] = new double[columns];
			for(int m=0; m < columns; m++){
				arr[i][m] = rand()/(double)RAND_MAX;
			}
		}
	}else{
		std::cout << "\nProvied row or column is set to zero so, 2D array cannot be created." << std::endl;	  
	}
}

DArray2d::~DArray2d(){ //Destructor

	if(arr != nullptr)
		delete [] arr;
}

DArray2d::DArray2d(DArray2d& that){ //Copy Constructor
std::cout << "\nIn D2Array2d(DArray& that) Copy Constructor function..." << std::endl;
	arr = new double*[rows];
	for(int i=0; i < rows; i++){
		arr[i] = new double[columns];
		for(int m=0; m < columns; m++){
			arr[i][m] = that.arr[i][m];
		}
	}
}

DArray2d& DArray2d::operator=(DArray2d& that){ //Copy Assignment operator
std::cout << "\nIn D2Array2d(DArray2d& that) Copy Assignment operator function..." << std::endl;
	if(this != &that){
		rows = that.rows;
		columns = that.columns;
		arr = new double *[rows];

		for(int i=0; i < rows; i++){
			arr[i] = new double[columns];
			for(int m=0; m < columns; m++){
				arr[i][m] = that.arr[i][m];
			}
		}
	}
return *this;
}

DArray2d::DArray2d(DArray2d&& that){ //Move Constructor
std::cout << "\nIn D2Array2d(DArray2d&& that) Move operator function..." << std::endl;
	if(that.rows > 0 && that.columns > 0){
		rows = that.rows;
		columns = that.columns;
		arr = that.arr;
		that.arr = nullptr;
	}else{
		std::cout << "\nPassed in object is not 2-dimension." << std::endl;
	}
}

DArray2d& DArray2d::operator=(DArray2d&& that){ //Move Assignment operator
std::cout << "\nIn D2Array2d(DArray2d&& that) Move Assignment operator function..." << std::endl;
	if(this != &that){
		if(arr != nullptr){
			delete [] arr;
		}
		rows = that.rows;
		columns = that.columns;
		arr = that.arr;
		that.arr = nullptr;
	}

return *this;
}

double DArray2d::check() const{ //returns the average of arr variable
	double sum = 0.0;

   	if(arr){
		for(int r=0; r < rows; r++){
			for(int c=0; c < columns; c++){
				sum += arr[r][c];
			}
		}
	}else{
		std::cout << "\nCalled sum of zombie object/variable." << std::endl;
	}
return sum/(rows*columns);
}
