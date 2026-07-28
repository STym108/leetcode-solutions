class Solution {
public:
int find(vector<vector<int>>& grid,int i){
    vector<int>v=grid[i];
    int n=grid[i].size();
    vector<int>pse(n);
    vector<int>nse(n);
    //pse
    stack<int>st;
    for(int j=0;j<n;j++){
    while(st.size()>0&&v[st.top()]>=v[j]) st.pop();
    if(st.size()==0) pse[j]=-1;
    else pse[j]=st.top();
    st.push(j);
    }
    st=stack<int>();
    //nse
    for(int i=n-1;i>=0;i--){
        while(st.size()>0&&v[st.top()]>=v[i]) st.pop();
       if(st.size()==0)  nse[i]=n;
       else nse[i]=st.top();
       st.push(i);
    }
    int maxi=0;
    for(int i=0;i<n;i++){
    int l=i-pse[i];
    int r=nse[i]-i;
    int len=l+r-1;
    maxi= max(maxi,len*v[i]);
    }
    return maxi;
}
    int maximalRectangle(vector<vector<char>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    int maxi=0;
    vector<vector<int>>nums(r,vector<int>(c,0));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        if(grid[i][j]=='1') nums[i][j]=1;
        }
    }
    for(int i=1;i<r;i++){
        for(int j=0;j<c;j++){
       if(nums[i-1][j]>0&&nums[i][j]==1) nums[i][j]+=nums[i-1][j];
        }
        
    }
    for(int i=0;i<r;i++) maxi=max(find(nums,i),maxi);
return maxi;
    }
};