#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter any characters from '(', ')', '*' : ";
    cin >> s;
    int open_cnt = 0, close_cnt = 0, star_cnt = 0, margin = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            open_cnt++;
        }
        else if (s[i] == ')')
        {
            close_cnt++;
        }
        else if (s[i] == '*')
        {
            star_cnt++;
        }
        else
        {
            cout << "False" << endl;
            return 0;
        }
    }
    if (open_cnt > close_cnt)
    {
        margin = open_cnt - close_cnt;
    }
    if (open_cnt < close_cnt)
    {
        margin = close_cnt - open_cnt;
    }
    if (open_cnt == close_cnt)
    {
        cout << "True" << endl;
        return 0;
    }
    if (margin <= star_cnt)
    {
        cout << "True" << endl;
        return 0;
    }
    cout << "False" << endl;
}