// Name: Aryan Jigneshbhai Bhagat
// Net ID: sl5310
// Email: abhagat4@horizon.csueastbay.edu

#include "hw3.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }
    ItemType list;
    string fileName = argv[1];
    ifstream File(fileName);
    string line;

    if (!File.is_open())
    {
        cerr << "Error: Could not open file!" << endl;
        return 0;
    }

    getline(File, line);
    stringstream s1(line);
    string card;
    while (getline(s1, card, ',') && list.isFull() == false)
    {
        card = cut(card);
        list.putItem(card);
    }

    list.printAll();

    if (getline(File, line))
    {
        stringstream s2(line);
        while (getline(s2, card, ','))
        {
            card = cut(card);
            list.deleteItem(card);
        }

        list.printAll();
    }

    getline(File, line);
    stringstream s3(line);
    while (getline(s3, card, ','))
    {
        card = cut(card);
        list.putItem(card);
    }

    list.printAll();

    getline(File, line);
    stringstream ss4(line);
    while (getline(ss4, card, ','))
    {
        card = cut(card);
        cout << card << " " << list.getItem(card) << endl;
    }

    File.close();
    return 0;
}