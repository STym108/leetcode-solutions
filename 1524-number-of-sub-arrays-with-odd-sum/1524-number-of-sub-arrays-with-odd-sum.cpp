class Solution {
public:
const int mod=1e9+7;
typedef long long int ll;
    int numOfSubarrays(vector<int>& arr) {
    ll oddsum=0;
    ll evensum=0;
    ll sum=0;
    ll ans=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum%2==0){ ans+=oddsum; evensum++;}
        else{
            oddsum++;
            ans+=evensum+1;
        }
    }
    return ans%mod;

    }
};