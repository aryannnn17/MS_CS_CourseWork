#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    string roman_ans;
    cout << "Enter an integer number : ";

    cin >> num;

    while (num >= 1000)
    {
        roman_ans.append("M");
        num -= 1000;
    }

    while (num >= 900)
    {
        roman_ans.append("CM");
        num -= 900;
    }

    while (num >= 500)
    {
        roman_ans.append("D");
        num -= 500;
    }

    while (num >= 400)
    {
        roman_ans.append("CD");
        num -= 400;
    }

    while (num >= 100)
    {
        roman_ans.append("C");
        num -= 100;
    }

    while (num >= 90)
    {
        roman_ans.append("XC");
        num -= 90;
    }

    while (num >= 50)
    {
        roman_ans.append("L");
        num -= 50;
    }

    while (num >= 40)
    {
        roman_ans.append("XL");
        num -= 40;
    }

    while (num >= 10)
    {
        roman_ans.append("X");
        num -= 10;
    }

    while (num == 9)
    {
        roman_ans.append("IX");
        num -= 9;
    }

    while (num >= 5)
    {
        roman_ans.append("V");
        num -= 5;
    }

    while (num == 4)
    {
        roman_ans.append("IV");
        num -= 4;
    }

    while (num >= 1)
    {
        roman_ans.append("I");
        num -= 1;
    }

    cout << roman_ans << endl;
    return 0;
}