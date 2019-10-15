class FreqStack {
    unordered_map<int,int> indexMap;
    unordered_map<int, std::stack<int>> stackMap;
    int length;
public:
    FreqStack() : length(0) {
        
    }
    
    void push(int x) {
        auto it = indexMap.find(x);
        if ( it != indexMap.end()) {
            it->second += 1;
            length = max(length,it->second);
            stackMap[it->second].push(x);
        } else {
            indexMap[x] = 1;
            length = max(length,1);
            stackMap[1].push(x);
        }
        
    }
    
    int pop() {
        //return 0;
        int result = stackMap[length].top();
        stackMap[length].pop();
        if ( stackMap[length].empty() ) {
            --length;
        }
        indexMap[result]--;
        return result;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
