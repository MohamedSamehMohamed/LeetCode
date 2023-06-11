class SnapshotArray {
public:
    map<vector<int>, int> mp;
    set<int> st[50001];
    int snapId;
    SnapshotArray(int length) {
        mp = map<vector<int>, int>();
        for (int i = 0; i < 50001; i++)
            st[i].clear();
        snapId = 0;
    }
    
    void set(int index, int val) {
        mp[{index, snapId}] = val;
        st[index].insert(snapId);
    }
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        if (mp.find({index, snap_id}) != mp.end())
            return mp[{index, snap_id}];
        if (st[index].size() == 0) return 0;
        auto it = st[index].lower_bound(snap_id);
        if (it == st[index].end())
            it--;
        while (it != st[index].begin() && (*it) > snap_id)
            it--;
        int val = *it;
        if (val <= snap_id && val >= 0)
            return mp[{index, val}];
        return 0;
        
    }
};
    
/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */