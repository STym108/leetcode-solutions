class Solution {
public:
int ans(vector<vector<int>>& books,int idx, int sw,vector<int>&dp){
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
int maxh=0;
int thisans=INT_MAX;
int thisw=0;
for(int i=idx;i>=0;i--){
    if(thisw+books[i][0]>sw) break;
    thisw+=books[i][0];
    maxh=max(books[i][1],maxh);
    thisans=min(maxh+ans(books,i-1,sw,dp),thisans);
}

return dp[idx]=thisans;
}
    int minHeightShelves(vector<vector<int>>& books, int sw) {
        vector<int>dp(books.size(),-1);
        
        return ans(books,books.size()-1,sw,dp);
    }
};