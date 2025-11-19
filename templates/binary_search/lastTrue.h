template<class T>
T lastTrue(T l, T r, function<bool(T)> f) {
    l--;
    for (T diff=r-l; diff>0; diff/=2)
        while (l + diff <= r && f(l + diff))
            l += diff;
    return l;
}