#include <iostream>
#include <conio.h> // cls
#include <unistd.h> // sleep
using namespace std;

//==================================== global var =======================

char staffName[99][99] = {"Luqman", "Adib", "Zarif"}; // 3
char staffPass[99][99] = {"luqman123", "adibudeen", "zash04"};
char foodsList[99][99] = {"Nasi Minyak Ayam Kari", "Nasi Minyak Ayam Merah", "Mee Kari", "Nasi Kandar"}; // 4
int foodsQty[99] = {10, 10, 10, 10};
float foodsPrice[99] = {7.00, 7.00, 6.00, 8.00};
char drinksList[99][99] = {"Milo Kotak", "Jagung Susu", "Air Kosong"}; // 3
int drinksQty[99] = {10, 10, 10};
float drinksPrice[99] = {2.50, 5.00, 1.00};
char iceCreamList[99][99] = {"Magnolia", "Aiskrim Malaysia", "Magnum",}; // 3
int iceCreamQty[99] = {10, 10, 10};
float iceCreamPrice[99] = {7.00, 0.50, 4.50};
int totalCust = 0;
float paymentList[99] = {};

//==================================== fn prototype =====================

void custOp();
void staffOp();
void custMenu();
void staffMenu();
bool staffLogin();
void custOrder();
void foodsMenu();
void drinksMenu();
void iceCreamMenu();
void custPayment(float totalMoneyThatCustNeedToPay, char whereItemGo); //-------- custPayment
void fpxPayment(float money);
void stocks();
void itemGoodsInfo();
void statistics();
void addInfo();

//==================================== main =============================

int main() {
	char custOrStaff;
	bool exitProgram = false;
	
	while (exitProgram == false) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          WELCOME TO KSHOPPE          |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|      ( )         [ ]        |\\/|     |" << endl;
		cout << "|      / \\         / \\        |/\\|     |" << endl;
		cout << "| [1] Customer  [2] Staff   [3] Exit   |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "            Enter key : ";
		cin >> custOrStaff;
		if (custOrStaff == '1') {
			custOp();
		} else if (custOrStaff == '2') {
			staffOp();
		} else {
			exitProgram = true;
		}
	}
}

//=================================== fn def =============================

// FUNCTION (CUSTOMER)

void custOp() { //------------------------------------------------ custOp
	bool isShopping = true;
	
	while (isShopping == true) {
		custOrder();
		isShopping = false;
	}
}

void custMenu() { //---------------------------------------------custMenu
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|           K-SHOPPE ONLINE            |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << " 1. Foods" << endl;
	cout << " 2. Drinks" << endl;
	cout << " 3. Ice Cream" << endl;
	cout << "+--------------------------------------+" << endl;
}

void foodsMenu() { //--------------------------------------------foodsMenu
	for (int i = 0; i < 4; i++) {
		cout << " " << i + 1 << ". " << foodsList[i] << endl;
		cout << " Price : RM " << foodsPrice[i] << " , Available : " << foodsQty[i] << endl;
		cout << endl;
	}
}

void drinksMenu() { //------------------------------------------drinksMenu
	for (int i = 0; i < 3; i++) {
		cout << " " << i + 1 << ". " << drinksList[i] << endl;
		cout << " Price : RM " << drinksPrice[i] << " , Available : " << drinksQty[i] << endl;
		cout << endl;
	}
}

void iceCreamMenu() { //--------------------------------------iceCreamMenu
	for (int i = 0; i < 3; i++) {
		cout << " " << i + 1 << ". " << iceCreamList[i] << endl;
		cout << " Price : RM " << iceCreamPrice[i] << " , Available : " << iceCreamQty[i] << endl;
		cout << endl;
	}
}

void custOrder() { //------------------------------------------ custOrder
	string itemCart[99];
	float itemPrice[99];
	int itemQty[99];
	bool isAdding = true;
	float totalPrice = 0;
	char pickupMethod;
	
	for (int i = 0; i < 99; i++) {
		itemCart[i] = "0";
	}
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|            PICKUP METHOD             |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|       / |--|           /==\\          |" << endl;
	cout << "|       -o--o-           |__|          |" << endl;
	cout << "|   [D] Delivery    [S] Self Pickup    |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "     Choose your preference : ";
	cin >> pickupMethod;
	
	while (isAdding == true) {
		system("cls");
		char category;
		custMenu();
		cout << " Choose category : ";
		cin >> category;
		
		if (category == '1') {
			system("cls");
			int orderKey;
			cout << "+-------------+" << endl;
			cout << " Shop! >> Foods" << endl;
			cout << "+-------------+" << endl;
			foodsMenu();
			cout << "Choose your food : ";
			cin >> orderKey;
			if (orderKey == 1) {
				system("cls");
				int foodQty;
				cout << "+------------------------+" << endl;
				cout << "| NASI MINYAK    RM 7.00 |" << endl;
				cout << "| AYAM KARI              |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> foodQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = foodsList[orderKey-1];
						itemPrice[i] = foodsPrice[orderKey-1];
						itemQty[i] = foodQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 2) {
				system("cls");
				int foodQty;
				cout << "+------------------------+" << endl;
				cout << "| NASI MINYAK    RM 7.00 |" << endl;
				cout << "| AYAM MERAH             |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> foodQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = foodsList[orderKey-1];
						itemPrice[i] = foodsPrice[orderKey-1];
						itemQty[i] = foodQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 3) {
				system("cls");
				int foodQty;
				cout << "+------------------------+" << endl;
				cout << "| MEE KARI       RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> foodQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = foodsList[orderKey-1];
						itemPrice[i] = foodsPrice[orderKey-1];
						itemQty[i] = foodQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 4) {
				system("cls");
				int foodQty;
				cout << "+------------------------+" << endl;
				cout << "| NASI KANDAR    RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> foodQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = foodsList[orderKey-1];
						itemPrice[i] = foodsPrice[orderKey-1];
						itemQty[i] = foodQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			}
		} else if (category == '2') {
			system("cls");
			int orderKey;
			cout << "+-------------+" << endl;
			cout << " Shop! >> Drinks" << endl;
			cout << "+-------------+" << endl;
			drinksMenu();
			cout << "Choose your drinks : ";
			cin >> orderKey;
			if (orderKey == 1) {
				system("cls");
				int drinksQty;
				cout << "+------------------------+" << endl;
				cout << "| MILO KOTAK     RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> drinksQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = drinksList[orderKey-1];
						itemPrice[i] = drinksPrice[orderKey-1];
						itemQty[i] = drinksQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 2) {
				system("cls");
				int drinksQty;
				cout << "+------------------------+" << endl;
				cout << "| JAGUNG SUSU    RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> drinksQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = drinksList[orderKey-1];
						itemPrice[i] = drinksPrice[orderKey-1];
						itemQty[i] = drinksQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 3) {
				system("cls");
				int drinksQty;
				cout << "+------------------------+" << endl;
				cout << "| AIR KOSONG     RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> drinksQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = drinksList[orderKey-1];
						itemPrice[i] = drinksPrice[orderKey-1];
						itemQty[i] = drinksQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			}
		} else {
			system("cls");
			int orderKey;
			cout << "+-------------+" << endl;
			cout << " Shop! >> Ice Cream" << endl;
			cout << "+-------------+" << endl;
			iceCreamMenu();
			cout << "Choose your ice cream : ";
			cin >> orderKey;
			if (orderKey == 1) {
				system("cls");
				int iceCreamQty;
				cout << "+------------------------+" << endl;
				cout << "| MAGNOLIA       RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> iceCreamQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = iceCreamList[orderKey-1];
						itemPrice[i] = iceCreamPrice[orderKey-1];
						itemQty[i] = iceCreamQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 2) {
				system("cls");
				int iceCreamQty;
				cout << "+------------------------+" << endl;
				cout << "| ESKEM MESIA    RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> iceCreamQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = iceCreamList[orderKey-1];
						itemPrice[i] = iceCreamPrice[orderKey-1];
						itemQty[i] = iceCreamQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			} else if (orderKey == 3) {
				system("cls");
				int iceCreamQty;
				cout << "+------------------------+" << endl;
				cout << "| MAGNUM         RM 7.00 |" << endl;
				cout << "|                        |" << endl;
				cout << "+------------------------+" << endl;
				cout << "Enter quantity : ";
				cin >> iceCreamQty;
				for (int i = 0; i < 99; i++) {
					if (itemCart[i] == "0") {
						itemCart[i] = iceCreamList[orderKey-1];
						itemPrice[i] = iceCreamPrice[orderKey-1];
						itemQty[i] = iceCreamQty;
						cout << "Item successfully added to cart!" << endl;
						sleep(1);
						break;
					}
				}
			}
		}
		char isContinue = 'Y';
		cout << "Add another order? (Y/N) : ";
		cin >> isContinue;
		if (toupper(isContinue) == 'N') {
			isAdding = false;
		}
	}
	for (int i = 0; i < 99; i++) {
		if (itemCart[i] != "0") {
			totalPrice = totalPrice + (itemPrice[i] * itemQty[i]);
		}
	}
	system("cls");
	cout << "+----------+" << endl;
	cout << " ORDER LIST" << endl;
	cout << "+----------+" << endl;
	for (int i = 0; i < 99; i++) {
		if (itemCart[i] != "0") {
			cout << " " << i+1 << ". " << itemCart[i] << "(" << itemQty[i] << ")" << endl;
		}
	}
	cout << "The total price : RM " << totalPrice << endl;
	custPayment(totalPrice, pickupMethod);
}

void custPayment(float totalMoneyThatCustNeedToPay, char whereItemGo) { //-------- custPayment
	int paymentKey;
	if (whereItemGo == 'S' || whereItemGo == 's') {
		cout << "+-----------------+" << endl;
		cout << "| PAYMENT METHOD  |" << endl;
		cout << "+-----------------+" << endl;
		cout << " 1. Pay On Pickup" << endl;
		cout << " 2. FPX" << endl;
		cout << "Choose payment method : ";
		cin >> paymentKey;
		if (paymentKey == 1) {
			system("cls");
			// add payOnPickup() method function
			cout << "Checkout successfully!" << endl;
			sleep(3);
		} else {
			system("cls");
			fpxPayment(totalMoneyThatCustNeedToPay);
			cout << "Checkout successfully!" << endl;
			sleep(3);
		}
	} else {
		fpxPayment(totalMoneyThatCustNeedToPay);
		system("cls");
		cout << "Checkout successfully!" << endl;
		sleep(3);
	}
	paymentList[totalCust] = totalMoneyThatCustNeedToPay;
	totalCust = totalCust + 1;
}

void fpxPayment(float money) { //-----------------------------------fpxPayment
	char bankKey;
	cout << "+--------------+" << endl;
	cout << " FPX GATEWAY" << endl;
	cout << "+--------------+" << endl;
	cout << " [A] Bank Islam" << endl;
	cout << " [B] BSN" << endl;
	cout << " [C] RHB" << endl;
	cout << " [D] Maybank" << endl;
	cout << " Choose your bank :";
	cin >> bankKey;
	if (bankKey == 'A' || bankKey == 'a') {
		system("cls");
		cout << "Redirecting to Bank Islam's page..." << endl;
		sleep(3);
	} else if (bankKey == 'B' || bankKey == 'b') {
		system("cls");
		cout << "Redirecting to BSN's page..." << endl;
		sleep(3);
	} else if (bankKey == 'C' || bankKey == 'c') {
		system("cls");
		cout << "Redirecting to RHB's page..." << endl;
		sleep(3);
	} else {
		system("cls");
		cout << "Redirecting to Maybank's page..." << endl;
		sleep(3);
	}
}

// FUNCTION (STAFF)

void staffOp() { //---------------------------------------------- staffOp
	bool isStaff = staffLogin();
	while (isStaff == true) {
		int keyStaff;
		staffMenu();
		cout << "Enter key : ";
		cin >> keyStaff;
		if (keyStaff == 1) {
			stocks();
		} else if (keyStaff == 2) {
			statistics();
		} else if (keyStaff == 3) {
			addInfo();
		} else if (keyStaff == 4) {
			isStaff = false;
		}
	}
}

void staffMenu() { //-------------------------------------------staffMenu
	system("cls");
	cout << "+----------------+" << endl;
	cout << " K-SHOPPE STAFF" << endl;
	cout << "+----------------+" << endl;
	cout << " 1. Stocks" << endl;
	cout << " 2. Statistics" << endl;
	cout << " 3. Additional Info" << endl;
	cout << " 4. Exit" << endl;
	cout << "+----------------+" << endl;
}

bool staffLogin() { //------------------------------------------staffLogin
	system("cls");
	bool trueStaff = false;
	char username[99], password[99];
	cout << "+----------------+" << endl;
	cout << " STAFF LOGIN" << endl;
	cout << "+----------------+" << endl;
	cout << " Enter username : ";
	cin >> username;
	cout << " Enter password : ";
	cin >> password;
	
	for (int i = 0; i < 3; i++) {
		if (strcmp(username, staffName[i]) == 0 && strcmp(password, staffPass[i]) == 0) {
			trueStaff = true;
		}
	}
	
	return trueStaff;
}

void stocks() { //----------------------------------------------stocks
	system("cls");
	int stocksKey;
	cout << "+---------------+" << endl;
	cout << " STOCKS" << endl;
	cout << "+---------------+" << endl;
	cout << " [1] Foods" << endl;
	cout << " [2] Drinks" << endl;
	cout << " [3] Ice Cream" << endl;
	cout << "Choose category : ";
	cin >> stocksKey;
	if (stocksKey == 1) {
		system("cls");
		cout << "+-------------------------------+" << endl;
		cout << " STOCKS => FOODS" << endl;
		cout << "+-------------------------------+" << endl;
		for (int i = 0; i < 4; i++) {
			cout << " " << i+1 << ". " << foodsList[i] << endl;
			cout << " Stocks : " << foodsQty[i] << endl;
		}
		cout << endl;
	} else if (stocksKey == 2) {
		system("cls");
		cout << "+-------------------------------+" << endl;
		cout << " STOCKS => DRINKS" << endl;
		cout << "+-------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i+1 << ". " << drinksList[i] << endl;
			cout << " Stocks : " << drinksQty[i] << endl;
		}
		cout << endl;
	} else if (stocksKey == 3) {
		system("cls");
		cout << "+-------------------------------+" << endl;
		cout << " STOCKS => ICE CREAM" << endl;
		cout << "+-------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i+1 << ". " << iceCreamList[i] << endl;
			cout << " Stocks : " << iceCreamQty[i] << endl;
		}
		cout << endl;
	}
	cout << "Press Enter to Continue";
	getch();
}

void statistics() { //-------------------------------------------statistics
	system("cls");
	float moneyFromCust = 0;
	cout << "+---------------+" << endl;
	cout << " STATISTICS" << endl;
	cout << "+---------------+" << endl;
	cout << "Total customer : " << totalCust << endl;
	for (int i = 0; i < 99; i++) {
		if (paymentList[i] > 0) {
			moneyFromCust = moneyFromCust + paymentList[i];
		}
	}
	cout << "Total payment : " << moneyFromCust << endl;
	cout << endl;
	cout << "Press Enter to continue ";
	getch();
}

void addInfo() { //------------------------------------------------addInfo
	system("cls");
	cout << "+---------------+" << endl;
	cout << " ADDITIONAL INFO" << endl;
	cout << "+---------------+" << endl;
	cout << " Program Informations : " << endl;
	cout << " Version : 1.0" << endl;
	cout << " Last update : 14/1/2023" << endl;
	
	cout << endl;
	cout << "Press Enter to continue ";
	getch();
}
