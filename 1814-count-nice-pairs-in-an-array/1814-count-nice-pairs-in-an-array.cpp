class Solution {
public:
const int mod=1e9+7;
typedef long long int ll;
ll rev(int n){
   string str=to_string(n);
   reverse(str.begin(),str.end());
   int x=stoi(str);
   return x;
}
    int countNicePairs(vector<int>& nums) {
    unordered_map<ll,ll>mp;
ll count=0;
    for(int i=0;i<nums.size();i++){
    ll x=nums[i]-rev(nums[i]);
    if(mp.find(x)!=mp.end()){
    count+=mp[x];
    }
    mp[x]++;
    }
return count%mod;
    }
};