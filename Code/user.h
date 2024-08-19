#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>//used this for setw , to set width to make the display better.
#define size 100
#include"Admin.h"
using namespace std;

class User:public Admin{
public:
	User();	// constructor function
	void main_menu();	 //Menu function.
	void make_reservation();	// To make reservation.
	void cancel_reservation();	//To cancel reservation.
	void search_passenger();	//to search a passenger and print info.
	void change_reservation();	//To change reservation.
	void print_list();	 //To print the passenger list.
	void print_report();	 //To print the status report.
	void user_register();    //to register user
	bool Logged_In();        // to check if user logged in
	
		
private:
	struct node
	{
		string fname, lname, ID, phone_num, menu;
		int reserve_num, seat_num;
	

		node *next;

	}; 
	
	node *start;
		
	node *temp, *temp2;
	


			
			
		
};
Admin a;
User u;
int reserve = 9999;
	bool User :: Logged_In(){
	string username, password, name, ps;
	
	cout<<"Enter Username: ";
	cin>>username;
	cout<<"Enter Password: ";
	cin>>password;
	ifstream myFile;
	myFile.open("login.txt");
	getline(myFile,name);
	getline(myFile,ps);
	
	
	if(name == username && ps == password){
		return true;
	}else{
		return false;
	}
}
void User :: user_register(){
	int option;

	cout<<"1: Register"<<endl<<"Your Choice: ";
	cin>>option;
	if(option == 1){
		string username, password;

		cout<<"Select a Username: ";
		cin>>username;
		cout<<"Select a Password: ";
		cin>>password;

		ofstream MyFile;
		MyFile.open("login.txt");
		MyFile<<username<<endl<<password;
		MyFile.close();
		int back;
		cout<<"Enter 1 to return to menu\n"<<endl;
		cout<<"Head over to the User panel and login \n"<<endl;
		cin>>back;
		if(back==1){
		system("CLS");
		a.Guest_menu();
		
	}else{
		cout<<"Error!\n"<<endl;
	}

		
	}else {
		cout<<"Error!"<<endl;
	}
}


int seat[size];
void seat_fill()
{	
	for (int i = 0; i < size; i++)
	{
		seat[i] = 0;
	}
}

bool taken=false;
bool seat_no(int y)
{
	
        for (int i = 0; i < size; i++ ) //loop checks if the seat is taken or not.
        {
                if( seat[i] == -1 )
                {
				taken=true;
  	                 cout << "The seat is taken already. \n";
                        cout << "Please choose another seat number from below."<<endl;
			
				int j = 1;
				while ( j < size+1 )
				{
					if ( seat[j-1] == -1)
					j++;
					else
					{	
						cout <<"|" << j << "|";
						if ( j%10 == 0 )
						cout << endl;
						j++;	
					}	
						
                		}
		}			
		
        }

} // this will print the available seat numbers only




void menu()
{
int choice;

do{
	cout<<"                                                                                                   \n\n\n";
	cout<<"\t####################################################################################################\n";
    cout<<"                                            ~AIRLINE RESERVATION SYSTEM~                             \n";
	cout<<"\t####################################################################################################\n\n\n";
	cout<<endl;
	cout<<"                                                 1. Make Reservation         \n";
	cout<<"                                                 2. Cancel Reservation       \n";
	cout<<"                                                 3. Search Passenger         \n";
	cout<<"                                                 4. Change Seat Reservation  \n";
	cout<<"                                                 5. Print a List             \n";
	cout<<"                                                 6. Print status             \n";
	cout<<"                                                 7. Main Menu                \n";
	cout<<"\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd";
	cout<<endl; 
    cout<<"--------------------";
    cout<<"\n Choice:";
	
	cin >> choice;
	switch (choice)	 
	{
	case 1: 
    	system("CLS"); 
        u.make_reservation();
		break;
	case 2: 
	    system("CLS"); 
	    u.cancel_reservation();
		break;	
	case 3: 
	    system("CLS"); 
        u.search_passenger();
		break;
	case 4: 
	    system("CLS"); 
	    u.change_reservation();
		break;
	case 5: 
	    system("CLS"); 
	    u.print_list();
		break;
	case 6: 
	     system("CLS"); 
	     u.print_report();
		break;
	case 7: 
	     a.main_menu(); 
   		break;

	default: cout<<" Error\n\n";
		break;
		
								
	}	
	
		
	
	cin.get();
	if(cin.get()=='\n')
		system("CLS");
	 
		
 }while(choice != 7 );

}	

User::User()	//Constructor sets the pointer to null.
// initalizing pointers
{
	start = NULL;
}

void User:: make_reservation()	 //This function makes reservation.
{ 	
	int meal_choice, x;
		

	temp = new node;	//adding new nodes.

	cout<<"\n\nEnter First Name of person: ";
	cin>>temp->fname;

	cout<<"Enter Last Name of Person: ";
	cin>>temp->lname;

	cout<<"Enter CNIC of the person: ";
	cin>>temp->ID;

	cout<<"Enter Phone Number of Person: ";
	cin>>temp->phone_num;

	do{
	cout << "Please Enter the Seat Number: ";

		cin>>x;
		while(x>size){
		cout<<"   Try again:: ";
		cin >>x;
		}
		

	cout<<"--------------------------------\n";
		if((seat[x-1])>-1) 	// if seat value is 0 and more than it's is empty
		taken = false;
		else 
		seat_no(x);	// if taken print available seat from another function
	seat[x-1] = -1;	// make current seat unavailable as -1 value representation
	temp->seat_num = x;
	
	}while(taken==true);



	// prints the menu list and prompts to make a choice.

		cout << "Please Enter Your Menu Preference from below: \n\n";
		cout << "   1. Veg            \n";
		cout << "   2. Non-Veg        \n";
		cout << "   3. No meal      \n\n";

		cout <<"   Your Choice :: ";
		cin >> meal_choice;

		while(meal_choice>3 || meal_choice<1){
		cout<<"   Try Again:: ";
		cin>>meal_choice;
		}

		if (meal_choice == 1)
		temp->menu = "veg";
	
		else if (meal_choice == 2)
		temp->menu = "Non-Veg";
	
		else 
		temp->menu = "No meal";
		
			

	
	reserve++;   
	temp->reserve_num=reserve;
	cout <<"\n******************************************************************\n";
	cout << "YOUR RESERVATION NUMBER IS :: " << reserve << "\n\n";
	cout << "Please show this number at the time of boarding \n";
	cout <<"********************************************************************\n";

	temp->next = NULL;

	if(start == NULL)
		start = temp;
	else
	{
		temp2 = start;
		while (temp2->next != NULL)
		{  
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}

} 
int cancel=0;
void User:: cancel_reservation()	//This function cancels reservation.
{	int num;
	cout << "Please Enter your reservation Number here: ";
	cin >> num;

		node *cur = start;
		if(cur!=NULL)
		{ 

		if ( start->reserve_num == num )	//first node.
		{
			node *del = start;
			start = start->next;
			delete del;
			seat[0] = 0;
			cancel++;
			return;
		}
		else
		{
			node *pre, *cur; 	//To delete a middle or last node.
			pre = start;
			cur = start->next;
			while(cur != NULL)
			{
				if ( cur->reserve_num == num )
						break;
				pre = cur;
				cur = cur->next;
			}
			seat[cur->seat_num-1] = 0;	
			if (cur != NULL )
			pre->next = cur->next;
				
		}

	cancel++;
	

		}
		else
		{
		cout<<"No Reservations to delete \n"<<endl;
		}
	
}

void User:: search_passenger()	//This function helps to search a passenger
{//either by first name
		string fakename;
		cout << "Please enter your first name here: ";
		cin >> fakename;
	
		node *cur = start;
		while (cur != NULL)
		{
			if (cur->fname == fakename) //found
			{
				cout << "First Name : " << cur->fname << endl;
				cout << "Last Name : " << cur->lname << endl;
				cout << "ID " << cur->ID << endl;
				cout << "Phone number: " << cur->phone_num << endl;
				cout << "seat Number: " << cur->seat_num << endl;
				cout << "Reservation No. " << cur->reserve_num<< endl;
				return;
			}	cur = cur->next;
		}	cout << " NOT FOUND!!! \n\n";
	
}
	
void User:: change_reservation()	//This function helps to upgrade class or seats.
//or to make more reservations.
{
	int option , next_seat;	
	cout << " Please enter your seat number: ";
	cin >> option;
	node *cur;
	cur = start;

	while(cur != NULL)
	{
		if ( cur->seat_num == option )
			break;
		cur = cur->next;
	}			
	cout << "Please choose another seat number from below.";
		int j = 1;
		while ( j < size+1 )
		{
			if ( seat[j-1] == -1)
			j++;
			else
			{	
			cout <<"| " << j << "|";//prints the seats
			if ( j%10 == 0 )
			cout << endl;
			j++;	
			}
		}	
	cin >> next_seat;
	seat[cur->seat_num-1]=0;
	cur->seat_num = next_seat;
	seat[next_seat-1] = -1;

}


void User:: print_list()	 //This function prints the list of the passengers.
{
	temp=start;
	if(temp == NULL)
	cout<<" End of lists"<<endl;
	else
	{	int cnt = 1;
		cout << "\tNumber\t First Name\t Last Name\t CNIC\t";
		cout << "Phone Number\t seat Number\t Reservation No\t Menu\n"; 

		while(temp != NULL)	// will run untill temp is not equal to null
		{
			cout << "\t" << cnt <<setw(15);//sets width
			cout << temp->fname <<setw(15);
			cout << temp->lname << setw(12);
			cout << temp->ID << setw(20);
			cout << temp->phone_num <<setw(15);
			cout << temp->seat_num <<setw(18);
			cout << temp->reserve_num <<setw(12);
			cout << temp->menu << "\n";
			// Move to next node
			temp=temp->next;
			cnt++;
		}
		cout << "\n\n";

	}
}

void User:: print_report()	 //This function prints the status report of the flight.
{	int count = 0;
	for (int i =0; i < size; i++ )
	{
		if (seat[i] == -1)
			count++;
	}
	cout<<" Seats Reserved: " << count <<endl;
	cout<<" Cancellations : " << cancel <<endl;
}









