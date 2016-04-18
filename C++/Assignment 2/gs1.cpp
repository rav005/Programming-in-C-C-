#include "a2main.h"
#include "EAN.h"
#include "gs1.h"

Prefix::Prefix(const char* f){ //Reading from Prefix file and saving it in to class Prefix...
	if (f != nullptr) {
         std::ifstream file(f);
         if (file.is_open()) {
             int num = 0;
             do {
                 file >> area[num] >> pubLow[num] >> pubHgh[num]; 
                 if (file.good()) {
                     pubLen[num] = std::strlen(pubLow[num]);
                     num++;
                 }
             } while (file.good());
             if (num > 0) {
                 no = num;
             }
         }
     }
}

bool Prefix::isRegistered(int a) const{ //Receives area and uses class prefix to see if area exits or not.....
										//If registered returns true, false otherwise......
	bool ret = false,temp = true;
    for(int i = 0; i <= 616; i++){
		if(area[i] == a){
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

}

int Prefix::minNoDigits(int a) const{ // Receives registered area and finds the minimun length for the area. returns minimum no..
	int no = 0;
	  for(int i = 0; i < 616; i++){   
        if(area[i] == a){
            no = pubLen[i];
            i = MAX;
        }
    }
return no;
}

bool Prefix::isRegistered(int a, const char* p) const{	//Matches the area then checks if publisher is equal to or in between
														//pubLow or pubHgh. If yes then returns true, false otherwise.
	int x = 0, y = 0, z = 0;
    bool check = false, real = false;
	
	for(int i = 0; i < MAX; i++){
        if(area[i] == a){
           if(strlen(p) == strlen(pubLow[i])){ 
				x = atoi(p);
				y = atoi(pubLow[i]);
				z = atoi(pubHgh[i]);
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
}