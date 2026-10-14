class Solution {
public:
    int findMaximizedCapital(int k, int currcapital, vector<int>& pr, vector<int>& cap) {
    priority_queue<int>pq;
    int i=0;
    int n=pr.size();
    vector<pair<int,int>>v;
    for(int j=0;j<n;j++){
        v.push_back({cap[j],pr[j]});
    }
    sort(v.begin(),v.end());
    while(i<n){
    while(i<n&&v[i].first<=currcapital){
        pq.push(v[i].second);
       i++;
    }
    if(i<n&&k>0&&pq.size()>0){
    currcapital+=pq.top();pq.pop(); k--; continue;
     }
     if(k==0) break;
    i++;
    }
    while(k>0&&pq.size()>0){
        currcapital+=pq.top();pq.pop();k--;
    }
    return currcapital;
    
    }
};