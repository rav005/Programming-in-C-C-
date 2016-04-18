#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#include "GS1.h"

//Function which reads from file and puts the data in Prefix *p struct.
bool load(const char* filename, Prefix* p) {
     bool rc = false;
     if (filename != nullptr) {
         std::ifstream file(filename);
         if (file.is_open()) {
             int no = 0;
             do {
                 file >> p->area[no] >> p->pubLow[no] >> p->pubHgh[no]; 
                 if (file.good()) {
                     p->pubLen[no] = std::strlen(p->pubLow[no]);
                     no++;
                 }
             } while (file.good());
             if (no > 0) {
                 rc = true;
                 p->no = no;
             }
         }
     }
     return rc;
}//END of load function.

bool isRegistered(const Prefix* p, int area){
    bool ret = false,temp = true;
/* Reads Prefix struct until it matches the area.
    if area matches returns true otherwise return false.
*/    for(int i = 0; i <= p->no - 1; i++){
		if(p->area[i] == area){
            ret = true;
            i = MAX;    
        }
        else
            temp = false;
    }
    
    if(ret == true){
        return ret;
    }
    else 
        return temp;

}//END of isRegistered function.

int minNoDigits(const Prefix* p, int area){
    int no = 0;
/* Reads through the Prefix struct and if area matches
  it passes minimum length required for publisher.
*/    for(int i = 0; i < p->no; i++){   
        if(p->area[i] == area){
            no = p->pubLen[i];
            i = MAX;
        }
    }
return no;
}//End of minNoDigits function.

bool isRegistered(const Prefix* p, int area, const char* publisher){
    int x, y,z;
    bool check;
    bool real = false;
/*Matches the area then checks if publisher is equal
 to or in between pubLow or pubHgh. If yes then 
 returns true else return false.
*/  for(int i = 0; i < MAX; i++){
        if(p->area[i] == area){
           if(strlen(publisher) == strlen(p->pubLow[i])){ 
            x = atoi(publisher);
            y = atoi(p->pubLow[i]);
            z = atoi(p->pubHgh[i]);
            if(x >= y && x <= z){
                real = true;
                i = MAX;
			}
			}
		}
	}
    if(real == true){
        return real;
    }else
        return check;
}//END of isRegistered function.
