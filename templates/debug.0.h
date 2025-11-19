// note: this was adapted from user Livw08's blog on codeforces. I added debug for arrays, maps, queues, deque, stacks, priority queues, and tuples
// put file in /usr/local/include
// USAGE: debug(x, a, d)
#include <bits/stdc++.h>
using namespace std;

void deb(int x) {cerr << x;}
void deb(long long x) {cerr << x;}
void deb(float x) {cerr << x;}
void deb(double x) {cerr << x;}
void deb(char x) {cerr << '\'' << x << '\'';}
void deb(const char* x) {cerr << '\"' << x << '\"';}
void deb(const string& x) {cerr << '\"' << x << '\"';}
void deb(bool x) {cerr << (x ? "True" : "False");}

template<typename T, typename V>
void deb(const map<T, V>& x);
template <typename T, typename V>
void deb(const pair<T, V>& x);
template<typename T>
void deb(const T& x);
template<typename T>
void deb(const queue<T>& x);
template<typename T>
void deb(const deque<T>& x);
template<typename T>
void deb(const stack<T>& x);
template<typename T>
void deb(const priority_queue<T>& x);
template <size_t I, typename... T>
typename enable_if<I == sizeof...(T), void>::type deb(tuple<T...> t);
template <size_t I, typename... T>
typename enable_if<(I < sizeof...(T)), void>::type deb(tuple<T...> t);

// pairs
template<typename T, typename V>
void deb(const pair<T, V>& x) {
    cerr << '{';
    deb(x.first);
    cerr << ", ";
    deb(x.second);
    cerr << '}';
}

// maps
template <typename T, typename V>
void deb(const map<T, V>& x){
    int f = 0;
    cerr << '{';
    for (const auto& i : x){
        cerr << '{';
        cerr << (f++ ? ", " : "");
        deb(i.first);
        cerr << ":";
        deb(i.second);
        cerr << '}';
    }
    cerr << '}';
}

// vectors, sets, multisets
template<typename T>
void deb(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x) {
        cerr << (f++ ? ", " : "");
        deb(i);
    }
    cerr << '}';
}

// queue
template<typename T>
void deb(const queue<T>& x){
    queue<T> q(x);
    int f = 0;
    cerr << '{';
    while(!q.empty()){
        cerr << (f++ ? ", " : "");
        deb(q.front());
        q.pop();
    }
    cerr << '}';
}

// priority queue
template<typename T>
void deb(const priority_queue<T>& x){
    priority_queue<T> q(x);
    int f = 0;
    cerr << '{';
    while(!q.empty()){
        cerr << (f++ ? ", " : "");
        deb(q.top());
        q.pop();
    }
    cerr << '}';
}

// stack
template<typename T>
void deb(const stack<T>& x){
    stack<T> q(x);
    int f = 0;
    cerr << '{';
    while(!q.empty()){
        cerr << (f++ ? ", " : "");
        deb(q.top());
        q.pop();
    }
    cerr << '}';
}

// dequeue
template<typename T>
void deb(const deque<T>& x){
    deque<T> q(x);
    int f = 0;
    cerr << '{';
    while(!q.empty()){
        cerr << (f++ ? ", " : "");
        deb(q.front());
        q.pop_front();
    }
    cerr << '}';
}

// tuples
int temp = 0;
template <size_t I = 0, typename... T>
typename enable_if<I == sizeof...(T), void>::type
deb(tuple<T...> t) { cerr << "}"; (void)t;}

template <size_t I = 0, typename... T>
typename enable_if<(I < sizeof...(T)), void>::type
deb(tuple<T...> t) {
    if (!temp++) cerr << "{";
    else cerr << ", ";

    deb(get<I>(t));
    deb<I+1>(t);
    temp = 0;
}


void debug() {cerr << "\n";}
template <typename T, typename... V>
void debug(T&& t, V&&... v) {
    deb(t);
    if (sizeof...(v)) cerr << ", ";
    debug(v...);
}

#define debug(x...) cerr << #x << " = "; debug(x);
