#include <iostream>
#include <iomanip> // setw();
#include <string.h> // strcmp(), toupper()
#include <stdlib.h> // system("cls") - clearing the screen
#include <windows.h> // Sleep(milisecond); - delayed
#include <unistd.h> //sleep(second); - delay
#include <conio.h> // getch() - PAUSE, press ENTER to continue
using namespace std;
void homePage();
//----------------------------------------------------------------------------- ADMINISTRATOR PROTOTYPE BELOW
void admin();
void adminMenu();
void printTotSale();
void printAverage();
void showAllInfo();
//----------------------------------------------------------------------------- GUEST PROTOTYPE BELOW
void guest();
double calTotal(int, double);
void cash(double);
void creditCard(double);
void touchNGo(double);
void boost(double);
void paypal(double);
//global variables below
double totalSales = 0, average = 0;
int count = 0;
int main() {	
	homePage();
	cout<<"\nPROGRAM TERMINATED SUCCESSFULLY!";
return 0;
}

void homePage() {
	char choose, proceed, yes;
	system("cls");

	cout<<"+----------------------------------------+"<<endl;
	cout<<"|HOME PAGE: WELCOME TO CLOUD ICEREAM CAFE|"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"|1. Administrator [A]                    |"<<endl;
	cout<<"|2. Guest         [G]                    |"<<endl;
	cout<<"|3. CLOSE Program [X]                    |"<<endl;
	cout<<"+----------------------------------------+"<<endl;
	cout<<"Choose Login As: ";
	cin>> choose;
	//cout<<"Alphabet: "<< toupper(choose) <<endl;
	if (choose == '1' || choose == 'A' || choose == 'a')
		admin();
	else if (choose == '2' || choose == 'G' || choose == 'g')
		guest();
	else if (choose == '3' || choose == 'X' || choose == 'x') {
		cout<<"Are you sure you want to CLOSE the Program?\nPress [X]: ";
		cin>> yes;
		if (toupper(yes) == 'X')
			system(0); // force exit program (you have to reexecute/rerun the program. 
		else
			homePage();
	}	
	else
		homePage();
	
	
}
//----------------------------------------------------------------------------- ADMINISTRATOR DEFINITION BELOW
void admin() {
	char username[20], password[20];
	int attempt = 0, countDown = 2;
	system("cls");
	do
	{
		cout<<"+----------------------------------------+"<<endl;;
		cout<<"|   You want to Login as Administrator   |"<<endl;
		cout<<"+----------------------------------------+"<<endl;;
		cout<<"Username: " ;
		cin>> username;
		cout<<"Password: ";
		cin>> password;
		if (strcmp(username, "123") == 0 && strcmp(password, "123") == 0) 
		{
			adminMenu();
		}
		else {
			if(attempt == 2) 
			{
				if(countDown == 0) {
					cout<<"\nYou are redirected to the HOME PAGE."<<endl;
					for(int i=0; i<35; i++)
					{
						cout<<"*";
						Sleep(200);
					}
					
				}
				homePage();
			}
			else {
				cout<<"Wrong username and password. "<<countDown<<" attempt left!"<<endl<<endl;
				attempt++;
				countDown--;
				Sleep(3000);			
			}
		}
	} while (true);
}
void adminMenu() {
	system("cls");
	int menu;
	char reselect;
	//do {
	cout<<"+------------------------------+"<<endl;
	cout<<"|WELCOME TO ADMINISTRATION MENU|"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|1. Check Total Sale           |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|2. Check Average Sale         |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|3. Show all Information       |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"|4. Back to HOME PAGE          |"<<endl;
	cout<<"+------------------------------+"<<endl;
	cout<<"Choose Menu: ";
	cin>> menu;
	if (menu == 1)
		printTotSale();
	else if (menu == 2)
		printAverage();
	else if (menu == 3)
	  	showAllInfo();
	else if (menu == 4)
		homePage();
	else {
		cout<<"\nInvalid Input!"<<endl;
		cout<<"Press ENTER to continue";
		getch();
		adminMenu();
	}

}

void printTotSale() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"|   TOTAL SALE PAGE    |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Total Sale: "<< totalSales <<endl;	
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
void printAverage() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"|     AVERAGE PAGE     |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Average sale: "<< average <<endl;
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
void showAllInfo() {
	system("cls");
	cout<<"+----------------------+"<<endl;
	cout<<"| SHOW ALL INFORMATION |"<<endl;
	cout<<"+----------------------+"<<endl;
	cout<<"Total sale: "<< totalSales <<endl;
	cout<<"Average sale: "<< average <<endl;
	cout<<"Press ENTER to continue."<<endl;
	getch();
	adminMenu();
}
//-------------------------------------------------------------------------------------------------------------------- GUEST DEFINITION BELOW
void guest() {
	system("cls"); // clearing all previous output
	char name[40], code, proceed;
	int qty, paymentType, cho = 0, str = 0, van = 0; // count is to count number of transactions.
	double total = 0, price;
	cin.ignore(1024,'\n'); // to flush out remaining characters
	cout<<"+----------------------------------+"<<endl;
	cout<<"|       WELCOME TO GUEST PAGE      |"<<endl;
	cout<<"+----------------------------------+"<<endl;
	cout<<"Please enter your name: " ;
	cin.getline(name,20);
	count++; // counting number of customer
	system("cls");
	do {
		qty = 0;
		cout<<"+---------------------------+"<<endl;
		cout<<"| Hi "<< name <<"!"<<endl;
		cout<<"+---------------------------+"<<endl;
		cout<<"+------+------------+-------+"<<endl;
		cout<<"| CODE | MENU       | PRICE |"<<endl;
		cout<<"+------+------------+-------+"<<endl;
 		cout<<"|  C   | Chocolate  |  3.00 |"<<endl;
		cout<<"|  S   | Strawberry |  4.00 |"<<endl;
		cout<<"|  V   | Vanilla    |  2.00 |"<<endl;
		cout<<"+------+--------------------+"<<endl;
		cout<<"|  X   | Back to HOME PAGE  |"<<endl;
		cout<<"+---------------------------+"<<endl;
		cout<<"Enter code: ";
		cin>> code;
		if (toupper(code) != 'C' && toupper(code) != 'S' && toupper(code) != 'V') // Back to HOME PAGE if code is not C, S or V 
			homePage();
		cout<<"Quantity: ";
		cin>> qty;
		
		if (toupper(code) == 'C') {
			cho += qty;
			total += calTotal(qty, 3.0);
		}
		else if (toupper(code) == 'S') {
			str += qty;
			total += calTotal(qty, 4.0);
		}
		else if (toupper(code) == 'V') {
			van += qty;
			total += calTotal(qty, 2.0);
		}
		system("cls");
		cout<<"+-----------------------------------+"<<endl;
		cout<<"|   ITEM   |      QTY     |  PRICE  |"<<endl;
		cout<<"+----------+--------------+---------+"<<endl;
		cout<<"|Chocolate |"<<setw(9)<< cho <<setw(6)<<"|"<<setw(7)<<cho * 3.0<<setw(3)<<"|"<<endl;
		cout<<"+----------+--------------+---------+"<<endl;
		cout<<"|Strawberry|"<<setw(9)<< str <<setw(6)<<"|"<<setw(7)<<str * 4.0<<setw(3)<<"|"<<endl;
		cout<<"+----------+--------------+---------+"<<endl;
		cout<<"|Vanilla   |"<<setw(9)<< van <<setw(6)<<"|"<<setw(7)<<van * 2.0<<setw(3)<<"|"<<endl;
		cout<<"+----------+--------------+---------+"<<endl;
		cout<<"           |Total Purchase| "<<setw(6)<< total<<setw(3)<<"|"<<endl;
		cout<<"           +--------------+---------+"<<endl<<endl;
		cout<<"Press Y to continue shopping: ";
		cin>> proceed;
	} while (toupper(proceed) == 'Y');
	
	system("cls");
	cout<<"+-------------------------------+"<<endl;
	cout<<"|Your total purchase is: " << total <<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"|Choose your payment method     |"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"|1. Cash                        |"<<endl;
	cout<<"|2. Credit Card (discounted 10%)|"<<endl;
	cout<<"|3. Touch-N-Go (discounted 5%)  |"<<endl;
	cout<<"|4. Boost (discounted 4%)       |"<<endl;
	cout<<"|5. Paypal (charged 2% interest)|"<<endl;
	cout<<"+-------------------------------+"<<endl;
	cout<<"Your choice: ";
	cin>> paymentType;
	if (paymentType == 1)
		cash(total);
	else if (paymentType == 2)
		creditCard(total);
	else if (paymentType == 3)
		touchNGo(total);
	else if (paymentType == 4)
		boost(total);
	else if (paymentType == 5)
		paypal(total);
	else {
		cout<<"Invalid input. "<<endl;
	}
	
}
double calTotal(int qty, double price) {
	return qty * price;
}
void cash(double total) {
	system("cls");
	double pay;
	cout<<"You choose to pay in CASH."<<endl;
	cout<<"You need to pay RM " << total<<endl;
	cout<<"Customer cash RM: ";
	cin>> pay;
	cout<<"Balance RM: " << (pay - total) <<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales += total; // update global variable (totalSale)
	average = totalSales/count; // calculate average
	cout<<"Press ENTER to continue";
	getch();
	homePage();
}
void creditCard(double total) {
	system("cls");
	double discount = 0.1; // give 10 percent discount
	cout<<"You choose to pay using CREDIT CARD."<<endl;
	cout<<"You need to pay RM " << total - (total * discount) <<endl;
	cout<<"PayWave... transaction completed.\nYour Credit Card has been charged."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales += total - (total * discount) ; // update global variable
	average = totalSales/count; // calculate average
	cout<<"Press ENTER to continue";
	getch();
	homePage();
}
void touchNGo(double total) {
	system("cls");
	double discount = 0.05; // give 10 percent discount
	cout<<"You choose to pay using Touch-N-Go."<<endl;
	cout<<"You need to pay RM " << total - (total * discount) <<endl;
	cout<<"Scanning QR Code... transaction completed. \nYour Touch N Go Card has been charged."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales += total - (total * discount); // update global variable
	average = totalSales/count; // calculate average
	cout<<"Press ENTER to continue";
	getch();
	homePage();
}
void boost(double total) {
	system("cls");
	double discount = 0.04; // give 10 percent discount
	cout<<"You choose to pay using Boost."<<endl;
	cout<<"You need to pay RM " << total - (total * discount) <<endl;
	cout<<"Scanning QR Code... transaction completed. \nYour Boost e-Wallet has been charged."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales += total - (total * discount); // update global variable	
	average = totalSales/count; // calculate average
	cout<<"Press ENTER to continue";
	getch();
	homePage();
}
void paypal(double total) {
	system("cls");
	double interest = 0.02; // 2%
	cout<<"You choose to pay using Paypal."<<endl;
	cout<<"You need to pay RM " << total + (total * interest) <<endl;
	cout<<"Scanning QR Code... transaction completed. \nYour payPal e-Wallet has been deducted."<<endl;
	cout<<"\nThank you for using our service." <<endl;
	
	totalSales += total + (total * interest); // update global variable	
	average = totalSales/count; // calculate average	
	cout<<"Press ENTER to continue";
	getch();
	homePage();
}


