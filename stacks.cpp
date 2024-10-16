#include <iostream>
using namespace std;

const int capacity = 5;
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
    int data = stack_arr[tos];
    tos--;
    return data;
}

void pushStack(int element)
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

void printStack(){
    if(checkUnderflow()){
        cout << "Stack is empty!";
        return ;
    }
    int size = tos+1;
    cout << "Stack is : "<<endl;
    while(size){
        cout << stack_arr[size-1]<<endl;
        size--;
    }
    return;
}

int main()
{
    int opt = 0;
    int value = 0;
    do{
        cout << "\n\n1. Push in the stack \n2. Pop from the stack\n";
        cout << "3. Display the stack\n4. Print Top element of stack \n5. Exit\n\n";

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
            break;
        case 3:
            printStack();
            break;
        case 4:
            if(tos == -1){
                cout << "Stack is empty!";
                break;
            }
            cout<< "Top of the stack is "<< stack_arr[tos] <<endl;
            break;
        case 5 :
            break;
        default:
            cout << "Invalid option. Try again!"<<endl;
            break;
        }
    }while (opt != 5);
    return 0;
}