class SmallestInfiniteSet {
public:
    set<int> st;
    SmallestInfiniteSet() {
        st.clear();
    }
    
    int popSmallest() {
        int cur = 1;
        for (int i: st){
            if (i != cur){
                st.insert(cur);
                return cur;
            }
            cur++;
        }
        st.insert(cur);
        return cur;
    }
    
    void addBack(int num) {
        st.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */