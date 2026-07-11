class LFUCache {
public:
list<int>dll;
unordered_map<int,pair<list<int>::iterator,int>>mp ; //key to {address,value } pair
unordered_map<int,int>keytofreq; //key to freq map
unordered_map<int,list<int>>freqlist; //list for each frequencies 

int limit;
int minf=1;
    LFUCache(int capacity) {
        limit=capacity;
    }
    void makercentlyused(int key){
    int fq=keytofreq[key];keytofreq[key]++;
    freqlist[fq].erase(mp[key].first);
    if(minf==fq&&freqlist[fq].size()==0) minf++;
    fq++;
    freqlist[fq].push_front(key);
    mp[key].first=freqlist[fq].begin();
        for(auto p:keytofreq) minf=min(minf,p.second);

    }
       
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        int x=mp[key].second;
        makercentlyused(key);
        return x;
    }
    
    void put(int key, int value) {
    int cap=mp.size();
    if(mp.find(key)!=mp.end()){
        mp[key].second=value;
        makercentlyused(key);}
    else{

        if(cap>=limit){
        while(freqlist[minf].size()==0){ 
            freqlist.erase(minf); minf++;
         }

        int k=freqlist[minf].back();
        freqlist[minf].pop_back();
        mp.erase(k);
        cap=mp.size();
        keytofreq.erase(k);

        }
    
     keytofreq[key]++;
        freqlist[1].push_front(key);
        mp[key]={freqlist[1].begin(),value};
        // for(auto p:keytofreq) minf=min(minf,p.second);
        minf=1;
              cap++;

    }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */