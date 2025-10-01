// COMSC-210 | Lab 17 | Dat Hoang Vien
// IDE used: Visual Code Studio

// Libraries and headers
#include <iostream>
#include "Node.h"
using namespace std;

// Constants
const int SIZE = 7;  

// Function prototypes
void displayMenu();                                    // Display the menu of operations

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

    // Create a loop and allow the user to perform Linked list operations
    while (true)
    {
        // Display the menu of operations
        displayMenu();

        // Declare an integer variable to store the user's choice
        int choice = 0;

        // Prompt the user to enter their choice
        cout << " - Your choice: ";
        cin >> choice;

        // Check whether the choice was valid
        while (choice < 1 || choice > 7)
        {
            // Display an error message
            cout << " --- Error! Your choice must be between 1 and 7! --- " << endl;
            
            // Prompt the user to enter a new choice
            cout << "Please enter a new choice: ";
            cin >> choice;
        }

        // Perform the operations based on the user's choice
        switch (choice)
        {
            // Add a Node to the front
            case 1:
            {
                // Declare a float variable to store the user's input value 
                float value = 0;

                // Prompt the user to enter the value
                cout << "Enter your Node's value: ";
                cin >> value;

                // Call the addFront() function
                addFront(head, value);

                break;
            }

            // Add a Node to the tail
            case 2:
            {
                // Declare a float variable to store the user's input value 
                float value = 0;

                // Prompt the user to enter the value
                cout << "Enter your Node's value: ";
                cin >> value;

                // Call the addTail() function
                addTail(head, value);

                break;
            }

            // Insert a Node into the Linked list
            case 3:
            {
                // Declare a float variable to store the user's input value 
                float value = 0;

                // Prompt the user to enter the value
                cout << "Enter your Node's value: ";
                cin >> value;

                // Declare an integer variable to store the position
                int pos = -1;

                // Prompt the user to enter the position to insert
                cout << "Enter the position to insert: ";
                cin >> pos;

                // Check whether the entered position was valid (positive) or not
                while (pos < 0)
                {
                    // Display an error message
                    cout << " --- Invalid! Position cannot be negative! --- " << endl;
                    
                    // Prompt the user to enter a new position
                    cout << "Please enter a valid position (>= 0): ";
                    cin >> pos;
                }

                // Call the insertNode() function
                insertNode(head, value, pos);

                break;
            }

            // Delete a Node from the Linked list
            case 4:
            {
                // Declare an integer variable to store the position
                int pos = -1;

                // Prompt the user to enter the position to delete
                cout << "Enter the position to delete: ";
                cin >> pos;

                // Check whether the entered position was valid (positive) or not
                while (pos < 0)
                {
                    // Display an error message
                    cout << " --- Invalid! Position cannot be negative! --- " << endl;
                    
                    // Prompt the user to enter a new position
                    cout << "Please enter a valid position (>= 0): ";
                    cin >> pos;
                }

                // Call the deleteNode() function
                deleteNode(head, pos);

                break;
            }

            // Delete the entire Linked list
            case 5:
            {
                // Ask the user to verify their choice
                cout << "Are you sure you want to delete the entire Linked list (Y/N): ";
                // Call the deleteList() function
                deleteList(head);

                break;
            }
        }
    }

    return 0;
}

// Function implementations
/*
    displayMenu()
    Display the menu of operations the user can implement on the Linked list
    Arguments: none
    Return: none

*/
void displayMenu()
{
    // Display the whole menu
    cout << " --- Linked list operations --- " << endl;
    cout << "1. Add a Node to the front" << endl;
    cout << "2. Add a Node to the tail" << endl;
    cout << "3. Insert a Node at a position" << endl;
    cout << "4. Delete a Node at a position" << endl;
    cout << "5. Delete the entire Linked list" << endl;
    cout << "6. Display the Linked list" << endl;
    cout << "7. Exit the program" << endl;
    cout << " -------------------------- --- " << endl;
}

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