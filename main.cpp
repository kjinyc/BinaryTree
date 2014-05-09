#include "bst.hpp"

int main()
{
    char ch,ch1,ch2;
    Tree *ptr = newTreeNode('F');
    Tree *found;
    Tree *succ;
    Tree *pred;
    Tree *ancestor;
    char charArr[9] = {'A','B','C','D','E','F','G','H','I'};

    Tree *root = newTreeNode('F');
    root = insertTreeNode(root, 'B');

    cout << (root->left)->data<<endl;
    insertTreeNode(root,'B');
    insertTreeNode(root,'A');
    insertTreeNode(root,'D');
    insertTreeNode(root,'C');
    insertTreeNode(root,'E');
    insertTreeNode(root,'G');
    insertTreeNode(root,'I');
    insertTreeNode(root,'H');

    isBST(root);

    cout << "Size of tree" << treeSize(root) << endl;
    cout << "Depth of tree " <<maxDepth(root) << endl;
    cout << "Minimum Depth " << minDepth(root) << endl;

    reverseOrderPrint(root);
    cout << endl;
    printTreeInOrder(root);
    cout << endl;

    n_th_max = 3;
    NthMax(root);

    return 0;
}
