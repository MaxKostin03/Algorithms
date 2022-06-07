


#include <iostream>
#include <iomanip>
using namespace std;

//===================================Task1=======================================

void decBin(int n)
{
    if (n >= 2)
    {
        decBin(n / 2);
    }
    cout << n % 2;
}

void inline Task1()
{
    int n;
    cout << "Enter decimal number: ";
    cin >> n;
    cout << "Number in binary representation: ";
    decBin(n);
    cout << endl;
}

//===================================Task2=======================================

int Exponent(int number, unsigned int exp)
{
    if (exp > 0)
    {
        return number * Exponent(number, exp - 1);
    }
    return 1; 
}

int ExponentParity(int number, unsigned int exp)
{
    if (exp > 0)
    {
        if (exp % 2 == 0) 
        {
            return ExponentParity(number * number, exp/2);
        }
        else return number * ExponentParity(number, exp - 1);
    }
    return 1;
}


void inline Task2()
{
    int a;
    unsigned int b;
    cout << "Enter the number: " ;
    cin >> a;
    cout << "Enter the degree of the number: ";
    cin >> b;
    cout << "a^b = " << Exponent(a, b) << endl;
    cout << "a^b = " << ExponentParity(a, b) << endl;
    
}

//===================================Task3=======================================
int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);
}

int** init2dIntArray(int** array, const int row, const int col) {
    int* line = (int*) calloc(sizeof(int), row * col);
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = &line[i*col];
    }
    return array;
}

void set2dInt(int** array, const int row, const int col, int value) {
    *((*(array + row)) + col) = value;
}

void __fastcall print2dIntArray(int** arr, const int row, const int col) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
        cout << endl;
    }
}

int kingMove(int x, int y, int** arr) {
    if (get2dInt(arr, y, x) == 1) {
        return 0;
    }
    if (x == 0 && y == 0) {
        return 0;
    }
    else if (x == 0) {
        if (kingMove(x, y - 1, arr) == 0 && y != 1) {
            return 0;
        }
        else {
            return 1;
        }
    }
    else if (y == 0) {
        if (kingMove(x - 1, y, arr) == 0 && x != 1) {
            return 1;
        }

        return kingMove(x, y - 1, arr) + kingMove(x - 1, y, arr);
    }
}

void inline Task3()
{
    size_t SZ = 6;
    int** desk = init2dIntArray(desk, SZ, SZ);
    set2dInt(desk, 0, 2, 1);
    set2dInt(desk, 2, 1, 1);
    set2dInt(desk, 2, 2, 1);
    print2dIntArray(desk, SZ, SZ);
    cout << endl;
    for (size_t y = 0; y < SZ; y++) {
        for (size_t x = 0; x < SZ; x++) {
            cout << kingMove(x, y, desk);
        }
        cout << endl;
        cout << endl;
    }
    
   
}


int main()
{

    Task1();
    Task2();
    Task3();
    return 0;
}
