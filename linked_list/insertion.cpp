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
    int data, n;
    cout << "How many inputs? \n";
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Insert data: \n";
        cin >> data;
        InsertAtStart(data, &head);
        PrintLinkedList(&head);
    }
}
