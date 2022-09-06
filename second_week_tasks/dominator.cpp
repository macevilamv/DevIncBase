#include <iostream>

using namespace std;

bool zeroDominator(int);
void writeToArray(bool[], int, int);
int getBinaryDigitsNumber(int);

int main()
{
	int const N = 170;
	bool result = false;
	
	result = zeroDominator(N);
	
	if (result)
		cout << "The are more zero's than one's" << endl;
		printBinary(N);
	else
		cout << "The are more one's than zero's" << endl;	
	
	return 0;
}

bool zeroDominator(int number)
{
	int oneCounter = 0;
	int zeroCounter = 0;
	int binDigitsNumber = getBinaryDigitsNumber(number);
	bool binDigits [binDigitsNumber];

    writeToArray(binDigits, number, binDigitsNumber);

	for (int i = 0; i < binDigitsNumber - 1; i++)
	{
		if (binDigits[i])
		{
			oneCounter++;
		} else {
            zeroCounter++;
        }
	}
	
	
	return zeroCounter > oneCounter;
}

void printBinary(bool array [], int binDigitsNumber)
{
	for (int i = 0; i < binDigitsNumber; i++)
    {
        cout << array[i];
    }
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

