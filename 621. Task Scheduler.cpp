class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for (char task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> maxHeap;

        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;

                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
