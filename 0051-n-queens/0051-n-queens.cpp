class Solution {
public:
unordered_set<int>taken_cols;

bool checkit(vector<string>&grid,int r,int c){
int i=r;
int j=c;
while(i>=0&&j>=0){
    if(grid[i][j]=='Q') return false;
    i--;j--;
}
i=r;j=c;
while(i>=0&&j<grid[0].size()){
        if(grid[i][j]=='Q') return false;
    i--;j++;
}
return true;
}


void getans(vector<string>&grid,int curr_row,vector<vector<string>>&ans){
if(curr_row>=grid.size()){
    ans.push_back(grid);return;
}

for(int j=0;j<grid[0].size();j++){
    if(taken_cols.find(j)!=taken_cols.end()) continue;
    if(checkit(grid,curr_row,j)){
        grid[curr_row][j]='Q';
        taken_cols.insert(j);
       getans(grid,curr_row+1,ans);
       taken_cols.erase(j);
       grid[curr_row][j]='.';
    }

}
}

    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>>ans;

     vector<string>grid(n,string(n,'.'));
     getans(grid,0,ans);
     return ans;
    }
};