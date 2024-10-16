#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *prev;
    node *next;
};

bool isEmpty(node *temp);
bool isSingleNode(node *temp);
node *createLinkedList(node *temp, int data);
node *createNode(node *temp, int data);
void display(node *temp);
node *insertAtBeg(node *temp, int data);
node *insertAtEnd(node *temp, int data);
node *insertAfterKey(node *temp);
node *deleteAtBeg(node *temp);
node *deleteAtEnd(node *temp);
node *deleteAtKey(node *temp);
int countNodes(node *temp);

int main()
{
    node *head = NULL;
    int opt;
    int data = 0;
    do
    {
        cout << "\n1. Create a Linked List\n2. Display Linked List\n3. Insert at beg\n4. Insert at end\n5. Insert after the key\n6. Delete begnning node";
        cout << "\n7. Delete end node\n8. Delete node at any location\n9. Count number of nodes\n10. Exit \n\nEnter option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            head = createLinkedList(head, data);
            display(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            cout << "Enter data: ";
            cin >> data;
            head = insertAtBeg(head, data);
            display(head);
            break;
        case 4:
            cout << "Enter data: ";
            cin >> data;
            head = insertAtEnd(head, data);
            display(head);
            break;
        case 5:
            head = insertAfterKey(head);
            display(head);
            break;
        case 6:
            head = deleteAtBeg(head);
            display(head);
            break;
        case 7:
            head = deleteAtEnd(head);
            display(head);
            break;
        case 8:
            head = deleteAtKey(head);
            display(head);
            break;
        case 9:
            cout << "Number of nodes in Linked List is : " << countNodes(head);
            break;
        case 10:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
    } while (opt != 10);

    return 0;
}

bool isEmpty(node *temp)
{
    return (temp == NULL);
}

bool isSingleNode(node *temp)
{
    return (temp->next == NULL);
}

node *createLinkedList(node *temp, int data)
{
    if (temp == NULL)
    {
        temp = createNode(temp, data);
    }
    else
    {
        cout << "Linked list already exits!" << endl;
    }
    return temp;
}

node *createNode(node *temp, int data)
{
    temp = (node *)malloc(sizeof(node));
    temp->info = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void display(node *temp)
{
    if (isEmpty(temp))
    {
        cout << "\nLinked list is empty!" << endl;
        return;
    }
    cout << "Linked list is: ";
    node *ptr = NULL;
    for (ptr = temp; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->info << " ";
    }
    cout << endl;
    return;
}

node *insertAtBeg(node *temp, int data)
{
    node *newNode = createNode(temp, data);
    if(isEmpty(temp)){
        return newNode;
    }
    newNode->next = temp;
    temp->prev = newNode;
    return newNode;
}

node *insertAtEnd(node *temp, int data)
{
    node *newNode = createNode(temp, data);
    if (isEmpty(temp))
    {
        return newNode;
    }
    node *i = temp;
    while (i->next != NULL)
    {
        i = i->next;
    }
    newNode->prev = i;
    i->next = newNode;
    newNode->next = NULL;
    return temp;
}

node *insertAfterKey(node *temp)
{
    if (isEmpty(temp))
    {
        return NULL;
    }
    int key = 0;
    cout << "Enter key after which you have to add data: ";
    cin >> key;
    node *ptr = temp;
    while (ptr != NULL && ptr->info != key)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        cout << "Key not found!" << endl;
        return temp;
    }

    int data = 0;
    cout << "Enter data: ";
    cin >> data;
    node *newNode = createNode(temp, data);
    newNode->prev = ptr;
    newNode->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->prev = newNode;
    }
    ptr->next = newNode;
    return temp;
}

node *deleteAtBeg(node *temp)
{
    if (isEmpty(temp))
    {
        return temp;
    }
    node *dltNode = temp;
    temp = temp->next;
    if (temp != NULL)
    {
        temp->prev = NULL;
    }
    free(dltNode);
    cout << "Deleted Successfully!" << endl;
    return temp;
}

node *deleteAtEnd(node *temp)
{
    if (isEmpty(temp))
    {
        return NULL;
    }
    node *ptr = temp;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if(ptr->prev != NULL){
        ptr->prev->next = NULL;
    }else{
        temp = NULL;
    }
    free(ptr);
    cout << "Deleted Successfully!" << endl;
    return temp;
}

node *deleteAtKey(node *temp)
{
    if (isEmpty(temp))
    {
        return NULL;
    }
    int key = 0;
    cout << "Enter the key which you have to delete: ";
    cin >> key;
    node *ptr = temp;
    while (ptr != NULL && ptr->info != key)
    {
        ptr = ptr->next;
    }
    if(ptr == NULL){
        cout<< "Key value not found!"<<endl;
        return temp;
    }
    if(ptr->prev != NULL){
        ptr->prev->next = ptr->next;
    }else{
        //delting head node
        temp = deleteAtBeg(temp);
        return temp;
    }
    if( ptr->next != NULL){
        ptr->next->prev = ptr->prev;
    }
    node *dltNode = ptr;
    free(dltNode);
    cout << "\nDeleted Successfully!" << endl;
    return temp;
}

int countNodes(node *temp)
{
    int cnt = 0;
    node *ptr = temp;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}
