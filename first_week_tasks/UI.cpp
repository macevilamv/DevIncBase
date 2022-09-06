#include <iostream>

using namespace std;

void printMenu();
double getMoney();
double convertBYNtoUSD(double byn);
double const USD_RATE = 2.5678;

int main () {
	
	int choice = 0;
	double byn = 0.0;
	
	while(true) {
		printMenu();
		cout << "Your choice? ";
		cin >> choice;
		if (choice == 1) {
			byn = getMoney();
			cout << "Ok, " << byn << " BYN deposited.";
		}
		else if (choice == 2) {
			cout << "Ok, take your " <<	convertBYNtoUSD(byn) << " USD";
		}
		else if (choice == 5)
			break;
		else 
			cout << "Select [1..5], please" << endl;	
	}
	return 0;
}

void printMenu()
{
	cout << endl << "Currency Exchange Point" << endl;
	cout << "1) Deposite BYN" << endl;
	cout << "2) Convert to USD" << endl;
	cout << "0) Exit" << endl;
}

double getMoney()
{
	return 100.0;
}

double convertBYNtoUSD(double byn) {
	return byn / USD_RATE;
}
