class Solution {
public:
    int seg[40001];
    void build(int node, int l, int r){
        if (l == r){
            seg[node] = 1e9;
            return;
        }
        int m = (l+r) >> 1;
        build(node * 2 + 1, l, m);
        build(node * 2 + 2, m+1, r);
        seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
    }
    void update(int index, int val, int node, int l, int r){
        if (l > index || r < index) return;
        if (l == r){
            seg[node] = val;
            return;
        }
        int m = (l+r) >> 1;
        update(index, val, node * 2 + 1, l, m);
        update(index, val, node * 2 + 2, m+1, r);
        seg[node] = min(seg[node * 2 + 1], seg[node * 2 + 2]);
    }
    int get_min(int le, int re, int node, int l, int r){
        if (le > r || re < l) return (int)1e9;
        if (l >= le && r <= re)
            return seg[node];
        int m = (l+r) >> 1;
        return min(get_min(le, re, node * 2 + 1, l, m),
                   get_min(le, re, node * 2 + 2, m+1, r));
    }
    int jump(vector<int>& nums) {
        int sz = nums.size();
        build(0, 0, sz-1);
        vector<int> mnJumps(sz, (int)1e9);
        mnJumps[sz-1] = 0;
        update(sz-1, 0, 0, 0, sz-1);
        for (int i = nums.size()-2; i >= 0; i--){
            int l = i+1, r = min(sz-1, nums[i] + i); 
            mnJumps[i] = 1 + get_min(l, r, 0, 0, sz-1);
            update(i, mnJumps[i], 0, 0, sz-1);
        }
        return mnJumps[0];
    }
};