#include <iostream>

using namespace std;

bool validateBinaryRotation(int);
int getBinaryDigitsNumber(int);
void writeToArray(bool[], int, int);
void printBinaryNotation(bool array[], int);

int main()
{
	int const N = 170;
	bool result = false;
	
	if (N <= 0)
	{
		cout << "Error! Incorrect input: enter a positive more than zero number." << endl;
		return 1;
	}
	
	result = validateBinaryRotation(N);
	
	if (result) {
		cout << "The binary notation sequence of number is rotative"; 
	} else {
		cout << "The binary notation sequence of number is not rotative"; 
	}

	return 0;
}

bool validateBinaryRotation(int number)
{
    bool isRotative = false;
	int binDigitsNumber = getBinaryDigitsNumber(number);
	bool binDigits [binDigitsNumber];

    writeToArray(binDigits, number, binDigitsNumber);
    printBinaryNotation(binDigits, binDigitsNumber);

	for (int i = 0; i < binDigitsNumber - 1; i++)
	{
		if (binDigits[i] != binDigits[i+1])
		{
			isRotative = true;
		} else {
            isRotative = false;
            break;
        }
	}
	return isRotative;
}

void writeToArray(bool array [], int number, int binDigitsNumber) {
    int digit = 0;

    for (int i = 0; i < binDigitsNumber; i++)
    {
        digit = number % 2;
        number /= 2;
        array[i] = digit;
    }
}

int getBinaryDigitsNumber(int number)
{
	int digitNumber = 0;

	while(number > 0)
	{
		number /= 2;
		digitNumber++;
	}

	return digitNumber;
}

void printBinaryNotation(bool array[], int binDigitsNumber) 
{
	for (int i = 0; i < binDigitsNumber - 1; i++)
	{
		cout << array[i];
	}
	cout << endl;
}

