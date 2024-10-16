#include <iostream>
#include <string>
using namespace std;

const int capacity = 50;
char stack_arr[capacity];
int tos = -1;

bool checkUnderflow()
{
    return (tos == -1);
}

bool checkOverflow()
{
    return (tos == (capacity - 1));
}

int popStack()
{

    if (checkUnderflow())
    {
        cout << "Stack Underflow!";
        return -1;
    }
    char data = stack_arr[tos];
    tos--;
    return data;
}

void pushStack(char element)
{
    if (checkOverflow())
    {
        cout << "Stack Overflow!";
        return;
    }
    tos++;
    stack_arr[tos] = element;
    return;
}

void printStack()
{
    if (checkUnderflow())
    {
        cout << "Stack is empty!";
        return;
    }
    int size = tos + 1;
    cout << "Stack is : " << endl;
    while (size)
    {
        cout << stack_arr[size - 1] << endl;
        size--;
    }
    return;
}

int priority(char opr)
{
    if (opr == '+' || opr == '-')
    {
        return 1;
    }
    if (opr == '*' || opr == '/')
    {
        return 2;
    }
    if (opr == '^')
    {
        return 3;
    }
    return 0;
}

bool checkOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool checkOperand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

bool checkDigit(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

string infixToPostfix(string infixExp)
{

    string postfixExp = "";
    infixExp.append(")");
    pushStack('(');

    int i = 0;
    while (!(checkUnderflow()) && i < infixExp.length())
    {
        if (checkOperand(infixExp[i]))
        {
            while (i < infixExp.length() && checkOperand(infixExp[i]))
            {
                postfixExp += infixExp[i];
                i++;
            }
            postfixExp += " ";
            i--;
        }
        else if (infixExp[i] == '(')
        {
            pushStack(infixExp[i]);
        }
        else if (checkOperator(infixExp[i]))
        {
            if (priority(stack_arr[tos]) >= priority(infixExp[i]))
            {
                while (!checkUnderflow() && priority(stack_arr[tos]) >= priority(infixExp[i]))
                {
                    postfixExp += popStack();
                    postfixExp += " ";
                }
            }
            pushStack(infixExp[i]);
        }
        else if (infixExp[i] == ')')
        {
            while (!checkUnderflow() && stack_arr[tos] != '(')
            {
                postfixExp += popStack();
                postfixExp += " ";
            }
            popStack();
        }
        i++;
    }
    return postfixExp;
}

int applyOperator(int a, int b, char opr)
{
    if (opr == '+')
    {
        return a + b;
    }
    if (opr == '-')
    {
        return a - b;
    }
    if (opr == '*')
    {
        return a * b;
    }
    if (opr == '/')
    {
        return a / b;
    }
    if (opr == '^')
    {
        int sum = 1;
        while (b)
        {
            sum *= a;
            b--;
        }
        return sum;
    }
}

bool checkAlpha(char c)
{
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

int postfixEvaluation(string postfixExp, string infixExp)
{
    postfixExp.append(")");
    int i = 0;
    while (postfixExp[i] != ')')
    {
        if (checkOperand(postfixExp[i]))
        {
            if (checkAlpha(postfixExp[i]))
            {
                cout << "Enter value for " << postfixExp[i] << " : ";
                int x = 0;
                cin >> x;
                pushStack(x);
                //printStack();
            }
            else
            {
                int num = 0;

                while (i < postfixExp.length() && checkOperand(postfixExp[i]))
                {
                    num = num * 10 + (postfixExp[i] - '0');
                    i++;
                }
                pushStack(num);
            }
        }
        else if (checkOperator(postfixExp[i]))
        {
            char opr = postfixExp[i];
            int a = popStack();
            int b = popStack();
            pushStack(applyOperator(b, a, opr));
        }
        i++;
    }
    return stack_arr[tos];
}

int main()
{
    string infixExp = "";
    cout << "Enter infix expression : ";
    cin >> infixExp;

    cout << "\nInfix expression is : " << infixExp << endl;

    string postfixExp = infixToPostfix(infixExp);

    cout << "Postfix expression is : " << postfixExp << endl;

    cout << "Evaluation of Posfix expression is : " << postfixEvaluation(postfixExp, infixExp) << endl;

    return 0;
}