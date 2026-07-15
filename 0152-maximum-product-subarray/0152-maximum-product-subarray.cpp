class Solution {
public:
typedef long long int ll;
    int maxProduct(vector<int>& nums) {
    ll count=0;
        ll maxi=INT_MIN;

    for(int i=0;i<nums.size();i++){ if(nums[i]<0) count++; maxi=max(maxi,(ll)nums[i]);}
    ll n=nums.size();
    vector<ll>pre(n);
    vector<ll>suff(n);
    suff[n-1]=nums[n-1];
    pre[0]=nums[0];
    for(int i=1;i<n;i++){
        if(nums[i]==0) maxi=max(maxi,pre[i-1]);
        if(nums[i-1]==0) pre[i]=nums[i];
        else pre[i]=pre[i-1]*nums[i];
         }
    for(int j=n-2;j>=0;j--){
        if(nums[j]==0) maxi=max(maxi,suff[j+1]);
        if(nums[j+1]==0) suff[j]=nums[j];
        else suff[j]=suff[j+1]*nums[j];
         }

    // if(count%2==0){
    //     for(int i=0;i<n;i++) maxi=max(maxi,pre[i]);
    //     return maxi;
    // }
    for(int i=0;i<n;i++){
        if(nums[i]<0){
          if(i!=0&&i!=n-1) { maxi=max({pre[i-1],maxi,suff[i+1]});}
          else if(i==0&&i!=n-1) maxi=max(maxi,suff[i+1]);
          else if(i!=0&&i==n-1) maxi=max(maxi,pre[i-1]);
        }
         maxi=max({maxi,pre[i],suff[i]});

    }
    return maxi;
    }
};