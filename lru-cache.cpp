class LRUCache {
private:
    list<pair<int, int>> cache;
    int cacheSize;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        cacheSize = capacity;
    }
    
    int get(int key) {
        // if the key exists
        if(mp.find(key) != mp.end()) {
            auto it = mp[key]; 
            int val = it -> second;
            cache.erase(it); // erase it
            cache.push_front({key, val}); // push it to the front as it was recently used
            mp[key] = cache.begin(); // make that the front
            return val; 
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // check if the key is new
        if(mp.find(key) == mp.end()) {
            if(cacheSize == cache.size()) { // check if the cache buffer is full
                // remove the least recently used
                pair<int, int> lru = cache.back(); 
                cache.pop_back();
                mp.erase(lru.first);
            } 
        } 
        // if the key is present in the cache, erase it.
        else {
            cache.erase(mp[key]);
        }
        // as it was recently accessed/used, push it to the front of the cache buffer.
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
