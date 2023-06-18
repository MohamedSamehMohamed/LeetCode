class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;
        priority_queue<vector<int>> pq;
        for (int i = 0; i < nums1.size(); i++){
            pq.push({-(nums1[i] + nums2[0]), 0});
        }
        while (!pq.empty() && k--){
            auto cur = pq.top();
            pq.pop();
            cur[0] *= -1;
            int firstNumber =  cur[0] - nums2[cur[1]];
            int secondNumber = nums2[cur[1]];
            ret.push_back({firstNumber, secondNumber});
            cur[1]++;
            if (cur[1] < nums2.size()){
                pq.push({-(firstNumber + nums2[cur[1]]), cur[1]});
            }
        }
        return ret;
    }
};