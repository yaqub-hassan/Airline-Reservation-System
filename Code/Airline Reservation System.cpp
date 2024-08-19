#include<iostream>
#include<string>
#include <fstream>
#include "guest.h"
using namespace std;

void Admin::main_menu(){
 	Admin a;
	User u;	
	Guest g;
	
	system("CLS");
	cout<<"                                                                                                   \n\n\n";
	cout<<"\t####################################################################################################\n";
    cout<<"                                            ~AIRLINE RESERVATION SYSTEM~                             \n";
	cout<<"\t####################################################################################################\n\n\n";
	cout<<endl;
	cout<<"                                                 1. USER PANEL \n";
	cout<<"                                                 2. ADMIN PANEL\n";
	cout<<"                                                 3. GUEST\n";
	cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<endl;
	
   int select;
   
	cout<<"Please enter your choice:";
	cin>>select;
	system("CLS");
	
	switch(select) {
		
	 	case 1:
			cout<<"\n                                 User Panel Has Been Selected.\n\n";
			if(u.Logged_In()){
				system("CLS");
				menu();	//calling the menu function.
	            seat_fill();	// initialize seat array.
			}
			break;
		
		case 2:
			cout<<"\nPlease enter your credentials to access admin panel.\n\n";
                if(a.Admin_login()){
                	a.admin_menu();
				}
				else{
					cout<<"Incorrect Password";
					break;
				}
		case 3:
		a.Guest_menu();
		break;		
				
		
		default:	
			break;
		
	}
  }	
int main(){
	Admin a;
	a.main_menu();
	
}
	
 


		







