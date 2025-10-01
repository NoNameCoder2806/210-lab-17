// COMSC-210 | Lab 17 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries and headers
#include <iostream>
#include "Node.h"
using namespace std;

// Constants
const int SIZE = 7;  

// Function prototypes
void addFront(Node*& head, float value);               // Add a Node to the front of the Linked list

void addTail(Node*& head, float value);                // Add a Node to the tail of the Linked list

void insertNode(Node*& head, float value, int pos);    // Insert a Node into the Linked list

void deleteNode(Node*& head, int pos);                 // Delete a Node from the Linked list

void deleteList(Node*& head);                          // Delete the entire Linked list

void output(Node* head);                               // Display the values of the Nodes in the Linked list

// Main function
int main()
{
    // Create a Linked list
    Node* head = nullptr;      // A Node pointer as the head of the Linked list
    int count = 0;             // An integer counter of the total Nodes

    // Create a Linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

// Function implementations
/*
    addFront()
    Add a Node to the front of the Linked list
    Arguments:
        - head: a Node pointer (the head of the Linked list)
        - value: the value of the Node to insert
    Return: none
*/
void addFront(Node*& head, float value)
{
    // Create a Node and assign the value to it
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    // Let newNode point to the head
    newNode->next = head;

    // Let the head point to newNode
    head = newNode;
}

/*
    addTail()
    Add a Node to the tail of the Linked list
    Arguments:
        - head: a reference to a Node pointer (the head of the Linked list)
        - value: the value of the Node to insert
    Return: none
*/
void addTail(Node*& head, float value)
{
    // Create a new Node and assign the value to it
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    // Check whether the Linked list is empty
    if (head == nullptr)
    {
        // Assign the newNode to the head
        head = newNode;

        return;      // Exit the function
    }

    // Create a Node and let it point to the head
    Node* current = head;

    // Iterate through the Linked list until we reach the last Node
    while(current->next)
    {
        // Let it point to the next Node in the Linked list
        current = current->next;
    }

    // Add newNode to the tail
    current-> next = newNode;
}

/*
    insertNode()
    Insert a Node into the Linked list
    Arguments:
        - head: a reference to a Node pointer (the head of the Linked list)
        - value: the value of the Node to insert
        - pos: the position of the Node to insert
    Return: none    
*/
void insertNode(Node*& head, float value, int pos)
{
    // Create a new Node and assign the value to it
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    // Check whether the Linked list is empty or the position is 0
    if (head == nullptr || pos == 0)
    {
        // Let newNode point to the head
        newNode->next = head;

        // Let the head point to newNode
        head = newNode;

        // Exit the function
        return;
    }

    // Declare an integer counter
    int index = 0;

    // Create a Node and let it point to the head
    Node* current = head;

    // Iterate through the Linked list until we reach the last Node or the position to insert
    while(current && index < pos - 1)
    {
        // Move to the next Node
        current = current->next;

        // Increment the index
        index++;
    }

    // Add newNode to the Linked list
    newNode->next = current->next;
    current->next = newNode;
}

/*
    deleteNode()
    Delete a Node from the Linked list
    Arguments:
        - head: a reference to a Node pointer (the head of the Linked list)
        - pos: the position of the Node to delete
    Return: none
*/
void deleteNode(Node*& head, int pos)
{
    // Check whether the Linked list is empty
    if (head == nullptr)
    {
        // Display an error message
        cout << " --- The Linked list is empty! --- " << endl;
        
        // Exit the function
        return;
    }

    // Check whether we're deleting the first Node (the head)
    if (pos == 0)
    {
        // Declare a new Node as the Node to delete
        Node* temp = head;

        // Unlink and delete the first Node
        head = head->next;
        delete temp;

        // Exit the function
        return;
    }

    // Declare an integer counter
    int index = 0;

    // Create a Node and let it point to the head
    Node* current = head;

    // Iterate through the Linked list until we reach the last Node or the position to insert
    while (current && index < pos - 1)
    {
        // Move to the next Node
        current = current->next;

        // Increment the index
        index++;
    }

    // Check if the next Node exist
    if (current->next == nullptr)
    {
        // Display an error message
        cout << " --- Invalid poistion! Cannot delete Node --- " << endl;

        // Exit the function
        return;
    }

    // Declare a new Node as the Node to delete
    Node* temp = current->next;

    // Unlink and delete the Node
    current->next = temp->next;
    delete temp;
}

/*
    deleteList()
    Delete the whole Linked list
    Arguments:
        - head: a reference to a Node pointer (the head of the Linked list)
    Return: none
*/
void deleteList(Node*& head)
{
    // Iterate through the Linked list
    while (head)
    {
        // Create a Node and let it point to the head
        Node* current = head;

        // Move on to the next Node
        head = head->next;

        // Delete the current Node
        delete current;
    }
}

/*
    output()
    Display the values of all the Nodes of the Linked list
    Arguments: 
        - head: a Node pointer (the head of the Linked list)
    Return: none
*/
void output(Node* head)
{
    // If the Linked list is empty
    if (!head)
    {
        // Display a message
        cout << " --- Empty list. --- " << endl;

        return;      // Exit the function
    }

    // An int counter for the number of Nodes
    int count = 1;

    // Declare a current Node and let it be the head
    Node* current = head;

    // Iterate through the Linked list until we reach a nullptr
    while (current)
    {
        // Display the value of the Nodes
        cout << "[" << count++ << "] " << current->value << endl;

        // Move to the next Node
        current = current->next;
    }

    // Enter a new line
    cout << endl;
}