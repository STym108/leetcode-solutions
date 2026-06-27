class Solution {
public:
int getans(string &s1,int i,int j,string &s2){
if(i<0&&j<0) return 0;

if(i <0) return j+1;
if(j <0) return i+1;
int ok=INT_MAX;
if(s1[i]==s2[j]) ok= getans(s1,i-1,j-1,s2);

int t=getans(s1,i,j-1,s2);
int insert=INT_MAX;int del=INT_MAX;int replace=INT_MAX;
if(t!=INT_MAX) insert=1+t;

t=getans(s1,i-1,j,s2);

 if(t!=INT_MAX)  del=1+t;

 t=getans(s1,i-1,j-1,s2);
if(t!=INT_MAX) replace=1+t;

return min({insert,del,replace,ok});
}

    int minDistance(string word1, string word2) {
    // int ans= getans(word1,word1.size()-1,word2.size()-1,word2);
    int r=word1.size();
    int c=word2.size();
    vector<vector<int>>dp(r+1,vector<int>(c+1,INT_MAX));

    for(int i=0;i<r+1;i++){
        for(int j=0;j<c+1;j++){
      if(i==0&&j==0) dp[i][j]=0;
       else if(j==0&&i!=0) dp[i][j]=i;
       else if(i==0&&j!=0) dp[i][j]=j;

    else {  int left=dp[i-1][j]; int up=dp[i][j-1];int cross=dp[i-1][j-1];
    int backbest=min({left,up,cross});
        if(word1[i-1]==word2[j-1]) dp[i][j]=cross;
       else{
      if(backbest!=INT_MAX) { dp[i][j]=1+backbest;}
       }
       }
        }
    }

    return  dp[r][c];
    }
};