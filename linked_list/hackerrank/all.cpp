
#include <iostream>

using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;
};

SinglyLinkedListNode *insertNodeAtTail(SinglyLinkedListNode *head, int data)
{

    SinglyLinkedListNode *newNode = new SinglyLinkedListNode();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    SinglyLinkedListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *head, int data, int position)
{
    int n = position + 1;
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode();
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    SinglyLinkedListNode *temp = head;
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

SinglyLinkedListNode *deleteNode(SinglyLinkedListNode *head, int position)
{
    int n = position + 1;
    SinglyLinkedListNode *temp = head;
    if (n == 1)
    {
        SinglyLinkedListNode *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    for (int i = 0; i < n - 2; i++)
    {
        temp = temp->next;
    }
    SinglyLinkedListNode *ntbd = temp->next;
    temp->next = ntbd->next;
    delete ntbd;
    return head;
}

void reversePrint(SinglyLinkedListNode *head)
{
    SinglyLinkedListNode *temp = head;
    if (temp == NULL)
    {
        return;
    }
    reversePrint(temp->next);
    cout << temp->data << "\n";
}
