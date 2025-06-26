#include <iostream>
using namespace std;

class Node
{
public:
    int info;
    Node *leftchild;
    Node *rightchild;

    // constructor for node class
    Node()
    {
        leftchild = nullptr;  // initialize left child to null
        rightchild = nullptr; // initialize right child to null
    }
};

class BinaryTree
{

};