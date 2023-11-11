#include<iostream>
#include<conio.h>
#include<stdio.h>

using namespace std;

// Node class to represent a node in the Binary Search Tree (BST)
class Node
{
public:
    Node *lchild;
    Node *rchild;
    int Data;
};

// BstNode class to manage the Binary Search Tree (BST) operations
class BstNode
{
public:
    Node *root = NULL;

    // Function to insert a new node with the given data into the BST
    void Insert(int data)
    {
        Node *NewNode = new Node;
        NewNode->Data = data;
        NewNode->lchild = NULL;
        NewNode->rchild = NULL;

        if (root == NULL)
        {
            root = NewNode;
        }
        else
        {
            Node *Current = root;
            Node *TrialCurrent = root;

            while (Current != NULL)
            {
                TrialCurrent = Current;

                if (Current->Data == data)
                {
                    cout << "  ___________! Warning !_______________" << endl;
                    cout << " Duplicate Not Allowed " << endl;
                    break;
                }
                else if (Current->Data > data)
                {
                    Current = Current->lchild;
                }
                else
                {
                    Current = Current->rchild;
                }
            }
            int test = TrialCurrent->Data;
            if (test > data)
            {
                TrialCurrent->lchild = NewNode;
            }
            else if (test < data)
                TrialCurrent->rchild = NewNode;
        }
    }

    // Function to delete a node with the given key from the BST
    void Delete(int key)
    {
        Node *Current = root;
        Node *TrialCurrent = root;
        bool found = false;

        if (root == NULL)
        {
            cout << "_______________!Warning ! __________________________" << endl;
            cout << "Empty" << endl;
        }
        else
        {
            while (Current != NULL && found != true)
            {

                if (Current->Data == key)
                {
                    found = true;
                }
                else
                {
                    TrialCurrent = Current;

                    if (Current->Data > key)
                    {
                        Current = Current->lchild;
                    }
                    else
                        Current = Current->rchild;
                }
            }

            if (Current == NULL || found == false)
            {
                cout << "Item To Be Deleted Is Not In The Tree " << endl;
            }
            else if (found == true)

