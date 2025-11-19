// https://leetcode.com/problems/design-a-stack-with-increment-operation

class CustomStack {
public:
    stack<int> s;
    vector<int> incs;
    int N;

    CustomStack(int maxSize) {
        N = maxSize;
        incs = vector<int>(maxSize, 0);
    }
    
    void push(int x) {
        if ((int)s.size() < N)
            s.push(x);
    }
    
    int pop() {
        if (s.empty())
            return -1;

        int sz = (int)s.size()-1;
        int ret = s.top() + incs[sz];

        s.pop();
        if (sz-1 >= 0)
            incs[sz - 1] += incs[sz];
        incs[sz] = 0;

        return ret;
    }
    
    void increment(int k, int val) {
        incs[min(k-1, N-1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
 
 /*

 Input
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
Output
[null,null,null,2,null,null,null,null,null,103,202,201,-1]


Explanation
CustomStack stk = new CustomStack(3); // Stack is Empty []
stk.push(1);                          // stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
stk.push(2);                          // stack becomes [1, 2]
stk.push(3);                          // stack becomes [1, 2, 3]
stk.push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
stk.increment(5, 100);                // stack becomes [101, 102, 103]
stk.increment(2, 100);                // stack becomes [201, 202, 103]
stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
stk.pop();                            // return -1 --> Stack is empty return -1.



stack<int> s = {2, 4, 6, 3};
int N; // maxSize = 4
vector<int> incs (maxSize, 0);

inc(2, 3)
inc(3, 5)
incs = {0, 0, 0, 0};

pop -> 3
pop -> 11
pop -> 12
pop -> 10


time complexity: O(1) for each operation
space complexity: O(N) for data structure

*/