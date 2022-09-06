#include <iostream>

using namespace std;

int getReversedNumber(int);
int getDigitsNumber(int);
int getMultiplier(int);
int transform(int, int, int);

int main()
{
	const int N = 1234;
	int result = 0;
	
	if (N <= 0) {
		cout << "Error! Incorrect input: enter a positive more than zero number." << endl;
		return 1;
	}
	
	result = getReversedNumber(N);
	
	cout << result;
	
	return 0;
}

int getReversedNumber(int number)
{	
	int digitNumber = 0;
	int multiplier = 0;

	digitNumber = getDigitsNumber(number);
	multiplier = getMultiplier(digitNumber);
	
	return transform(number, digitNumber, multiplier);	
}

int getDigitsNumber(int number)
{
	int digitNumber = 0;
	
	while(number > 0)
	{
		number /= 10;
		digitNumber++;
	}
	
	return digitNumber;
}

int transform(int number, int digitNumber, int multiplier)
{
	int digit = 0;
	int reversedNumber = 0;
	
	while (number > 0)
	{
		digit = number % 10;
		reversedNumber += digit * multiplier;
		multiplier /= 10;
		number /= 10;
	}
	
	return reversedNumber;	
}


int getMultiplier(int digitsNumber)
{
	int multiplier = 10;
	
	for (int i = 1; i < digitsNumber - 1; i++)
	{
		multiplier *= 10;
	}
	
	return multiplier;
}


