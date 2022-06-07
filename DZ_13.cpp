


#include <iostream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

#define T char

const int n = 6; // кол-во вершин графа
int matrix[n][n] = { // матрица смежности
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0},
};
int visited[n] = { 0 }; // посещенные вершины

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode* next;
} OneLinkNode;

typedef struct {
    OneLinkNode* head;
    int size;
} OneLinkList;

typedef struct TwoLinkNode {
    int dat;
    struct TwoLinkNode* next;
    struct TwoLinkNode* prev;
} TwoLinkNode;

typedef struct {
    struct TwoLinkNode* head;
    struct TwoLinkNode* tail;
    int size;
} TwoLinkList;

void depthTravers(int st) {

    cout << st;
    visited[st] = 1; // индекс стартовой вершины
    for (int r = 0; r < n; r++) {
        if (matrix[st][r] == 1 && !visited[r]) {
            depthTravers(r);
        }
    }
}

void resetArr() {
    for (size_t i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

void depthTraversUseStack(int st) {
    stack <int> graph;
    
    graph.push(st);
    while (!graph.empty()) {
        int node = graph.top();
        graph.pop();
        if (visited[node] == 2) {
        continue;
        }
        visited[node] = 2;
        for (int j = 0; j < n; j++) {
            if (matrix[node][j] == 1 && visited[j] != 2) {
                graph.push(j);
                visited[j] = 1;
            }
        }
        cout << node;
    }
    cout << endl;
}

void initTwoLinkList(TwoLinkList* lst) {
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void clearIntArray(bool* arr, const int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = 0;
    }
}

bool TwoLinkEnqueue(TwoLinkList* queue, T value) {
    TwoLinkNode* tmp = new TwoLinkNode;
    if (tmp == NULL) {
        printf("Out of memory! \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = NULL;
    tmp->prev = queue->tail;

    if (queue->tail != NULL) {
        queue->tail->next = tmp;
    }
    if (queue->head == NULL) {
        queue->head = tmp;
    }

    queue->tail = tmp;
    queue->size++;
    return true;
}

T TwoLinkDequeue(TwoLinkList* queue) {
    if (queue->size == 0) {
        printf("Queue is empty \n");
        return -1;
    }
    TwoLinkNode* tmp = queue->head;
    T data = queue->head->dat;

    queue->head = queue->head->next;

    if (queue->head != NULL) {
        queue->head->prev = NULL;
    }
    if (tmp == queue->tail) {
        queue->tail = NULL;
    }

    free(tmp);
    queue->size--;
    return data;
}

int get2dInt(int** array, const int row, const int col) {
    return *((*(array + row)) + col);
}

void initOneLinkList(OneLinkList* lst) {
    lst->head = NULL;
    lst->size = 0;
}

int traversalLinks[6] = { 0 };
int adjacencyLinks[6] = { 0 };
bool visit[6] = { 0 };

void adjacencyCount(int** matrix, const int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size; j++) {
            if (matrix[i][j] == 1)
                if (i != j) adjacencyLinks[i]++;
        }
    }
}

void traversalCount(int** matrix, int start, const int size) {
    TwoLinkList* queue = new TwoLinkList;
    initTwoLinkList(queue);
    clearIntArray(visit, size);
    TwoLinkEnqueue(queue, start);
    while (queue->size > 0) {
        int indx = TwoLinkDequeue(queue);
        if (visit[indx]) continue;
        visit[indx] = true;
        for (int i = 0; i < size; i++) {
            if (get2dInt(matrix, indx, i) == 1) {
                if (i != indx)
                    traversalLinks[i]++;
                if (!visit[i])
                    TwoLinkEnqueue(queue, i);
            }
        }
    }
    clearIntArray(visit, size);
}

void printIntArray(int* array, int size) {
    
    
    for (int i = 0; i < size; ++i) {
        cout<< "   " << array[i];
        if (i != size - 1)
           cout << ",";
    }
    cout << endl;
}


bool pushOneLinkStack(OneLinkList* stack, T value) {
    OneLinkNode* tmp = new OneLinkNode;
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T popOneLinkStack(OneLinkList* stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode* tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

int getUnvisitedVertex(int** matrix, int ver, int size) {
    for (int i = 0; i < size; i++) {
        if (get2dInt(matrix, ver, i) == 1 && ! visit[i]) {
            return i;
        }
    }
    return -1;
}

void depthTraversStack(int** matrix, int size) {
    OneLinkList* stack = new OneLinkList;
    initOneLinkList(stack);
    visit[0] = true;
    
    pushOneLinkStack(stack, 0);
    while (stack->size) {
        int v = getUnvisitedVertex(matrix, stack->head->dat, size);
        if (v==-1){
            popOneLinkStack(stack);
        }
        else {
            visit[v] = true;
            cout << "    " << v;
            pushOneLinkStack(stack, v);
        }
    }
    clearIntArray(visit, size);
    cout << endl;
}

int main()
{
    
    resetArr();
    cout << endl;
    depthTravers(2);
    cout << endl;
    cout << endl;


    //================================Task1==============================
    resetArr();
    depthTraversUseStack(2);
    cout << endl;


    //================================Task2==============================

   
    const size_t n = 6;
    int** adj = new int* [n]; 
    for (size_t i = 0; i < n; i++) {
        adj[i] = new int[n]; 
    }
    adj[0][0] = 0, adj[0][1] = 1, adj[0][2] = 1, adj[0][3] = 0, adj[0][4] = 0, adj[0][5] = 0;
    adj[1][0] = 0, adj[1][1] = 0, adj[1][2] = 0, adj[1][3] = 1, adj[1][4] = 1, adj[1][5] = 1;
    adj[2][0] = 0, adj[2][1] = 0, adj[2][2] = 0, adj[2][3] = 0, adj[2][4] = 0, adj[2][5] = 0;
    adj[3][0] = 1, adj[3][1] = 0, adj[3][2] = 0, adj[3][3] = 0, adj[3][4] = 0, adj[3][5] = 0;
    adj[4][0] = 0, adj[4][1] = 0, adj[4][2] = 0, adj[4][3] = 0, adj[4][4] = 0, adj[4][5] = 0;
    adj[5][0] = 0, adj[5][1] = 0, adj[5][2] = 0, adj[5][3] = 0, adj[5][4] = 0, adj[5][5] = 0;
    
    depthTraversStack(adj, 6);
   
    adjacencyCount(adj, 6);
    printIntArray(adjacencyLinks, 6);
    traversalCount(adj, 0, 6);
    printIntArray(traversalLinks, 6);

    return 0;
}


