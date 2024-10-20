#include <iostream>
using namespace std;

struct queueNode
{
    int info;
    queueNode *next;
};
queueNode * front = NULL;
queueNode * rear = NULL;

bool checkUnderflow()
{
    return (front == NULL);
}

int deQueue()
{
    if (checkUnderflow())
    {
        cout << "Queue Underflow!";
        return -1;
    }
    int data = front->info; 
    if(front == rear){
        queueNode * dltNode = front;
        front = NULL;
        rear = NULL;
        free(dltNode);
        return data;
    }
    queueNode * dltNode = front;
    front = front->next;
    rear->next= front;
    free(dltNode);

    return data;
}

void enQueue(int element)
{
    queueNode * newNode = (queueNode*) malloc(sizeof(queueNode));
    newNode->info = element;
    newNode->next = NULL;
    if(checkUnderflow()){
        front = newNode;
        rear = newNode;
        rear->next = front;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    rear->next = front;
    return;
}

void printQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!";
        return ;
    }
    queueNode * i = front;
    cout << "Queue is : ";
    do{
        cout << i->info<<" ";
        i = i->next;
    }while(i != front);
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
