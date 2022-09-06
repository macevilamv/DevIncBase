#include <iostream>
#include <windows.h>

using namespace std;

void print();
void rotate();
bool areAntagonists(char ch1, char ch2);
void clear();
void getSoundSignal();

int const N = 10;
char arr[N] = {'<', '<', '>','<', '<', '<', '>','<', '<', '>'};

int main()
{	
	print();
	Sleep(3000);
	clear();
    print();
    Sleep(3000);
   	clear();
    rotate();
    getSoundSignal();
}

void print()
{
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotate()
{
    char holder = '\0';
    int nRot = N;

    while(nRot > 0)
    {
        for (int i = 0; i < N - 1; i++) {
            if (areAntagonists(arr[i], arr[i + 1])) {
                holder = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = holder;
            }
        }
        
        print();
      	Sleep(1000);
        clear();
        nRot -= 1;
    }
}

char getAntagonist(char ch)
{
    if (ch == '<') {
        return '>';
    } else if (ch == '>') {
        return '<';
    }
}



bool areAntagonists(char ch1, char ch2)
{
    if (ch1 == '>' and ch2 == '<')
        return true;
    else
        return false;
}

void clear()
{
	system("cls");
}

void getSoundSignal()
{
	cout << "*SOUND SIGNAL*" << endl;
}
