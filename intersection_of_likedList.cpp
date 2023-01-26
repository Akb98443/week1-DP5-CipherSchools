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
     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        if(temp1 == NULL || temp2 == NULL)
            return NULL;
        while(temp1!=temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1 == temp2)
                return temp1;
            if(temp1 == NULL)
                temp1 =headB;
            if(temp2 == NULL)
                temp2 = headA;
        }
        return temp2;
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
    ListNode *first1 = new ListNode(3);
    ListNode *sec1 = new ListNode(4);
    ListNode *thrd1 = new ListNode(6);
    ListNode *forth1 = new ListNode(8);

    head1->next = first1;
    first1->next = sec1;
    sec1->next = thrd1;
    thrd1->next = forth1;
    forth1->next = nullptr;

    ListNode *head2 = new ListNode(2);
    ListNode *first2 = new ListNode(3);
    ListNode *sec2 = new ListNode(4);
    ListNode *thrd2 = new ListNode(5);

    head2->next = first2;
    first2->next = sec2;
    sec2->next = thrd1;

    cout << "Original Liked List : " << endl;
    display_linkedList(head1);
    cout << endl;
    display_linkedList(head2);

    cout << endl;

    Solution obj;
    ListNode *curr = obj.getIntersectionNode(head1, head2);

    cout<<"Intersection Point of the Linked List : "<<curr->val; 

}