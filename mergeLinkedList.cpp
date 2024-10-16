#include <bits/stdc++.h>
using namespace std;

struct node
{
    int info;
    node *next;
};

node *mergeSortedList(node *list1, node *list2);
node *createLinkedList(node *head);
void display(node *head);
node *createnode(node *head);

int main()
{
    node *list1 = NULL;
    node *list2 = NULL;
    node *mergeList = NULL;
    int opt = 0;
    do
    {
        cout << "\n1. Create First Linked List. \n2. Display First Linked List.\n3. Create second linked list.\n4. Display Second Linked List." << "\n5. Merge the two sorted list." << "\n6. Display Merged list." << "\n7.Exit.";
        cout << "\nEnter option: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            list1 = createLinkedList(list1);
            display(list1);
            break;
        case 2:
            display(list1);
            break;
        case 3:
            list2 = createLinkedList(list2);
            display(list2);
            break;
        case 4:
            display(list2);
            break;
        case 5:
            mergeList = mergeSortedList(list1, list2);
            display(mergeList);
            break;
        case 6:
            display(mergeList);
            break;
        case 7:
            cout << "Exiting...";
            break;
        default:
            cout << "Invalid option ! Try again." << endl;
            break;
        }
    } while (opt != 7);

    return 0;
}

node *mergeSortedList(node *list1, node *list2)
{
    node *mergeHead = (node *)malloc(sizeof(node));
    mergeHead->info = 0;
    mergeHead->next = NULL;
    node *temp = mergeHead;

    node *ptr1 = list1;
    node *ptr2 = list2;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->info <= ptr2->info)
        {
            temp->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        else
        {
            temp->info = ptr2->info;
            ptr2 = ptr2->next;
        }
        if (ptr1 != NULL && ptr2 != NULL)
        {
            node *newNode = (node *)malloc(sizeof(node));
            newNode->next = NULL;
            temp->next = newNode;
            temp = temp->next;
        }
    }
    if (ptr1 != NULL)
        temp->next = ptr1;
    else
    {
        temp->next = ptr2;
    }
    return mergeHead;
}

node *createLinkedList(node *head)
{
    cout << "How much nodes u want in this list: ";
    int nodes = 0;
    cin >> nodes;
    if (nodes)
    {
        head = createnode(head);
    }
    node *ptr = head;
    while (nodes-1)
    {
        ptr->next = createnode(head);
        ptr = ptr->next;
        nodes--;
    }
    return head;
}

node *createnode(node *head)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    node *newnode = (node *)malloc(sizeof(node));
    newnode->info = data;
    newnode->next = NULL;
    return newnode;
}

void display(node *temp)
{
    if (temp == NULL)
    {
        cout << "\nLinked list is empty!" << endl;
        return;
    }
    node *ptr = NULL;
    cout << "Linked list is :";
    for (ptr = temp; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->info << " ";
    }
    cout << endl;
    return;
}
