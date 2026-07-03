/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
 if(!head) return nullptr;

    ListNode* h1=head;
    ListNode* temp=head;
    //size calculation
    int n=0;
    while(temp){n++;temp=temp->next;}
      k=k%n;
    if(k==0) return head;

      //breaking list in n-k and k part , and fetching the head of k sized list
    ListNode* h2;
    temp=head;
    int x=0;
    while(temp&&x!=n-k){ 
        x++;
        if(x==n-k){ h2=temp->next;temp->next=nullptr;}
        temp=temp->next;
    }



    ListNode* h3;
  if(h2)  temp=h2;
    while(temp){
    if(!temp->next) h3=temp;
    temp=temp->next;
    }

   if(h3) h3->next=h1;
   if(h2) return h2;
return h1;
    }
};