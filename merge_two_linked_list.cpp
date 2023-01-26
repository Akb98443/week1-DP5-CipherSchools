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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res = new ListNode(-1);
        ListNode*  temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp3 = res;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val < temp2->val){
                temp3->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp2= temp2->next;
            }
            temp3 = temp3->next;
        }

        if(temp2 != nullptr)
        temp3->next = temp2;
        if(temp1 != nullptr)
        temp3->next = temp1;
        return res->next;
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
    sec2->next = thrd2;
    thrd2->next = nullptr;

    cout << "Original Liked List : " << endl;
    display_linkedList(head1);
    cout << endl;
    display_linkedList(head2);

    cout << endl;
    cout << "Linked List after Merging : " << endl;

    Solution obj;
    ListNode *curr = obj.mergeTwoLists(head1, head2);

   display_linkedList(curr);
}