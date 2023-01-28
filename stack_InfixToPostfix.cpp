// Header file
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkOperator(char k)
{
    if (k == '+' || k == '-' || k == '*' || k == '/' || k == '^')
    {
        return true;
    }
    return false;
}

int checkTingkatan(char k)
{
    if (k == '^')
    {
        return 3;
    }
    else if (k == '*' || k == '/')
    {
        return 2;
    }
    else if (k == '+' || k == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string toPostfix(string infix)
{
    stack<char> opStack;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        if (checkOperator(infix[i]))
        {
            while (!opStack.empty() && checkTingkatan(opStack.top()) >= checkTingkatan(infix[i]))
            {
                postfix += opStack.top();
                opStack.pop();
            }

            opStack.push(infix[i]);
        }

        else if (infix[i] == '(')
        {
            opStack.push(infix[i]);
        }

        else if (infix[i] == ')')
        {
            while (opStack.top() != '(')
            {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();
        }
        else
        {
            postfix += infix[i];
        }
    }
    while (!opStack.empty())
    {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// pertama
int main()
{
    string infix;
    cout << "Masukkan data infix: ";
    cin >> infix;

    string postfix = toPostfix(infix);

    cout << "data postfix/output: " << postfix << endl;

    return 0;
}