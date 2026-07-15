class Solution {
public:

    bool searchMatrix(vector<vector<int>>& grid, int t) {
    int r=grid.size();
    int c=grid[0].size();
    int j=c-1;
    int i=0;
    while(i<r&&j>=0){
        if(i>=r&&j<0) return false;
        if(grid[i][j]==t) return true;

            while(i<r&&j>=0&&grid[i][j]>t){
            if(grid[i][j]==t) return true;
            j--;
            }
            
            while(i<r&&j>=0&&grid[i][j]<t){
            if(grid[i][j]==t) return true;
            i++;
            }
        if(i>=r&&j<0) return false;
    }
return false;
    }
};