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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>v1;
        vector<int>v2;
        ListNode* temp=l1;
        while(temp){v1.push_back(temp->val);temp=temp->next;}
        temp=l2; reverse(v1.begin(),v1.end());
        while(temp){v2.push_back(temp->val);temp=temp->next;}
         reverse(v2.begin(),v2.end());
         while(v1.size()>0&&v1[0]==0) v1.erase(v1.begin());
        while(v2.size()>0&&v2[0]==0) v2.erase(v2.begin());
        vector<int>sum;
        int carr=0;
        int i=v1.size()-1;
        int j=v2.size()-1;
        while(i>=0&&j>=0){
            int x=v1[i]+v2[j]+carr;
           int  rem=x%10;
             carr=x/10;
             sum.push_back(rem);
              i--;j--;
        }
        if(i>=0){
            while(i>=0){
            int x=v1[i]+carr;
           int  rem=x%10;
             carr=x/10;
             sum.push_back(rem);
             i--;
            }
        }

        if(j>=0){
            while(j>=0){
            int x=v2[j]+carr;
           int  rem=x%10;
             carr=x/10;
             sum.push_back(rem);
             j--;
            }
        }
        if(carr>0) sum.push_back(carr);
        // reverse(sum.begin(),sum.end());
        if(sum.size()==0){
            ListNode* tt=new ListNode(0);
            return tt;
        }
        ListNode* head=new ListNode(sum[0]);
        temp=head;
        i=1;
        while(i<sum.size()){
            ListNode* nnode=new ListNode(sum[i]);
            temp->next=nnode;
            temp=temp->next;i++;
        }
        return head;

    }
};