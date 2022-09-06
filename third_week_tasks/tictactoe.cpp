#include <iostream>
#include <windows.h>

using namespace std;

void printActualGameField();
void printInitialGameField();
void printTurns();
void getPlayer();
void takePlayerTurn();
void clear();
void printGreeting();
void start();
void gameProcess();
bool checkGameStatus();
void machineTurn();
void makeTurn(int);
void zerosTurn();
void crossesTurn();
bool checkXwin();
bool checkOwin();
bool checkTurnCorrectness(int turn);
int calculateGoodTurn(int);
void machineFirstTurn();
int convertFieldToNumber(int x, int y);
int findHorizontal(int, int);
int findVertical(int, int);
int findDiagonal1();
int findDiagonal2();
int findCell(int owner);

int const FIELD_SIZE = 3;
int gameField[FIELD_SIZE][FIELD_SIZE] = {{0,0,0}, {0,0,0}, {0,0,0}};
int player = 0;
int ai = 0;
bool isGameOver = false;
int xWin = 0;
int oWin = 0;
int turns [FIELD_SIZE * FIELD_SIZE] = {0};
int turnId = 0;
int const goodChoiceNum = 5;
int  bestPractice [goodChoiceNum] = {5,1,3,7,9};


int main()
{
    start();
    gameProcess();
}

void printActualGameField()
{
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            for (int j = 0; j < FIELD_SIZE; j++)
            {
                if (gameField[i][j] == 1)
                {
                    cout << " " << "X";
                } else if (gameField[i][j] == 2)
                {
                    cout << " " <<"0";
                } else {
                    cout << " " << " ";
                }

                if (j != FIELD_SIZE - 1)
                    cout << " |";
            }
            if (i != FIELD_SIZE - 1)
                cout << endl << "---|---|---"<< endl;
        }
        cout << endl << endl;
}

void printTurns()
{
    for (int i = 1; i <= FIELD_SIZE * FIELD_SIZE; i++)
    {
        cout << i << " ";
        if (i % FIELD_SIZE == 0)
            cout << endl;
    }
}

void makeTurn(int turn, int owner)
{
    turns[turnId] = turn;
    turnId++;

    switch (turn) {
        case 1:
            gameField[0][0] = owner;
            break;
        case 2:
            gameField[0][1] = owner;
            break;
        case 3:
            gameField[0][2] = owner;
            break;
        case 4:
            gameField[1][0] = owner;
            break;
        case 5:
            gameField[1][1] = owner;
            break;
        case 6:
            gameField[1][2] = owner;
            break;
        case 7:
            gameField[2][0] = owner;
            break;
        case 8:
            gameField[2][1] = owner;
            break;
        case 9:
            gameField[2][2] = owner;
            break;
        default:
            cout << "Please, enter a valid number";
    }
}

void takePlayerTurn()
{
    int turn = 0;

    while(true) {
        cout << "Please enter a 1 - 9 number to make your turn..." << endl;
        cin >> turn;

        if (checkTurnCorrectness(turn))
        {
            makeTurn(turn, player);
            break;
        } else {
            cout << "Incorrect turn! There already was such turn!" << endl << endl;
        }
    }
}

void getPlayer()
{
    while (player != 1 or player != 2)
    {
        cout << "Choose your side: " << endl;
        cout << "1: X " << endl;
        cout << "2: 0 " << endl << endl;

        cin >> player;
        cout << endl;

        if (player == 1)
        {
            ai = 2;
            cout << "You are playing X" << endl;
            cout << "AI is playing 0" << endl << endl;
            break;
        } else if (player == 2)
        {
            ai = 1;
            cout << "You are playing 0" << endl;
            cout << "AI is playing X" << endl << endl;
            break;
        }
        cout << "Please enter a valid number..." << endl;
    }
}

void clear()
{
    system("cls");
}

void printGreeting()
{
    cout << "       WELCOME  "<< endl;
    cout << "to the Tic Tac Toe game!" << endl;
    cout << endl;
}

void start()
{
    printGreeting();
    getPlayer();
    printActualGameField();
}

void gameProcess()
{
    while (true)
    {
        printTurns();
        crossesTurn();
        isGameOver = checkGameStatus();
        clear();
        printActualGameField();

        if (isGameOver)
            break;

        clear();
        printActualGameField();
        printTurns();
        zerosTurn();
        isGameOver = checkGameStatus();
        clear();
        printActualGameField();

        if (isGameOver)
            break;

        clear();
        printActualGameField();

    }

    if  (oWin == 1)
    {
        cout << "0 wins!" << endl << endl;
        cout << "GAME IS OVER!" << endl;
        return;
    }

    if (xWin == 1)
    {
        cout << "X wins!" << endl << endl;
        cout << "GAME IS OVER!" << endl;
        return;
    }

    cout << "TIE!" << endl;
    cout << "GAME IS OVER!" << endl;
}

bool checkGameStatus()
{
    if (checkXwin())
    {
        xWin = 1;
        return true;
    }

    if (checkOwin()) {
        oWin = 1;
        return true;
    }

    if (turnId >= 9)
    {
        return true;
    }

    return false;
}

void machineTurn()
{
    int turn = 0;

    if (turnId <= 1)
    {
        machineFirstTurn();
        return;
    }

    turn = calculateGoodTurn(ai);

    if (turn != 0) {
        makeTurn(turn, ai);
        return;
    }

    turn = calculateGoodTurn(player);

    if (turn != 0) {
        makeTurn(turn, ai);
        return;
    }

    turn = findCell(ai);

    if (turn != 0) {
        makeTurn(turn, ai);
        return;
    }
}

void zerosTurn()
{
    if (player == 2)
    {
        takePlayerTurn();
    } else {
        machineTurn();
    }
}

void crossesTurn()
{
    if (player == 1)
    {
        takePlayerTurn();
    } else {
        machineTurn();
    }
}

bool checkXwin()
{
    int winCondition1 = 0;
    int winCondition2 = 0;
    int winCondition3 = 0;
    int winCondition4 = 0;

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0, k = FIELD_SIZE - 1; j < FIELD_SIZE; j++, k--) {
            if (gameField[i][j] == 1)
            {
                winCondition1++;
            }
            if (gameField[j][i] == 1)
            {
                winCondition2++;
            }
            if (gameField[j][j] == 1)
            {
                winCondition3++;
            }
            if (gameField[j][k] == 1)
            {
                winCondition4++;
            }
        }
        if (winCondition1 == 3
            or winCondition2 == 3
            or winCondition3 == 3
            or winCondition4 == 3)
            return true;

        winCondition1 = 0;
        winCondition2 = 0;
        winCondition3 = 0;
        winCondition4 = 0;
    }
    return false;
}

bool checkOwin()
{
    int winCondition1 = 0;
    int winCondition2 = 0;
    int winCondition3 = 0;
    int winCondition4 = 0;

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0, k = FIELD_SIZE - 1; j < FIELD_SIZE; j++, k--) {
            if (gameField[i][j] == 2)
            {
                winCondition1++;
            }
            if (gameField[j][i] == 2)
            {
                winCondition2++;
            }
            if (gameField[j][j] == 2)
            {
                winCondition3++;
            }
            if (gameField[j][k] == 2)
            {
                winCondition4++;
            }
        }
        if (winCondition1 == FIELD_SIZE
            or winCondition2 == FIELD_SIZE
            or winCondition3 == FIELD_SIZE
            or winCondition4 == FIELD_SIZE)
            return true;

        winCondition1 = 0;
        winCondition2 = 0;
        winCondition3 = 0;
        winCondition4 = 0;
    }
    return false;
}

bool checkTurnCorrectness(int turn)
{
    for (int i = 0; i < FIELD_SIZE * FIELD_SIZE; i++) {
        if (turns[i] == turn) {
            return false;
        }
    }
    return true;
}

int calculateGoodTurn(int owner)
{
    cout << "Hello from calculateGoodTurn!!" << endl;

    int winCondition1 = 0;
    int winCondition2 = 0;
    int winCondition3 = 0;
    int winCondition4 = 0;
    int turn = 0;

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0, k = FIELD_SIZE - 1; j < FIELD_SIZE; j++, k--) {
            if (gameField[i][j] == owner)
            {
                winCondition1++;
            }
            if (gameField[j][i] == owner)
            {
                winCondition2++;
            }
            if (gameField[j][j] == owner)
            {
                winCondition3++;
            }
            if (gameField[j][k] == owner)
            {
                winCondition4++;
            }
        }
        if (winCondition1 == 2)
        {
           turn = findHorizontal(owner, i);
           if (checkTurnCorrectness(turn)) {
               return turn;
           }

        }

        if (winCondition2 == 2)
        {
            turn = findVertical(owner, i);
            if (checkTurnCorrectness(turn)) {
                return turn;
            }
        }

        if (winCondition3 == 2)
        {
            turn = findDiagonal1();
            if (checkTurnCorrectness(turn)) {
                return turn;
            }
        }

        if (winCondition4 == 2)
        {
            turn = findDiagonal2();
            if (checkTurnCorrectness(turn)) {
                return turn;
            }
        }

        winCondition1 = 0;
        winCondition2 = 0;
        winCondition3 = 0;
        winCondition4 = 0;
    }
    return 0;
}

void machineFirstTurn()
{
    for (int i = 0; i < goodChoiceNum; i++) {
        if (checkTurnCorrectness(bestPractice[i])) {
            makeTurn(bestPractice[i], ai);
            break;
        }
    }
}

int convertFieldToNumber(int x, int y)
{
    int number = 0;
    number = (FIELD_SIZE  * y) + x + 1;
    return  number;
}

int findHorizontal(int onwer, int i)
{
    for (int j = 0; j < FIELD_SIZE ; j++) {
        if (gameField[i][j] == 0)
        {
            return convertFieldToNumber(j, i);
        }
    }
}

int findVertical(int owner, int i)
{
    for (int j = 0; j < FIELD_SIZE; j++) {
        if (gameField[j][i] == 0)
        {
            return convertFieldToNumber(i, j);
        }
    }
}

int findDiagonal1()
{
    for (int i = 0; i < FIELD_SIZE; i++) {
        if (gameField[i][i] == 0)
        {
            return convertFieldToNumber(i, i);
        }
    }
}

int findDiagonal2()
{
    for (int i = FIELD_SIZE - 1, k = 0; k < FIELD_SIZE and i >= 0; i--, k++) {
        if (gameField[k][i] == 0)
        {
            return convertFieldToNumber(i, k);
        }
    }
}

int findCell(int owner) {
    int rowSum = 0;
    int columnSum = 0;
    int diagonal1Sum = 0;
    int diagonal2Sum = 0;

    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0, k = FIELD_SIZE - 1; j < FIELD_SIZE and k >= 0; j++, k--) {
            rowSum += gameField[i][j];
            columnSum += gameField[j][i];
            diagonal1Sum += gameField[j][j];
            diagonal2Sum += gameField[j][k];
        }

        if (rowSum == owner)
        {
            if (checkTurnCorrectness(convertFieldToNumber(0, i)))
            {
                return convertFieldToNumber(0, i);
            }
            if (checkTurnCorrectness(convertFieldToNumber(2, i))){
                return convertFieldToNumber(2, i);
            }
        }
        if (columnSum == owner)
        {
            if (checkTurnCorrectness(convertFieldToNumber(i, 0)))
            {
                return convertFieldToNumber(i, 0);
            }
            if (checkTurnCorrectness(convertFieldToNumber(i, 2))) {
                return convertFieldToNumber(i, 2);
            }
        }

        if (diagonal1Sum == owner)
        {
            if (checkTurnCorrectness(convertFieldToNumber(0, 0)))
            {
                return convertFieldToNumber(0, 0);
            }
            if (checkTurnCorrectness(convertFieldToNumber(2,2)))
            {
                return convertFieldToNumber(2,2);
            }
        }

        if (diagonal2Sum == owner)
        {
            if (checkTurnCorrectness(convertFieldToNumber(0, 2)))
            {
                return convertFieldToNumber(0, 2);
            }
            if (checkTurnCorrectness(convertFieldToNumber(2,0)))
            {
                return convertFieldToNumber(2,0);
            }
        }

        rowSum = 0;
        columnSum = 0;
        diagonal1Sum = 0;
        diagonal2Sum = 0;
    }

    return 0;
}
