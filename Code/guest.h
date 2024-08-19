#include<iostream>
#include<string>
#include <fstream>
#include "user.h"
using namespace std;

class Guest: public User{
	public:
	Admin a;
	User u;

};
void Admin :: Guest_menu(){
	system("CLS");
	cout<<"                                                                                                   \n\n\n";
	cout<<"\t####################################################################################################\n";
	cout<<"                                            ~AIRLINE RESERVATION SYSTEM~                             \n";
	cout<<"\t####################################################################################################\n\n\n";
	cout<<endl;
	cout<<"                                                 1. Display Flights\n";
	cout<<"                                                 2. Register\n";
	cout<<"                                                 3. Main menu\n";
	cout<<"Enter your choice\n"<<endl;
	int choice;
	cin>>choice;
	switch(choice){
		case 1:
			a.Guest_display();
			break;
		case 2:
		   u.user_register();
			break;	
		case 3:
		    a.main_menu();
		    break;
		
				
	}
}


