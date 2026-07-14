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
    ListNode* oddEvenList(ListNode* head) {
    if(!head) return head;
    ListNode* oddhead=head;
    if(!head->next) return head;
    ListNode*   evenhead=head->next;
    ListNode* tempodd=oddhead;
    ListNode* tempeven=evenhead;

    while(tempeven&&tempodd){
    tempodd->next=tempeven->next;
    if(tempeven->next) tempeven->next=tempeven->next->next;
    if(!tempodd->next)break;
    tempodd=tempodd->next;
    tempeven=tempeven->next;
    }
    tempodd->next=evenhead;
    return oddhead;

    }
};