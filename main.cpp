#include <iostream>
using namespace std;

//==================================== global var =======================

char staffName[99][99] = {"Luqman", "Adib", "Zarif"};
char staffPass[99][99] = {"luqman123", "adibudeen", "zash04"};
char foodList[99][99] = {"Maggi Ayam", "Maggi Tomye", "Samyang Cheese"};
int foodQty[99] = {10, 10, 10};
float foodPrice[99] = {5.00, 5.00, 5.50};

//==================================== fn def ===========================

void custOp();
void staffOp();
void custMenu();
void staffMenu();
bool staffLogin();

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
	custMenu();
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
	cout << " 4. Stationaries" << endl;
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
	cout << "Enter username : ";
	cin >> username;
	cout << "Enter password : ";
	cin >> password;
	
	for (int i = 0; i < 3; i++) {
		if (strcmp(username, staffName[i]) == 0 && strcmp(password, staffPass[i]) == 0) {
			trueStaff = true;
		}
	}
	
	return trueStaff;
}
