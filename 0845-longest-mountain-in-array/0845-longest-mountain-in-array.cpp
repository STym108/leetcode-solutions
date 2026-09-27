class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int n=arr.size();
    vector<int>len1(n,1);
    vector<int>len2(n,1);
    for(int i=1;i<n;i++){
      if(arr[i]>arr[i-1]) len1[i]=len1[i-1]+1;
    }
    for(int i=n-2;i>=0;i--){
    if(arr[i]>arr[i+1]) len2[i]=len2[i+1]+1;
    }
    int maxi=1;
    for(int i=1;i<n-1;i++){
    if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]) maxi=max(maxi,len1[i]+len2[i]);
    }
    return maxi-1;
    }
};