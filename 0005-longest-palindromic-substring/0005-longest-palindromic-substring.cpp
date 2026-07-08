class Solution {
public:
int n;
    vector<vector<int>>dp;

bool checkpalin(string &str,int l,int r){


    if(l>=r) return true;
    
    if(dp[l][r]!=-1) return dp[l][r];

    if(str[l]==str[r]) return dp[l][r]=checkpalin(str,l+1,r-1);
  
    return dp[l][r]=false;
}

    string longestPalindrome(string s) {
        this->n=s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    int maxi=1;
    int idx=0;

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
      bool temp=  checkpalin(s,i,j);
        if(temp==true){
            if(maxi<j-i+1){
                idx=i;
                maxi=max(maxi,j-i+1);
            } 
        }
        }
    }
    string ans="";
    for(int i=idx;i<maxi+idx;i++) ans+=s[i];
    return ans;

    }
};