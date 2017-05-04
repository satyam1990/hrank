/********************************************************************
 A linked list is said to contain a cycle if any node is visited more than 
 once while traversing the list.

 Your function must return a boolean denoting whether or not there is a cycle 
 in the list. If there is a cycle, return true; otherwise, return false.

********************************************************************/

#include <iostream>

using namespace std;

class Node {
    public:

    int data;
    Node* next;

    Node(int d, struct Node* n)
    {
        data = d;
        next = n;
    }
};

bool has_cycle(Node* head);

int main()
{
    Node* temp = NULL;
    
    Node* cycleList = new struct Node(1, NULL);
    Node* noCycleList = new struct Node(1, NULL);

    // create a list with cycle
    temp = cycleList;
    for (int i = 2; i < 5; i++)
    {
        temp->next = new struct Node (i, NULL);
        temp = temp->next;
    }
    // created the cycle
    temp->next = cycleList;

    // check list has cycle
    cout << has_cycle(cycleList) << endl;

    // create a list with no cycle
    temp = noCycleList;
    for (int i = 2; i < 5; i++)
    {
        temp->next = new struct Node (i, NULL);
        temp = temp->next;
    }

    // check list has cycle
    cout << has_cycle(noCycleList) << endl;

    return 0;
}

bool has_cycle(Node* head)
{
    if (head == NULL)
        return false;
    
    Node* hare = head;

    while (hare->next->next != NULL)
    {
        head = head->next;
        hare = hare->next->next;

        if (head == hare)
            return true;
    }
    
    return false;
}
