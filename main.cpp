#include <iostream>
using namespace std;

//==================================== global var =======================

char staffName[99][99] = {"Luqman", "Adib", "Zarif", "0"};
char staffPass[99][99] = {"luqman123", "adibudeen", "zash04"};
char foodsList[99][99] = {"Nasi Minyak Ayam Kari", "Nasi Minyak Ayam Merah", "Mee Kari", "Nasi Kandar", "0"};
int foodsQty[99] = {10, 10, 10, 10};
float foodsPrice[99] = {7.00, 7.00, 6.00, 8.00};
char drinksList[99][99] = {"Milo Kotak", "Jagung Susu", "Air Kosong", "0"};
int drinksQty[99] = {10, 10, 10};
float drinksPrice[99] = {2.50, 5.00, 1.00};
char iceCreamList[99][99] = {"Magnolia", "Aiskrim Malaysia", "Magnum", "0"};
int iceCreamQty[99] = {10, 10, 10};
float iceCreamPrice[99] = {7.00, 0.50, 4.50};

//==================================== fn def ===========================

void custOp();
void staffOp();
void custMenu();
void staffMenu();
bool staffLogin();
float custOrder();
void foodsMenu();
void drinksMenu();
void iceCreamMenu();
void stationariesMenu();

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
	float totalPayment;
	
	while (isShopping == true) {
		totalPayment = custOrder();
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
	int totalFoods = 0;
	while (foodsList[totalFoods] != "0") {
		totalFoods++;
	}
	for (int i = 0; i < totalFoods; i++) {
		cout << " " << i + 1 << ". " << foodsList[i] << endl;
		cout << " Price : RM " << foodsPrice[i] << " , Available : " << foodsQty[i] << endl;
		cout << endl;
	}
}

void drinksMenu() { //------------------------------------------drinksMenu
	int totalDrinks = 0;
	while (drinksList[totalDrinks] != "0") {
		totalDrinks++;
	}
	for (int i = 0; i < totalDrinks; i++) {
		cout << " " << i + 1 << ". " << drinksList[i] << endl;
		cout << " Price : RM " << drinksPrice[i] << " , Available : " << drinksQty[i] << endl;
		cout << endl;
	}
}

void iceCreamMenu() { //--------------------------------------iceCreamMenu
	int totalIceCream = 0;
	while (totalIceCream < 3) {
		if (iceCreamList[totalIceCream] != "0") {
			cout << " " << totalIceCream + 1 << ". " << iceCreamList[totalIceCream] << endl;
			cout << " Price : RM " << iceCreamPrice[totalIceCream] << " , Available : " << iceCreamQty[totalIceCream] << endl;
			cout << endl;
		}
		totalIceCream++;
	}
}

float custOrder() { //------------------------------------------ custOrder
	char itemCart[99][99] = {};
	char itemPrice[99] = {};
	char itemQty[99] = {};
	bool isAdding = true;
	
	while (isAdding == true) {
		char category;
		custMenu();
		cout << " Choose category : ";
		cin >> category;
		
		if (category == '1') {
			cout << "+-------------+" << endl;
			cout << " Shop! >> Foods" << endl;
			cout << "+-------------+" << endl;
			foodsMenu();
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
		isAdding = false;
	}
}
