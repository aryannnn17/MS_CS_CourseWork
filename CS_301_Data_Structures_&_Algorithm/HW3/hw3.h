
// Name: Aryan Jigneshbhai Bhagat
// NetID: sl5310
// Email: abhagat4@horizon.csueastbay.edu

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct NodeType
{
    string card;
    NodeType *next;
};

string cut(const string &str)
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

class ItemType
{
private:
    NodeType *head;
    int length;
    const int max_size = 20;

public:
    ItemType()
    {
        head = nullptr;
        length = 0;
    }

    ~ItemType()
    {
        NodeType *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    bool isFull() const
    {
        return length == max_size;
    }

    bool isEmpty() const
    {
        return length == 0;
    }

    void putItem(string newCard)
    {
        if (isFull() || getItem(newCard) == "YES")
            return;

        NodeType *newNode = new NodeType;
        newNode->card = newCard;
        newNode->next = nullptr;

        if (head == nullptr || compareTo(newCard, head->card) < 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            NodeType *temp = head;
            while (temp->next != nullptr && compareTo(newCard, temp->next->card) > 0)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    void deleteItem(string cardToDelete)
    {
        if (isEmpty())
            return;

        NodeType *temp = head;
        NodeType *prev = nullptr;

        if (head->card == cardToDelete)
        {
            head = head->next;
            delete temp;
            length--;
            return;
        }

        while (temp != nullptr && temp->card != cardToDelete)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
            return;
        prev->next = temp->next;
        delete temp;
        length--;
    }

    string getItem(string cardToSearch)
    {
        NodeType *temp = head;
        while (temp != nullptr)
        {
            if (temp->card == cardToSearch)
                return "YES";
            temp = temp->next;
        }
        return "NO";
    }

    void printAll() const
    {
        NodeType *temp = head;
        while (temp != nullptr)
        {
            cout << temp->card;
            if (temp->next != nullptr)
                cout << ",";
            temp = temp->next;
        }
        cout << endl;
    }

    int compareTo(string card1, string card2)
    {
        char suit1 = card1[0];
        char suit2 = card2[0];
        if (suit1 != suit2)
        {
            return suit1 < suit2 ? -1 : 1;
        }

        string ranks = "23456789TJQKA";
        char rank1 = card1[1];
        char rank2 = card2[1];

        if (rank1 == '1')
            rank1 = 'T';
        if (rank2 == '1')
            rank2 = 'T';

        return ranks.find(rank1) < ranks.find(rank2) ? -1 : ranks.find(rank1) > ranks.find(rank2) ? 1
                                                                                                  : 0;
    }
};
