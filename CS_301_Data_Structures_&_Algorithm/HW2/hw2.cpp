
// // Name : Aryan Jigneshbhai Bhagat
// // NetID: sl5310
// // Email : abhagat4@horizon.csueastbay.edu

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "hw2.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to add a node at the end of the list
void putItem(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position or at the end if position is "END"
void putItem(Node *&head, int value, string position)
{
    Node *newNode = new Node(value);

    if (position == "END")
    {
        putItem(head, value);
        return;
    }

    int pos = stoi(position);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete a node by its value
void deleteItem(Node *&head, int value)
{
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cerr << "Item not found in the list." << endl;
        return;
    }

    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
}

// Function to print all the nodes in the list
void printAll(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    string filename;

    ifstream dataFile;
    // cout << "Enter a valid file name: ";
    // cin >> filename;
    dataFile.open("HW2Data.txt");
    while (!dataFile.is_open())
    {
        cerr << "Error opening file. Please enter a valid filename: ";
        cin >> filename;
        dataFile.open(filename);
    }

    Node *head = nullptr;
    string line;

    // Read the first line and add items to the list
    if (getline(dataFile, line))
    {
        stringstream ss(line);
        string num;
        while (getline(ss, num, ','))
        {
            putItem(head, stoi(num));
        }
    }
    printAll(head);

    // Read the second line and delete items from the list
    if (getline(dataFile, line))
    {
        stringstream ss(line);
        string num;
        while (getline(ss, num, ','))
        {
            deleteItem(head, stoi(num));
        }
    }
    printAll(head);

    // Read the third line and insert items at specific positions
    if (getline(dataFile, line))
    {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            size_t pos = token.find('@');
            int value = stoi(token.substr(0, pos));
            string position = token.substr(pos + 1);
            putItem(head, value, position);
        }
    }
    printAll(head);

    dataFile.close();
    return 0;
}
