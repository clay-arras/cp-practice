#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#define open(x) freopen(x, "r", stdin);
#else
#define open(x)
#endif

struct DSU {
    vector<int> e;
    void init(int N) {
        e = vector<int>(N,-1);
    }
    int get(int x) {
        if (e[x] < 0)
            return x;
        return e[x] = get(e[x]);
    }
    int size(int x) {
        return -e[get(x)];
    }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x,y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    open("input.txt");

    int t=1;
    while (t--) {
        solve();
    }
}

/*


So far there are two ways to approach this
- Add edges and calculate it like that
- Find the optimal edge to remove

Always remove 1 friend per operation
- How to find new min value
Keep an array of the number of friends everyone has
Every time we remove someone we iterate through the adj_list and remove them
=> Iterating through normally isn't fast enough

Keep a set...
Find minimum in O(1)
Update in O(NlogN)

Total O(NlogN)




We can choose which nodes to add
Adding might be futile because there's no way to greedily choose which node to add
If we choose wrong we might build the solution from the wrong node


Question: Will we always narrow in on the right one (right friendship group)



New Approach: don't build or break anything


If there a subset of nodes that we can iterate through to find the maximum
Two approaches:
- Fix the number of friends
Iterate through 1 to N
For each number grab a subset of all the numbers

- Fix the minimum number of friends


USE DSU
Every time we add a node we go through it's neighbors and check how many friends they have
Will take O(M) time

How do we know which node to add

We need some way to sort them
What if the one we just add has strictly less friends than the other ones

For each DSU keep an array storing all the friends that they have that aren't on the thing yet
The indices of the numbers on the group store how many friends they have
The indices of the numbers outside the group store the number of friends the person has in the group, so how much the min value would change by adding them
The value can only increase, so if there is a decrease it has to come from the newcomer

***Problem: What if there's a tie
=> What if you just do both options

Will adding the best option now always work out => YES
- Because it's always on the minimum, so it doesn't matter if it increases later down the road, because we'll catch it
 */
