#include <iostream>
#include <conio.h> // cls
#include <unistd.h> // sleep
using namespace std;

//==================================== fn prototype =====================

void staffOp(char staffName[99][99], char staffPass[99][99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99]);
void custMenu();
void staffMenu();
bool staffLogin(char x[99][99], char y[99][99]);
void custOrder(char par1[99][99], int par2[99], float par3[99], char par4[99][99], int par5[99], float par6[99], 
	char par7[99][99], int par8[99], float par9[99], int par10, float par11[99], string par12[99], string par13[99]);
void foodsMenu(char x[99][99], int y[99], float z[99]);
void drinksMenu(char x[99][99], int y[99], float z[99]);
void iceCreamMenu(char x[99][99], int y[99], float z[99]);
void custPayment(float totalMoneyThatCustNeedToPay, char whereItemGo, int a, string b[99], string c[99]); //-------- custPayment
void fpxPayment(float money);
void itemGoodsInfo();
void statistics(int a, float b[99]);
void addInfo();
void viewStocks(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]);
void updateStocks(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], 
	float foodsPrice[99], char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]);
void inputErrorHandling();
void noStock();
void inputPlease();
bool terminateProgram(bool isTerminate, int terminateKey);
void deliveryInfo();
void stocksOp(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]);

//==================================== main =============================

int main() {
	// ---------- main init
	
	char staffName[99][99] = {"Luqman", "Adib", "Zarif"}; // 3
	char staffPass[99][99] = {"luqman123", "adibudeen", "zash04"};
	bool isStaff = false;
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
	bool isTerminate = false;
	int terminateKey = 90271;
	string custCollegeType[99] = {};
	string custRoomNumber[99] = {};
	
	// ----------
	char custOrStaff;
	
	while (isTerminate == false) {
		point0:
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          WELCOME TO KSHOPPE          |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|         ( )             [ ]          |" << endl;
		cout << "|         / \\             / \\          |" << endl;
		cout << "|     [1] Customer      [2] Staff      |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "            Enter key : ";
		cin >> custOrStaff;
		if (custOrStaff == '1') {
			custOrder(foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, iceCreamList, iceCreamQty, 
			iceCreamPrice, totalCust, paymentList, custCollegeType, custRoomNumber);
		} else if (custOrStaff == '2') {
			staffOp(staffName, staffPass, isStaff, isTerminate, terminateKey, totalCust, paymentList, foodsList, foodsQty, 
			foodsPrice, drinksList, drinksQty, drinksPrice, 
			iceCreamList, iceCreamQty, iceCreamPrice);
		} else {
			inputErrorHandling();
		}
	}
}

//=================================== fn def =============================

// FUNCTION (CUSTOMER)

void custOrder(char foodsList[99][99], int foodsQty[99], float foodsPrice[99], char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], int totalCust, float paymentList[99], string custCollegeType[99], string custRoomNumber[99]) { //------------------------------------------ custOrder
	string itemCart[99];
	float itemPrice[99];
	int itemQty[99];
	bool isAdding = true;
	float totalPrice = 0;
	char pickupMethod;
	bool cartIsEmpty = true;
	bool truePickupMethod = false;
	
	for (int i = 0; i < 99; i++) {
		itemCart[i] = "0";
	}
	
	while (truePickupMethod != true) {
		point1:
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|            PICKUP METHOD             |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|       / |--|           /==\\          |" << endl;
		cout << "|       -o--o-           |__|          |" << endl;
		cout << "|   [D] Delivery    [S] Self Pickup    |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "     Choose your preference : ";
		cin >> pickupMethod;
		
		if (pickupMethod == 'D' || pickupMethod == 'd' || pickupMethod == 'S' || pickupMethod == 's') {
			truePickupMethod = true;
		} else if (pickupMethod == '0') {
			main();
		} else {
			inputErrorHandling();
			truePickupMethod = false;
		}
	}
	
	while (isAdding == true) {
		point2:
		bool isEnough = false;
		system("cls");
		char category;
		custMenu();
		cout << "       Choose category : ";
		cin >> category;
		
		if (category == '1') {
			point3:
			system("cls");
			int orderKey;
			cout << "+--------------------------------------+" << endl;
			cout << "|            Shop! >> Foods            |" << endl;
			cout << "+--------------------------------------+" << endl;
			foodsMenu(foodsList, foodsQty, foodsPrice);
			cout << "    Choose your food : ";
			cin >> orderKey;
			if (orderKey >= 1 && orderKey <= 4) {
				system("cls");
				int foodQty;
				cout << "+--------------------------------------+" << endl;
				cout << "  " << foodsList[orderKey-1] << endl;
				cout << "  Price : RM " << foodsPrice[orderKey-1] << endl;
				cout << "        ooo                            |" << endl;
				cout << "       \\___/                           |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "|             [0] Back                 |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "          Enter quantity : ";
				cin >> foodQty;
				// check for stock
				if (foodsQty[orderKey-1] - foodQty  < 0) {
					noStock();
				} else if (foodQty == 0) {
					goto point3;
				} else {
					for (int i = 0; i < 99; i++) {
						cartIsEmpty = false;
						isEnough = true;
						if (itemCart[i] == "0") {
							itemCart[i] = foodsList[orderKey-1];
							itemPrice[i] = foodsPrice[orderKey-1];
							itemQty[i] = foodQty;
							system("cls");
							cout << "+--------------------------------------+" << endl;
							cout << "|   Item successfully added to cart!   |" << endl;
							cout << "+--------------------------------------+" << endl;
							sleep(2);
							break;
						}
					}
					foodsQty[orderKey-1] -= foodQty;
				}
			} else if (orderKey == 0) {
				goto point2;
			} else {
				inputErrorHandling();
			}
		} else if (category == '2') {
			point4:
			system("cls");
			int orderKey;
			cout << "+--------------------------------------+" << endl;
			cout << "|           Shop! >> Drinks            |" << endl;
			cout << "+--------------------------------------+" << endl;
			drinksMenu(drinksList, drinksQty, drinksPrice);
			cout << "    Choose your drinks : ";
			cin >> orderKey;
			if (orderKey >= 1 && orderKey <= 3) {
				system("cls");
				int drinksQuantity;
				cout << "+--------------------------------------+" << endl;
				cout << "  " << drinksList[orderKey-1] << endl;
				cout << "  Price : RM " << drinksPrice[orderKey-1] << endl;
				cout << "      [ ]                              |" << endl;
				cout << "      [ ]                              |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "|             [0] Back                 |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "          Enter quantity : ";
				cin >> drinksQuantity;
				if (drinksQty[orderKey-1] - drinksQuantity  < 0) {
					noStock();
				} else if (drinksQuantity == 0) {
					goto point4;
				} else {
					isEnough = true;
					cartIsEmpty = false;
					for (int i = 0; i < 99; i++) {
						if (itemCart[i] == "0") {
							itemCart[i] = drinksList[orderKey-1];
							itemPrice[i] = drinksPrice[orderKey-1];
							itemQty[i] = drinksQuantity;
							system("cls");
							cout << "+--------------------------------------+" << endl;
							cout << "|   Item successfully added to cart!   |" << endl;
							cout << "+--------------------------------------+" << endl;
							sleep(2);
							break;
						}
					}
					drinksQty[orderKey-1] -= drinksQuantity;
				} 	
			} else if (orderKey == 0) {
				goto point2;
			} else {
				inputErrorHandling();
			}
		} else if (category == '3') {
			point5:
			system("cls");
			int orderKey;
			cout << "+--------------------------------------+" << endl;
			cout << "|           Shop! >> Ice Cream         |" << endl;
			cout << "+--------------------------------------+" << endl;
			iceCreamMenu(iceCreamList, iceCreamQty, iceCreamPrice);
			cout << "     Choose your ice cream : ";
			cin >> orderKey;
			if (orderKey >= 1 && orderKey <= 3) {
				system("cls");
				int iceCreamQuantity;
				cout << "+--------------------------------------+" << endl;
				cout << "  " << iceCreamList[orderKey-1] << endl;
				cout << "  Price : RM " << iceCreamPrice[orderKey-1] << endl;
				cout << "     O                                 |" << endl;
				cout << "     \\/                                |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "|             [0] Back                 |" << endl;
				cout << "+--------------------------------------+" << endl;
				cout << "          Enter quantity : ";
				cin >> iceCreamQuantity;
				if (iceCreamQty[orderKey-1] - iceCreamQuantity  < 0) {
					noStock();
				} else if (iceCreamQuantity == 0) {
					goto point5;
				} else {
					isEnough = true;
					cartIsEmpty = false;
					for (int i = 0; i < 99; i++) {
						if (itemCart[i] == "0") {
							itemCart[i] = iceCreamList[orderKey-1];
							itemPrice[i] = iceCreamPrice[orderKey-1];
							itemQty[i] = iceCreamQuantity;
							system("cls");
							cout << "+--------------------------------------+" << endl;
							cout << "|   Item successfully added to cart!   |" << endl;
							cout << "+--------------------------------------+" << endl;
							sleep(2);
							break;
						}
					}
					iceCreamQty[orderKey-1] -= iceCreamQuantity;
				}
			} else if (orderKey == 0) {
				goto point2;
			} else {
				inputErrorHandling();
			}
		} else if (category == '0') {
			goto point1;
		} else {
			inputErrorHandling();
		}
		if (isEnough == true) {
			char isContinue = 'Y';
			cout << endl;
			cout << "    Add another order? (Y/N) : ";
			cin >> isContinue;
			if (toupper(isContinue) == 'N') {
				isAdding = false;
			}
		}
	}
	if (cartIsEmpty != true) {
		for (int i = 0; i < 99; i++) {
			if (itemCart[i] != "0") {
				totalPrice = totalPrice + (itemPrice[i] * itemQty[i]);
			}
		}
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|             ORDER LIST               |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 99; i++) {
			if (itemCart[i] != "0") {
				cout << "   " << i+1 << ". " << itemCart[i] << " (" << itemQty[i] << ")" << endl;
			}
		}
		cout << "+--------------------------------------+" << endl;
		cout << "|   The total price : RM " << totalPrice << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "    Press Enter to continue ";
		getch();
		custPayment(totalPrice, pickupMethod, totalCust, custCollegeType, custRoomNumber);
		paymentList[totalCust] = totalPrice;
	}
	
}

void custMenu() { //---------------------------------------------custMenu
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|           K-SHOPPE ONLINE            |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|   ooo          [ ]           Oo      |" << endl;
	cout << "|  \\___/         [ ]           \\/      |" << endl;
	cout << "|[1] Foods   [2] Drinks  [3] Ice Cream |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|             [0] Back                 |" << endl;
	cout << "+--------------------------------------+" << endl;
}

void foodsMenu(char foodsList[99][99], int foodsQty[99], float foodsPrice[99]) { //--------------------------------------------foodsMenu
	for (int i = 0; i < 4; i++) {
		cout << "   " << i + 1 << ". " << foodsList[i] << endl;
		cout << "   Price : RM " << foodsPrice[i] << " , Available : " << foodsQty[i] << endl;
		cout << endl;
		cout << "+--------------------------------------+" << endl;
	}
	cout << "|             [0] Back                 |" << endl;
	cout << "+--------------------------------------+" << endl;
}

void drinksMenu(char drinksList[99][99], int drinksQty[99], float drinksPrice[99]) { //------------------------------------------drinksMenu
	for (int i = 0; i < 3; i++) {
		cout << "    " << i + 1 << ". " << drinksList[i] << endl;
		cout << "    Price : RM " << drinksPrice[i] << " , Available : " << drinksQty[i] << endl;
		cout << endl;
		cout << "+--------------------------------------+" << endl;
	}
	cout << "|             [0] Back                 |" << endl;
	cout << "+--------------------------------------+" << endl;
}

void iceCreamMenu(char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99]) { //--------------------------------------iceCreamMenu
	for (int i = 0; i < 3; i++) {
		cout << "    " << i + 1 << ". " << iceCreamList[i] << endl;
		cout << "    Price : RM " << iceCreamPrice[i] << " , Available : " << iceCreamQty[i] << endl;
		cout << endl;
		cout << "+--------------------------------------+" << endl;
	}
	cout << "|             [0] Back                 |" << endl;
	cout << "+--------------------------------------+" << endl;
}



void custPayment(float totalMoneyThatCustNeedToPay, char whereItemGo, int totalCust, string custCollegeType[99], 
	string custRoomNumber[99]) { //-------- custPayment
	system("cls");
	int paymentKey;
	if (whereItemGo == 'S' || whereItemGo == 's') {
		cout << "+--------------------------------------+" << endl;
		cout << "|            PAYMENT METHOD            |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|         /--\\              (  )        |" << endl;
		cout << "|         |  |              (  )       |" << endl;
		cout << "|   [1] Pay On Pickup      [2] FPX      |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "       Choose payment method : ";
		cin >> paymentKey;
		if (paymentKey == 1) {
			system("cls");
			// add payOnPickup() method function
			cout << "+--------------------------------------+" << endl;
			cout << "|      Checked Out Successfully!       |" << endl;
			cout << "+--------------------------------------+" << endl;
			cout << "    Order Code : C" << totalCust << endl;
			cout << "    Total amount : RM " << totalMoneyThatCustNeedToPay << endl;
			cout << "    Thank you!" << endl;
			cout << "+--------------------------------------+" << endl;
			cout << "    Press Enter to continue ";
			getch();
		} else {
			system("cls");
			fpxPayment(totalMoneyThatCustNeedToPay);
			cout << "+--------------------------------------+" << endl;
			cout << "|      Checked Out Successfully!       |" << endl;
			cout << "+--------------------------------------+" << endl;
			sleep(3);
		}
	} else {
		string kolejType;
		string roomNumber;
		cout << "+--------------------------------------+" << endl;
		cout << "|         Enter your address :         |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "  1. Send to :" << endl;
		cout << "   [KMK] Kolej Mat Kilau" << endl;
		cout << "   [KTT] Kolej Tun Teja" << endl;
		cout << "   [BS] Bangunan Sarjana" << endl;
		cout << "   [BC] Bangunan Cendekiawan" << endl;
		cout << endl;
		cout << "  Enter : ";
		cin >> kolejType;
		cout << endl;
		cout << "  2. Room Number" << endl;
		cout << endl;
		cout << "  Enter : ";
		cin >> roomNumber;
		custCollegeType[totalCust] = kolejType;
		custRoomNumber[totalCust] = roomNumber;
		fpxPayment(totalMoneyThatCustNeedToPay);
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|      Checked Out Successfully!       |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "    Order Code : C" << totalCust << endl;
		cout << "    Total amount : RM " << totalMoneyThatCustNeedToPay << endl;
		cout << "    Delivery address : " << endl;
		cout << "       " << kolejType << "," << endl;
		cout << "       " << roomNumber << endl;
		cout << "    Thank you!" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "    Press Enter to continue ";
		getch();
	}
	totalCust = totalCust + 1;
}

void fpxPayment(float money) { //-----------------------------------fpxPayment
	system("cls");
	char bankKey;
	cout << "+--------------------------------------+" << endl;
	cout << "|              FPX GATEWAY             |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "| [A] Bank Islam                       |" << endl;
	cout << "| [B] BSN                              |" << endl;
	cout << "| [C] RHB                              |" << endl;
	cout << "| [D] Maybank                          |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "       Choose your bank : ";
	cin >> bankKey;
	if (bankKey == 'A' || bankKey == 'a') {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "| Redirecting to Bank Islam's page...  |" << endl;
		cout << "+--------------------------------------+" << endl;
		sleep(3);
	} else if (bankKey == 'B' || bankKey == 'b') {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|     Redirecting to BSN's page...     |" << endl;
		cout << "+--------------------------------------+" << endl;
		sleep(3);
	} else if (bankKey == 'C' || bankKey == 'c') {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|     Redirecting to RHB's page...     |" << endl;
		cout << "+--------------------------------------+" << endl;
		sleep(3);
	} else {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|   Redirecting to Maybank's page...   |" << endl;
		cout << "+--------------------------------------+" << endl;
		sleep(3);
	}
}

void noStock() { //-----------------------------------------------noStock
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|       Sorry, Item Out Of Stock!      |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "      Press Enter to continue ";
	getch();
}

void inputErrorHandling() {
	cout << "+--------------------------------------+" << endl;
	cout << "|            Invalid input!            |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "      Press Enter to continue ";
	getch();
}

void inputPlease() { //-----------------------------------------inputPlease
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|        Please input amount!          |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "      Press Enter to continue ";
	getch();
}

// FUNCTION (STAFF)

void staffOp(char staffName[99][99], char staffPass[99][99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99]) { //---------------------------------------------- staffOp
	if (isStaff != true) {
		isStaff = staffLogin(staffName, staffPass);
	}
	while (isStaff == true) {
		int keyStaff;
		staffMenu();
		cout << "    Enter key : ";
		cin >> keyStaff;
		if (keyStaff == 1) {
			stocksOp(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		} else if (keyStaff == 2) {
			statistics(totalCust, paymentList);
		} else if (keyStaff == 3) {
			addInfo();
		} else if (keyStaff == 4) {
			isStaff = false;
			main();
		} else if (keyStaff == 5) {
			bool termOrNot = terminateProgram(isTerminate, terminateKey);
			if (termOrNot == true) {
				isStaff = false;
			}
		} else {
			inputErrorHandling();
		}
	}
}

void stocksOp(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]) {
	int keyStocks;
	bool isKeyStocks = false;
	while (isKeyStocks == false) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|                STOCKS                |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|       [===]              =\\==        |" << endl;
		cout << "|       [===]              ==\\=        |" << endl;
		cout << "|  [1] View Stocks  [2] Update Stocks  |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "          Enter key : ";
		cin >> keyStocks;
		if (keyStocks == 1 || keyStocks == 2) {
			isKeyStocks = true;
		} else if (keyStocks == 0) {
			staffOp(staffName, staffPass, isStaff, isTerminate, terminateKey, totalCust, paymentList, foodsList, foodsQty, 
			foodsPrice, drinksList, drinksQty, drinksPrice, 
			iceCreamList, iceCreamQty, iceCreamPrice);
		} else {
			inputErrorHandling();
		}
	}
	if (keyStocks == 1) {
		viewStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
	} else if (keyStocks == 2) {
		updateStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
	}
}

void staffMenu() { //-------------------------------------------staffMenu
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|           K-SHOPPE STAFF             |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|   1. Stocks                          |" << endl;
	cout << "|   2. Statistics                      |" << endl;
	cout << "|   3. Additional Info                 |" << endl;
	cout << "|   4. Exit                            |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|  [5] Terminate Session               |" << endl;
	cout << "+--------------------------------------+" << endl;
}

bool staffLogin(char staffName[99][99], char staffPass[99][99]) { //------------------------------------------staffLogin
	system("cls");
	bool trueStaff = false;
	char username[99], password[99];
	cout << "+--------------------------------------+" << endl;
	cout << "|             STAFF LOGIN              |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "    Enter username : ";
	cin >> username;
	cout << "    Enter password : ";
	cin >> password;
	
	for (int i = 0; i < 3; i++) {
		if (strcmp(username, staffName[i]) == 0 && strcmp(password, staffPass[i]) == 0) {
			trueStaff = true;
		}
	}
	if (trueStaff == true) {
		cout << "+--------------------------------------+" << endl;
		cout << "|        Logged in successfully!       |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "       Press Enter to continue ";
		getch();
	} else {
		cout << "+--------------------------------------+" << endl;
		cout << "|    Invalid username or password!     |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "       Press Enter to continue ";
		getch();
	}
	
	return trueStaff;
}

void viewStocks(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], float foodsPrice[99], 
	char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]) { //------------------------------------------viewStocks
	int stocksKey;
	bool isKey = false;
	while (isKey == false) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|             VIEW STOCKS              |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   ooo          [ ]           Oo      |" << endl;
		cout << "|  \\___/         [ ]           \\/      |" << endl;
		cout << "|[1] Foods   [2] Drinks  [3] Ice Cream |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "    Choose category : ";
		cin >> stocksKey;
		
		if (stocksKey == 1 || stocksKey == 2 || stocksKey == 3) {
			isKey = true;
		} else if (stocksKey == 0) {
			stocksOp(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		} else {
			inputErrorHandling();
		}
	}
	if (stocksKey == 1) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => FOODS             |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "    " << i+1 << ". " << foodsList[i] << endl;
			cout << "    Stocks : " << foodsQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << endl;
		cout << "    Press Enter to back ";
		getch();
		viewStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
	} else if (stocksKey == 2) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => DRINKS            |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    " << i+1 << ". " << drinksList[i] << endl;
			cout << "    Stocks : " << drinksQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << endl;
		cout << "    Press Enter to back ";
		getch();
		viewStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
	} else {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => ICE CREAM         |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i+1 << ". " << iceCreamList[i] << endl;
			cout << " Stocks : " << iceCreamQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << endl;
		cout << "    Press Enter to back ";
		getch();
		viewStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
	}
}

void updateStocks(char staffName[99][99], char staffPass[99][99], char foodsList[99][99], int foodsQty[99], 
	float foodsPrice[99], char drinksList[99][99], int drinksQty[99], float drinksPrice[99], 
	char iceCreamList[99][99], int iceCreamQty[99], float iceCreamPrice[99], bool isStaff, bool isTerminate, int terminateKey, 
	int totalCust, float paymentList[99]) { //---------------------------------------updateStocks
	int stocksKey;
	bool isKey = false;
	while (isKey == false) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|            UPDATE STOCKS             |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|   ooo          [ ]           Oo      |" << endl;
		cout << "|  \\___/         [ ]           \\/      |" << endl;
		cout << "|[1] Foods   [2] Drinks  [3] Ice Cream |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "    Choose category : ";
		cin >> stocksKey;
		
		if (stocksKey == 1 || stocksKey == 2 || stocksKey == 3) {
			isKey = true;
		} else if (stocksKey == 0) {
			stocksOp(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		} else {
			inputErrorHandling();
		}
	}
	if (stocksKey == 1) {
		system("cls");
		int selectionKey, newVal;
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => FOODS             |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "    " << i+1 << ". " << foodsList[i] << endl;
			cout << "    Stocks : " << foodsQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << "    Choose item to be update : ";
		cin >> selectionKey;
		if (selectionKey == 0) {
			updateStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		}
		cout << "    Input new value : ";
		cin >> newVal;
		foodsQty[selectionKey-1] = newVal;
	} else if (stocksKey == 2) {
		system("cls");
		int selectionKey, newVal;
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => DRINKS            |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << "    " << i+1 << ". " << drinksList[i] << endl;
			cout << "    Stocks : " << drinksQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << "    Choose item to be update : ";
		cin >> selectionKey;
		if (selectionKey == 0) {
			updateStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		}
		cout << "    Input new value : ";
		cin >> newVal;
		drinksQty[selectionKey-1] = newVal;
	} else if (stocksKey == 3) {
		system("cls");
		int selectionKey, newVal;
		cout << "+--------------------------------------+" << endl;
		cout << "|          STOCKS => ICE CREAM         |" << endl;
		cout << "+--------------------------------------+" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " " << i+1 << ". " << iceCreamList[i] << endl;
			cout << " Stocks : " << iceCreamQty[i] << endl;
			cout << "+--------------------------------------+" << endl;
		}
		cout << "|             [0] Back                 |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << endl;
		cout << "    Choose item to be update : ";
		cin >> selectionKey;
		if (selectionKey == 0) {
			updateStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
		}
		cout << "    Input new value : ";
		cin >> newVal;
		iceCreamQty[selectionKey-1] = newVal;
	} else {
		inputErrorHandling();
	}
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|        STOCK HAS BEEN UPDATED        |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "    Press Enter to Continue ";
	getch();
	updateStocks(staffName, staffPass, foodsList, foodsQty, foodsPrice, drinksList, drinksQty, drinksPrice, 
		iceCreamList, iceCreamQty, iceCreamPrice, isStaff, isTerminate, terminateKey, totalCust, paymentList);
}

void statistics(int totalCust, float paymentList[99]) { //-------------------------------------------statistics
	system("cls");
	float moneyFromCust = 0;
	cout << "+--------------------------------------+" << endl;
	cout << "|             STATISTICS               |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|   Total customer : " << totalCust << endl;
	cout << "|" << endl;
	cout << "+--------------------------------------+" << endl;
	for (int i = 0; i < 99; i++) {
		if (paymentList[i] > 0) {
			moneyFromCust = moneyFromCust + paymentList[i];
		}
	}
	cout << "|   Total payment : RM " << moneyFromCust << endl;
	cout << "|" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "    Press Enter to back ";
	getch();
}

void addInfo() { //------------------------------------------------addInfo
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|           ADDITIONAL INFO            |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|     Program Informations,            |" << endl;
	cout << "|     Version : 1.0                    |" << endl;
	cout << "|     Last update : 14/1/2023          |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << endl;
	cout << "    Press Enter to back ";
	getch();
}

bool terminateProgram(bool isTerminate, int terminateKey) { //----------------------------------terminateProgram
	system("cls");
	int termKey;
	bool goTerminate;
	cout << "+--------------------------------------+" << endl;
	cout << "|          SESSION TERMINATION         |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "|   Are you sure? All saved data will  |" << endl;
	cout << "|               lost...                |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "     Press Enter to continue ";
	getch();
	system("cls");
	cout << "+--------------------------------------+" << endl;
	cout << "|          SESSION TERMINATION         |" << endl;
	cout << "+--------------------------------------+" << endl;
	cout << "    Enter key : ";
	cin >> termKey;
	if (termKey == terminateKey) {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|          SESSION TERMINATED          |" << endl;
		cout << "+--------------------------------------+" << endl;
		isTerminate = true;
		goTerminate = true;
	} else {
		system("cls");
		cout << "+--------------------------------------+" << endl;
		cout << "|       Invalid termination key!       |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|      Session termination failed!     |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "     Press Enter to continue ";
		getch();
		goTerminate = false;
	}
	return goTerminate;
}
