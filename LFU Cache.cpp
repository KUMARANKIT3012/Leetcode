class LFUCache {
private:
    int capacity, minFreq;
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };
    unordered_map<int, list<Node>::iterator> keyNode;
    unordered_map<int, list<Node>> freqList;

    void updateFreq(int key) {
        auto it = keyNode[key];
        int freq = it->freq, value = it->value;
        freqList[freq].erase(it);
        if (freqList[freq].empty() && freq == minFreq) minFreq++;
        freqList[freq + 1].push_front(Node(key, value, freq + 1));
        keyNode[key] = freqList[freq + 1].begin();
    }

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        updateFreq(key);
        return keyNode[key]->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            keyNode[key]->value = value;
            updateFreq(key);
            return;
        }
        if (keyNode.size() == capacity) {
            int delKey = freqList[minFreq].back().key;
            keyNode.erase(delKey);
            freqList[minFreq].pop_back();
        }
        minFreq = 1;
        freqList[1].push_front(Node(key, value, 1));
        keyNode[key] = freqList[1].begin();
    }
};


