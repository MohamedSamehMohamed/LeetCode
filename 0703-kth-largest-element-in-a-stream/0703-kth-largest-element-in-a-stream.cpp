class KthLargest {
public:
    priority_queue<int> one, two;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < nums.size(); i++)
            one.push(nums[i]);
    }
    
    int add(int val) {
        // put largest [k] elements in [two] pq with smallest element in top, 
        // so that the top of [two] pq will be the largest k element  
        // two.top() >= one.top()
        one.push(val);
        while (!two.empty() && -two.top() < one.top()){
            int twoElement = -two.top(); two.pop();
            int oneElement = one.top(); one.pop();
            one.push(twoElement);
            two.push(-oneElement);
        }
        while (two.size() < k){
            two.push(-one.top());
            one.pop();
        }
        return -two.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */