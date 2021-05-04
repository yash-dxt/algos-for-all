#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void InsertAtStart(int data, Node **head)
{

    Node *temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void ReverseLinkedList(Node **head)
{
    Node *current, *prev, *next;
    prev = NULL;
    current = *head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void InsertAtEnd(int data, Node **head)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    Node *temp2 = *head;
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void InsertAtPostion(int data, int position, Node **head)
{

    Node *temp = new Node();
    temp->data = data;
    if (position == 1)
    {
        temp->next = *head;
        *head = temp;
        return;
    }
    Node *temp2 = *head;
    for (int i = 0; i < position - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void DeleteAtPosition(int position, Node **head)
{
    Node *temp1 = *head;
    if (position == 1)
    {
        *head = temp1->next;
        delete temp1;
        return;
    }
    for (int i = 0; i < position - 2; i++)
    {
        temp1 = temp1->next;
    }
    Node *temp2 = temp1->next;
    temp1->next = temp2->next;
    delete temp2;
}

void ReverseLinkedList(Node **head)
{
    Node *curr, *prev, *next;

    curr = *head;
    prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void ReverseLinkedListRecursion(Node **head)
{
    Node *temp = *head;
    if (temp->next == NULL)
    {
        *head = temp;
        return;
    }
    ReverseLinkedListRecursion(&(*head)->next);
    Node *lastInStack = temp->next;
    lastInStack->next = temp;
    temp->next = NULL;
}

void PrintLinkedList(Node **head)
{
    Node *temp = *head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void ReversePrint(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
        return;
    ReversePrint(&(temp->next));
    cout << temp->data << " ";
}

void PrintUsingRecursion(Node **head)
{
    Node *temp = *head;
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    PrintUsingRecursion(&(temp->next));
}

int main()
{
    int data, n, position;
    Node *head = NULL;

    InsertAtEnd(4, &head);
    InsertAtEnd(2, &head);
    InsertAtEnd(0, &head);
    InsertAtEnd(6, &head);
    InsertAtEnd(9, &head);
    ReversePrint(&head);
}
