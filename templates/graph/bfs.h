template<class T>
vector<T> BFS(T src, int N) {
    const T mxV = 1e18+9;
    queue<int> q;
    vector<T> dist(N, mxV);
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int t : adj_list[x]) {
            if (dist[t] == mxV) {
                dist[t] = dist[x] + 1;
                q.push(t);
            }
        }
    }
	return dist;
}