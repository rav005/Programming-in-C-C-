/*  Student     : Gaurav Patel
    Description : Gets input from user and checks if it's valid. If it
            valid then it finds the Area, Publisher, Title of the EAN
            user has entered. It may not find Area, Publisher, Title if
            anyone of these aren't registered.
*/
#include <iostream>
using namespace std;

#include "a1main.h"
#include "EAN.h"
#include "GS1.h"

int main(){

    char ean[14];
    Prefix list;
    char area[6];
    char publisher[8];
    char title[7];
    bool check;

    cout << "EAN Processor\n";
    cout << "=============" << endl;
    cout << "Enter EAN no: " ;
    cin >> ean;
    
    do{
//Reads from file and saves data in struct prefix called list.
//isvalid function validates the user input according to EAN book rules.
        check = load(F_NAME,&list); 
            if(check == true){        
                check = isValid(ean);
                if(check == true){
/*If EAN is valid then then checks the recods of Prefix to determine
  to separates area, publisher, and title from ean if it's registered 
  and prints out area, publisher and title.
*/                  check = isRegistered(&list,ean,area,publisher,title);
                    if(check == true){ 
                        cout << "Area \t\t:" << area << endl;
                        cout << "Publisher \t:" << publisher << endl;
                        cout << "Title \t\t:" <<title << endl;
                    }
                }
            }
//This loop clears all the data in any array so it will be empty for next search.
            for(int m = 0; m < 14; m++){
                ean[m] = '\0';
                area[m] = '\0';
                publisher[m] = '\0';
                title[m] = '\0';
            }
        cout << endl; 
        cout << "EAN (0 to quit) : ";
        cin >> ean;
        }while(ean[0] != '0');
// exits the loop when user enters 0 and outputs exit message. 
    cout << endl;
    cout << "Signing off ..." << endl;
 
return 0;
}