class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxheap;

        for(int stone : stones){
            maxheap.push(stone);
        }

        while(maxheap.size() > 1){
            int first = maxheap.top();
            maxheap.pop();

            int second = maxheap.top();
            maxheap.pop();

            if(first != second){
                maxheap.push(first - second);
            }
        }

        return maxheap.empty() ? 0 : maxheap.top();
    }
};
