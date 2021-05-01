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
