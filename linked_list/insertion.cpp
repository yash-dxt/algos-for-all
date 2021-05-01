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

int main()
{
    int data, n, position;
    cout << "How many inputs? \n";
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Insert data: \n";
        cin >> data;
        cout << "Which position? \n";
        cin >> position;
        InsertAtPostion(data, position, &head);
        PrintLinkedList(&head);
    }
}
