#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node *head)
    {
        // here we are using slow and fats pointer first we detect if there is any loop in the liked list
        // after that we will use hare-tortoise algorithm to remove the loop
        Node *slow = head;
        Node *fast = head;

        Node *prev;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            prev = fast;
            fast = fast->next;
            if (slow == fast)
            {
                break;
            }
        }
        if (fast != slow)
            return;

        slow = head;
        while (slow != fast)
        {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = nullptr;
        return;
    }
};

void display_linkedList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head1 = new Node(1);
    Node *first1 = new Node(8);
    Node *sec1 = new Node(9);
    Node *thrd1 = new Node(2);
    Node *forth1 = new Node(6);

    head1->next = first1;
    first1->next = sec1;
    sec1->next = thrd1;
    thrd1->next = forth1;
    forth1->next = first1;


    Solution obj;
    obj.removeLoop(head1);
    display_linkedList(head1);

}