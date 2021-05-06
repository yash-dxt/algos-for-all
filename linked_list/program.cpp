#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void Push(int data, Node **head)
{
    Node *newNode = new Node(); // head   [ | ]
    newNode->data = data;       //  head   [ data |  ]
    newNode->next = *head;      // [ data | &head  ]--->head (If null points to null)
    *head = newNode;            // head ---> [ data | &head  ] ---> prevhead
}

void Append(int data, Node **head)
{
    Node *newNode = new Node();
    Node *temp = *head;
    newNode->data = data;
    if (*head == NULL)
    {
        *head = newNode; //If the list is empty
        return;
    }
    while (temp->next != NULL) //Loops till the last element and makes temp as the last element.
    {
        temp = temp->next;
    }
    temp->next = newNode; //last element's next will be new node
}

void InsertAt(int position, int data, Node **head)
{
    Node *newNode = new Node();
    Node *temp = *head;
    newNode->data = data;

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void PrintRecursion(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    cout << (*head)->data << " ";
    PrintRecursion(&((*head)->next));
}

void ReversePrint(Node **head)
{
    if (*head == NULL)
    {
        return;
    }
    ReversePrint(&((*head)->next));

    cout << (*head)->data << " ";
}

void Print(Node **head)
{
    while ((*head)->next != NULL)
    {
        cout << (*head)->data << " ";
    }
}

void DeleteAtPos(int position, Node **head)
{
    Node *temp = *head;
    if (position == 1)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; i < position - 2; i++)
    {
        temp = temp->next;
    }
    Node *deleted = temp->next;
    temp->next = deleted->next;
    delete deleted;
}

void reverseIterative(Node **head)
{
    Node *prev, *curr, *next;
    curr = *head;
    prev = NULL;
    next = curr->next;
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    *head = prev;
}

void reverseRecursive(Node **head)
{
}

int main()
{
    const int exit = 0;
    int input;
    int data;
    Node *head = NULL;
    cout << "Let's play linked list linked list?\n\n";
    while (1)
    {
        cout << "Enter a number: \n 0 --> Exit \n 1 --> Enter a number at beginning of linked list \n 2 --> Enter a number at end of linked list \n 68/69 --> Print \n 70 --> Reverse Print \n  ";
        cin >> input;
        if (input == 0)
        {
            break;
        }
        if (input == 1)
        {
            cout << "Data? \n";
            cin >> data;
            Push(data, &head);
        }
        if (input == 2)
        {
            cout << "Data? \n";
            cin >> data;
            Append(data, &head);
        }
        if (input == 68)
        {
            cout << "\n";
            Print(&head);
            cout << "\n";
        }
        if (input == 69)
        {
            cout << "\n";
            PrintRecursion(&head);
            cout << "\n";
        }
        if (input == 70)
        {
            cout << "\n";
            ReversePrint(&head);
            cout << "\n";
        }
    }
}
