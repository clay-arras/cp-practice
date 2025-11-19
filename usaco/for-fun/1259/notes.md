we can solve this problem in two steps

a) identifying a greedy order to add edges
b) looping through with DSU to calculate the answer

in the first step, we want to slowly DECREASE the number of friends by keeping
track of the cows in the connected component with the least friends, and
getting rid of them first. of course, getting rid of a cow can decrease the
number of friends for other cows, so we keep a unordered map pointing to a set,
which contains the number of friends a cow has. we can just decrement the cow's
friends in the set every time we remove a cow, which will happen at most M
times. when we decrement, we also keep track of which edge we're removing, and
the best friendship at the time (which will be the beginning of the set)

in the second step, we will have a list of edges, and the minimum number of
friend the cow has. we then simply use a DSU to loop through and calculate the
answer
