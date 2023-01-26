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
     ListNode* removeNthFromEnd(ListNode* head, int n) {

        /////////////////////////////METHOD1/////////////////////////////////
        // int size =  0;
        // ListNode *temp = head;
        // while(temp) {
        //     size++;
        //     temp = temp->next;
        // }
        // if(size==n) return head->next;
        // ListNode *temp2 = head;
        // ListNode * temp3 = head->next;
        // while(size-1 > n){
        //     temp2 = temp2->next;
        //     temp3 = temp3->next;
        //     size--;
        // }
        // temp2->next = temp3->next;
        // return head; 

//method 2

        ListNode* slow = head;
        ListNode* fast = head;

        while(n--){
            fast = fast->next;
        }

        if(!fast){
            return head->next;
        }
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode*  temp = slow->next;
        slow->next = temp->next;
        delete temp;

return head;

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
    ListNode *thrd1 = new ListNode(4);
    ListNode *forth1 = new ListNode(6);

    head1->next = first1;
    first1->next = sec1;
    sec1->next = thrd1;
    thrd1->next = forth1;
    forth1->next = nullptr;

    

    cout << "Original Liked List : " << endl;
    display_linkedList(head1);
    cout << endl;

    cout << "Linked List after the removing nth node from the end : " << endl;

    Solution obj;
    ListNode *curr = obj.removeNthFromEnd(head1, 2);

   display_linkedList(curr);
}