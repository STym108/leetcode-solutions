class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
    unordered_map<int,pair<int,int>>mp;
    int r=mat.size();
    int c=mat[0].size();
    int i=0;
    int j=0;

        while(true){
            int maxi=-1;
                    bool anylarger=false;
         if(i-1>=0){  mp[mat[i-1][j]]={i-1,j};
         if(mat[i][j]<mat[i-1][j]){ anylarger=true; maxi=max(maxi,mat[i-1][j]);}
         }
         if(i+1<r){   mp[mat[i+1][j]]={i+1,j};
         if(mat[i][j]<mat[i+1][j]){ anylarger=true; maxi=max(maxi,mat[i+1][j]);}
         }
          if(j-1>=0){  mp[mat[i][j-1]]={i,j-1};
           if(mat[i][j]<mat[i][j-1]){ anylarger=true; maxi=max(maxi,mat[i][j-1]);}
          }
          if(j+1<c){  mp[mat[i][j+1]]={i,j+1};
          if(mat[i][j]<mat[i][j+1]){ anylarger=true; maxi=max(maxi,mat[i][j+1]);}
          }

            if(!anylarger) return {i,j};
          i=mp[maxi].first;
          j=mp[maxi].second;
        }
        return {0,0};
    
    }
};