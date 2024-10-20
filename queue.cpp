#include <iostream>
using namespace std;

const int capacity = 5;
int queue_arr[capacity];
int front = -1;
int rear = -1;

bool checkUnderflow()
{
    return (front == -1);
}

bool checkOverflow()
{
    return (rear == capacity-1);
}

int deQueue()
{

    if (checkUnderflow())
    {
        cout << "Queue Underflow!";
        return -1;
    }
    int data = 0;
    if(front == rear){
        data = queue_arr[front];
        front = rear = -1;
        return data;
    }
    data = queue_arr[front];
    front++;
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
        front++;   
    }
    rear++;
    queue_arr[rear] = element;
    return;
}

void printQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!";
        return ;
    }
    int i = front;
    cout << "Queue is : ";
    while(i <= rear){
        cout << queue_arr[i]<<" ";
        i++;
    }
    return;
}


int main()
{
    int opt = 0;
    int value = 0;
    do{
        cout << "\n\n1. Enqueue \n2. Dequeue\n";
        cout << "3. Display queue\n4. Exit\n\n";

        cout << "Enter your option :";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter element to enqueue : ";
            cin >> value;
            enQueue(value);
            printQueue();
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
            printQueue();
            break;
        case 4:
            break;
        default:
            cout << "Invalid option. Try again!"<<endl;
            break;
        }
    }while (opt != 4);
    return 0;
}
