#include <iostream>
#include <string>
using namespace std;

void inline Task1() {
    cout << "Enter text: ";
    string text;
    getline(cin, text);
    int summ = 0;
    for (size_t i = 0; i < text.size(); ++i) {
        summ = summ + ((int)(text[i] & 255));
    }
    cout << summ;
    cout << endl;
}

int* exchange(int* money, int size, int sum) {
    if (size == 0 || sum == 0) {
        return NULL;
    }
    int* rslt = (int*)calloc(100, sizeof(int));
    rslt[0] = 0;
    int current;
    int k = 1;
    for (size_t i = 0; i < size; i++) {
        current = 0;
        while (sum - current >= money[i]) {
            current += money[i];
            rslt[k] = money[i];
            rslt[0]++;
            k++;
            if (sum == current) {
                return rslt;
            }

        }
        sum -= current;
    }
    cout << "Exchange failed";
    return NULL;
}

void __fastcall printOneDimArray(int* arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void inline Task2() {
    int money[] = { 50, 10, 5, 2, 1 };
    int size = 5;
    int sum = 98;
    printOneDimArray(exchange(money, size, sum), 9);
}

int main()
{
    Task1();
    Task2();
    return 0;
}

