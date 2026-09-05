class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> hp;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int num : nums){
            hp.push(num);

            if(hp.size() > k){
                hp.pop();
            }
        }
    }
    
    int add(int val) {
        hp.push(val);

        if(hp.size() > k){
            hp.pop();
        }

        return hp.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
