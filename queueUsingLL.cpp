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
    queueNode * dltNode = front;
    front = front->next;
    free(dltNode);

    if(front == NULL){
        rear = NULL;
    }

    return data;
}

void enQueue(int element)
{
    queueNode * newNode = (queueNode*) malloc(sizeof(queueNode));
    if(newNode == NULL){
        cout << "Stack overflow!"<<endl;
        return;
    }
    newNode->info = element;
    newNode->next = NULL;
    if(checkUnderflow()){
        front = rear =  newNode;
    }
    rear->next = newNode;
    rear = newNode;
    return;
}

void printQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!";
        return ;
    }
    queueNode * i = front;
    cout << "Queue is : ";
    while(i){
        cout << i->info<<" ";
        i = i->next;
    }
    return;
}

int peekQueue(){
    if(checkUnderflow()){
        cout << "Queue is empty!"<<endl;
        return -1;
    }
    return front->info;
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
            //if(checkOverflow()){cout << "Queue is overflow!";}
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