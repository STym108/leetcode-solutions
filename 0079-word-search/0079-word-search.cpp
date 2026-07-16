class Solution {
public:
bool checkkar(vector<vector<char>>& grid,int i,int j,int idx,string word,vector<vector<bool>>&visit){
        if(idx>=word.size()) return true;
    if(i>=grid.size()||i<0||j>=grid[0].size()||j<0||grid[i][j]!=word[idx]||visit[i][j]) return false;
    bool up=false;bool down=false;bool left=false;bool right=false;
    visit[i][j]=true;
    up=checkkar(grid,i-1,j,idx+1,word,visit);
    down=checkkar(grid,i+1,j,idx+1,word,visit);
    left=checkkar(grid,i,j-1,idx+1,word,visit);
    right=checkkar(grid,i,j+1,idx+1,word,visit);
    visit[i][j]=false;
    return up||down||left||right;
}
    bool exist(vector<vector<char>>& grid, string word) {
    int r=grid.size();
    int c=grid[0].size();
    vector<vector<bool>>visit(r,vector<bool>(c,false));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
        if(grid[i][j]==word[0]){

            if(checkkar(grid,i,j,0,word,visit)) return true;
        }
        }
    }
    return false;

    }
};