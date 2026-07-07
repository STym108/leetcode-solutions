class Solution {
public:
typedef long long int ll;
const int mod=1e9+7;
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
    sort(nums.begin(),nums.end());
     vector<vector<int>>ans;
   ll n=nums.size();
   ll i=0;
   while(i<n){
    if(t<=0&&nums[i]>0) break;
    while(i>0&&i<n&&nums[i]==nums[i-1])i++;
    if(i>=n) return ans;
    ll j=i+1;
    while(j<n){
        while(j-1!=i&&j<n&&nums[j]==nums[j-1])j++;
                if(j>=n) break;

        ll x=((ll)t-(ll)nums[i]-(ll)nums[j]);
                // ll x=t-nums[i]-nums[j];

        ll l=j+1;
        ll r=n-1;
        while(l<r){
            if(nums[l]+nums[r]>x) r--;
            else if(nums[l]+nums[r]<x) l++;
            else{
                while(r>l&&nums[r]==nums[r-1]) r--;
                while(l<r&&nums[l]==nums[l+1]) l++;
                ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                r--;
                l++;
            }
        }
j++;
    }
    i++;
   }
   return ans;
    }
};