class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll; // Doubly Linked List to store (key, value)
    unordered_map<int, list<pair<int, int>>::iterator> cache; // Hashmap to store key and iterator to list node
    
    void moveToFront(list<pair<int, int>>::iterator it) {
        int key = it->first, value = it->second;
        dll.erase(it);
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        // Move the accessed node to the front as it is now recently used
        moveToFront(cache[key]);
        return dll.front().second;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            moveToFront(cache[key]);
            dll.front().second = value;
            return;
        }
        
        if (dll.size() == capacity) {
            // Remove the least recently used (LRU) key from both list and hashmap
            int lruKey = dll.back().first;
            cache.erase(lruKey);
            dll.pop_back();
        }
        
        // Insert the new key-value pair at the front
        dll.push_front({key, value});
        cache[key] = dll.begin();
    }
};
