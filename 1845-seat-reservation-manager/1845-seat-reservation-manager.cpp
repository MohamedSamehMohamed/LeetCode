class SeatManager {
public:
    set<int> st;
    SeatManager(int n) {
        st = set<int>();
        for (int i = 1; i <= n; i++) 
            st.insert(i);
    }
    
    int reserve() {
        int smallest = *st.begin();
        st.erase(smallest);
        return smallest;
    }
    
    void unreserve(int seatNumber) {
        st.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */