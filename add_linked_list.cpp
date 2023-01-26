#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        ListNode *temp = new ListNode(0);
        ListNode *ptr = temp;
        int carry = 0;
        while (l1 || l2 || carry > 0)
        {
            int v = carry;
            if (l1)
            {
                v += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                v += l2->val;
                l2 = l2->next;
            }

            carry = v / 10;
            v = v % 10;

            ListNode *node = new ListNode(v);
            temp->next = node;
            temp = temp->next;
        }
        return ptr->next;
    }
};

void display_linkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    ListNode *head1 = new ListNode(1);
    ListNode *first1 = new ListNode(8);
    ListNode *sec1 = new ListNode(9);
    ListNode *thrd1 = new ListNode(0);
    ListNode *forth1 = new ListNode(6);

    head1->next = first1;
    first1->next = sec1;
    sec1->next = thrd1;
    thrd1->next = forth1;
    forth1->next = nullptr;

    ListNode *head2 = new ListNode(2);
    ListNode *first2 = new ListNode(5);
    ListNode *sec2 = new ListNode(3);
    ListNode *thrd2 = new ListNode(7);

    head2->next = first2;
    first2->next = sec2;
    sec2->next = thrd2;
    thrd2->next = nullptr;

    cout << "Original Liked List : " << endl;
    display_linkedList(head1);
    cout << endl;
    display_linkedList(head2);

    cout << endl;
    cout << "Linked List after the addition : " << endl;

    Solution obj;
    ListNode *curr = obj.addTwoNumbers(head1, head2);

   display_linkedList(curr);
}