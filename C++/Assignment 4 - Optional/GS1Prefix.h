const int MAX = 700; //Global variable for MAX use of data can be saved...

class Prefix { 
	int no;  //Saves total numbers read from file....
	int area[MAX]; //saves area read from file at indexes...
	char pubLow[MAX][8]; //saves minimum publisher point at area......
	char pubHgh[MAX][8]; //saves maximum publisher point at area......
	char pubLen[MAX]; //saves length of publisher.....
public:
	Prefix(); //Prefix safe empty safe Constructor......
	Prefix(const char* f); //receives filename, and reads data from file..... 
	bool isRegistered(int a) const; //receives area and checkes if the it exits in the Prefix object returns true if it does, false otherwise....
	int minNoDigits(int a) const; //returns pubLen for received area........
	bool isRegistered(int a, const char* p) const; //checks if received input matches with Prefix array, returns true if it does false otherwise....
};