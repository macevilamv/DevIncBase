#include <iostream>

using namespace std;

void findInvisiblePoints(double points[], int n);
double calculateAlphaParameter(double max, double start, int coordinate);
double calculateVisibleHeight(double start, double alpha, int coordinate);
void showInvisible();

const int STEP_SIZE = 1;
const int N = 10;
double points [N] = {3, 2 , 2,  2, 20, 9, 2 , 2, 4, 50};
double inVisible[N - 1];

int main()
{
    findInvisiblePoints(points, N);
    showInvisible();

    return 0;
}


void findInvisiblePoints(double points[], int n)
{
    double max = 0.0;
    double start = points[0];
    double alpha = 0.0;
    int invisibleCounter = 0;
    double yPredicted = 0.0;

    for (int i = 1; i < n; i++)
    {
        if (max == 0.0)
        {
            if (start < points[i])
            {
                max = points[i];
                alpha = calculateAlphaParameter(max, start, i * STEP_SIZE);
            }
        }

        if (max != 0)
        {
            yPredicted = calculateVisibleHeight(start, alpha, i * STEP_SIZE);

            if (points[i] < yPredicted)
            {
                inVisible[invisibleCounter] = i;
                invisibleCounter++;
            }

            if (points[i] > yPredicted)
            {
                max = points[i];
                alpha = calculateAlphaParameter(max, start, i * STEP_SIZE);
            }
        }
    }
    inVisible[invisibleCounter] = '\0';
}

void showInvisible()
{
    int ind = 0;
    for (int i = 0; inVisible[i] != '\0'; i++) {
        ind = inVisible[i];
        cout << "Point [" << ind + 1 << "] value= " << points[ind] << " is not visible. " << endl;
    }
}

double calculateAlphaParameter(double max, double start, int coordinate)
{
    double alpha = (max - start) / coordinate;

    return alpha;
}

double calculateVisibleHeight(double start, double alpha, int coordinate)
{
    double visibleHeight = 0.0;

    visibleHeight = (alpha * coordinate) + start;

    return visibleHeight;
}

