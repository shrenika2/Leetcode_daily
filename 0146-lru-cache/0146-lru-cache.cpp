class LRUCache {
public:
    int n;
    list<pair<int,int>>cache;
    unordered_map<int , list<pair<int , int >>::iterator>mp;


    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        auto it = mp[key];
        int val = it->second;

        cache.erase(it);
        cache.push_back({key , val});

        mp[key]=prev(cache.end());

        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            cache.erase(mp[key]);

            cache.push_back({key , value});
            mp[key]=prev(cache.end());
            return;
        }

        if(cache.size()==n){
            int remo = cache.front().first;

            mp.erase(remo);
            cache.pop_front();
        }
        cache.push_back({key , value});
        mp[key]=prev(cache.end());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */