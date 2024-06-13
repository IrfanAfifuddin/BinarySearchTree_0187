#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string info;
    Node* leftchild;
    Node* rightchild;

    // Constructor for the node class
    Node(string i, Node* l, Node* r)
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }
};

class BinaryTree {
public:
    Node* ROOT;

    BinaryTree()
    {
        ROOT = nullptr; //initializing ROOT to null
    }

    void insert(string element) // insert a node in the binary search tree 
    {
        Node* newNode = new Node(element, nullptr, nullptr); // allocate memomry for the new node
        newNode->info = element; // assign value to the data field of the new node
        newNode->leftchild = nullptr; // make the left child of the new node point to NULL
        newNode->rightchild = nullptr; // make the right child of the new node point to NULL

        Node* parent = nullptr;
        Node* currentNode = nullptr;
        search(element, parent, currentNode); //locate the node which will be the parent of the node to be insert

        if (parent == nullptr) // If the parent is NULL (tree is empty)
        {
            ROOT = newNode; // Mark the new node as ROOT
            return; //exit
        }

        if (element < parent->info) // If the values in the data field of the new node is less than that of the
        {
            parent->leftchild = newNode; // Make the left child of the parent to the new node
        }

        else if (element > parent->info) // if the value in the data field of the new node is greater than that
        {
            parent->rightchild = newNode; // Make the right child of the parent point to the new node
        }
    }

    void search(string element, Node*& parent, Node*& currentNode) {
        // this function searches the currentNode of the specified Node as current Node of its parents
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else 
                currentNode = currentNode->rightchild;
        }
    }
};



int main()
{
    
}