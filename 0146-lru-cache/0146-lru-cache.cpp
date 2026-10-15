class LRUCache {
public:
list<int>dll;
  unordered_map<int,pair<list<int>::iterator,int>>mp;
    int cap;
    LRUCache(int capacity) {
    cap=capacity;
    }
    void makerecentlyused(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        int val=mp[key].second;
        makerecentlyused(key);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            makerecentlyused(key);
            return ;
        }

        dll.push_front(key);
        mp[key]={dll.begin(),value};
        cap--;
        if(cap<0){
        mp.erase(dll.back());
        dll.pop_back();
        cap++;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */