class LRUCache {
public:
    int cap;
    int used;
    unordered_map<int, int> mp, frq;
    set<vector<int>> lru;
    int lst;
    LRUCache(int capacity) {
        cap = capacity;
        used = 0;
        mp = unordered_map<int, int>();
        frq = unordered_map<int, int>();
        lru = set<vector<int>>();
        lst = 1;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end() || mp[key] == -1) return -1;
        lru.erase({frq[key], key});
        frq[key] = lst++;
        lru.insert({frq[key], key});
        return mp[key];
    }
    
    void put(int key, int value) {
        bool modify = get(key) != -1;
        if (used == cap && !modify)
        {
            used--;
            auto to_remove = *lru.begin();
            mp[to_remove[1]] = -1;
            lru.erase(to_remove);
        }
        lru.erase({frq[key], key});
        mp[key] = value;
        frq[key] = lst++;
        lru.insert({frq[key], key});
        if (!modify)
            used++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */