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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    if(!head) return nullptr;
    ListNode* temp=head;
    ListNode* backtemp=head;
    int x=1;
    while(temp&&x!=n+1){
        temp=temp->next;
      x++;
    }
 if(temp==NULL) return head->next;

    while(temp&&temp->next){
        temp=temp->next;
        backtemp=backtemp->next;
    }

    // if(backtemp==head&&!temp) return head->next;
 backtemp->next=backtemp->next->next;
    return head;

    }
};