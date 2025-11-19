#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <list>
#include <stack>
#include <array>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& lst);

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map);

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set);

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set);

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value);

template <typename T, typename Container, typename Compare>
std::ostream& operator<<(std::ostream& out, std::priority_queue<T, Container, Compare> pq);

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& out, std::stack<T, Container> stk);

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& out, std::queue<T, Container> q);


template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::pair<T1, T2>& pair) {
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    if (vec.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < (int)vec.size() - 1; i++) {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& arr) {
    if (N == 0) {
        out << "[]";
        return out;
    }
    out << '[';
    for (std::size_t i = 0; i < N - 1; i++) {
        out << arr[i] << ", ";
    }
    return out << arr[N - 1] << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& deq) {
    if (deq.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++) {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& lst) {
    if (lst.empty()) {
        out << "[]";
        return out;
    }
    out << '[';
    auto it = lst.begin();
    auto last = std::prev(lst.end());
    while (it != last) {
        out << *it << ", ";
        ++it;
    }
    return out << *last << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, const std::map<T1, T2>& map) {
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++) {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unordered_multiset<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& set) {
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++) {
        T element = *it;
        out << element;
        if (std::next(it) != set.end()) {
            out << ", ";
        }
    }
    return out << '}';
}

// Source: https://stackoverflow.com/a/31116392/12128483
template<typename Type, unsigned N, unsigned Last>
struct TuplePrinter {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct TuplePrinter<Type, N, N> {
    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }
};

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}

template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
std::ostream& operator<<(std::ostream& out, std::priority_queue<T, Container, Compare> pq) {
    out << '[';
    bool first = true;
    while (!pq.empty()) {
        if (!first) out << ", ";
        first = false;
        out << pq.top();
        pq.pop();
    }
    return out << ']';
}

template <typename T, typename Container = std::deque<T>>
std::ostream& operator<<(std::ostream& out, std::stack<T, Container> stk) {
    out << '[';
    bool first = true;
    while (!stk.empty()) {
        if (!first) out << ", ";
        first = false;
        out << stk.top();
        stk.pop();
    }
    return out << ']';
}

template <typename T, typename Container = std::deque<T>>
std::ostream& operator<<(std::ostream& out, std::queue<T, Container> q) {
    out << '[';
    bool first = true;
    while (!q.empty()) {
        if (!first) out << ", ";
        first = false;
        out << q.front();
        q.pop();
    }
    return out << ']';
}
