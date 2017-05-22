/******************************************************************************
 Given the root node of a binary tree, can you determine if it's also a binary 
 search tree?
 Note: We do not consider a binary tree to be a binary search tree if it 
 contains duplicate values.

 *****************************************************************************/

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }

        static Node* getNode(int val)
        {
            return new Node(val);
        }
};

class Bst {
    private:
        Node* root;

        Node* insert(Node* root, int data)
        {
            if (root == NULL)
                root = Node::getNode(data);
            else if (root->data > data)
                root->left = insert(root->left, data);
            else
                root->right = insert(root->right, data);

            return root;
        }

        void traverse(Node* root)
        {
            if (root == NULL)
                return;

            cout << root->data << "->";
            traverse(root->left);
            traverse(root->right);
        }

    public:
        Bst()
        {
            root = NULL;
        }

        void insert(int data)
        {
            root = insert(root, data);
        }

        void traverse()
        {
            traverse(root);
            cout << "\b\b  \b\b" << endl;
        }

        Node* getRoot()
        {
            return root;
        }
};

void makeSortedArray(Node* root, vector<int>& sorted)
{
    if (root == NULL)
        return;

    makeSortedArray(root->left, sorted);
    sorted.push_back(root->data);
    makeSortedArray(root->right, sorted);
}

bool checkBST(Node* root)
{
    // traverse in-order and store in vector
    vector<int> sorted;
    makeSortedArray(root, sorted);

    int length = sorted.size();

    // verify vector if not sorted return false
    for (int i = 1; i < length; i++)
    {
        if (sorted[i - 1] >= sorted[i])
            return false;
    }

    return true;
}

int main()
{
    Bst b1;
    
    // insert few elements
    b1.insert(4);
    b1.insert(2);
    b1.insert(1);
    b1.insert(3);
    b1.insert(6);
    b1.insert(5);
    b1.insert(7);

    // print bst just to verify
    b1.traverse();

    
    // Test Case 1 no changes in tree see if tree is bst
    assert(checkBST(b1.getRoot())); 
    cout << "PASS::Tree is BST" << endl;

    // explicitly corrupt the bst
    Node* root = b1.getRoot();

    // Test Case 2 make root small
    root->data = 0;

    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->data = 4;

    // Test Case 3 make left larger
    root->left->data = 10;
    
    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->left->data = 2;

    // Test Case 4 make right of left subtree larger than top most root
    root->left->right->data = 10;

    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->left->right->data = 3;

    //Test Case 5 make right smaller
    root->right->data = 0;

    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->right->data = 6;
    
    //Test Case 6 make left of right subtree smaller than top most root
    root->right->left->data = 0;

    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->right->left->data = 5;

    // Test Case 7 put duplicate value left side
    root->left->data = 4;

    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->left->data = 2;

    // Test Case 8 put duplicate value in right of left sub tree
    root->left->right->data = 4;
    
    // see if tree is bst
    assert(checkBST(b1.getRoot()) == false);
    cout << "PASS::Tree is not BST" << endl;

    // reset value
    root->left->right->data = 3;

    return 0;
}
