

#include <iostream>
#include <stack>  
using namespace std;
#define SZ 10
typedef struct {
    int pr; 
    int dat; 
} Node;

Node* arr[SZ];
int head; 
int tail; 
int items; 

void init() {
    for (size_t i = 0; i < SZ; i++) {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void printQueue() {
    for (size_t i = 0; i < SZ; i++) {
        if (arr[i]==NULL) {
            cout << "[*, *]";
        }
        else {
            cout << "[" << arr[i]->pr << ", " << arr[i]->dat << "]";
        }
        cout << endl;
    }
}

void insException(int pr, int dat) { //включение элемента в очередь с приоритетным исключением
    Node* node = new Node;  
    node->dat = dat;
    node->pr = pr;
    int flag; 
    if (items == 0) { 
        arr[tail++] = node; 
        items++; 
    }
    else if (items == SZ) { 
        cout << "Queue is full" << endl;
        return;
    }
    else { 
        int i = 0; 
        int idx = 0;
        for (i = head; i < tail; i++) {
            idx = i % SZ;
            idx++; 
        }
        flag = idx % SZ;
        i++;
        arr[flag] = node; 
        items++;
        tail++;
    }
}

void remException() {
    int maxPr = 0;
    int max = 0; 
    Node* note = new Node;
    if (items == 0) {
        return;
    }
    int i = 0; 
    maxPr = arr[0]->pr;
    for (i = head; i < tail; i++) {
        if (arr[i] != NULL) {
            if (arr[i]->pr > maxPr) {
                maxPr = arr[i]->pr;
                max = i;
            }
        }
    }
    cout << "The element with the highest priority [" << arr[max]->pr << "]" << "[" << arr[max]->dat << "] " << "is removed" << endl;
    for ( int i = max; i < tail-1; i++) {
        Node* node = new Node;
        node->dat = arr[i+1]->dat;
        node->pr = arr[i+1]->pr;
        arr[i] = node;
    }
    items--;
    tail--;
    arr[tail] = NULL;
}

void decToBin(int number) {
    int i = 0;
    stack <int> stackBin;
    while (number) {
        stackBin.push(number % 2);
        number /= 2;
        i++;
    }
    while (i != 0) {
        cout << stackBin.top();
        stackBin.pop();
        i--;
    }
}

int main() 
{   
   //================================Task1===============================
    init();
    insException(11, 22);
    insException(8, 33);
    insException(6, 44);
    insException(7, 55);
    insException(10, 66);
    insException(4, 99);
    insException(9, 23);
    insException(2, 70);
    insException(5, 80);
    insException(1, 66);
    printQueue();
    cout << endl;
    remException();
    printQueue();
    cout << endl;
    //================================Task2===============================

    int number;
    cout << "Enter decimal number: ";
    cin >> number;
    cout << "Number in binary representation: ";
    decToBin(number);
    cout << endl;
    return 0;
}

