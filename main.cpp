// COMSC-210 | Lab 17 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries
#include <iostream>
#include "Node.h"
using namespace std;

// Constants
const int SIZE = 7;  

// Function prototypes
void addFront(Node* head);                     // Add a Node to the front of the Linked list

void addTail(Node* head);                      // Add a Node to the tail of the Linked list

void insertNode(Node* head, float value);      // Insert a Node into the Linked list

void deleteNode(Node* head, float value);      // Delete a Node from the Linked list

void deleteList(Node* head);                   // Delete the entire Linked list

void output(Node* head);

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

/*
    output()
    Display the values of all the Nodes of the Linked list
    Arguments: 
        - head: the head of the Linked list
    Return: none
*/
void output(Node * head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}