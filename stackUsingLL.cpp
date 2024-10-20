#include <iostream>
using namespace std;

struct stackNode
{
    int info;
    stackNode *next;
};
stackNode * tos = NULL;


bool checkUnderflow()
{
    return (tos == NULL);
}

int popStack()
{
    if (checkUnderflow())
    {
        cout << "Stack Underflow!";
        return -1;
    }
    stackNode * dltNode = tos;
    tos = tos->next;
    int data = dltNode->info;
    free(dltNode);
    return data;
}

void pushStack(int element)
{
    stackNode * newNode = (stackNode*) malloc(sizeof(stackNode));
    newNode->info = element;
    newNode->next = NULL;
    if(tos != NULL){
        newNode->next = tos;
    }
    tos = newNode;
    return;
}

void printStack(){
    if(checkUnderflow()){
        cout << "Stack is empty!";
        return ;
    }
    stackNode * temp = tos;
    cout << "Stack is : "<<endl;
    while(temp){
        cout << temp->info << endl;
        temp = temp->next;
    }
    return;
}

int main()
{
    int opt = 0;
    int value = 0;
    do{
        cout << "\n\n1. Push in the stack \n2. Pop from the stack\n";
        cout << "3. Display the stack\n4. Exit\n\n";

        cout << "Enter your option :";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter element to push in the stack : ";
            cin >> value;
            pushStack(value);
            printStack();
            break;
        case 2:
            value = popStack();
            if (value == -1){
                break;
            }
            cout << "Popped element from stack "<< value <<endl;
            cout << "Now ";
            printStack();
            break;
        case 3:
            printStack();
            break;
        case 4 :
            break;
        default:
            cout << "Invalid option. Try again!"<<endl;
            break;
        }
    }while (opt != 4);
    return 0;
}
