#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
      ListNode* temp = head;
        ListNode*curr = NULL;
        ListNode *res = head->next;
      while(temp!=NULL){
          temp->next = curr;
          curr = temp;
          temp = res;
          if(res!=NULL) res = res->next;
      }
      return curr;  
    }
};

int main() {
    ListNode* head = new ListNode(12);
    ListNode* first = new ListNode(22);
    ListNode* sec = new ListNode(32);
    ListNode* thrd = new ListNode(42);
    ListNode* forth = new ListNode(52);

    head->next = first;
    first->next = sec;
    sec->next = thrd;
    thrd->next =forth;
    forth->next =nullptr;

    cout<<"Original Liked List : "<<endl;
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
cout<<endl;
    cout<<"Linked List after the reverse: "<<endl;

    Solution obj;
    ListNode* curr = obj.reverseList(head);

    while(curr){
        cout<<curr->val<<" ";
        curr = curr->next;
    }


}