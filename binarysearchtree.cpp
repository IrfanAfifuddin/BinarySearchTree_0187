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
public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr; // initializing ROOT to null
    }
    void search(int element, Node *&parent, Node *&currentNode)
    {
        // this function searches the currentNode of the specified Node as well as the current Node of its parent
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element))
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode - currentNode->rightchild;
        }
    }

    void insert()
    {
        int x;
        cout << "Masukkan nilai :";
        cin >> x;

        // step 1 : allocated memory for the new node
        Node *newNode = new Node();

        // step 2 : assign value to the data field of new node
        newNode->info = x;

        // step 3 : make the left and right child of the new Node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // step 4 : locate the node witch will be the parent of the nood to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode);

        // step 5 : if parent is NULL (tree is empty)
        {
            if (parent == nullptr)
                // 5a : allocate memory for thr new node
                ROOT = newNode;

            // 5a : exit
            return;
        }
        // step 6 : if the value in the data field of new node is less than that of parent
        if (x < parent->info)
        {
            // 6a : make the left child of parent point to the new Node
            parent->leftchild = newNode;

            // 6b : exit
            return;
        }

        // step 7 : if the value in the data field of the new node is greater than that of the new node
        else if (x > parent->info)
        {
            // 7a : make the right chid of parent point to the new node
            parent->rightchild = newNode;

            // 7b : exit
            return;
        }
    }

    bool isEmpty()
    {
        // check if the tree is empty
        return ROOT == nullptr;
    }
    void inorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
        inorder(ptr->leftchild);
        cout << ptr->info << " "; // parent
        inorder(ptr->rightchild);
    }

    void preorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
        cout << ptr->info << " "; // parent
        preorder(ptr->leftchild);
        preorder(ptr->rightchild);
    }

    void postorder(Node *ptr)
    {
        if (isEmpty())
        {
            cout << "Tree is Empty" << endl;
            return;
        }
        if (ptr == nullptr)
            return;
        postorder(ptr->leftchild);
        postorder(ptr->rightchild);
        cout << ptr->info << " "; // parent
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
}