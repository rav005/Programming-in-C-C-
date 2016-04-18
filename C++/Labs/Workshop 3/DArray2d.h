#include <iostream>

namespace w3{
	class DArray2d{
		int rows;
		int columns;
		double **arr;
	public:
		DArray2d(); //Constructor
		DArray2d(int row, int col); //Two argument Constructor
		~DArray2d(); //Destructor
		DArray2d(DArray2d& that); //Copy Constructor
		DArray2d& operator=(DArray2d& that); //Copy Assignment operator
		DArray2d(DArray2d&& that); //Move Constructor
		DArray2d& operator=(DArray2d&& that); //Move Assignment operator
		double check() const; //returns the average of arr variable
	};
}
