class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int>lis(n,1);
    int maxlis=0;
    vector<int>v(n,1);
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){ 
            if(lis[i]<lis[j]+1){ lis[i]=lis[j]+1;v[i]=v[j];}
            else if(lis[i]==lis[j]+1) v[i]+=v[j];
                }
        }
     maxlis=max(maxlis,lis[i]);

    }
int count=0;
for(int i=0;i<n;i++) if(lis[i]==maxlis) count+=v[i];
return count;
    }
};