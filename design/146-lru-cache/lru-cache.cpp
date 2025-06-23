/*
 * LRUCache Implementation using Doubly Linked List + Hash Map
 * 
 * Overview:
 * - Maintains access order using a `list` where the front is the most recently used (MRU) and the back is the least recently used (LRU).
 * - Provides O(1) time complexity for both `get()` and `put()` operations.
 * 
 * Components:
 * - `capacity`: Maximum number of key-value pairs the cache can hold.
 * - `lru`: Doubly linked list to store key-value pairs in access order.
 * - `cache`: Hash map to store key -> iterator to node in list for O(1) access.
 * 
 * Operations:
 * - `get(key)`:
 *     - If the key exists, move it to the front of the list and return its value.
 *     - If it doesn't exist, return -1.
 * 
 * - `put(key, value)`:
 *     - If the key exists, update its value and move it to the front.
 *     - If the key doesn't exist:
 *         - If at capacity, evict the LRU (back of the list).
 *         - Add the new key-value pair to the front and update the hash map.
 * 
 * Time Complexity:
 * - get: O(1)
 * - put: O(1)
 * 
 * Space Complexity:
 * - O(capacity) for both the hash map and the linked list.
 */
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