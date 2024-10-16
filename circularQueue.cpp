#include <iostream>
using namespace std;

const int capacity = 5;
int cirQueue_arr[capacity];
int front = -1;
int rear = -1;

bool checkUnderflow()
{
    return (front == -1);
}

bool checkOverflow()
{
    return ((rear+1)%capacity == front);
}

int deQueue()
{

    if (checkUnderflow())
    {
        cout << "Queue Underflow!";
        return -1;
    }
    int data = cirQueue_arr[front];
    if(front == rear){
        front = rear = -1;
        return data;
    }
    front = (front+1)%capacity;
    return data;
}

void enQueue(int element)
{
    if (checkOverflow())
    {
        cout << "Queue Overflow!";
        return;
    }
    if(checkUnderflow()){
        front = (front+1)%capacity;   
    }
    rear = (rear+1)%capacity;
    cirQueue_arr[rear] = element;
    return;
}

void printQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!";
        return ;
    }
    int i = front;
    cout << "Queue is : ";
    while(i != rear){
        cout << cirQueue_arr[i]<<" ";
        i = (i+1)%capacity;
    }
    cout << cirQueue_arr[rear]<<" ";
    return;
}

int peekQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!"<<endl;
        return -1;
    }
    return cirQueue_arr[front];
}

int main()
{
    int opt = 0;
    int value = 0;
    do{
        cout << "\n\n1. Enqueue \n2. Dequeue\n";
        cout << "3. Check status of queue \n4. Display queue\n5. Exit\n\n";

        cout << "Enter your option :";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter element to enqueue : ";
            cin >> value;
            enQueue(value);
            break;
        case 2:
            value = deQueue();
            if (value == -1){
                break;
            }
            cout << "Element that is removed : "<< value <<endl;
            cout << "Now ";
            printQueue();
            break;
        case 3:
            if(checkUnderflow()){cout << "Queue is empty!";}
            if(checkOverflow()){cout << "Queue is overflow!";}
            break;
        case 4:
            printQueue();
            break;
        case 5:
            break;
        default:
            cout << "Invalid option. Try again!"<<endl;
            break;
        }
    }while (opt != 5);
    return 0;
}