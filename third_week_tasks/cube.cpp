#include <iostream>

using namespace std;

void print();
bool isTransparent();

int const N = 3;
int arr[N][N][N] = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                    {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}}};

int main()
{
    print();
	
	if (isTransparent)
	{
		cout << "Cube is transparent";	
	} else {
		  cout << "There is no transparency";
	}
}

bool isTransparent()
{
	bool hasTransparencyX = true;
    bool hasTransparencyY = true;
    bool hasTransparencyZ = true;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {

                if (arr[k][i][j] == 0) {
                    hasTransparencyX = false;
                }

                if (arr[i][k][j] == 0) {
                    hasTransparencyY = false;
                }

                if (arr[i][j][k] == 0) {
                    hasTransparencyZ = false;
                }
        }
            if (hasTransparencyX or hasTransparencyY or hasTransparencyZ)
            {
               return true;
            }
            hasTransparencyX = true;
            hasTransparencyY = true;
            hasTransparencyZ = true;
        }
    }
    
    return false;
}

void print()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

