class SeatManager {
public:
    set<int>buf;
    SeatManager(int n) {
        for (int i = 1; i <= n; ++ i)
            buf.insert(i);
    }
    
    int reserve() {
        int tmp = *buf.begin();
        auto idx = buf.begin();
        buf.erase(idx);
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        buf.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
