//Aproximate numbers of data in file.
const int MAX = 700;

//Struct to put the data from the file that holds records.
struct Prefix {
    int no;
    int area[MAX];
    char pubLow[MAX][8];
    char pubHgh[MAX][8];
    int pubLen[MAX];
};

//Reads from file and put's the data in the prifix struct.
bool load(const char* filename, Prefix* p);

//To check if area is valid or not.
bool isRegistered(const Prefix* p, int area);

//To get mininum length required for publisher using area found in record.
int minNoDigits(const Prefix* p, int area);

//Uses the passed publisher number to see if matching area has that publisher.
bool isRegistered(const Prefix* p, int area, const char* publisher);


