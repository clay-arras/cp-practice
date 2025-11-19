template<class T>
vector<T> Dijkstras(T src, int N) {
    const T mxV = 1e18+9;
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>>> q;
    vector<T> dist(N, mxV);
    dist[src] = 0;
    q.push({0, src});
    while (!q.empty()) {
        T x=q.top().first, u=q.top().second;
        q.pop();
        if (x > dist[u]) continue;
        for (auto t : adj_list[u]) {
            if (x+t.second < dist[t.first]) {
                dist[t.first] = x+t.second;
                q.push({dist[t.first], t.first});
            }
        }
    }
    return dist;
}