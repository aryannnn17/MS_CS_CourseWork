// Name: Aryan Jigneshbhai Bhagat
// Net ID: sl5310
// Email: abhagat4@horizon.csueastbay.edu

#include "hw4.h"

int main(int argc, char *argv[])
{
    cout << endl;

    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    // Reading Letters.txt and Sequence.txt datafile
    // file1Name = Sequence.txt 
    // file2Name = Letters.txt
    string file1Name = argv[2], file2Name = argv[1];
    ifstream File1(file1Name), File2(file2Name);
    string file1line, file2line;

    if (!File1.is_open())
    {
        cerr << "Error: Could not open file!" << endl;
        return 0;
    }
    if (!File2.is_open())
    {
        cerr << "Error: Could not open file!" << endl;
        return 0;
    }

    // Creating doubly linked list of Letters
    node *temp = new node('a');
    node *head = temp;
    while (getline(File1, file1line))
    {
        // cout << line[0] << endl;
        putItem(head, file1line[0]);
    }
    temp = temp->next;

    // Logic to print "DATASTRUCTURES" using doubly linked list
    while (getline(File2, file2line, ','))
    {
        printindex(temp, stoi(file2line));
    }

    File1.close();
    File2.close();

    cout << endl;
    return 0;
}