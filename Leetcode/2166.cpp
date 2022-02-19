class Bitset {
public:
    vector<bool> bits;
    int cnt1, sz; bool f;
    Bitset(int size) {
        bits.resize(size, 0);
        cnt1 = 0; sz = size; f = 0;
    }
    
    void fix(int idx) {
        if (bits[idx] == f) cnt1++; //if bits[idx]=0 and not flipped (f=0), then it becomes 1 (cnt1++). if bits[idx]=1 and flipped (f=1), then it is currently 0 - making it 1 will increment cnt1
        if (f) bits[idx] = 0;
        else bits[idx] = 1;
    }
    
    void unfix(int idx) {
        if (bits[idx] != f) cnt1--; //same logic as above
        if (f) bits[idx] = 1;
        else bits[idx] = 0;
    }
    
    void flip() {
        f = !f; 
        cnt1 = sz - cnt1;
    }
    
    bool all() {
        return cnt1==sz;
    }
    
    bool one() {
        return cnt1;
    }
    
    int count() {
        return cnt1;
    }
    
    string toString() {
        string ret = "";
        for (int i=0; i<sz; i++) {
            if (f) ret += to_string(!bits[i]);
            else ret += to_string(bits[i]);
        }
        return ret;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */