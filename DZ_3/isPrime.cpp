#include <iostream>
#include <clocale>
using namespace std;


void _fastcall isPrime(int number)
{
    int i = 1;
    int k = 0;
    while (i <= number)
    {
        if (number % i++ == 0)
        {
            k++;
        }
        else
        {
            continue;
        }
        if (k == 3)
        {
            break;
        }
    }
    if (k == 2)
    {
        cout << "Введенное число " << number << " является простым" << endl;
    }
    else
        cout << "Введенное число " << number << " не является простым" << endl;
}




int main()
{

    setlocale(LC_ALL, "Russian");   
    int c;
    cout << "Введите число: ";
    cin >> c;
    
    isPrime(c);
    
}