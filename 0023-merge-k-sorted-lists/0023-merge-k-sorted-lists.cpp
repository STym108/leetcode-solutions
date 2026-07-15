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
typedef pair<int,ListNode*>pr;
    ListNode* mergeKLists(vector<ListNode*>& list) {
    if(list.size()==0) return nullptr;
    priority_queue<pr,vector<pr>,greater<pr>>pq;
    for(int i=0;i<list.size();i++){
        if(list[i]==nullptr) continue;
         pq.push({list[i]->val,list[i]});}
if(pq.size()==0) return nullptr;
    ListNode* head=pq.top().second;pq.pop();
    if(head->next) pq.push({head->next->val,head->next});
    ListNode* temp=head;
    ListNode* minnode;
    while(pq.size()){
     minnode=pq.top().second;pq.pop();
    temp->next=minnode;
    if(minnode->next) pq.push({minnode->next->val,minnode->next});
    temp=temp->next;
    }
    return head;
    }
};