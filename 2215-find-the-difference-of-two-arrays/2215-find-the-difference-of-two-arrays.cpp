class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ret(2);
        set<int> st[2];
        for (int i = 0; i < nums1.size(); i++)
            st[0].insert(nums1[i]);
        for (int i = 0; i < nums2.size(); i++)
            st[1].insert(nums2[i]);
        for (int id = 0; id < 2; id++){
            for (int i: st[id]){
                if (st[id^1].count(i) == 0)
                    ret[id].push_back(i);
            }
        }
        return ret;
    }
};