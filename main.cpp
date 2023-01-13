#include <iostream>
#include <list>
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

//==================================== fn def ===========================

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

//==================================== main =============================

int main() {
	char custOrStaff;
	bool exitProgram = false;
	
	while (exitProgram == false) {
		cout << "+----------+" << endl;
		cout << " 1. Customer" << endl;
		cout << " 2. Staff" << endl;
		cout << " 3. Exit" << endl;
		cout << "+----------+" << endl;
		cout << " Enter key : ";
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

//=================================== fn proto ==========================

void custOp() { //------------------------------------------------ custOp
	bool isShopping = true;
	
	while (isShopping == true) {
		custOrder();
		isShopping = false;
	}
}

void staffOp() { //---------------------------------------------- staffOp
	bool isStaff = staffLogin();
	if (isStaff == true) {
		staffMenu();
	}
}

void custMenu() { //---------------------------------------------custMenu
	cout << "+----------------+" << endl;
	cout << " K-SHOPPE ONLINE" << endl;
	cout << "+----------------+" << endl;
	cout << " 1. Foods" << endl;
	cout << " 2. Drinks" << endl;
	cout << " 3. Ice Cream" << endl;
	cout << "+----------------+" << endl;
}

void staffMenu() { //-------------------------------------------staffMenu
	cout << "+----------------+" << endl;
	cout << " K-SHOPPE STAFF" << endl;
	cout << "+----------------+" << endl;
	cout << " 1. Stocks" << endl;
	cout << " 2. Item/Goods" << endl;
	cout << " 3. Statistics" << endl;
	cout << " 4. Additional Info" << endl;
	cout << "+----------------+" << endl;
}

bool staffLogin() { //------------------------------------------staffLogin
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
	
	cout << "+------------------------+" << endl;
	cout << " [S] Self Pickup" << endl;
	cout << " [D] Delivery" << endl;
	cout << "+------------------------+" << endl;
	cout << "Choose your preference : ";
	cin >> pickupMethod;
	
	while (isAdding == true) {
		char category;
		custMenu();
		cout << " Choose category : ";
		cin >> category;
		
		if (category == '1') {
			int orderKey;
			cout << "+-------------+" << endl;
			cout << " Shop! >> Foods" << endl;
			cout << "+-------------+" << endl;
			foodsMenu();
			cout << "Choose your food : ";
			cin >> orderKey;
			if (orderKey == 1) {
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
						break;
					}
				}
			} else if (orderKey == 2) {
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
						break;
					}
				}
			} else if (orderKey == 3) {
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
						break;
					}
				}
			} else if (orderKey == 4) {
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
						break;
					}
				}
			}
		} else if (category == '2') {
			cout << "+-------------+" << endl;
			cout << " Shop! >> Drinks" << endl;
			cout << "+-------------+" << endl;
			drinksMenu();
		} else {
			cout << "+-------------+" << endl;
			cout << " Shop! >> Ice Cream" << endl;
			cout << "+-------------+" << endl;
			iceCreamMenu();
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
			cout << "Checkout successfully!" << endl;
		} else {
			cout << "Choosing bank..." << endl;
			// edit this part later!
		}
	} else {
		cout << "+-----------------+" << endl;
		cout << "| PAYMENT METHOD  |" << endl;
		cout << "+-----------------+" << endl;
		cout << "Choosing bank..." << endl;
		cout << "Checkout successfully" << endl;
	}
}
