// CS_311_PLC_Assignment01
// Author : Aryan Jigneshbhai Bhagat
// NetID: sl5310
// Teammate: Venkata Sai Krishna Aditya Vatturi
// Teammate NetID: by4412
// Contribution: I've worked on the code part and brainstorming part along with my teammate, he helped me in testing and verifying different cases
// Date: 09/04/2024

#include <bits/stdc++.h>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

int main()
{
    // Read file and storing each word in vector (optimal for my txt file only - "dictionary.txt")
    string myWord;
    vector<string> dictionary;
    ifstream readFile("dictionary.txt");
    while (getline(readFile, myWord))
    {   
        dictionary.push_back(myWord);
    }
    readFile.close();

    // Selection of 4 words from dictionary & 16 letters vector(char)
    vector<string> selectedWords;
    vector<char> letters;
    string wordToChar;
    srand(time(0));
    for (int i = 0; i < 4; i++)
    {
        selectedWords.push_back(dictionary.at(rand() % dictionary.size()));
        wordToChar = selectedWords.at(i);
        for (int j = 0; j < 4; j++)
        {
            letters.push_back(wordToChar[j]);
        }
    }

    // just to debug and verify (you can ignore this part)
    // for (auto s : selectedWords)
    // {
    //     cout << s << endl;
    // }
    // cout<< "( just to verify and check what are the actual random four words are ) \n\n\n";

    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         // letters[(i*4)+j] = (letters.at(rand() % letters.size()));
    //         cout << letters[(i*4)+j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "\n<<<<<<<<<<<<<<<  GAME->FOUR_WORD_GRID  >>>>>>>>>>>>>>>>>>>>\n\n";
    cout << "\t\t\t";

    // shuffle all letters and print 4x4 matrix on the console
    random_device rd;
    mt19937 g(rd());
    shuffle(letters.begin(), letters.end(), g);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << letters[(i * 4) + j] << " ";
        }
        cout << endl
             << "\t\t\t";
    }

    cout << "\n<<<<<<<<<<  YOU HAVE 3 LIVES TO GUESS FOUR WORDS  >>>>>>>>\n\n";

    // User input 4 words (3 chances) and verification part
    int lives = 3, count = 0;
    string user_word;
    vector<string> user_list;
    while (lives--)
    {
        int word_count = 4;
        while (word_count--)
        {
            cout << "Enter Word " << 4 - word_count << ": ";
            cin >> user_word;
            while (find(user_list.begin(), user_list.end(), user_word) != user_list.end())
            {
                cout << "you've already entered this word before, enter different one\n";
                cout << "Enter Word " << 4 - word_count << ": ";
                cin >> user_word;
            }
            user_list.push_back(user_word);

            if (find(selectedWords.begin(), selectedWords.end(), user_word) != selectedWords.end())
            {
                count++;
            }
        }
        if (count == 4)
        {
            cout << "\n<<<<<<<<<<<  CONGRATULATIONS! YOU'RE THE WINNER  >>>>>>>>>>>>\n\n"<< endl;
            return 0;
        }
        if (lives == 0)
        {
            break;
        }
        count = 0;
        user_list.clear();
        cout << "\nSorry! These are not the correct words!\nNow, You have only " << lives << " lives are remaining!\n"<< endl;
    }
    cout << "\nThe correct 4 words are: ";
    for (auto s : selectedWords)
    {
        cout << s << ", ";
    }
    cout << "\n\n<<<<<<<<<<<  YOUR ALL LIVES ARE OVER! BETTER LUCK NEXT TIME!  >>>>>>>>>>>>\n\n"<< endl;
    
    return 0;
}