#include <iostream>
#include <string.h>
using namespace std;

const int capacity = 50;
int stack_arr[capacity];
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

int applyOperator(int a, int b, char opr)
{
    if (opr == '+')
    {
        return a + b;
    }
    if (opr == '-')
    {
        return abs(a - b);
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

int main()
{
    char postfixExp[capacity]= {};
    cout << "Enter postfix expression : ";
    cin.getline(postfixExp, capacity);

    cout << "\nPostfix expression is : " << postfixExp << endl;

    int length = strlen(postfixExp);
    postfixExp[length] = ')';
    postfixExp[length + 1] = '\0';

    int i = 0;

    while (postfixExp[i] != ')'){
        if(checkOperand(postfixExp[i])){
            pushStack(postfixExp[i] - '0');
        }
        else if(checkOperator(postfixExp[i])){
            char opr = postfixExp[i];
            int a = popStack();
            int b = popStack(); 
            pushStack(applyOperator(b, a, opr));
        }
        i++;
    }
    cout << "Result is : " << stack_arr[tos] << endl;

    return 0;
}