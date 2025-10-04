// Name: Aryan Jigneshbhai Bhagat
// NetID: sl5310
// Email: abhagat4@horizon.csueastbay.edu

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    node *next;
    node *prev;

    node(char val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void putItem(node *&head, char val)
{

    node *temp = new node(val);
    head->next = temp;
    temp->prev = head;
    head = temp;
    // cout << head->data << ",";
}

// void printAll(node *head)
// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

void printindex(node *&temp, int count)
{
    // node *temp = head;
    if (count < 0)
    {
        while (temp->prev->prev != NULL && count != 0)
        {
            temp = temp->prev;
            count++;
        }
    }
    else if (count > 0)
    {
        while (temp != NULL && count != 0)
        {
            temp = temp->next;
            count--;
        }
    }
    cout << temp->data;
}
