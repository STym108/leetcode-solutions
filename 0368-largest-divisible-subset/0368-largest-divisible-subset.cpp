class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    vector<int>v(n,1);
    vector<int>par(n);
    for(int i=0;i<n;i++) par[i]=i;
    int maxi=1;
    for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
       if(nums[i]>nums[j]&&(nums[i]%nums[j]==0)){
       if(v[i]<v[j]+1){v[i]=v[j]+1;par[i]=j;  }
       } 
    }
    maxi=max(maxi,v[i]);
    }

    int idx;
    for(int i=n-1;i>=0;i--){ if(v[i]==maxi)idx=i;}
    vector<int>ans;
    while(par[idx]!=idx){
    ans.push_back(nums[idx]);
    idx=par[idx];
    }
    ans.push_back(nums[idx]);
    reverse(ans.begin(),ans.end());
    return ans;

    }
};