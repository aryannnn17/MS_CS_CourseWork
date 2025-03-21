// Aryan Bhagat - sl5310
// Moksha Shah - bp4199
// CS_601 - HW5_Q1 Solution

#include <bits/stdc++.h>
using namespace std;

// This is a stack implementation with class MyStack using two queues.
class MyStack
{
private:
    queue<int> q1, q2;

public:
    // push x onto stack
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    // removes the element on top of the stack
    int pop()
    {
        int val = q1.front();
        q1.pop();
        return val;
    }

    // get the top element
    int top()
    {
        return q1.front();
    }

    // return whether the stack is empty
    bool empty()
    {
        return q1.empty();
    }
};