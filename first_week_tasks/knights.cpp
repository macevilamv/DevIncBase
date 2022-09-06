#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int yKnight1 = 0;
    int xKnight1 = 0;
    int yKnight2 = 0;
    int xKnight2 = 0;
    int maxSize = 8;
    int minSize = 1;
    bool answer = false;
    bool errorConditionKnight1 = false;
    bool errorConditionKnight2 = false;
    const int ONE_STEP = 1;
    const int TWO_STEPS = 2;
	int xDifference = 0;
	int yDifference = 0; 

    cout << "Enter coordinates X for the first knight: ";
    cin >> xKnight1;
    cout << "Enter coordinates Y for the first knight: ";
    cin >> yKnight1;
    cout << "Enter coordinates X for the second knight: ";
    cin >> xKnight2;
    cout << "Enter coordinates Y for the second knight: ";
    cin >> yKnight2;
    
    errorConditionKnight1 = (xKnight1 > maxSize or xKnight1 < minSize) or (yKnight1 > maxSize or yKnight2 < minSize);
    errorConditionKnight2 = (xKnight2 > maxSize or xKnight1 < minSize) or (yKnight1 > maxSize or yKnight2 < minSize);
    
    if (errorConditionKnight1 or errorConditionKnight2) {
		cout << "Error: Wrong coordinates. Use numbers < 9 and > 0" << endl;
		return 1;
    }
	if (xKnight1 == xKnight2 and yKnight1 == yKnight2) {
    	cout << "Error: Wrong coordinates. Horses in the same position";
    	return 2;
    }
    
    xDifference = abs(xKnight1 - xKnight2);
    yDifference = abs(yKnight1 - yKnight2);
    
    if (xDifference == TWO_STEPS and yDifference == ONE_STEP or xDifference == ONE_STEP and yDifference == TWO_STEPS) {
		answer = true;
	}
            
    if (answer) {
        cout << "Kngihts can beat one another!";
    } else {
        cout << "Knights can't beat one another!";
    }

    return 0;
}
