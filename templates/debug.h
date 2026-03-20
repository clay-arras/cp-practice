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
#include <string_view>
#include <type_traits>

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
    for (std::size_t i = 0; i < vec.size() - 1; i++) {
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
    for (std::size_t i = 0; i < deq.size() - 1; i++) {
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


namespace aggregate_print_impl {

template<typename T>
constexpr std::string_view type_name() {
    #if defined(__GNUC__) || defined(__clang__)
    std::string_view fn = __PRETTY_FUNCTION__;
    std::size_t start = fn.find("T = ");
    if (start == std::string_view::npos) return "unknown";
    start += 4;
    std::size_t end = fn.find_first_of(";]", start);
    if (end == std::string_view::npos) return "unknown";
    return fn.substr(start, end - start);
    #else
    return "struct";
    #endif
}

struct Any { template<typename T> constexpr operator T() const noexcept; };

template<typename T, typename Seq, typename = void>
struct is_brace_constructible_n : std::false_type {};

template<typename T, std::size_t... Is>
struct is_brace_constructible_n<T, std::index_sequence<Is...>,
    std::void_t<decltype(T{(void(Is), Any{})...})>> : std::true_type {};

template<typename T, std::size_t N = 4>
constexpr std::size_t member_count_impl() {
    if constexpr (N == 0) return 0;
    else if constexpr (is_brace_constructible_n<T, std::make_index_sequence<N>>::value) return N;
    else return member_count_impl<T, N - 1>();
}

template<typename T>
constexpr std::size_t member_count = member_count_impl<T, 4>();

template<typename T>
void print_members(std::ostream&, const T&, std::integral_constant<std::size_t, 0>) {}

template<typename T>
void print_members(std::ostream& out, const T& obj, std::integral_constant<std::size_t, 1>) {
    const auto& [m0] = obj;
    out << "[0]: " << m0;
}

template<typename T>
void print_members(std::ostream& out, const T& obj, std::integral_constant<std::size_t, 2>) {
    const auto& [m0, m1] = obj;
    out << "[0]: " << m0 << ", [1]: " << m1;
}

template<typename T>
void print_members(std::ostream& out, const T& obj, std::integral_constant<std::size_t, 3>) {
    const auto& [m0, m1, m2] = obj;
    out << "[0]: " << m0 << ", [1]: " << m1 << ", [2]: " << m2;
}

template<typename T>
void print_members(std::ostream& out, const T& obj, std::integral_constant<std::size_t, 4>) {
    const auto& [m0, m1, m2, m3] = obj;
    out << "[0]: " << m0 << ", [1]: " << m1 << ", [2]: " << m2 << ", [3]: " << m3;
}

template<typename T>
constexpr bool is_printable_aggregate_v =
    std::is_aggregate_v<T> && std::is_class_v<T> && !std::is_array_v<T>;

} // namespace aggregate_print_impl

template<typename T>
auto operator<<(std::ostream& out, const T& obj)
    -> std::enable_if_t<aggregate_print_impl::is_printable_aggregate_v<T>, std::ostream&>
{
    constexpr std::size_t N = aggregate_print_impl::member_count<T>;
    out << aggregate_print_impl::type_name<T>() << " { ";
    aggregate_print_impl::print_members(out, obj, std::integral_constant<std::size_t, N>{});
    out << " }";
    return out;
}
