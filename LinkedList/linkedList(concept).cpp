#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
    }
}
Void Reverse(Node *head)
{
    Node *prev = NULL;
    Node *temp;
    while (head->next)
    {
        temp = head->next;
        head->next = prev;
        prev = head;
        head = temp;
    }

    Print(head);
}
int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    Node *head = new Node;
    head->data = a[0];
    Node *temp = head;

    for (int i = 1; i < 5; i++)
    {
        temp->next = new Node;
        temp = temp->next;
        temp->data = a[i];
    }

    Print(head);
    Reverse(head);
    return 0;
}