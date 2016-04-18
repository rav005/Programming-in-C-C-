#include "a2main.h"
#include "EAN.h"
#include "gs1.h"
using namespace std;

EAN::EAN(){        //safe empty state for class.........
	dec = '-';
	ean[0] = '\0';
	area[0] = '\0';
	publisher[0] = '\0';
	title[0] = '\0';
	style_ean[0] = '\0';
}

bool EAN::read(std::istream& is, const Prefix& list){ //Gets user input and validates the input then calls constructor.
	bool see = false;
	int a = 1;
	EAN temp;
	do{	
		cout << "\nEAN (0 to quit) : ";
		is >> ean;
		see = isValid(ean);
		if(see == true || ean[0] - '0' != 0){
			a = 0;
		temp = EAN(ean,list);
		//cout << temp.ean << endl;    //for testing....
		}
		
	}while(a != 0);

	*this = temp;

return see;
}

EAN::EAN(const char* str, const Prefix& list){  //EAN constructor validates input then copies the input into the ean and calls
												//isRegister to extract area, publisher, title from user input.
	EAN temp;
	if(isValid(str)){
		strcpy(temp.ean,str);
		temp.isRegistered(list);
	}else
		EAN();
*this = temp;
}

bool isValid(const char* str){  //Function receives the user input and validates the user input........if valid return true, false otherwise...
	int a,b,c,d,e,f,last;
    bool ret,temp = true, chk = false;
    int total = 0;
    int m = 0;
    int length;

    if ((str) != NULL){ 
        length = strlen(str);
    }
    if(length == 13){
        if(str[0] - '0' == 9 && str[1] - '0' == 7 && str[2] - '0' == 8 || str[2] - '0' == 9){
			for(int z = 0; z < 13; z++){
                if(str[z] - '0' >= 0 && str[z] - '0' <= 9)
                    chk = true;
                else
                temp = false;
            }
        }else{
            ret = false;
            cout << "Invalid check digit. Try again." << endl;
        }

        if(chk == true){
            ret = true;
        }else{
            ret = false;
            cout << "Invalid check digit. Try Again." << endl;
        }
        
    }else{
        ret = false;
    }
   
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

	if(m == 0){
        ret = true;
    }else{ 
        ret = false;
        cout << "Invalid check digit. Try again." << endl;
    }

return ret;
}

bool EAN::isRegistered(const Prefix& list){   //Uses the user input from class ean and extracts the area, publisher, title using the gs1 file functions.
	bool check = false,chk = false;
    int trans, counter = 0, min_no = 0, m = 0, length = 0;
	
	if(isValid(ean)){

		for(int i=0;i<= 6;i++){
			area[i] = '\0';
		}
			do{ 
				area[counter] = ean[3 + counter];
				trans = atoi(area);
				check = list.isRegistered(trans);

				if(check == true){
					counter = 5;
				}
				counter++;
			}while(counter < 5);

			if(counter >= 5 && check == false){
				cout << "This EAN is not registered." << endl;
				for(int k = 0; k < 9; k++){
					area[k] = '\0';
				}
			}
		for(int i=0;i<= 8;i++){
			publisher[i] = '\0';
		}
			counter = strlen(area) + 3;
			if(check == true){
				min_no = list.minNoDigits(trans);
		
				do{
					publisher[m] = ean[counter + m];
					m++;
				if(m >= min_no){
					chk = list.isRegistered(trans,publisher);
				}if(chk == true){
					m = 8;
				  }
				}while(m < 8);

				if(chk = true){
					check = true;
				}
				else 
					check = false;
		for(int i=0;i<= 7;i++){
			title[i] = '\0';
		}
				if(check == true){
					m = strlen(area) + strlen(publisher) + 3;
					if(check == true){
						for(int z = 0; z < 7 && (m + z) < 12; z++){
							title[z] = ean[m + z];
						}
					}
				}
			}
	}
return check;
}

void EAN::style(char s){  //Receives user input for ean style they wish and puts that style in registerd ean's only...
	bool chk;
	char test[18];

		if(s == ' ' || s == '\n' || s == '-' ||s == '\0'){
				dec = s;
				if(area[0] != '\0')
					toStrWithStyle(test); //function call.................
				else 
					toStr(test);          //function call................
		}
		else{
			cout << "Invalid style Input! " << endl;
		}
	strcpy(style_ean,test); 
		
}

void EAN::toStrWithStyle(char* str) const{  //Uses the class variables and makes a style ean for out put........
	char wstyle[18];
	int index = 0;
	wstyle[0] = '\0';

		wstyle[0] = ean[0];
		wstyle[1] = ean[1];
		wstyle[2] = ean[2]; 
	wstyle[3] = '\0';
//cout << "1st three are : " << wstyle << endl; //END of 1st three.....................FOR TEST

		wstyle[3] = dec; 
	wstyle[4] = '\0';
		strcat(wstyle,area);

	index = strlen(wstyle);
	wstyle[index] = '\0';
//cout << "with area is : " << wstyle << endl; //END of area.........................FOR TEST

		wstyle[index] = dec;
	wstyle[index + 1] = '\0';

		strcat(wstyle,publisher);
	index = strlen(wstyle);
	wstyle[index] = '\0';
//cout << "with publisher is : " << wstyle << endl; //END of publisher......................FOR TEST

		wstyle[index] = dec;
	wstyle[index + 1] = '\0';

		strcat(wstyle,title);
	index = strlen(wstyle);
	wstyle[index] = '\0';
//cout << "with title is : " << wstyle << endl; //END of title..................................FOR TEST

		wstyle[index] = dec;
	wstyle[index + 1] = '\0';

		index = strlen(wstyle);
		wstyle[index] = ean[12];
	wstyle[index + 1] = '\0';
//cout << "last is : " << wstyle << endl; //END of last........................................FOR TEST

	strcpy((str),wstyle);

}

void EAN::toStr(char* str) const{ //for not Registered ean's it just copies the ean to str to return the value.....
	strcpy(str,ean);
}

bool EAN::isRegistered() const{ //This function checks if the EAN is registered or not. If yes retun true, false otherwise...
	if(area[0] != '\0' && publisher[0] != '\0' && title[0] != '\0'){
		return true;
	}
	else
		return false;
}

bool EAN::empty() const{ //Checks if the Object is in defalut state(safe empty state). If yes returns true, false otherwise..
	bool ret = true;

	if(ean[0] == '\0')
		ret = true;
	else
		ret = false;

return ret;
}

void EAN::display(std::ostream& os) const{ //Displays the ean with right justify by 18...
	os.width(18);
	os << right << style_ean << endl;

}