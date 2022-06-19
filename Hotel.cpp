#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include <iomanip>
#include<fstream>
using namespace std;


class Exception;
class Customer;
class RoomCustomer;
class Employee;
class Dish;
class RestaurantCustomer;
class Restaurant;
class Hotel;
class Room;
class RoomService;


class Exception
{
	public:
		int errNo;
		string msg;
		
	public:
		Exception(int errNo,string msg)
		{
			this->errNo=errNo;
			this->msg=msg;
		}
		
		void what()
		{
			cout<<"\t\t"<< errNo<<" :: "<< msg<<endl;
		}
};


class Room
{
	public:
		string roomType;
		int noOfBeds;
		double rent;
		int roomNo;
		int status;


	public:
		Room(string roomType,int noOfBeds,double rent,int roomNo )
		{
			this->roomType=roomType;
			this->noOfBeds=noOfBeds;
			this->rent=rent;
			this->roomNo=roomNo;
			this->status=0;
						
		}
		
		
		void setRoom()
		{
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Enter Room Type, No of beds, Rent, RoomNo   |\n";
			cin>>this->roomType;
			cin>>this->noOfBeds;
			cin>>this->rent;
			cin>>this->roomNo;
			status=0;
			
		}
		
			
		Room()
		{
		}


		bool isVacant(Room r)
		{
			if(r.status==1)
			return false;
			else 
			return true;
		}
		
			
		void displayDetail()
		{
			
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Room Type :   "<<this->roomType<<endl;
			cout<<" \n\n\t\t\t\t\t\t\t|   Number of Beds :   "<<this->noOfBeds<<endl;
			cout<<" \n\n\t\t\t\t\t\t\t|   Rent :   "<<this->rent<<endl;
			cout<<" \n\n\t\t\t\t\t\t\t|   Room Number :   "<<this->roomNo<<endl;
			if(status==1)
			cout<<"  \n\n\n\t\t\t\t\t\t\t|   Occupied   | \n";
			else
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Vacant   | \n";
		}
		
		void vacateRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(this->roomNo==rno)
			this->status=0;
		}
		}
		
			
		void displayAvailable(Room r[6])
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(r[i].status==0)
				r[i].displayDetail();
			}
		}
		
};



class Dish
{
	public:
		string dishName;
		double price;
		string dishType;
		
	
	public:
		Dish(string dishName,double price,string dishType)
		{
			this->dishName=dishName;
			this->price=price;
			this->dishType=dishType;
		}
		Dish()
		{
		    
		}
};

	
class Customer
{
	public:
		string custName;
		string custAddress;
		string custID;
		long int custPhone;
		string custEmail;
		string checkInTime;
		int status;


	public:
		Customer()
		{
			time_t c=time(0);
	        string dt = ctime(&c);
			this->custName=" ";
			this->custAddress =" ";
			this->custID =" ";
			this->custPhone = 0L;
			this->custEmail =" ";
			this->checkInTime = dt;
			status=0;
		}
		
	void setData()
		{
			time_t now=time(0);
			string dt = ctime(&now);
			this->checkInTime = dt;
			ofstream customer;
			customer.open("Customer.txt",ios::ate);
			cout<<"\n\t\tEnter Your Name :\n";
			cin>>this->custName;
			customer << "Name ::"<< this->custName<<"\n";
			
			cout<<"\n\t\tEnter Your Address :\n";
			cin>>this->custAddress;
   			customer<< "Address ::"<< this->custAddress<<"\n";
			
			cout<<"\n\t\tEnter Your Phone Number :\n";
			cin>>this->custPhone;
			customer << "Phone ::"<< this->custPhone<<"\n";
			
			cout<<"\n\t\tEnter Your Email :\n";
			cin>>this->custEmail;
			customer << "Email ::"<< this->custEmail<<"\n\n";
			customer.close();
			
		}

		int selectChoice()
		{
			int ch;
			cout<<" Hello!\n";
			cout<<"Enter \n1. Accomodation \n 2. Dine\n ";
			cin>>ch;
			return ch;
		}
		
		
		virtual void printCustomer()
		{
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Name :   "<<this->custName<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   Address :   "<< this->custAddress<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   ID :   " <<custID<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   Phone Number :   "<< custPhone<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   Email :   "<<custEmail<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   Check-In Time :  "<<this->checkInTime<<endl;
			
 		} 
		virtual void viewTotalBill(){
		}
		virtual void allocateRoom(Room r1){
		}
		virtual void allocateDish(Dish d1){
		}
		virtual void checkout(){
		}
};

class RoomCustomer : public Customer
{
	public:
		double rbill;
		Room r;
		int bookStatus;
	public:
		
		void viewTotalbill()
		{
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Bill =   "<<rbill;
		}
		
		void allocateRoom(Room r1)
		{
			this->r=r1;
		}


		void printCustomer()
		{		
				
				Customer :: printCustomer();
				if(r.status==1 && bookStatus==1)
				
				{
				cout<<" \n\n\n\t\t\t\t\t\t\t|   Check-In Time :   "<< checkInTime<<endl;
				cout<<" \n\t\t\t\t\t\t\t|   Room type :   "<<r.roomType<<endl;
				cout<<" \n\t\t\t\t\t\t\t|   Room Number :   "<<r.roomNo<<endl;
				
		}}
		
			void viewTotalBill()
		{
			this->rbill=r.rent;
			cout<<" \n\n\t\t\t\t\t\t\t|   Charge :   "<<this->rbill<<endl;
		}
		void checkOut()
		{
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Your Charge is :   "<<this->rbill<<"/-"<<endl;
			this->rbill=0;
			this->r.status=0;
				cout<<" \n\n\t\t\t\t\t\t\t|   Thank You !!!   |  \n\n\t\t\t\t\t\t\t|   Visit Again !!! |\n"<<endl;
			
		}
		
			
};

class RestaurantCustomer:public Customer
{
	public:
		double dbill;
		Dish d;
		int orderStatus;
	public:
		
		void viewTotalbill()
		{
			cout<<" \n\n\t\t\t\t\t\t\t|   Charge =   "<<dbill;
		}
		
		 void allocateDish(Dish d1)
		 {
		 	this->d=d1;
		 }
		 
		 
		void printCustomer()
		{		
				
				Customer :: printCustomer();
				if(orderStatus )
				{
				cout<<" \n\n\t\t\t\t\t\t\t|   Dish Name :   "<<d.dishName<<endl;
				cout<<" \n\t\t\t\t\t\t\t|   Dish Type :   "<<d.dishType<<endl;
				
				}}

		void viewTotalBill()
		{
			this->dbill=d.price;
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Charge :   "<<this->dbill<<endl;
		}
			
};


class Employee
{
	
	public:
		
	
		virtual void performDuty()=0;
		virtual ~Employee(){
		}
};


class RoomService:public Employee
{
	public:
		void performDuty()
		{
		cout<<" \n\n\t\t\t\t\t|   Employee LapZ Arriving At Your Doorstep.   |\n\n";
		}
		
		virtual ~RoomService(){
		}

};


class Waiter:public Employee
{
	public:
		void performDuty()
		{
			
			cout<<"\n\n \n\n\t\t\t\t\t|   Employee LapZ Arriving At Your Table To Take Your Order.   |\n\n";
			
		}
		virtual ~Waiter(){
		}
};


class SelectEmployee{
	
	Employee *e;
	
	public:
		SelectEmployee(Employee *e1)
		{
			e=e1;
		}
		
		void performDuty()
		{
			e->performDuty();
		}
	
};


class Restaurant
{
	public:
		Dish dish[8];
	
	public:
		void addDishes()
		{
			ofstream menu;
			menu.open("Menu.txt",ios::ate);
			int i;
			for(i=0;i<8;i++)
			{
				cout<<i+1<<"]  \n\n\n\t\t\t\t\t|   Enter Dish Name Price and Type :   \n";
				cin>>dish[i].dishName>>dish[i].price>>dish[i].dishType;
				menu<< dish[i].dishName<<"\t"<<dish[i].price<<"\t"<<dish[i].dishType<<"\n";
			}
			menu.close();
		}
		
	
			Dish getDish(string dnam)
		{
			int i;
			for(i=0;i<8;i++)
			{
				
				if(dish[i].dishName==dnam)	
						
				{
					return dish[i];
				}
		}
	}
	
		
			void displayDish(Dish d)
		{
			cout<<"  \n\n\n\t\t\t\t\t\t\t|   Dish Name :   "<<d.dishName<<endl;
			cout<<"  \n\t\t\t\t\t\t\t|   Price :   "<<d.price<<endl;
			cout<<"  \n\t\t\t\t\t\t\t|   Dish Type :   "<<d.dishType;
			
		}
		
	
		void displayMenu()
		{
			int i;
			for(i=0;i<8;i++)
			{
				displayDish(dish[i]);
			}
			
		}
	
};


class Hotel
{
	private:
		static Hotel *instanceHotel;
		string hotelName;
		string hotelAddress;
	public:
		Employee *employee[5];
		Restaurant restuarant;
		
		Room room[6];
		Customer *customer[5];
		
			
	private: 
			
		
		Hotel(string hname,string add)
		{
			this->hotelName=hname;
			this->hotelAddress=add;
		}

	public:
		static Hotel* getHotel()
		{
			if(!instanceHotel)
			instanceHotel=new Hotel("RENNAISSANCE","HUBLI");
			return instanceHotel;
		}


		void setHotel(Restaurant r,Room rs[6])
		{
			int i;
			
			for(i=0;i<6;i++)
			{
				this->room[i]=rs[i];
			}
			for( i=0;i<8;i++)
			this->restuarant.dish[i]=r.dish[i];
			
		}
		
		
		void generateID(Customer *c)
		{
			time_t t;
			static const char m[]="abcdefghijklmnopqrstuvwxyz";
			int i;
			
			for(i=0;i<6;i++)
			{
				c->custID=c->custID+ m[rand() % (sizeof(m)- 1)];
			}
			
		}

		Room getRoom(int rno)
		{
			int i;
			for(i=0;i<6;i++)
			{
				if(room[i].roomNo==rno)
				return room[i];
			}
		}


void displayAvailble(){
	 	int i;
	 	cout<<"\n\n\t\t\t<================================   Room   Details   ===========================>\n\n\n";
	 	
	
	 	cout<<setw(26)<<"Room Type"<<setw(29)<<"Number of Beds"<<setw(20)<<"Rent"<<setw(30)<<"Room Number\n";
			for(i=0;i<6;i++)
			{
				if(room[i].status==0)
				{
					cout<<setw(25)<<room[i].roomType;
					cout<<setw(25)<<room[i].noOfBeds;
					cout<<setw(25)<<room[i].rent;
					cout<<setw(25)<<room[i].roomNo<<"\n";
				}
			}
			cout<<"\n\n";
	 }
	 
	 
	 void displayMenu()
	 {
	 	cout<<"\n\n\t\t\t<===============================  Menu   ==========================>\n\n\n ";
	 		int i;
	 		const int width=8;
	 		cout<<setw(30)<<" Dish Name"<<setw(32)<<"Price"<<setw(34)<<"Dish Type"<<endl;
			for(i=0;i<8;i++)
			{
			
			cout<<setw(30)<<restuarant.dish[i].dishName;
			cout<<setw(32)<<restuarant.dish[i].price;
			cout<<setw(34)<<restuarant.dish[i].dishType<<"\n";
			}
	 	cout<<"\n\n";
	}

		void bookRoom(int r)
		{
			int i;
			for(i=0;i<6;i++)
			{
			if(room[i].roomNo==r)
		room[i].status=1;}
		}
		void askFeedback()
		{
			int f;
			string cname;
			ofstream feedback;
  			feedback.open ("feedback.txt",ios::app);
  			feedback <<"Customer Name\t : ";
			cout<<"\n\n\t\t\tEnter your Name :\n";
			cin>>cname;
			feedback<<cname<<"\t\t\t";
			cout<<" \n\n\t\t\t\t\t\t\t|   Thanks for your time !!!   | \n\n\t\t\t\t\t|   Mention The Percentage You Recommend this Hotel to Others?   |";
			cin>>f;
			feedback<<"Feedback\t: ";
			feedback<<f<<"\n";
			feedback.close();
				cout<<"  \n\n\t\t\t\t\t\t\t|   Thanks for your valuable feedback !!!   |"<<endl;
		}
		
			
		void getCustomerData(Customer *c)
		{
			cout<<" \n\n\n\t\t\t\t\t\t\t|   Name :   "<<c->custName<<endl;
			cout<<" \n\t\t\t\t\t\t\t|   Address :   "<<c->custAddress<<endl;
			cout<<"  \n\t\t\t\t\t\t\t|   Phone Number :   "<<c->custPhone <<endl;
			cout<<"  \n\t\t\t\t\t\t\t|   Email :   "<<c->custEmail <<endl;
			cout<<"  \n\t\t\t\t\t\t\t|   Check-In Time:   "<<c->checkInTime <<endl;
		}

 void vacateRoom(int rno)
		{
			int i,j=0;
			for(i=0;i<6;i++)
			{
				
				if(room[i].roomNo==rno)
			{
				j=1;
			room[i].status=0;
			cout<<" \n\n\t\t\t\t\t\t\t|   Thank You !!!   |  \n\n\t\t\t\t\t\t\t|   Visit Again !!! |\n"<<endl;}
			}
				if(j==0)
				throw Exception(8,"Sorry! Room Not Found, or occupied at the moment\n");
		
		}
		
		
		void takeOrder(string dnm)
		{
			int i,j=0;;
			for(i=0;i<8;i++)
			{
			if(	restuarant.dish[i].dishName== dnm)
			{ 
			j=1;
			cout<<"\n\n\t\t\t\t\t\t\t|   Order Successful !!!   |\n"<<endl;
			}
			}
			if(j==0)
			throw Exception(9, "Sorry! Dish Not Found, Enter a valid entry");
		}
			 
};


Hotel *Hotel :: instanceHotel=0;
int main()
{

		ifstream file("Description.txt");
		if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        printf("%s", line.c_str());
    }
    file.close();
}


cout<<"\n";
	int ch,i,o,ch1,ch2,r,rno,rcount=0,dcount=0;
	Room r2;
	string dname;
	Dish d2;
	Hotel *Rennaisance=Rennaisance->getHotel();
	
	Dish d[8]={
		Dish("Chocolate_Pudding",150,"Desert"),
		Dish("Roast_Chicken_kottu",850,"Main Course"),
		Dish("Masala",900,"Main Course"),
		Dish("Green_Tea",100,"Beverage"),
		Dish("Fruit_Salad",200,"Salad"),
		Dish("Yellow_Rice",270,"Starter"),
		Dish("Scofflaw_Cocktail",350,"Cocktail"),
		Dish("Ice_Cream_Rolls",150,"Ice Cream")
			};
			
		
	Customer *c[5];
	Restaurant res;
	for(i=0;i<8;i++)
	{
		res.dish[i]=d[i];
	}
	Rennaisance->restuarant=res;
	
	 Room rm[6] = {
		Room("AC",2,7500,1),
 		Room("AC",1,4500,2),
 		Room("Non AC",2,2500,3),
		Room("Deluxe",2,3500,4),
		Room("Air Condition",2,4000,5),
	 	Room("Full Air Condition",3,5000,6)
		 };
		 SelectEmployee *e;
	Rennaisance->setHotel(res,rm);


	while(1)
	{
		for(i=0;i<5;i++)
		{
			try{

			
	level2:	cout<<"\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================> \n\n\n\t\t\t\t\t\t\t|   1. Book Now      |\n\n\t\t\t\t\t\t\t|   2. Visit Hotel   |\n\n\t\t\t\t\t\t\t|   3. Exit          |\n";
		cin>>ch;
		if(ch==1)
		{
		 Rennaisance->customer[i]=new RoomCustomer;
		 Rennaisance->generateID(Rennaisance->customer[i]);
		 cout<<"\n\t\t\t<=============================== Enter  Your  Details ==========================>\n\n";
		 Rennaisance->customer[i]->setData();
		level1:	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================> \n\n\n\t\t\t\t\t\t\t|   1. Display Rooms   | \n\n\t\t\t\t\t\t\t|   2. Book Room       | \n\n\t\t\t\t\t\t\t|   3. Vacate Room     | \n\n\t\t\t\t\t\t\t|   4. Get Invoice     |  \n\n\t\t\t\t\t\t\t|   5. Not Satisfied?  | \n\n\t\t\t\t\t\t\t|   6. Cancel Booking  | \n\n\t\t\t\t\t\t\t|   7. Give Feedback   | \n\n\t\t\t\t\t\t\t|   8. Back            |\n\n\n";
			cin>>ch1;


			switch(ch1)
			{
				case 1: Rennaisance->displayAvailble();
				goto level1;
				case 2: 
				if(Rennaisance->customer[i]->status)
				{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(1,"Sorry! You Cannot Book more than one room!\n");
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";}


else
				{
				Rennaisance->customer[i]->status=1;
				Rennaisance->displayAvailble();
				cout<<"\n\t\tEnter Room No :\n";
				cin>>rno;
				Rennaisance->bookRoom(rno);
				r2=Rennaisance->getRoom(rno);
				Rennaisance->customer[i]->allocateRoom(r2);
				}
				
				
				goto level1;
				case 3: 
				if(!Rennaisance->customer[i]->status)
				{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(3,"Cannot vacate a book unless booked\n");
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";}


				else
				{
				Rennaisance->customer[i]->status=0;
				cout<<"\n\t\tEnter Room No :\n";
				cin>>rno;
				Rennaisance->vacateRoom(rno);
				cout<<"\n\t\tRoom Vacated\n";
			
				}
				goto level1;
				case 4: if(!Rennaisance->customer[i]->status)
			{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"Cannot get Invoice Details unless you book a Room\n");
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";}



				else 
				{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				Rennaisance->customer[i]->printCustomer();
				Rennaisance->customer[i]->viewTotalBill();
					cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				goto level1;}




				case 5: 
				if(!Rennaisance->customer[i]->status)
				
			{
			cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"Cannot call Room Service Unless you book a Room\n");
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";}
				
				
				else
				{
					e=new SelectEmployee(new RoomService);
					e->performDuty();
				
			}
					goto level1;
				case 6: 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"No Room Booked\n");
				}
				
				
				
				else
				{
					
					Rennaisance->customer[i]->status=0;
					cout<<"\n\t\tEnter Room No :\n";
				cin>>rno;
				Rennaisance->vacateRoom(rno);
					cout<<"\n\n\t\t\t\t\t\t\t|   Cancellation Successful !!!   |\n";
					
				}
				goto level1;
				case 7: if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"Cannot give feedback unless you order a Dish\n");
				}


				else

				Rennaisance->askFeedback();
				goto level1;
				case 8: goto level2;
			}
			
		}
		
		
		else if(ch==2)
		{
	 	Rennaisance->customer[i]=new RestaurantCustomer;
		 Rennaisance->generateID(Rennaisance->customer[i]);
		 cout<<"\n\t\t\t<=============================== Enter  Your  Details ==========================>\n\n";
		 Rennaisance->customer[i]->setData();
	level3:	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================> \n\n\n\t\t\t\t\t\t\t|   1. To display Menu   |\n\n\t\t\t\t\t\t\t|   2. To order a Dish   |\n\n\t\t\t\t\t\t\t|   3. To Get Invoice    |\n\n\t\t\t\t\t\t\t|   4. To Cancel Order   |\n\n\t\t\t\t\t\t\t|   5. Give FeedBack     |\n\n\t\t\t\t\t\t\t|   6. Go back           |\n\n\n";
		cin>>ch2;
		

switch(ch2)
		{
			case 1:
				Rennaisance->displayMenu();
				goto level3;
			case 2:
				if(Rennaisance->customer[i]->status)
			{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(4,"You cannot order more than one dish\n");
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";}

				else
				{
					o=1;
					Rennaisance->customer[i]->status=1;
			 Rennaisance->displayMenu();
			 e=new SelectEmployee(new Waiter);
			 e->performDuty();
			 cout<<"\n\n\t\t\t\t\t\t\t|   Enter Your Dish Order   |\n";
	
		cin>>dname;
			 Rennaisance->takeOrder(dname);
			 
			 d2=Rennaisance->restuarant.getDish(dname);
			
			Rennaisance->customer[i]->allocateDish(d2);
		
			 if(o==0)
			 {
			 cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
			 throw Exception(6,"No such Dish Found");
		}
		
			 }
			 	 goto level3;



			 case 3:
			 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"Cannot get Invoice Details unless you order a Dish\n");
				}
				
				else 
				{
				cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				Rennaisance->customer[i]->printCustomer();
				Rennaisance->customer[i]->viewTotalBill();
					cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
			}

				goto level3;
				case 4: 	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"No Dish Ordered\n");
				}
				else
				{
					Rennaisance->customer[i]->status=0;
					cout<<"\n\n\t\t\t\t\t\t\t|   Cancelation Successful!!!   |\n";
					
				}
				
				case 5:	if(!Rennaisance->customer[i]->status)
			 {
				 	cout<<"\n\n\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
				throw Exception(2,"Cannot give feedback unless you order a Dish\n");
				}
				else

				Rennaisance->askFeedback();
				goto level1;
				case 6:
				goto level2;
				
			
		}
		}


		else if(ch==3)
		exit(0);
		else
		{
			cout<<"\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
			throw Exception(5,"INVALID INPUT\n");
			
		}
		goto level2;
		}

	catch(Exception eh)
	{
		eh.what();
		cout<<"\t\t\t<============================= C o d e S h o w   L a p Z ========================>\n\n\t\t\t<============================= HOTEL  MANAGEMENT  SYSTEM ========================>\n\n\t\t\t<============================= W   E   L   C   O   M   E ========================>\n\n";
	}
	}	}
return 0;
}	











		










	
		
		



