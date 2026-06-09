class LockingTree {
public:
    vector<int> parent;
    vector<int> locked;
    vector<vector<int>> child;

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();

        locked.resize(n, -1);
        child.resize(n);

        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (locked[num] != -1) {
            return false;
        }

        locked[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (locked[num] != user) {
            return false;
        }

        locked[num] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        int i = num;

        while (i != -1) {
            if (locked[i] != -1) {
                return false;
            }
            i = parent[i];
        }

        int lockedCount = 0;
        queue<int> q;
        q.push(num);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (locked[node] != -1) {
                locked[node] = -1;
                lockedCount++;
            }

            for (int childNode : child[node]) {
                q.push(childNode);
            }
        }

        if (lockedCount > 0) {
            locked[num] = user;
            return true;
        }

        return false;
    }
};
