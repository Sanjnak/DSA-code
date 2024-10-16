#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node *prev;
    node *next;
};

bool isEmpty(node *temp);
node *createLinkedList(node *temp, int data);
node *createNode(node *temp, int data);
void display(node *temp);
node *insertAtBeg(node *temp, int data);
node *insertAtEnd(node *temp, int data);
node *insertAfterKey(node *temp);
node *deleteAtBeg(node *temp);
node *deleteAtEnd(node *temp);
node *deleteAtKey(node *temp);


int main(){
    node* head = NULL;
    int opt;
    int data = 0;
    do{
        cout << "\n1. Create a Circular Linked List\n2. Display Circular Linked List\n3. Insert at beg\n4. Insert at end\n5. Insert after the key\n6. Delete begnning node";
        cout << "\n7. Delete end node\n8. Delete node at any location\n9. Exit \n\nEnter option: ";
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
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option! Try again." << endl;
            break;
        }
    } while (opt != 9);
    
    return 0;
}

bool isEmpty(node *temp)
{
    return (temp == NULL);
}
node *createLinkedList(node *temp, int data)
{
    if (temp == NULL)
    {
        temp = createNode(temp, data);
        temp->prev = temp;
        temp->next = temp;
    }
    else
    {
        cout << "Circular linked list already exits!" << endl;
    }
    return temp;
}
node* createNode(node* temp, int data){
    temp = (node*)malloc(sizeof(node));
    temp->info = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void display(node* temp)
{
    if (isEmpty(temp))
    {
        cout << "\nCircular linked list is empty!"<<endl;
        return;
    }
    cout << "Linked list is: ";
    node* ptr=temp;
    do {
        cout << ptr->info << " ";
        ptr = ptr->next;
    } while (ptr != temp);
    cout << endl;
    return;
}

node* insertAtBeg(node* temp, int data)
{
    node *newNode = createNode(temp, data);
    if (isEmpty(temp)) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    node* lastNode = temp->prev;
    newNode->prev = lastNode;
    newNode->next = temp;
    temp->prev = newNode;
    lastNode->next = newNode;
    return newNode;
}

node* insertAtEnd(node *temp, int data)
{
    node *newNode = createNode(temp, data);
    if (isEmpty(temp)) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    
    node* lastNode = temp->prev;
    newNode->prev = lastNode;
    newNode->next = temp;
    lastNode->next = newNode;
    temp->prev = newNode;
    return temp;
}

node* insertAfterKey(node *temp)
{
    if (isEmpty(temp)) {
        return temp;
    }
    int key, data = 0;
    cout << "Enter key after which you have to add data: ";
    cin >> key;
    cout << "Enter data: ";
    cin >> data;
    node *newNode = createNode(temp, data);
    node* ptr = temp;
    do {
        if (ptr->info == key) {
            newNode->next = ptr->next;
            newNode->prev = ptr;
            ptr->next->prev = newNode;
            ptr->next = newNode;
            return temp;
        }
        ptr = ptr->next;
    } while (ptr != temp);

    cout << "Key not found!" << endl;
    return temp;
}

node *deleteAtBeg(node *temp)
{
    if (isEmpty(temp)) {
        return temp;
    }
    if (temp->next == temp) 
    { 
        free(temp);
        cout << "\nDeleted Successfully!" << endl;
        return NULL;
    }
    node * dltNode = temp;
    node* lastNode = temp->prev;
    temp = temp->next;
    lastNode->next = temp;
    temp->prev = lastNode;
    free(dltNode);
    cout << "\nDeleted Successfully!" << endl;
    return temp;
}

node* deleteAtEnd(node *temp)
{
    if (isEmpty(temp)) {
        return temp;
    }
    if (temp->next == temp) 
    {
        free(temp);
        cout << "\nDeleted Successfully!" << endl;
        return NULL;
    }
    node * dltNode = temp->prev;
    node * lastNode = temp->prev;
    lastNode->prev->next = temp;
    temp->prev = lastNode->prev;
    free(dltNode);
    cout << "\nDeleted Successfully!" << endl;
    return temp;
}

node* deleteAtKey(node *temp)
{
    if (isEmpty(temp))
    {
        return NULL;
    }
    int key = 0;
    cout << "Enter the key which you have to delete: ";
    cin >> key;
    // node* ptr = temp;
    // do {
    //     if (ptr->info == key) {
    //         if (ptr == temp) {
    //             temp = deleteAtBeg(temp);
    //             return temp;
    //         }

    //         node* prevNode = ptr->prev;
    //         node* nextNode = ptr->next;
    //         prevNode->next = nextNode;
    //         nextNode->prev = prevNode;
    //         free(ptr);
    //         cout << "\nDeleted Successfully!" << endl;
    //         return temp;
    //     }
    //     ptr = ptr->next;
    // } while (ptr != temp);

//head node condition
    if(temp->info == key){
        if(temp->next == temp){
            cout << "\nDeleted Successfully!" << endl;
            free(temp);
            return NULL;
        }
        node * ptr = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp = temp->next;
        free(ptr);
        cout << "\nDeleted Successfully!" << endl;
        return temp;
    }

    node * ptr = temp->next;
    while(ptr != temp){
        if(ptr->info == key){
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
            cout << "\nDeleted Successfully!" << endl;
            return temp;
        }
        ptr = ptr->next;
    }
    cout << "Key not found!" << endl;
    return temp;
}


