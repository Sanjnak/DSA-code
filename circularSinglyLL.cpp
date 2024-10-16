#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
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

int main()
{
    node *head = NULL;
    int opt;
    int data= 0;
    do
    {
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
        temp->next = temp;
    }
    else
    {
        cout << "Circular linked list already exits!" << endl;
    }
    return temp;
}

node *createNode(node *temp, int data)
{
    temp = (node *)malloc(sizeof(node));
    temp->info = data;
    temp->next = NULL;
    return temp;
}

void display(node *temp)
{
    if (isEmpty(temp))
    {
        cout << "\nCircular linked list is empty!"<<endl;
        return;
    }
    cout << "\nCircular linked list is: ";
    node *ptr = temp;
    do
    {
        cout << ptr->info << " ";
        ptr = ptr->next;
    } while (ptr != temp);
    cout << endl;
    return;
}

node *insertAtBeg(node *temp, int data)
{
    node *newNode = createNode(temp, data);
    if (isEmpty(temp))
    {
        temp = newNode;
        temp->next = temp;
    }
    else
    {
        node *ptr = temp;
        while (ptr->next != temp)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
        newNode->next = temp;
        temp = newNode;
    }

    return temp;
}

node *insertAtEnd(node *temp, int data)
{
    node *newNode = createNode(temp, data);
    if (isEmpty(temp))
    {
        temp = newNode;
        temp->next = temp;
    }
    node *ptr = temp;
    while (ptr->next != temp)
    {
        ptr = ptr->next;
    }
    newNode->next = temp;
    ptr->next = newNode;
    return temp;
}

node *insertAfterKey(node *temp)
{
    if (isEmpty(temp))
    {
        return NULL;
    }
    int key, data = 0;
    cout << "Enter key after which you have to add data: ";
    cin >> key;
    node *ptr = temp;
    cout << "Enter data: ";
    cin >> data;
    node *newNode = createNode(temp, data);
    do
    {
        if (ptr->info == key)
        {
            newNode->next = ptr->next;
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
    if (isEmpty(temp))
    {
        return temp;
    }
    if (temp->next == temp)
    {
        free(temp);
        cout << "\nDeleted Successfully!" << endl;
        return NULL;
    }
    node *ptr = temp;
    while (ptr->next != temp)
    {
        ptr = ptr->next;
    }
    node *dltNode = temp;
    ptr->next = temp->next;
    temp = temp->next;
    free(dltNode);
    cout << "\nDeleted Successfully!" << endl;
    return temp;
}

node *deleteAtEnd(node *temp)
{
    if (isEmpty(temp))
    {
        return temp;
    }
    if (temp->next == temp)
    {
        free(temp);
        cout << "\nDeleted Successfully!" << endl;
        return NULL;
    }
    node *ptr = temp;
    while (ptr->next->next != temp)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = temp;
    cout << "\nDeleted Successfully!" << endl;
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
    if (key == temp->info)
    {
        return deleteAtBeg(temp);
    }
    node *ptr = temp;
    while (ptr->next != temp && ptr->next->info != key)
    {
        ptr = ptr->next;
    }
    if (ptr->next->info == key)
    {
        node *dltNode = ptr->next;
        ptr->next = ptr->next->next;
        free(dltNode);
        cout << "\nDeleted Successfully!" << endl;
    }else{
        cout << "Key not found!"<<endl;
    }
    return temp;
}
