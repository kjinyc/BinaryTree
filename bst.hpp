#include <iostream>
#include <deque>
#include <climits>
#include <vector>
using namespace std;


struct Tree
{
    char data;
    Tree *left;
    Tree *right;
    Tree *parent;
};

Tree* lookUp(struct Tree *node, char key)
{
    if (node == NULL) return node;

    if(node->data == key) return node;
    else{
        if(node->data < key)
            return lookUp(node->right, key);
        else{
            return lookUp(node->left,key);
        }
    }
}

Tree* leftMost(struct Tree *node)
{
    if (node == NULL) return NULL;
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

struct Tree* newTreeNode(int data)
{
    Tree *node = new Tree;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent=NULL;

    return node;
}

struct Tree* insertTreeNode(struct Tree* node, int data)
{
    static Tree *p;
    Tree *retNode;

    if(node == NULL){
        retNode = newTreeNode(data);
        retNode->parent = p;
        return retNode;
    }
    if(data < node->data){
        p = node;
        node->left = insertTreeNode(node->left,data);
    }else{
        p = node;
        node->right = insertTreeNode(node->right, data);
    }
    return node;
}

//Check if Binary Search Tree
//A type of binary tree where the nodes are arranged in order
//Left: equal or less
//right: greater
void isBST(struct Tree *node)
{
    static int lastData = INT_MIN;
    if(node == NULL) return;

    isBST(node->left);

    if(lastData < node->data){
        lastData = node->data;
    }else{
        cout << "Not a BST" << endl;
        return;
    }

    isBST(node->right);
    return;
}


int treeSize(struct Tree *node)
{
    if(node == NULL) return 0;
    else
        return treeSize(node->left) + 1 + treeSize(node->right);
}

int maxDepth(struct Tree *node)
{
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    int leftLength = maxDepth(node->left);
    int rightLength = maxDepth(node->right);

    return leftLength >  rightLength ? leftLength + 1 : rightLength + 1;
}

int minDepth(struct Tree *node){

    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    int leftLength = maxDepth(node->left);
    int rightLength = maxDepth(node->right);

    return leftLength <  rightLength ? leftLength + 1 : rightLength + 1;
}

bool isBalanced(struct Tree *root)
{
    if(maxDepth(root)-minDepth(root) <= 1)
        return true;
    else return false;
}

//Tree Minimum
Tree *minTree(struct Tree *node)
{
    if(node==NULL) return NULL;
    while(node->left)
        node = node->left;
    return node;
}

//Tree Maximum
Tree *maxTree(struct Tree *node)
{
    while(node->right)
        node = node->right;
    return node;
}

//Reverse Order Print
void reverseOrderPrint(struct Tree *node){

    if (node == NULL) return;
    if (node->left == NULL && node->right == NULL){
        cout << node->data << " ";
        return;
    }

    reverseOrderPrint(node->right);
    cout << node->data << " ";
    reverseOrderPrint(node->left);
}


void clear(struct Tree *node){
    if(node != NULL){
        clear(node->left);
        clear(node->right);
        delete node;
    }
}


void printTreeInOrder(struct Tree *node){
    if(node == NULL) return;

    printTreeInOrder(node->left);
    cout << node->data << " ";
    printTreeInOrder(node->right);
}

static int n_th_max = 10;
void NthMax(struct Tree *t){
    //static int n_th_max = 5;
    static int num = 0;
    if(t == NULL) return;
    NthMax(t->right);
    num++;
    if(num == n_th_max){
        cout << n_th_max << "-th maximum data is "
            << t->data << endl;
    }
    NthMax(t->left);
}






















