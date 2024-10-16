#include <iostream>
#include <string>
#include <math.h>
using namespace std;


const int cap = 50;
char st[cap];
int tos = -1;


bool isFull() {
    return tos == cap - 1;
}

bool isEmpty() {
    return tos == -1;
}

int top(){
	return st[tos];
}

int pop()
{

    if (isEmpty())
    {
        cout << "Stack Underflow!";
        return -1;
    }
    char data = st[tos];
    tos--;
    return data;
}

void push(char data)
{
    if (isFull())
    {
        cout << "Stack Overflow!";
        return;
    }

    st[++tos] = data;
    return;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty!";
        return;
    }
    int size = tos + 1;
    cout << "Stack is : " << endl;
    while (size)
    {
        cout << st[size - 1] << endl;
        size--;
    }
    return;
}

int prec(char op) {
  if (op == '^')
    return 3;
  else if (op == '/' || op == '*')
    return 2;
  else if (op == '+' || op == '-')
    return 1;
  else
    return -1;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c){
	return (c >= '0' && c <= '9');
}

string infixToPostfix(string infix){
	
	string postfix = "";
	for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        
        if (isOperand(c)) {
           
            while (i < infix.length() && isOperand(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';  
            i--; 
        }
        
        else if (c == '(') {
            push(c);
        }
       
        else if (c == ')') {
            while (!isEmpty() && top() != '(') {
                postfix += top();
                postfix += ' ';  // Add space after operators
                pop();
            }
            pop();  // Pop the left parenthesis
        }
        
        else {
            while (!isEmpty() && prec(infix[i]) <= prec(top())) {
            postfix += top();
            postfix += ' ';
            pop();
           }
           push(c);
        }
       
    }
    
    while (!isEmpty()) {
        postfix += top();
        postfix += ' ';  // Add space after operators
        pop();
    }

    return postfix;
        
	
}

int apply(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return abs(a - b);
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);  
        default: return 0;
    }
}

int evaluatePostfix(string postfix) {

    int i = 0;

    while (i < postfix.length()) {
        char c = postfix[i];

        
        if (isOperand(c)) {
            int num = 0;

           
            while (i < postfix.length() && isOperand(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            push(num);  
        }
        
        else if (isOperator(c)) {
            
            int op2 = top(); 
			pop();
            int op1 = top(); 
			pop();

            
            int result = apply(op1, op2, c);
            push(result);
        }


        i++;
    }

   
    return top();
}

int main() {
	
	
  string infix = "";
  cout << "Enter infix expression : ";
  cin >> infix;
	
  cout << "Infix expression: " << infix << endl;
  
  string postfix = infixToPostfix(infix);
  cout << "Postfix expression is : " << postfix << endl;
  
   // Evaluate the postfix expression
  int result = evaluatePostfix(postfix);
  cout << "Evaluation result: " << result << endl;
  
  
  return 0;
}
