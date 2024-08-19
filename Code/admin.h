#include<iostream>
#include<string>
#include<fstream>
#include <iomanip>
#include<stdlib.h>
using namespace std;

struct node
{
    string Flight_name,Flight_no,Flight_price,Flight_Departure,Flight_date,Flight_destination,Flight_location;
    struct node *next;
    struct node *prev;
}*start, *last;
int counter = 0;


class Admin {
	public:
		void main_menu();
		void Guest_menu();
  	node *create_node(string F_name,string F_no,string F_price,string F_dep,string F_date,string F_des,string F_loc);
        void insert_begin();
        void delete_flight();
        void search();
        void update();
        void display();
        void Guest_display();
        void reverse();
    
         Admin(){
		      start = NULL;
              last = NULL;	
		}
		
        
 void admin_menu() {	
		
	     system("CLS");
				cout<<"                                                                                                   \n\n\n";
	 cout<<"\t####################################################################################################\n";
	 cout<<"                                            ~AIRLINE RESERVATION SYSTEM~                             \n";
	 cout<<"\t####################################################################################################\n\n\n";
	cout<<endl;
			cout<<"                                                1. Add Flights"<<endl;
			cout<<"                                                2. Delete Flights"<<endl;
			cout<<"                                                3. Search Flights"<<endl;
			cout<<"                                                4. Update Flights:"<<endl;
			cout<<"                                                5. Display Flights "<<endl;
			cout<<"                                                6. Main Menu "<<endl;
			
			int menu;
			
			cout<<"Enter your choice:";
			cin>>menu;
				 switch(menu){
				case 1: {
					system("CLS");
					insert_begin();
		
					break;
				}
				case 2: {
					system("CLS");
					delete_flight();
					break;
				}
				case 3: {
					system("CLS");
				    search();
					break;
				}
				case 4: {
					system("CLS");
					update();
					break;
				}
				case 5: {
					system("CLS");
					display();
					break;
				}
				case 6: {
			   main_menu();
				   
				}
				
			}
		
		}
	int Admin_login()
{
    string name;
    string password;
    int login_Attempt = 0;

    while (login_Attempt < 5)
    {
        cout << "Please enter your user name: ";
        cin >> name;
        cout << "Please enter your user password: ";
        cin >> password;

        if (name == "admin" && password == "admin")
        {
            cout << "Welcome Admin\n";
            break;
        }
        else if (name == "nabeel" && password == "admin")
        {
            cout << "Welcome Nabeel!\n";
            break;
        }
        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            login_Attempt++;
        }
    }
    if (login_Attempt == 5)
    {
            cout << "Too many login attempts! The program will now terminate.";
            return 0;
    }

    cout << "Thank you for logging in.\n";
}
  void back(){
 int back;
    cout<<"Press 1 to return to menu\n"<<endl;
    cin>>back;
    if(back==1){
    	admin_menu();
    	
	}
	}
};

node* Admin::create_node(string F_name,string F_no,string F_price,string F_dep,string F_date,string F_des,string F_loc)
{
    counter++;  
    struct node *temp;
    temp = new(struct node);
    temp->Flight_name = F_name;
    temp->Flight_no = F_no;
    temp->Flight_price =F_price;
    temp->Flight_Departure = F_dep;
    temp->Flight_date = F_date;
    temp->Flight_destination = F_des;
    temp->Flight_location = F_loc;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void Admin::insert_begin()
{
    string fname,fno,fprice,fdep,fdate,fdes,floc;
    cout<<endl<<"Enter the Airline name: ";
    cin>>fname;
    cout<<endl<<"Enter the Flight number: ";
    cin>>fno;
    cout<<endl<<"Enter the Flight Fare: ";
    cin>>fprice;
    cout<<endl<<"Enter the Departure time: ";
    cin>>fdep;
    cout<<endl<<"Enter the Departure Date: ";
    cin>>fdate;
    cout<<endl<<"Enter the Flight Distination: ";
    cin>>fdes;
    cout<<endl<<"Enter the Flight current location";
    cin>>floc;
    struct node *temp;
    temp = create_node(fname,fno,fprice,fdep,fdate,fdes,floc);
    if (start == last && start == NULL)
    {    
        cout<<"Element inserted in empty list"<<endl;
        start = last = temp;
        start->next = last->next = NULL;
        start->prev = last->prev = NULL;
    }
    else
    {
        temp->next = start;
        start->prev = temp;
        start = temp;
        start->prev = last;
        last->next = start;
        cout<<"Element inserted"<<endl;
    }
     back();
}
void Admin::delete_flight()
{    
    int pos, i;
    node *ptr, *s;
    if (start == last && start == NULL)
    {
        cout<<"List is empty, nothing to delete"<<endl;
        back();
    }
    cout<<endl<<"Enter the postion of element to be deleted: ";
    cin>>pos;
    if (counter < pos)
    {
        cout<<"Position out of range"<<endl;
        back();
    }
    s = start;
    if(pos == 1)
    {
        counter--;
        last->next = s->next;
        s->next->prev = last;
        start = s->next;
        free(s);
        cout<<"Element Deleted"<<endl;
        back();  
    }
    for (i = 0;i < pos - 1;i++ )
    {  
        s = s->next;
        ptr = s->prev;    	  
    }    
    ptr->next = s->next;
    s->next->prev = ptr;
    if (pos == counter)
    {
        last = ptr; 	   
    }
    counter--;
    free(s);
    cout<<"Element Deleted"<<endl;
    back();
}

void Admin::update()
{
    int  i, pos;
    string fname,fno,fdeparture,fprice,fdate,floc,fdes;
  if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to update"<<endl;
        back(); 
    }
 else{
	
    cout<<endl<<"Enter the postion of node to be updated: ";
    cin>>pos;
    cout<<"Enter the new Flight Details: "<<endl;
    cout<<"Enter the Updated Flight name"<<endl;
    cin>>fname;
    cout<<"Enter the Updated Flight Number"<<endl;
    cin>>fno;
    cout<<"Enter the Updated Departure Time"<<endl;
    cin>>fdeparture;
    cout<<"Enter the Updated Price"<<endl;
    cin>>fprice;
    cout<<"Enter the Updated Date"<<endl;
    cin>>fdate;
    cout<<"Enter the Updated Destination"<<endl;
    cin>>fdes;
    cout<<"Enter the Updated Flight Location"<<endl;
    cin>>floc;
    
    struct node *s;
    if (counter < pos)
    {
        cout<<"Position out of range"<<endl;
        back();
    }
    else{
	
    s = start;  
    if (pos == 1)
    {
       s->Flight_name = fname;
       s->Flight_no = fno;
       s->Flight_Departure = fdeparture;
       s->Flight_price = fprice;
       s->Flight_date = fdate;
       s->Flight_destination = fdes;
       s->Flight_location = floc;
       cout<<"Flight Details Updated"<<endl; 
        back();
    }
    else{
	
    for (i=0;i < pos - 1;i++)
    {
        s = s->next; 		 
    }
       s->Flight_name = fname;
       s->Flight_no = fno;
       s->Flight_Departure = fdeparture;
       s->Flight_price = fprice;
       s->Flight_date = fdate;
       s->Flight_destination = fdes;
       s->Flight_location = floc;
    cout<<"Flight Details Updated"<<endl;
      back();
   }
  }
 }
}

void Admin::search()
{
    int pos = 0,  i;
    string value;
    bool flag = false;
    struct node *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to search"<<endl;
        back();
       
    }
    cout<<endl<<"Enter the value to be searched: ";
    cin>>value;
    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s->Flight_no == value)
        {
            cout<<"Element "<<value<<" found at position: "<<pos<<endl;
            flag = true;
        }    
        s = s->next;
    }
    if (!flag)
        cout<<"Element not found in the list"<<endl;
   back();
}
void Admin::Guest_display()
{
    int i;
    struct node *s;
    if (start == last && start == NULL)
    {
        cout<<"The List is empty, nothing to display"<<endl;
        cout<<"Enter 1 to go back\n"<<endl;
        int back1;
	    cin>>back1;
	    if(back1==1){
	    Guest_menu();
		}
        return;
    }
    s = start;
    for (i = 0;i < counter-1;i++)
    {	
        cout<<s->Flight_name<<"--"<<s->Flight_no<<"--"<<s->Flight_location<<"--"<<s->Flight_destination<<"--"<<s->Flight_date<<"--"<<s->Flight_Departure<<"--"<<s->Flight_price<<endl;
        s = s->next; 
    }
        fstream MyFile;
		MyFile.open("data.txt",ios_base::app);
		MyFile<<cout<<s->Flight_name<<"--"<<s->Flight_no<<"--"<<s->Flight_location<<"--"<<s->Flight_destination<<"--"<<s->Flight_date<<"--"<<s->Flight_Departure<<"--"<<s->Flight_price<<endl;
	    MyFile.close();
	    cout<<s->Flight_name<<"--"<<s->Flight_no<<"--"<<s->Flight_location<<"--"<<s->Flight_destination<<"--"<<s->Flight_date<<"--"<<s->Flight_Departure<<"--"<<s->Flight_price<<endl;
	    cout<<"Press 1 to go back\n"<<endl;
	    int back1;
	    cin>>back1;
	    if(back1==1){
	    Guest_menu();
		}
	    
	    
		
}
void Admin::display()
{
   	struct node *temp;
   	temp = start;
	if(temp == NULL){
	
	cout<<"Nothing to Display"<<endl;
	back();
}
	else
	{	int cnt = 1;
		cout << "\tNumber\t Flight Name\t Flight Number\t  Flight Location\t";
		cout << "Flight Destination\t Flight Date\t Flight Departure\t Flight Price\n"; 
		if(temp)

		while( temp!= last)	
		{
			cout << "\t" << cnt <<setw(15);//sets width
			cout << temp->Flight_name <<setw(16);
			cout << temp->Flight_no << setw(18);
			cout << temp->Flight_location<< setw(23);
			cout << temp->Flight_destination <<setw(25);
			cout << temp->Flight_date <<setw(20);
			cout << temp->Flight_Departure <<setw(20);
			cout << temp->Flight_price << "\n";
			// Move to next node
			temp=temp->next;
			cnt++;
		}
		    cout << "\n\n";
	}
	back();
}




