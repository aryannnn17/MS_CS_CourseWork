// Name : Aryan Jigneshbhai Bhagat
// NetID: sl5310
// Email : abhagat4@horizon.csueastbay.edu

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename;
    ifstream ex_File;
    // user to enter a valid file name and open the file
    cout << "Enter a valid file name: ";
    cin >> filename;
    ex_File.open(filename);
    while (!ex_File.is_open())
    {
        cerr << "Error opening file. Please enter a valid filename: ";
        cin >> filename;
        ex_File.open(filename);
    }

    const int MAX_SIZE = 100;
    int count = 0, i = 0, j = 0, sum_row1 = 0, size_row1 = 0, lar_num = 0, row1[MAX_SIZE], row2[MAX_SIZE];
    string num1, num2, inval_num[MAX_SIZE];

    while (getline(ex_File, num1, ',') && getline(ex_File, num2))
    {
        try
        {
            row1[i] = stoi(num1);
            sum_row1 += row1[i];
            size_row1++;
            if (to_string(row1[i]) != num1)
            {
                inval_num[j++] = num1;
            }
        }
        catch (invalid_argument &)
        {
            inval_num[j++] = num1;
        }

        try
        {
            row2[i] = stoi(num2);
            if (i == 0 || lar_num < row2[i])
            {
                lar_num = row2[i];
            }
            if (to_string(row2[i]) != num2)
            {
                inval_num[j++] = num2;
            }
        }
        catch (invalid_argument &)
        {
            inval_num[j++] = num2;
        }

        i++;
        count++;
    }

    // Output the results
    cout<<endl; 
    if (size_row1 > 0)
    {
        cout << fixed << setprecision(4);
        cout << "The average value of all numbers in the first column: " << static_cast<double>(sum_row1) / size_row1 << endl;
    }
    else
    {
        cout << "No valid numbers in the first column to calculate the average." << endl;
    }
    cout << "The largest value of all numbers in the second column: " << lar_num << endl;
    cout << "The total number of rows in the file is: " << count << endl;
    if (j > 0)
    {
        cout << "The invalid numbers are: ";
        for (int k = 0; k < j; k++)
        {
            cout << inval_num[k];
            if (k < j - 1)
            {
                cout << ", ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No invalid numbers found." << endl;
    }

    ex_File.close();
    return 0;
}
