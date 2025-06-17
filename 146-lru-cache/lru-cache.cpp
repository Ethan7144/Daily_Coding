class LRUCache {
private:
    int capacity;
    list<pair<int, int>> lru; // {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }

        // Move the accessed item to the front of the list
        lru.splice(lru.begin(), lru, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            cache[key]->second = value;
            lru.splice(lru.begin(), lru, cache[key]);
        } else {
            if (lru.size() == capacity) {
                // Remove LRU item
                int lru_key = lru.back().first;
                lru.pop_back();
                cache.erase(lru_key);
            }

            // Insert new item at front
            lru.emplace_front(key, value);
            cache[key] = lru.begin();
        }
    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */