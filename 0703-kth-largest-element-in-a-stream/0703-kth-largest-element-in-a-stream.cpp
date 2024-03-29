class KthLargest {
public:
    priority_queue<int> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++)
            pq.push(-nums[i]);
    }
    
    int add(int val) {
        pq.push(-val);
        while (pq.size() > k) 
            pq.pop();
        return -pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */