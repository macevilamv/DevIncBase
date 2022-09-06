#include <iostream>
#include <iomanip>

using namespace std;

const int N = 15;

int main()
{	
	int maxNumber = N * N;
	int maxNumberDigits = 0;
	int setwParameter = 0;
	
	while(maxNumber > 0)
	{
		maxNumber /= 10;
		maxNumberDigits++;
	}
	
	setwParameter = maxNumberDigits + 1;
	maxNumberDigits = 0;
	
	for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
        	cout << setw(setwParameter) << i * j;
    
        }
        cout << "\n";
    }
	
    return 0;
}

