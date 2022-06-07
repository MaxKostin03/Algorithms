
#include <iostream>
#include <stack>  
using namespace std;



//=====================================================================================================================
void inline Task1() {
    stack <int> p;
    string sequence;
    cout << "Enter bracket sequence" << endl;
    cin >> sequence;
    for (int i = 0; i < sequence.size(); i++) {
        if (sequence[i] == '(' || sequence[i] == '{' || sequence[i] == '[') {
            p.push(sequence[i]);
        }
        else {
            if (sequence[i] == ')' && !p.empty() && p.top() == '(') {
                p.pop();
            }
            else if (sequence[i] == '}' && !p.empty() && p.top() == '{') {
                p.pop();
            }
            else if (sequence[i] == ']' && !p.empty() && p.top() == '[') {
                p.pop();
            }
            else if ((sequence[i] == '}' || sequence[i] == ')' || sequence[i] == ']') && p.empty()) {
                p.push(i);
                break;
            }
        }
    }
    if (p.empty()) {
        cout << "The sequence is correct" << endl;
    }
    else {
        cout << "The sequence is not correct" << endl;
    }
}
//=====================================================================================================================
typedef struct Node { // узел данных и указатель на след 
    int dat;
    struct Node* next;
} Node;

typedef struct { // указатель на головной элемент и его размер
    Node* head;
    int size;
} List;


void init(List* lst) { // начальное значение головному элементу и началу списка
    lst->head = NULL;
    lst->size = 0;
}

void ins(List* lst, int data) { // создание нового узла, указатель на список и значение которое нужно положить в новый узел
    Node* new1 = new Node;
    new1->dat = data;
    new1->next = NULL;

    Node* current = lst->head; // переменная для поиска места куда вставлять новый элемент
    if (current == NULL) {
        lst->head = new1;
        lst->size++;
        return;
    }
    else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new1;
        lst->size++;
    }
}

Node* rm(List* lst, int data) { // удаление узла
    Node* current = lst->head;
    Node* parent = NULL;
    if (current == NULL) {
        return NULL;
    }
    while (current->next != NULL && current->dat != data) {
        parent = current;
        current = current->next;
    }
    if (current->dat != data) {
        return NULL;
    }
    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }
    parent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node* n) {
    if (n == NULL) {
        cout << "[] ";
        return;
    }
    cout << "[" << n->dat << "] ";
}

void printList(List* lst) {
    Node* current = lst->head;
    if (current == NULL) {
        printNode(current);
    }
    else {
        do {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    cout << "Size: " << lst->size << endl;

}


void copyListFunc(List* lst, List* copyLst) { // функция копирования списка
    init(copyLst);
    Node* copy = new Node;
    copy = lst->head;
    while (copy != NULL) {
        ins(copyLst, copy->dat);
        copy = copy->next;
    }
}

bool sort(List* lst) { // проверка на сортировку
    Node* cur = lst->head;
    while (cur->next != NULL) {
        if (cur->dat > cur->next->dat) {
            return false;
            cur = cur->next;
        }
         
    }
    return true;
}

void inline Task2() {
    List* lst = new List;
    init(lst);
    printList(lst);
    ins(lst, 1);
    printList(lst);
    ins(lst, 10);
    printList(lst);
    ins(lst, 20);
    printList(lst);
    printNode(rm(lst, 1));
    cout << "<-removed node" << endl;
    printList(lst);
    ins(lst, 30);
    ins(lst, 40);
    printList(lst);

    List* copyLst = new List;
    copyListFunc(lst, copyLst);
    printList(copyLst);
}

void inline Task3() {
    List* lst1 = new List;
    init(lst1);
    printList(lst1);
    ins(lst1, 70);
    ins(lst1, 20);
    ins(lst1, 30);
    ins(lst1, 40);
    printList(lst1);
    if (sort(lst1) == true) {
        cout << "List sorted" << endl;
    } 
    else cout << "List is not sorted" << endl;
}



int main()
{
    Task1();
    Task2();
    Task3();

    return 0;
}


