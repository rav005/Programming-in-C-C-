#include <iostream>
#include <cstring>
using namespace std;
#include "GS1.h"
#include "EAN.h"

//This function validates EAN number according to the rules of EAN
// and returns if it is valid(true) or not(false).
bool isValid(const char* str){
    int a,b,c,d,e,f,last;
    bool ret,temp = true, chk = false;
    int total = 0;
    int m;
    int length;

    if ((str) != NULL){ //If length of EAN is 13 then it goes in.
        //Requires first 3 characters as 978 or 979.
        length = strlen(str);
    }
    if(length == 13){
        if(str[0] - '0' == 9 && str[1] - '0' == 7 && str[2] - '0' == 8 || str[2] - '0' == 9){
            //Checks if all the characters are numbers or not if they 
            //aren't then it will return false.
            for(int z = 0; z < 13; z++){
                if(str[z] - '0' >= 0 && str[z] - '0' <= 9)
                    chk = true;
                else
                temp = false;
            }
        }else{//If first 3 digits are invalid then it changes return
            //value to false and output message.
            ret = false;
            cout << "Invalid check digit. Try again." << endl;
        }
        //Checks if any EAN number was character or not, if it is 
        //then it will set return value to false and outputs message.
        if(chk == true){
            ret = true;
        }else{
            ret = false;
            cout << "Invalid check digit. Try Again." << endl;
        }
        
    }else{//If there aren't 13 characters in EAN the return 
        // value changes to false.
        ret = false;
    }
    //If return value is true then it calculates the if the EAN is 
    // valid or not.
    if(ret == true){
        a = (str[1] - '0') * 3;
        b = (str[3] - '0') * 3;
        c = (str[5] - '0') * 3;
        d = (str[7] - '0') * 3;
        e = (str[9] - '0') * 3;
        f = (str[11] - '0') * 3;
        last = str[12] - '0';
        
        total = a + b + c + d + e + f + last;
        total += ((str[0]-'0')+(str[2]-'0')+(str[4]-'0')+(str[6]-'0')+(str[8]-'0')+(str[10]-'0'));
        m = total % 10;
    }
    //If the remainder is 0 then the number is valid so return 
    // value changes to true, if it isn't then return value
    // changes to false and outpt's message.
    if(m == 0){
        ret = true;
//cout << "passed all  the calculation" << endl;
    }else{ 
        ret = false;
        cout << "Invalid check digit. Try again." << endl;
    }

return ret;
}

int isRegistered(const Prefix* p, const char* str, char area[], char publisher[], char title[]){

    bool check = false,chk = false;
    int trans;
    int counter = 1;
    int min_no = 0;
    int m = 0;

for(int s = 0; s < 8; s++){
    area[s] = '\0';
    publisher[s] = '\0';
    title[s] = '\0';
}

//For isRegistered function with 2 parameters.

/*Will add 1 number to area array and passes the value 
to isRegistered so it can match area code from ean no.
*/    do{ 
		area[counter - 1] = str[2 + counter];
		trans = atoi(area);
        check = isRegistered(p,trans);
        if(check == true){
            counter = 6;
        }
        counter++;
    }while(counter < 6);

    if(counter >= 6 && check == false){
        cout << "This EAN is not registered." << endl;
        for(int k = 0; k < 9; k++){
            area[k] = '\0';
        }
    }

//For minNoDigits funtion and isRegistered for publisher
counter = strlen(area) + 3;
int length = 0;

	if(check == true){
			min_no = minNoDigits(p, trans);
/*	minNoDigits will get the minimum digits required for 
  publisher and will check if it's valid when publisher has 
  minNodigits in array after that it checks publisher until 
  it when chk is not true or length is 7.
*/		do{
				publisher[m] = str[counter + m];
				m++;
				if(m >= min_no){
					chk = isRegistered(p,trans,publisher);
				}if(chk == true){
					m = 8;
				}
		}while(m < 8);

		if(chk = true){
			check = true;
		}
		else 
			check = false;

		if(check == true){

	//This is to extract title from ean no. 
	/*  This will keep track of all the numbers used in ean and
		after it will copy all other numbers except the last one.
	*/  m = strlen(area) + strlen(publisher) + 3;
			if(check == true){
				for(int z = 0; z < 7 && (m + z) < 12; z++){
					title[z] = str[m + z];
				}
			}
		}
	}
return check;
}//END of isRegistered function.
