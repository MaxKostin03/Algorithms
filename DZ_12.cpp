



#include <iostream>
#include <time.h>
using namespace std;

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
}TreeNode;

TreeNode* treeInsert(TreeNode* t, int data) {
    TreeNode* newNode = new TreeNode;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;

    TreeNode* current = t; 
    TreeNode* parent = t;  
    if (t == NULL) {
        t = newNode;
    }
    else {
        while (current->key != data) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
    }
    return t;
}

void printTree(TreeNode* root) {
    if (root) {
        cout << root->key;
        if (root->left || root->right) {
            cout << "(";

            if (root->left) {
                printTree(root->left);
            }
            else {
                cout << "NULL";
            }
            cout << ",";
            if (root->right) {
                printTree(root->right);
            }
            else {
                cout << "NULL";
            }
            cout << ")";
        }
    }
}

void fillTree(int size, TreeNode* root) {
    for (size_t i = 0; i < size; i++) {
        treeInsert(root, rand() % 10000);
    }
}

int balanceCheckLeft(TreeNode* root) {
    if (root) {
        return balanceCheckLeft(root->left) + 1;
    }
}

int balanceCheckRight(TreeNode* root) {
    if (root) {
        return balanceCheckRight(root->right) + 1;
    }
}

bool binSearch(TreeNode* root, int value) {
    if (root == NULL)
        return false;
    if (root->key == value) {
        return true;
    }
    TreeNode* current = root;
    while (current->key != value) {
        if (value < current->key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
        if (current == NULL) {
            return false;
        }
    }
}

int main()
{
    TreeNode* tree = new TreeNode;
    int data = 10;
    tree->key = data;
    tree->left = NULL;
    tree->right = NULL;
    treeInsert(tree, 19);
    treeInsert(tree, 5);
    treeInsert(tree, 9);
    treeInsert(tree, 16);
    treeInsert(tree, 21);
    treeInsert(tree, 27);
    treeInsert(tree, 40);
    printTree(tree);
    cout << endl;

    //===================================Task1_1============================

    if (abs(balanceCheckRight(tree) - balanceCheckLeft(tree)) <= 1) {
        cout << "The tree is balanced" << endl;
    }
    else cout << "The tree is not balanced" << endl;

    //===================================Task1_2============================

    size_t trees = 50;
    size_t size = 10000;
    srand((unsigned)time(0));
    int counterBalanced = 0;
    for (size_t i = 0; i < trees; i++) {
        TreeNode* node = NULL;
        TreeNode* root = treeInsert(node, rand() % 10000);
        fillTree(size, root);
        if (abs(balanceCheckRight(root) - balanceCheckLeft(root)) <= 1) {
            counterBalanced++;
        }
    }
    cout << "Percent of balanced trees " << counterBalanced* 100/ trees<< "%" << endl;


    //===================================Task2==============================

    binSearch(tree, 40) ?  cout << "Number found" : cout << "Number not found";

    return 0;
}






