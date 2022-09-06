#include <iostream>

using namespace std;

int main()
{
    int yBishop1 = 0;
    int xBishop1 = 0;
    int yBishop2 = 0;
    int xBishop2 = 0;
    bool answer = false;
    bool errorConditionBishop1 = false;
    bool errorConditionBishop2 = false;

    cout << "Enter coordinates X for the first bishop: ";
    cin >> xBishop1;
    cout << "Enter coordinates Y for the first bishop: ";
    cin >> yBishop1;
    cout << "Enter coordinates X for the second bishop: ";
    cin >> xBishop2;
    cout << "Enter coordinates Y for the second bishop: ";
    cin >> yBishop2;
    
    errorConditionBishop1 = (xBishop1 > 8 or xBishop1 < 1) or (yBishop1 > 8 or yBishop2 < 1);
    errorConditionBishop2 = (yBishop1 > 8 or yBishop2 < 1) or (xBishop2 > 8 or xBishop1 < 1);

    if (errorConditionBishop1 or errorConditionBishop2) {
        cout << "Error: Wrong coordinates. Use numbers < 9 and > 0" << endl;
        return 1;
    }
	if (xBishop1 == xBishop2 and yBishop1 == yBishop2) {
        cout << "Error: Wrong coordinates. Bishops are in the same position";
        return 2;
    }

    for (int i = 0; i < 8; i++) {
        if (xBishop1 + i == xBishop2 and yBishop1 + i == yBishop2) {
            answer = true;
        }
        if (xBishop1 == xBishop2 - i and yBishop1 == yBishop2 - i) {
            answer = true;
        }
        if (xBishop1 - i == xBishop2 and yBishop1 + i == yBishop2) {
            answer = true;
        }
        if (xBishop1 + i == xBishop2 and yBishop1 - i == yBishop2) {
            answer = true;
        }
    }

    if (answer) {
        cout << "Bishops can beat one another!";
    } else {
        cout << "Bishops can't beat one another!";
    }

    return 0;
}
