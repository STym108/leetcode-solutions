class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
    unordered_map<char,int>mp;
    priority_queue<int>pq;
    for(auto ch:v) mp[ch]++;
    for(auto p:mp) pq.push(p.second);

    int time=0;

    while(pq.size()){
        vector<int>nums;
        for(int i=1;i<=n+1;i++){
            if(pq.size()){
             int x=pq.top();pq.pop();
             x--; 
             nums.push_back(x);
            }
        }
        for(auto ele: nums) if(ele>0) pq.push(ele);
        if(pq.size()>0) time+=n+1;
        else time+=nums.size();
    }
    return time;
    
    }
};